;SKIN (.SKN) - COMPILE WITH FASM

include 'skin.inc'

SKIN_PARAMS \
  height          = bmp_base.height,\     ; skin height
  margins         = [5:1:37:1],\          ; margins [left:top:right:bottom]
  colors active   = [binner=0x000000:\    ; border inner color
                     bouter=0x000000:\    ; border outer color
                     bframe=0x2d2d2d],\   ; border frame color
  colors inactive = [binner=0x000000:\    ; border inner color
                     bouter=0x000000:\    ; border outer color
                     bframe=0x2d2d2d],\   ; border frame color
  dtp             = 'default.dtp'          ; dtp colors

SKIN_BUTTONS \
  close    = [-16:5][10:10],\             ; buttons coordinates
  minimize = [-33:5][10:10]               ; [left:top][width:height]

SKIN_BITMAPS \
  left active   = bmp_left,\              ; skin bitmaps pointers
  left inactive = bmp_left1,\
  oper active   = bmp_oper,\
  oper inactive = bmp_oper1,\
  base active   = bmp_base,\
  base inactive = bmp_base1

BITMAP bmp_left ,'left.bmp'               ; skin bitmaps
BITMAP bmp_oper ,'oper.bmp'
BITMAP bmp_base ,'base.bmp'
BITMAP bmp_left1,'left_1.bmp'
BITMAP bmp_oper1,'oper_1.bmp'
BITMAP bmp_base1,'base_1.bmp'
