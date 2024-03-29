$Revision: 431 $
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;                                                              ;;
;; Copyright (C) KolibriOS team 2004-2007. All rights reserved. ;;
;; Distributed under terms of the GNU General Public License    ;;
;;                                                              ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;**********************************************************
;  ���������������� ������ � ����������� �D (ATAPI)
;**********************************************************
; ����� ��������� ������  ������� �������� �����������.
; ��������� � ��������� Mario79

;        ��������� ��� ������� ���������� ����
;           ������ �� ������� �������-�����
; ����� ������ ��������� ������� �������� �����������.


; ������������ ���������� ���������� �������� ������
MaxRetr equ 3
; ���������� ����� �������� ���������� � ������ �������
; (� �����)
BSYWaitTime equ 1000  ;2

;*************************************************
;*      ������ ������ ������� �������-�����      *
;* ����������� ������ ������������, ����������   *
;* ��������� � ����������� ����������            *
;* ������� ��������� ���������� ����� ���������� *
;* ���������:                                    *
;* ChannelNumber - ����� ������;                 *
;* DiskNumber - ����� ����� �� ������;           *
;* CDSectorAddress - ����� ������������ �������. *
;* ������ ����������� � ������ CDDataBuf.        *
;*************************************************
ReadCD:
        pusha
; ������ ������ �������
        mov     [CDBlockSize],2048 ;2352
; �������� ����� �������� �������
        call  clear_packet_buffer
; ������������ �������� ������� ��� ����������
; ������� ������
        ; ������ ��� ������� Read CD
        mov     [PacketCommand],byte 0x28  ;0xBE
        ; ������ ����� �������
        mov     AX,word [CDSectorAddress+2]
        xchg    AL,AH
        mov     word [PacketCommand+2],AX
        mov     AX,word [CDSectorAddress]
        xchg    AL,AH
        mov     word [PacketCommand+4],AX
;        mov   eax,[CDSectorAddress]
;        mov   [PacketCommand+2],eax
        ; ������ ���������� ����������� ��������
        mov     [PacketCommand+8],byte 1
        ; ������ ���������� ������ � ������ ������
;        mov     [PacketCommand+9],byte 0xF8
; ������ �������
        call    SendPacketDatCommand
;        call test_mario79
        popa
        ret

;********************************************
;*        ������ ������� � ���������        *
;* ������������ ���������� ������ ��� ����� *
;********************************************
ReadCDWRetr:
        pusha
; ����, ���� ������� �� ��������� ������� ��� ��
; ��������� ���������� �������
        mov     ECX,MaxRetr
@@NextRetr:
; ������ �������
        call    ReadCD
        cmp     [DevErrorCode],0
        je      @@End_4
; �������� �� 2,5 �������
        mov     EAX,[timer_ticks]
        add     EAX,250 ;50
@@Wait:
        call    change_task
        cmp     EAX,[timer_ticks]
        ja      @@Wait
        loop    @@NextRetr
;        call test_mario79
; ��������� �� ������
;        mov     SI,offset ErrS
;        call    FatalError
@@End_4:
        popa
        ret


;   ������������� ���������, �������������� ����������
;             �������� ������ � ������ PIO
;
; ����� ������ ��������� ������� �������� �����������.

; ����������� ���������� ����� �������� �������
; ���������� �� �������� ������� (� �����)
MaxCDWaitTime equ 1000 ;200 ;10 ������

; ������� ������ ��� ������������ �������� �������
PacketCommand:   rb 12  ;DB 12 DUP (?)
; ������� ������ ��� ������ ������ �� ���������
;CDDataBuf       DB 4096 DUP (0)
; ������ ������������ ����� ������ � ������
CDBlockSize     DW ?
; ����� ������������ ������� ������
CDSectorAddress: DD ?
; ����� ������ ��������� �������� � ������
TickCounter_1 DD 0
; ����� ������ �������� ���������� ����������
WURStartTime DD 0
; ��������� ������ ��� ����������
CDDataBuf_pointer dd 0

;****************************************************
;*    ������� ���������� ATAPI �������� �������,    *
;* ����������������� �������� ������ ������� ������ *
;*     �������� 2048 ���� �� ���������� � �����     *
;* ������� ��������� ���������� ����� ����������    *
;* ���������:                                       *
;* ChannelNumber - ����� ������;                    *
;* DiskNumber - ����� ����� �� ������;              *
;* PacketCommand - 12-������� ��������� �����;      *
;* CDBlockSize - ������ ������������ ����� ������.  *
;****************************************************
SendPacketDatCommand:
        pushad
; ������ ����� CHS
        mov     [ATAAddressMode],0
; ������� ATA-������� �������� �������� �������
        mov     [ATAFeatures],0
        mov     [ATASectorCount],0
        mov     [ATASectorNumber],0
        ; ��������� ������ ������������� �����
        mov     AX,[CDBlockSize]
        mov     [ATACylinder],AX
        mov     [ATAHead],0
        mov     [ATACommand],0A0h
        call    SendCommandToHDD_1
;        call test_mario79
        cmp     [DevErrorCode],0 ;��������� ��� ������
        jne     @@End_8    ;���������, �������� ��� ������

; �������� ���������� ��������� � ������
; �������� �������
        mov     DX,[ATABasePortAddr]
        add     DX,7     ;���� 1�7h
@@WaitDevice0:
        call    change_task
        ; ��������� ����� ���������� �������
        mov     EAX,[timer_ticks]
        sub     EAX,[TickCounter_1]
        cmp     EAX,BSYWaitTime
        ja      @@Err1_1   ;������ ����-����
        ; ��������� ����������
        in      AL,DX
        test    AL,80h   ;��������� ������� BSY
        jnz     @@WaitDevice0
        test    AL,1     ;��������� ������� ERR
        jnz     @@Err6
        test    AL,08h   ;��������� ������� DRQ
        jz      @@WaitDevice0
; ������� �������� �������
        cli
        mov     DX,[ATABasePortAddr]
        mov     AX,[PacketCommand]
        out     DX,AX
        mov     AX,[PacketCommand+2]
        out     DX,AX
        mov     AX,[PacketCommand+4]
        out     DX,AX
        mov     AX,[PacketCommand+6]
        out     DX,AX
        mov     AX,[PacketCommand+8]
        out     DX,AX
        mov     AX,[PacketCommand+10]
        out     DX,AX
        sti
; �������� ���������� ������
        mov     DX,[ATABasePortAddr]
        add     DX,7   ;���� 1�7h
@@WaitDevice1:
        call    change_task
        ; ��������� ����� ���������� �������
        mov     EAX,[timer_ticks]
        sub     EAX,[TickCounter_1]
        cmp     EAX,MaxCDWaitTime
        ja      @@Err1_1   ;������ ����-����
        ; ��������� ����������
        in      AL,DX
        test    AL,80h   ;��������� ������� BSY
        jnz     @@WaitDevice1
        test    AL,1     ;��������� ������� ERR
        jnz     @@Err6_temp
        test    AL,08h   ;��������� ������� DRQ
        jz      @@WaitDevice1
        cli
; ������� ���� ������ �� �����������
        mov     EDI,[CDDataBuf_pointer] ;0x7000  ;CDDataBuf
        ; ��������� ����� �������� ������ �����������
        mov     DX,[ATABasePortAddr] ;���� 1x0h
        ; ��������� � ������� ������ ����� � ������
        mov     CX,[CDBlockSize]
        ; ��������� ������ ����� � 16-��������� ������
        shr     CX,1 ;��������� ������ ����� �� 2
        ; ������� ���� ������
        cld
        rep     insw
        sti
        ; �������� ���������� ������ ������
        jmp @@End_8

; �������� ��� ������
@@Err1_1:
        mov     [DevErrorCode],1
        jmp @@End_8
@@Err6_temp:
        mov     [DevErrorCode],7
        jmp @@End_8
@@Err6:
        mov     [DevErrorCode],6

@@End_8:
        popad
        ret



;***********************************************
;*  ������� ���������� ATAPI �������� �������, *
;*     �� ����������������� �������� ������    *
;* ������� ��������� ���������� �����          *
;* ���������� ���������:                       *
;* ChannelNumber - ����� ������;               *
;* DiskNumber - ����� ����� �� ������;         *
;* PacketCommand - 12-������� ��������� �����. *
;***********************************************
SendPacketNoDatCommand:
        pushad
; ������ ����� CHS
        mov     [ATAAddressMode],0
; ������� ATA-������� �������� �������� �������
        mov     [ATAFeatures],0
        mov     [ATASectorCount],0
        mov     [ATASectorNumber],0
        mov     [ATACylinder],0
        mov     [ATAHead],0
        mov     [ATACommand],0A0h
        call    SendCommandToHDD_1
        cmp     [DevErrorCode],0 ;��������� ��� ������
        jne     @@End_9  ;���������, �������� ��� ������
; �������� ���������� ��������� � ������
; �������� �������
        mov     DX,[ATABasePortAddr]
        add     DX,7   ;���� 1�7h
@@WaitDevice0_1:
        call    change_task
        ; ��������� ����� ��������
        mov     EAX,[timer_ticks]
        sub     EAX,[TickCounter_1]
        cmp     EAX,BSYWaitTime
        ja      @@Err1_3   ;������ ����-����
        ; ��������� ����������
        in      AL,DX
        test    AL,80h   ;��������� ������� BSY
        jnz     @@WaitDevice0_1
        test    AL,1     ;��������� ������� ERR
        jnz     @@Err6_1
        test    AL,08h   ;��������� ������� DRQ
        jz      @@WaitDevice0_1
; ������� �������� �������
;        cli
        mov     DX,[ATABasePortAddr]
        mov     AX,word [PacketCommand]
        out     DX,AX
        mov     AX,word [PacketCommand+2]
        out     DX,AX
        mov     AX,word [PacketCommand+4]
        out     DX,AX
        mov     AX,word [PacketCommand+6]
        out     DX,AX
        mov     AX,word [PacketCommand+8]
        out     DX,AX
        mov     AX,word [PacketCommand+10]
        out     DX,AX
;        sti
; �������� ������������� ������ �������
        mov     DX,[ATABasePortAddr]
        add     DX,7   ;���� 1�7h
@@WaitDevice1_1:
        call    change_task
        ; ��������� ����� ���������� �������
        mov     EAX,[timer_ticks]
        sub     EAX,[TickCounter_1]
        cmp     EAX,MaxCDWaitTime
        ja      @@Err1_3   ;������ ����-����
        ; ������� ������������ ����������
        in      AL,DX
        test    AL,80h   ;��������� ������� BSY
        jnz     @@WaitDevice1_1
        test    AL,1     ;��������� ������� ERR
        jnz     @@Err6_1
        test    AL,40h   ;��������� ������� DRDY
        jz      @@WaitDevice1_1
        jmp @@End_9

; �������� ��� ������
@@Err1_3:
        mov     [DevErrorCode],1
        jmp @@End_9
@@Err6_1:
        mov     [DevErrorCode],6
@@End_9:
        popad
        ret

;****************************************************
;*          ������� ������� ��������� �����         *
;* ������� ��������� ���������� ����� ����������    *
;* ����������:                                      *
;* ChannelNumber - ����� ������ (1 ��� 2);          *
;* DiskNumber - ����� ����� (0 ��� 1);              *
;* ATAFeatures - "�����������";                     *
;* ATASectorCount - ���������� ��������;            *
;* ATASectorNumber - ����� ���������� �������;      *
;* ATACylinder - ����� ���������� ��������;         *
;* ATAHead - ����� ��������� �������;               *
;* ATAAddressMode - ����� ��������� (0-CHS, 1-LBA); *
;* ATACommand - ��� �������.                        *
;* ����� ��������� ���������� �������:              *
;* � ATABasePortAddr - ������� ����� HDD;           *
;* � DevErrorCode - ����.                           *
;* ��� ������������� ������ � DevErrorCode �����    *
;* ��������� ��� ������.                            *
;****************************************************
SendCommandToHDD_1:
        pushad
; ��������� �������� ���� ������
        cmp     [ATAAddressMode],1
        ja      @@Err2_4
; ��������� ������������ ������ ������
        mov     BX,[ChannelNumber]
        cmp     BX,1
        jb      @@Err3_4
        cmp     BX,2
        ja      @@Err3_4
; ���������� ������� �����
        dec     BX
        shl     BX,1
        movzx   ebx,bx
        mov     AX,[ebx+StandardATABases]
        mov     [ATABasePortAddr],AX
; �������� ���������� HDD � ������ �������
        ; ������� ������ ����
        mov     DX,[ATABasePortAddr]
        add     DX,6    ;����� �������� �������
        mov     AL,[DiskNumber]
        cmp     AL,1    ;��������� ������ �����
        ja      @@Err4_4
        shl     AL,4
        or      AL,10100000b
        out     DX,AL
        ; �������, ���� ���� �� ����� �����
        inc     DX
;        mov  ecx,0xfff
        mov     eax,[timer_ticks]
        mov     [TickCounter_1],eax
@@WaitHDReady_2:
        call    change_task
        ; ��������� ����� ��������
;        dec  ecx
;        cmp  ecx,0
;        je     @@Err1
        mov     eax,[timer_ticks]
        sub     eax,[TickCounter_1]
        cmp     eax,BSYWaitTime ;300    ;������� 3 ���.        
        ja      @@Err1_4   ;������ ����-����
        ; ��������� ������� ���������
        in      AL,DX
        ; ��������� ��������� ������� BSY
        test    AL,80h
        jnz     @@WaitHDReady_2
        ; ��������� ��������� ������� DRQ
        test    AL,08h
        jnz     @@WaitHDReady_2
; ��������� ������� � �������� �����������
        cli
        mov     DX,[ATABasePortAddr]
        inc     DX      ;������� "������������"
        mov     AL,[ATAFeatures]
        out     DX,AL
        inc     DX      ;������� ��������
        mov     AL,[ATASectorCount]
        out     DX,AL
        inc     DX      ;������� ������ �������
        mov     AL,[ATASectorNumber]
        out     DX,AL
        inc     DX      ;����� �������� (������� ����)
        mov     AX,[ATACylinder]
        out     DX,AL
        inc     DX      ;����� �������� (������� ����)
        mov     AL,AH
        out     DX,AL
        inc     DX      ;����� �������/����� �����
        mov     AL,[DiskNumber]
        shl     AL,4
        cmp     [ATAHead],0Fh ;��������� ����� �������
        ja      @@Err5_4
        or      AL,[ATAHead]
        or      AL,10100000b
        mov     AH,[ATAAddressMode]
        shl     AH,6
        or      AL,AH
        out     DX,AL
; ������� �������
        mov     AL,[ATACommand]
        inc     DX      ;������� ������
        out     DX,AL
        sti
; �������� ������� ������
        mov     [DevErrorCode],0
        jmp @@End_10
; �������� ��� ������
@@Err1_4:
        mov     [DevErrorCode],1
        jmp @@End_10
@@Err2_4:
        mov     [DevErrorCode],2
        jmp @@End_10
@@Err3_4:
        mov     [DevErrorCode],3
        jmp @@End_10
@@Err4_4:
        mov     [DevErrorCode],4
        jmp @@End_10
@@Err5_4:
        mov     [DevErrorCode],5
; ���������� ������ ���������
@@End_10:
        sti
        popad 
        ret
        
;*************************************************
;*    �������� ���������� ���������� � ������    *
;* ������� ��������� ���������� ����� ���������� *
;* ���������:                                    *
;* ChannelNumber - ����� ������;                 *
;* DiskNumber - ����� ����� �� ������.           *
;*************************************************
WaitUnitReady:
        pusha
; ��������� ����� ������ ��������
        mov     EAX,[timer_ticks]
        mov     [WURStartTime],EAX
; �������� ����� �������� �������
        call  clear_packet_buffer
; ������������ ������� TEST UNIT READY
        mov     [PacketCommand],word 00h
; ���� �������� ���������� ����������
@@SendCommand:
        ; ������ ������� �������� ����������
        call    SendPacketNoDatCommand
        call    change_task
        ; ��������� ��� ������
        cmp     [DevErrorCode],0
        je      @@End_11
        ; ��������� ����� �������� ����������
        mov     EAX,[timer_ticks]
        sub     EAX,[WURStartTime]
        cmp     EAX,MaxCDWaitTime
        jb      @@SendCommand
        ; ������ ����-����
        mov     [DevErrorCode],1
@@End_11:
        popa
        ret

        
;*************************************************
;*         ��������� �������� � ��������         *
;* ������� ��������� ���������� ����� ���������� *
;* ���������:                                    *
;* ChannelNumber - ����� ������;                 *
;* DiskNumber - ����� ����� �� ������.           *
;*************************************************
LoadMedium:
        pusha
; �������� ����� �������� �������
        call  clear_packet_buffer
; ������������ ������� START/STOP UNIT
        ; ������ ��� �������
        mov     [PacketCommand],word 1Bh
        ; ������ �������� �������� ��������
        mov     [PacketCommand+4],word 00000011b
; ������ �������
        call    SendPacketNoDatCommand
        popa
        ret

;*************************************************
;*         ������� �������� �� ���������         *
;* ������� ��������� ���������� ����� ���������� *
;* ���������:                                    *
;* ChannelNumber - ����� ������;                 *
;* DiskNumber - ����� ����� �� ������.           *
;*************************************************
UnloadMedium:
        pusha
; �������� ����� �������� �������
        call  clear_packet_buffer
; ������������ ������� START/STOP UNIT
        ; ������ ��� �������
        mov     [PacketCommand],word 1Bh
        ; ������ �������� ���������� ��������
        mov     [PacketCommand+4],word 00000010b
; ������ �������
        call    SendPacketNoDatCommand
        popa
        ret

;*************************************************
;* ���������� ����� ���������� �������� �� ����� *
;* ������� ��������� ���������� ����� ���������� *
;* ����������:                                   *
;* ChannelNumber - ����� ������;                 *
;* DiskNumber - ����� ����� �� ������.           *
;*************************************************
ReadCapacity:
        pusha
; �������� ����� �������� �������
        call  clear_packet_buffer
; ������ ������ ������ � ������
        mov     [CDBlockSize],8
; ������������ ������� READ CAPACITY
        mov     [PacketCommand],word 25h
; ������ �������
        call    SendPacketDatCommand
        popa
        ret

clear_packet_buffer:        
; �������� ����� �������� �������
        mov     [PacketCommand],dword 0
        mov     [PacketCommand+4],dword 0
        mov     [PacketCommand+8],dword 0
        ret

