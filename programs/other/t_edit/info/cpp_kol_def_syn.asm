macro wo txt,lf1,p1,p2,p3{
@@: db txt
rb @b+40-$
dd lf1
db p1
dw p2+0
db p3
}
count_colors_text dd (text-color_wnd_text)/4
count_key_words dd (f1-text)/48
color_cursor dd 0xffd000
color_wnd_capt dd 0xc0c0c0
color_wnd_work dd 0xffffff
color_wnd_bord dd 0x400080
color_select dd 0x000080
color_cur_text dd 0x800000
color_wnd_text:
	dd 0x808080
	dd 0x000000
	dd 0x00a000
	dd 0x0000ff
	dd 0x8000ff
	dd 0x0000ff
	dd 0xd000d0
	dd 0xff0000
text:
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'�'>,0,0,,7
wo<'!'>,f1.69-f1,0,,1
wo<'!='>,f1.70-f1,0,,1
wo<'"'>,f1.71-f1,4,(92 shl 8)+34,3
wo<'# define'>,0,7,13,2
wo<'# ifndef'>,0,7,13,2
wo<'#define'>,0,7,13,2
wo<'#else'>,0,3,,2
wo<'#endif'>,0,3,,2
wo<'#if'>,0,3,,2
wo<'#ifndef'>,0,7,13,2
wo<'#include'>,f1.79-f1,3,,2
wo<'#pragma'>,0,3,,2
wo<'%'>,0,0,,1
wo<'&'>,f1.82-f1,0,,1
wo<'&&'>,f1.83-f1,0,,1
wo<'&='>,0,0,,1
wo<39>,0,4,(92 shl 8)+39,3
wo<'('>,0,0,,1
wo<')'>,0,0,,1
wo<'*'>,0,0,,1
wo<'*='>,0,0,,1
wo<'+'>,0,0,,1
wo<'+='>,0,0,,1
wo<','>,0,0,,1
wo<'-'>,0,0,,1
wo<'-='>,0,0,,1
wo<'->'>,f1.95-f1,0,,1
wo<'.'>,0,0,,1
wo<'/'>,0,0,,1
wo<'/*'>,f1.98-f1,4,47,4
wo<'//'>,f1.99-f1,4,13,4
wo<'/='>,0,0,,1
wo<'0'>,0,24,,5
wo<'1'>,0,24,,5
wo<'2'>,0,24,,5
wo<'3'>,0,24,,5
wo<'4'>,0,24,,5
wo<'5'>,0,24,,5
wo<'6'>,0,24,,5
wo<'7'>,0,24,,5
wo<'8'>,0,24,,5
wo<'9'>,0,24,,5
wo<':'>,0,0,,1
wo<';'>,0,0,,1
wo<'<'>,f1.113-f1,0,,1
wo<'<='>,f1.114-f1,0,,1
wo<'='>,f1.115-f1,0,,1
wo<'=='>,f1.116-f1,0,,1
wo<'>'>,f1.117-f1,0,,1
wo<'>='>,f1.118-f1,0,,1
wo<'DECLARE_RESPONSE_TABLE'>,f1.119-f1,3,,2
wo<'DEFINE_RESPONSE_TABLE'>,f1.120-f1,21,40,2
wo<'END_RESPONSE_TABLE'>,f1.121-f1,3,,2
wo<'EV_CHILD_NOTIFY'>,0,3,,2
wo<'EV_CHILD_NOTIFY_ALL_CODES'>,0,3,,2
wo<'EV_CHILD_NOTIFY_AND_CODE'>,0,3,,2
wo<'EV_COMMAND'>,0,3,,2
wo<'EV_COMMAND_AND_ID'>,0,3,,2
wo<'EV_COMMAND_ENABLE'>,0,3,,2
wo<'EV_MESSAGE'>,0,3,,2
wo<'EV_NOTIFY_AT_CHILD'>,0,3,,2
wo<'EV_OWLDOCUMENT'>,0,3,,2
wo<'EV_OWLNOTIFY'>,0,3,,2
wo<'EV_OWLVIEW'>,0,3,,2
wo<'EV_REGISTERED'>,0,3,,2
wo<'EV_VIEWNOTIFY'>,0,3,,2
wo<'['>,0,0,,1
wo<']'>,0,0,,1
wo<'^'>,f1.137-f1,0,,1
wo<'asm'>,0,3,,1
wo<'bool'>,f1.139-f1,3,,1
wo<'break'>,f1.140-f1,3,,1
wo<'case'>,0,3,,1
wo<'catch'>,0,3,,1
wo<'char'>,f1.143-f1,3,,1
wo<'class'>,f1.144-f1,3,,1
wo<'const'>,f1.145-f1,3,,1
wo<'const_cast'>,0,3,,1
wo<'continue'>,f1.147-f1,3,,1
wo<'default'>,0,3,,1
wo<'delete'>,f1.149-f1,3,,1
wo<'do'>,f1.150-f1,3,,1
wo<'double'>,f1.151-f1,3,,1
wo<'else'>,0,3,,1
wo<'enum'>,0,3,,1
wo<'extern'>,0,3,,1
wo<'false'>,0,3,,1
wo<'far'>,0,3,,1
wo<'float'>,f1.157-f1,3,,1
wo<'for'>,f1.158-f1,3,,1
wo<'friend'>,0,3,,1
wo<'if'>,f1.160-f1,3,,1
wo<'inline'>,0,3,,1
wo<'int'>,f1.162-f1,3,,1
wo<'long'>,f1.163-f1,3,,1
wo<'new'>,f1.164-f1,3,,1
wo<'operator'>,0,3,,1
wo<'private'>,f1.166-f1,3,,1
wo<'protected'>,f1.167-f1,3,,1
wo<'public'>,f1.168-f1,3,,1
wo<'register'>,0,3,,1
wo<'return'>,f1.170-f1,3,,1
wo<'short'>,f1.171-f1,3,,1
wo<'signed'>,f1.172-f1,3,,1
wo<'sizeof'>,0,3,,1
wo<'static'>,0,3,,1
wo<'struct'>,f1.175-f1,3,,1
wo<'switch'>,0,3,,1
wo<'this'>,0,3,,1
wo<'throw'>,0,3,,1
wo<'true'>,0,3,,1
wo<'try'>,0,3,,1
wo<'typedef'>,f1.181-f1,3,,1
wo<'union'>,0,3,,1
wo<'unsigned'>,f1.183-f1,3,,1
wo<'virtual'>,f1.184-f1,3,,1
wo<'void'>,0,3,,1
wo<'wchar_t'>,0,3,,1
wo<'while'>,f1.187-f1,3,,1
wo<'{'>,0,0,,1
wo<'|'>,f1.189-f1,0,,1
wo<'|='>,0,0,,1
wo<'||'>,f1.191-f1,0,,1
wo<'}'>,0,0,,1
wo<'~'>,f1.193-f1,0,,1
f1: db 0
.69:db '�����᪮� ',39,'���栭��',39,'',0
.70:db '�� ࠢ��',0
.71:db '��ப���� ����⠭�',0
.79:db '��४⨢� ����祭�� 䠩���',0
.82:db '����⮢�� ',39,'�',39,'',0
.83:db '�����᪮� ',39,'�',39,'',0
.95:db '���室 �� 㪠��⥫�',0
.98:db '����� ����� ������਩',0
.99:db '���� ����� ������਩',0
.113:db '�����',0
.114:db '����� ��� ࠢ��',0
.115:db '��ᢠ������',0
.116:db 'ࠢ��',0
.117:db '�����',0
.118:db '����� ��� ࠢ��',0
.119:db '������� ⠡���� �⪫����',0
.120:db '��砫� ⠡���� �⪫����',0
.121:db '����� ⠡���� �⪫����',0
.137:db '����⮢�� ',39,'�᪫���饥 ���',39,'',0
.139:db '�����᪨� ⨯ ������',0
.140:db '��室 �� 横��',0
.143:db 'ᨬ����� ⨯ ������ 1 ����',0
.144:db '�����',0
.145:db '����⠭�',0
.147:db '�ய�� ⥫� 横�� � ���室 �� ��� ��砫�',0
.149:db '㤠���� ��ꥪ� �� �����',0
.150:db '横� � �᫮����, �믮������ ������ 1 ࠧ',0
.151:db '�᫮ � ������饩 ����⮩ ������� �筮�� 8 ����',0
.157:db '�᫮ � ������饩 ����⮩ 4 ����',0
.158:db '������ 横��',0
.160:db '�᫮��� ������',0
.162:db '楫� ⨯ ������ 2 ����',0
.163:db '������ ⨯ ������',0
.164:db 'ᮧ���� ��ꥪ� � �����',0
.166:db '����� �����. �������� ����㯭� ⮫쪮 ������ � ��� ��㦥�⢥��� ����ᠬ (�������� �१ friend)',0
.167:db '���饭��� ᥪ�� �����. �������� ����㯭� ������ � ��� �ந������ ����ᠬ.',0
.168:db '��饤���㯭�� ᥪ�� �����. �������� ����㯭� �����.',0
.170:db '��室 �� �㭪樨',0
.171:db '���⪨� ⨯ ������',0
.172:db '������� ⨯ ������',0
.175:db '�������',0
.181:db '��८�।������ ⨯�� ������',0
.183:db '���������� ⨯ ������',0
.184:db '�ᯮ������ ��� ᮧ����� ����㠫��� �㭪権',0
.187:db '横� � �᫮����',0
.189:db '����⮢�� ',39,'���',39,'',0
.191:db '�����᪮� ',39,'���',39,'',0
.193:db '����⮢�� ',39,'���栭��',39,'',0
