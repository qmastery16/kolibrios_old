$Revision: 431 $
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;                                                              ;;
;; Copyright (C) KolibriOS team 2004-2007. All rights reserved. ;;
;; Distributed under terms of the GNU General Public License    ;;
;;                                                              ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;***************************************************
;      ��������������� ������� ������� �������
;      ����� � ��������� � ������� �������� FDD
;      ����� Mario79
;***************************************************
        xor  eax,eax
        mov  edi,DRIVE_DATA
        mov  ecx,16384
        cld
        rep  stosd

      mov al,0x10
      out 0x70,al
      mov  cx,0xff
wait_cmos:
      dec  cx
      cmp cx,0
      jne wait_cmos
      in  al,0x71
      mov [DRIVE_DATA],al
