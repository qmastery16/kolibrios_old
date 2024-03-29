;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;                                                              ;;
;; Copyright (C) KolibriOS team 2004-2007. All rights reserved. ;;
;; Copyright (C) MenuetOS 2000-2004 Ville Mikael Turjanmaa      ;;
;; Distributed under terms of the GNU General Public License    ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

$Revision: 1689 $

WINDOW_MOVE_AND_RESIZE_FLAGS = \
  mouse.WINDOW_RESIZE_N_FLAG + \
  mouse.WINDOW_RESIZE_W_FLAG + \
  mouse.WINDOW_RESIZE_S_FLAG + \
  mouse.WINDOW_RESIZE_E_FLAG + \
  mouse.WINDOW_MOVE_FLAG

uglobal
align 4
  event_start   dd ?
  event_end     dd ?
  event_uid     dd 0
endg
EV_SPACE   = 512
FreeEvents = event_start-EVENT.fd    ; "�����������" event, ������������ ������ ����:
                                     ;  FreeEvents.fd=event_start � FreeEvents.bk=event_end
align 4
init_events:                                       ;; used from kernel.asm
        stdcall kernel_alloc,EV_SPACE*EVENT.size
        or      eax,eax
        jz      .fail
      ; eax - current event, ebx - previos event below
        mov     ecx,EV_SPACE         ; current - in allocated space
        mov     ebx,FreeEvents       ; previos - ������ ������
        push    ebx                  ; ��� �� � ����� ����� �����
  @@:   mov     [ebx+EVENT.fd],eax
        mov     [eax+EVENT.bk],ebx
        mov     ebx,eax              ; previos <- current
        add     eax,EVENT.size       ; new current
        loop    @b
        pop     eax                  ; ��� ��� ������ � �����
        mov     [ebx+EVENT.fd],eax
        mov     [eax+EVENT.bk],ebx
.fail:  ret

EVENT_WATCHED    equ 0x10000000 ;��� 28
EVENT_SIGNALED   equ 0x20000000 ;��� 29
MANUAL_RESET     equ 0x40000000 ;��� 30
MANUAL_DESTROY   equ 0x80000000 ;��� 31

align 4
create_event:                                      ;; EXPORT use
;info:
;   ��������� EVENT �� ������ FreeEvents � ������ ObjList �������� �����
;   EVENT.state ������������� �� ecx, EVENT.code �������� �� esi (���� esi<>0)
;param:
;   esi - event data
;   ecx - flags
;retval:
;   eax - event (=0 => fail)
;   edx - uid
;scratched: ebx,ecx,esi,edi
        mov     ebx,[current_slot]
        add     ebx,APP_OBJ_OFFSET
        mov     edx,[TASK_BASE]
        mov     edx,[edx+TASKDATA.pid]
        pushfd
        cli

set_event:                                         ;; INTERNAL use !!! don't use for Call
;info:
;   ����� ����� event �� FreeEvents, ��������� ��� ����, ��� ������� � ecx,edx,esi
;   � ������������� � ������, ��������� � ebx.
;   ���������� ��� event (� eax), � ��� uid (� edx)
;param:
;   ebx - start-chain "virtual" event for entry new event Right of him
;   ecx - flags      (copied to EVENT.state)
;   edx - pid        (copied to EVENT.pid)
;   esi - event data (copied to EVENT.code indirect, =0 => skip)
;retval:
;   eax - event (=0 => fail)
;   edx - uid
;scratched: ebx,ecx,esi,edi
        mov     eax,FreeEvents
        cmp     eax,[eax+EVENT.fd]
        jne     @f  ; not empty ???
        pushad
        call    init_events
        popad
        jz      RemoveEventTo.break ; POPF+RET
  @@:   mov     eax,[eax+EVENT.fd]
        mov     [eax+EVENT.magic],'EVNT'
        mov     [eax+EVENT.destroy],destroy_event.internal
        mov     [eax+EVENT.state],ecx
        mov     [eax+EVENT.pid],edx
        inc     [event_uid]
        Mov     [eax+EVENT.id],edx,[event_uid]
        or      esi,esi
        jz      RemoveEventTo
        lea     edi,[eax+EVENT.code]
        mov     ecx,EVENT.codesize/4
        cld
        rep     movsd

RemoveEventTo:                                     ;; INTERNAL use !!! don't use for Call
;param:
;   eax - ��������� �� event, ������� ���������
;   ebx - ��������� �� event, ����� �������� ���������
;scratched: ebx,ecx
        mov     ecx,eax              ; ecx=eax=Self,      ebx=NewLeft
        xchg    ecx,[ebx+EVENT.fd]   ; NewLeft.fd=Self,   ecx=NewRight
        cmp     eax,ecx              ; ����, ���� �����...
        je      .break               ; - � �� ����� �� �?
        mov     [ecx+EVENT.bk],eax   ; NewRight.bk=Self
        xchg    ebx,[eax+EVENT.bk]   ; Self.bk=NewLeft,   ebx=OldLeft
        xchg    ecx,[eax+EVENT.fd]   ; Self.fd=NewRight,  ecx=OldRight
        mov     [ebx+EVENT.fd],ecx   ; OldLeft.fd=OldRight
        mov     [ecx+EVENT.bk],ebx   ; OldRight.bk=OldLeft
.break: popfd
        ret

align 4
NotDummyTest:                                      ;; INTERNAL use (not returned for fail !!!)
        pop     edi
        call    DummyTest ; not returned for fail !!!
        mov     ebx,eax
        mov     eax,[ebx+EVENT.pid]
        push    edi
.small: ; ����� ���-��...
        pop     edi
        pushfd
        cli
        call    pid_to_slot ; saved all registers (eax - retval)
        shl     eax,8
        jz      RemoveEventTo.break ; POPF+RET
        jmp     edi ; ������� �������

align 4
raise_event:                                       ;; EXPORT use
;info:
;   ������������� ������ EVENT.code
;   ���� ��� ���� EVENT_SIGNALED ��� ������� - ������ ������
;   �����: ���� ���� ���������, �� ����������� ������ ������� ����� EVENT_WATCHED � edx
;   � ���� ������ EVENT_SIGNALED ��������� ���� ��� ������� EVENT_WATCHED � ����� �������
;param:
;   eax - event
;   ebx - uid (for Dummy testing)
;   edx - flags
;   esi - event data (=0 => skip)
;scratched: ebx,ecx,esi,edi
        call    NotDummyTest ; not returned for fail !!!
        or      esi,esi
        jz      @f
        lea     edi,[ebx+EVENT.code]
        mov     ecx,EVENT.codesize/4
        cld
        rep     movsd
  @@:
        test    byte[ebx+EVENT.state+3], EVENT_SIGNALED shr 24
        jnz     RemoveEventTo.break  ; POPF+RET
        bt      edx, 28 ;EVENT_WATCHED
        jnc     @f
        test    byte[ebx+EVENT.state+3], EVENT_WATCHED  shr 24
        jz      RemoveEventTo.break  ; POPF+RET
  @@:
        or      byte[ebx+EVENT.state+3], EVENT_SIGNALED shr 24
        add     eax,SLOT_BASE+APP_EV_OFFSET
        xchg    eax,ebx
        jmp     RemoveEventTo

align 4
clear_event:                                       ;; EXPORT use
;info:
;
;param:
;   eax - event
;   ebx - uid (for Dummy testing)
;scratched: ebx,ecx
        call    NotDummyTest ; not returned for fail !!!
        add     eax,SLOT_BASE+APP_OBJ_OFFSET
        and     byte[ebx+EVENT.state+3], not((EVENT_SIGNALED+EVENT_WATCHED)shr 24)
        xchg    eax,ebx
        jmp     RemoveEventTo

align 4
send_event:                                        ;; EXPORT use
;info:
;   ������� ����� EVENT (����������� �� ������ FreeEvents) � ������ EventList
;   �������� ����� (eax=pid), � ������� �� esi ��������, � state=EVENT_SIGNALED
;param:
;   eax - slots pid, to sending new event
;   esi - pointer to sending data (in code field of new event)
;retval:
;   eax - event (=0 => fail)
;   edx - uid
;warning:
;   may be used as CDECL with such prefix...
;       mov     esi,[esp+8]
;       mov     eax,[esp+4]
;   but not as STDCALL :(
;scratched: ebx,ecx,esi,edi
        mov     edx,eax
        call    NotDummyTest.small ; not returned for fail !!!
        lea     ebx,[eax+SLOT_BASE+APP_EV_OFFSET]
        mov     ecx,EVENT_SIGNALED
        jmp     set_event

align 4
DummyTest:                                         ;; INTERNAL use (not returned for fail !!!)
;param:
;   eax - event
;   ebx - uid (for Dummy testing)
        cmp     [eax+EVENT.magic],'EVNT'
        jne     @f
        cmp     [eax+EVENT.id],ebx
        je      .ret
  @@:   pop     eax
        xor     eax,eax
.ret:   ret


align 4
Wait_events:
        or      ebx,-1 ; infinite timeout
Wait_events_ex:
;info:
;   �������� "������������" ������� ����� ������� ����� � 5-� �������.
;   ������������� ��������� � ���, ��� ���� ������� ������������ �������� APPDATA.wait_test,
;   ������� �������� �������� � ����� ���� ���������� �����.
;   ��� ��������� shed-� ������� ���������� ���� �������, � �� ��������� "��������" ������������,
;   ��������������� ��� �������� ���� "����/�����" ������ ������.
;param:
;   edx - wait_test, ���������� �-� ������������ (����� ����)
;   ecx - wait_param, �������������� ��������, �������� ����������� ��� [wait_test]
;   ebx - wait_timeout
;retval:
;   eax - ��������� ������ [wait_test] (=0 => timeout)
;scratched: esi
        mov     esi,[current_slot]
        mov     [esi+APPDATA.wait_param],ecx
        pushad
        mov     ebx,esi;���� ��� ������, ���� ���� ������..........
        pushfd  ; ��� ��������� ����� ���������: ����� �-� ������������ �����
        cli     ; ����� ������������ �� �������� ����������, ��� ��� ������ �� shed
        call    edx
        popfd
        mov     [esp+28],eax
        popad
        or      eax,eax
        jnz     @f   ;RET
        mov     [esi+APPDATA.wait_test],edx
        mov     [esi+APPDATA.wait_timeout],ebx
        Mov     [esi+APPDATA.wait_begin],eax,[timer_ticks]
        mov     eax,[TASK_BASE]
        mov     [eax+TASKDATA.state], 5
        call    change_task
        mov     eax,[esi+APPDATA.wait_param]
  @@:   ret

align 4
wait_event:                                        ;; EXPORT use
;info:
;   �������� ����� EVENT_SIGNALED � ���������� ���������� Event
;   (����������������, ���� ��������, ����� raise_event)
;   ��� �������� ����� MANUAL_RESET - ������ ������
;   �����: ����� EVENT_SIGNALED � EVENT_WATCHED � ����������� ������� ������������,
;   �, ��� �������� MANUAL_DESTROY - ������������ � ������ ObjList �������� �����,
;   � ��� �� �������� - ������������ ������ (destroy_event.internal)
;param:
;   eax - event
;   ebx - uid (for Dummy testing)
;scratched: ecx,edx,esi
        call    DummyTest
        mov     ecx,eax              ; wait_param
        mov     edx, get_event_alone ; wait_test
        call    Wait_events          ; timeout ignored
        jmp     wait_finish

align 4
get_event_ex:                                      ;; f68:14
;info:
;   �������� ������ ������� � ������� EventList �������� �����
;   ������ ������� code - ���������� � ������ ���������� (�������� �� edi)
;   ��� �������� ����� MANUAL_RESET - ������ ������
;   �����: ����� EVENT_SIGNALED � EVENT_WATCHED � ����������� ������� ������������,
;   �, ��� �������� MANUAL_DESTROY - ������������ � ������ ObjList �������� �����,
;   � ��� �� �������� - ������������ ������ (destroy_event.internal)
;param:
;   edi - ����� � ���� ���������� ��� ����������� ������ �� EVENT.code
;retval:
;   eax - ���������� EVENT (����� �������� ��� ��� �������)
;scratched: ebx,ecx,edx,esi,edi
        mov     edx, get_event_queue ; wait_test
        call    Wait_events          ; timeout ignored
        lea     esi,[eax+EVENT.code]
        mov     ecx,EVENT.codesize/4
        cld
        rep     movsd
        mov     [edi-EVENT.codesize+2],cl ;clear priority field
wait_finish:
        test    byte[eax+EVENT.state+3], MANUAL_RESET shr 24
        jnz     get_event_queue.ret  ; RET
        and     byte[eax+EVENT.state+3], not((EVENT_SIGNALED+EVENT_WATCHED)shr 24)
        test    byte[eax+EVENT.state+3], MANUAL_DESTROY shr 24
        jz      destroy_event.internal
        mov     ebx,[current_slot]
        add     ebx,APP_OBJ_OFFSET
        pushfd
        cli
        jmp     RemoveEventTo

align 4
destroy_event:                                     ;; EXPORT use
;info:
;   ��������� EVENT � ������ FreeEvents, ������ ���� magic,destroy,pid,id
;param:
;   eax - event
;   ebx - uid (for Dummy testing)
;retval:
;   eax - ����� ������� EVENT (=0 => fail)
;scratched: ebx,ecx
        call    DummyTest ; not returned for fail !!!
.internal:
        xor     ecx,ecx   ; clear common header
        pushfd
        cli
        mov     [eax+EVENT.magic],ecx
        mov     [eax+EVENT.destroy],ecx
        mov     [eax+EVENT.pid],ecx
        mov     [eax+EVENT.id],ecx
        mov     ebx,FreeEvents
        jmp     RemoveEventTo

align 4
get_event_queue:
;info:
;   ���������� �-� ������������ ��� get_event_ex
;warning:
;  -don't use [TASK_BASE],[current_slot],[CURRENT_TASK] - it is not for your slot
;  -may be assumed, that interrupt are disabled
;  -it is not restriction for scratched registers
;param:
;   ebx - ����� APPDATA ����� ������������
;retval:
;   eax - ����� ������� EVENT (=0 => fail)
        add     ebx,APP_EV_OFFSET
        mov     eax,[ebx+APPOBJ.bk]  ; �������� � �����, �� �������� FIFO
        cmp     eax,ebx  ; empty ???
        je      get_event_alone.ret0
.ret:   ret

align 4
get_event_alone:
;info:
;   ���������� �-� ������������ ��� wait_event
;warning:
;  -don't use [TASK_BASE],[current_slot],[CURRENT_TASK] - it is not for your slot
;  -may be assumed, that interrupt are disabled
;  -it is not restriction for scratched registers
;param:
;   ebx - ����� APPDATA ����� ������������
;retval:
;   eax - ����� ������� EVENT (=0 => fail)
        mov     eax,[ebx+APPDATA.wait_param]
        test    byte[eax+EVENT.state+3], EVENT_SIGNALED shr 24
        jnz     .ret
        or      byte[eax+EVENT.state+3], EVENT_WATCHED shr 24
.ret0:  xor     eax,eax ; NO event!!!
.ret:   ret

align 4
sys_sendwindowmsg:                                 ;; f72
        dec     ebx
        jnz     .ret ;subfunction==1 ?
       ;pushfd  ;� ������?
        cli
        sub     ecx,2
        je      .sendkey
        dec     ecx
        jnz     .retf
.sendbtn:
        cmp     byte[BTN_COUNT],1
        jae     .result ;overflow
        inc     byte[BTN_COUNT]
        shl     edx, 8
        mov     [BTN_BUFF],edx
        jmp     .result
.sendkey:
        movzx   eax,byte[KEY_COUNT]
        cmp     al,120
        jae     .result ;overflow
        inc     byte[KEY_COUNT]
        mov     [KEY_COUNT+1+eax],dl
.result:
        setae   byte[esp+32] ;�������, ��� �������: dword[esp+32]==72
.retf: ;popfd
.ret:   ret

align 4
sys_getevent:                                      ;; f11
        mov     ebx,[current_slot] ;���� ��� ������, ���� ���� ������..........
        pushfd  ; ��� ��������� ����� ���������: ����� �-� ������������ �����
        cli     ; ����� ������������ �� �������� ����������, ��� ��� ������ �� shed
        call    get_event_for_app
        popfd
        mov     [esp+32],eax
        ret

align 4
sys_waitforevent:                                  ;; f10
        or      ebx,-1 ; infinite timeout
sys_wait_event_timeout:                            ;; f23
        mov     edx,get_event_for_app ; wait_test
        call    Wait_events_ex        ; ebx - timeout
        mov     [esp+32],eax
        ret

align 4
get_event_for_app:                                 ;; used from f10,f11,f23
;info:
;   ���������� �-� ������������ ��� ���������� (f10,f23)
;warning:
;  -don't use [TASK_BASE],[current_slot],[CURRENT_TASK] - it is not for your slot
;  -may be assumed, that interrupt are disabled
;  -it is not restriction for scratched registers
;param:
;   ebx - ����� APPDATA ����� ������������
;retval:
;   eax - ����� ������� (=0 => no events)
        movzx   edi,bh                ; bh  is assumed as [CURRENT_TASK]
        shl     edi,5
        add     edi,CURRENT_TASK      ; edi is assumed as [TASK_BASE]
        mov     ecx,[edi+TASKDATA.event_mask]
.loop: ; ���� �� ��������� ��� ���� �����
        bsr     eax,ecx        ; ������� ��������� ��� ����� (31 -> 0)
        jz      .no_events     ; ��������� ��� ���� �����, �� ������ �� ����� ???
        btr     ecx,eax        ; ���������� ����������� ��� �����
       ; ��������� �� ���������� ����� (eax) ����
        cmp     eax,16
        jae     .IRQ           ; eax=[16..31]=retvals, events irq0..irq15
        cmp     eax,9
        jae     .loop          ; eax=[9..15], ignored
        cmp     eax,3
        je      .loop          ; eax=3, ignored
        ja      .FlagAutoReset ; eax=[4..8], retvals=eax+1
        cmp     eax,1
        jae     .BtKy          ; eax=[1,2],  retvals=eax+1
.WndRedraw:                    ; eax=0, retval WndRedraw=1
        cmp     [edi-twdw+WDATA.fl_redraw],al ;al==0
        jne     .result
        jmp     .loop
  .no_events:
        xor     eax,eax
        ret
.IRQ:
;TODO: same thing as done for FlagAutoReset (BgrRedraw,Mouse,IPC,Stack,Debug)
        mov     edx,[irq_owner+eax*4-64] ; eax==16+irq
        cmp     edx,[edi+TASKDATA.pid]
        jne     .loop
        mov     edx,eax
        shl     edx,12
        cmp     dword[IRQ_SAVE+edx-0x10000],0 ; edx==(16+irq)*0x1000
        je      .loop          ; empty ???
        ret     ; retval = eax
.FlagAutoReset: ; retvals: BgrRedraw=5, Mouse=6, IPC=7, Stack=8, Debug=9
        cmp     eax,5 ; Mouse 5+1=6
        jne     @f
        push    eax
; If the window is captured and moved by the user, then no mouse events!!!
        mov     al, [mouse.active_sys_window.action]
        and     al, WINDOW_MOVE_AND_RESIZE_FLAGS
        test    al, al
	pop     eax
        jnz     .loop
@@:
        btr     [ebx+APPDATA.event_mask],eax
        jnc     .loop
  .result:      ; retval = eax+1
        inc     eax
        ret
  .BtKy:
        movzx   edx,bh
        movzx   edx, word[WIN_STACK+edx*2]
        je      .Keys          ; eax=1, retval Keys=2
.Buttons:                      ; eax=2, retval Buttons=3
        cmp     byte[BTN_COUNT],0
        je      .loop          ; empty ???
        cmp     edx,[TASK_COUNT]
        jne     .loop          ; not Top ???
        mov     edx, [BTN_BUFF]
        shr     edx, 8
        cmp     edx, 0xFFFF    ;-ID for Minimize-Button of Form
        jne     .result
        mov     [window_minimize],1
        dec     byte[BTN_COUNT]
        jmp     .loop
.Keys:    ; eax==1
        cmp     edx,[TASK_COUNT]
        jne     @f             ; not Top ???
        cmp     [KEY_COUNT],al ; al==1
        jae     .result        ; not empty ???
  @@:   mov     edx, hotkey_buffer
  @@:   cmp     [edx],bh       ; bh - slot for testing
        je      .result
        add     edx,8
        cmp     edx, hotkey_buffer+120*8
        jb      @b
        jmp     .loop
;end.
