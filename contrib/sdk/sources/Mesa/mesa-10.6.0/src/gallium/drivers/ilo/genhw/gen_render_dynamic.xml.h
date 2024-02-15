#ifndef GEN_RENDER_DYNAMIC_XML
#define GEN_RENDER_DYNAMIC_XML

/* Autogenerated file, DO NOT EDIT manually!

This file was generated by the rules-ng-ng headergen tool in this git repository:
https://github.com/olvaffe/envytools/
git clone https://github.com/olvaffe/envytools.git

Copyright (C) 2014-2015 by the following authors:
- Chia-I Wu <olvaffe@gmail.com> (olv)

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice (including the
next paragraph) shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE COPYRIGHT OWNER(S) AND/OR ITS SUPPLIERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


enum gen_compare_function {
    GEN6_COMPAREFUNCTION_ALWAYS				      = 0x0,
    GEN6_COMPAREFUNCTION_NEVER				      = 0x1,
    GEN6_COMPAREFUNCTION_LESS				      = 0x2,
    GEN6_COMPAREFUNCTION_EQUAL				      = 0x3,
    GEN6_COMPAREFUNCTION_LEQUAL				      = 0x4,
    GEN6_COMPAREFUNCTION_GREATER			      = 0x5,
    GEN6_COMPAREFUNCTION_NOTEQUAL			      = 0x6,
    GEN6_COMPAREFUNCTION_GEQUAL				      = 0x7,
};

enum gen_stencil_op {
    GEN6_STENCILOP_KEEP					      = 0x0,
    GEN6_STENCILOP_ZERO					      = 0x1,
    GEN6_STENCILOP_REPLACE				      = 0x2,
    GEN6_STENCILOP_INCRSAT				      = 0x3,
    GEN6_STENCILOP_DECRSAT				      = 0x4,
    GEN6_STENCILOP_INCR					      = 0x5,
    GEN6_STENCILOP_DECR					      = 0x6,
    GEN6_STENCILOP_INVERT				      = 0x7,
};

enum gen_blend_factor {
    GEN6_BLENDFACTOR_ONE				      = 0x1,
    GEN6_BLENDFACTOR_SRC_COLOR				      = 0x2,
    GEN6_BLENDFACTOR_SRC_ALPHA				      = 0x3,
    GEN6_BLENDFACTOR_DST_ALPHA				      = 0x4,
    GEN6_BLENDFACTOR_DST_COLOR				      = 0x5,
    GEN6_BLENDFACTOR_SRC_ALPHA_SATURATE			      = 0x6,
    GEN6_BLENDFACTOR_CONST_COLOR			      = 0x7,
    GEN6_BLENDFACTOR_CONST_ALPHA			      = 0x8,
    GEN6_BLENDFACTOR_SRC1_COLOR				      = 0x9,
    GEN6_BLENDFACTOR_SRC1_ALPHA				      = 0xa,
    GEN6_BLENDFACTOR_ZERO				      = 0x11,
    GEN6_BLENDFACTOR_INV_SRC_COLOR			      = 0x12,
    GEN6_BLENDFACTOR_INV_SRC_ALPHA			      = 0x13,
    GEN6_BLENDFACTOR_INV_DST_ALPHA			      = 0x14,
    GEN6_BLENDFACTOR_INV_DST_COLOR			      = 0x15,
    GEN6_BLENDFACTOR_INV_CONST_COLOR			      = 0x17,
    GEN6_BLENDFACTOR_INV_CONST_ALPHA			      = 0x18,
    GEN6_BLENDFACTOR_INV_SRC1_COLOR			      = 0x19,
    GEN6_BLENDFACTOR_INV_SRC1_ALPHA			      = 0x1a,
};

enum gen_blend_function {
    GEN6_BLENDFUNCTION_ADD				      = 0x0,
    GEN6_BLENDFUNCTION_SUBTRACT				      = 0x1,
    GEN6_BLENDFUNCTION_REVERSE_SUBTRACT			      = 0x2,
    GEN6_BLENDFUNCTION_MIN				      = 0x3,
    GEN6_BLENDFUNCTION_MAX				      = 0x4,
};

enum gen_logicop_function {
    GEN6_LOGICOP_CLEAR					      = 0x0,
    GEN6_LOGICOP_NOR					      = 0x1,
    GEN6_LOGICOP_AND_INVERTED				      = 0x2,
    GEN6_LOGICOP_COPY_INVERTED				      = 0x3,
    GEN6_LOGICOP_AND_REVERSE				      = 0x4,
    GEN6_LOGICOP_INVERT					      = 0x5,
    GEN6_LOGICOP_XOR					      = 0x6,
    GEN6_LOGICOP_NAND					      = 0x7,
    GEN6_LOGICOP_AND					      = 0x8,
    GEN6_LOGICOP_EQUIV					      = 0x9,
    GEN6_LOGICOP_NOOP					      = 0xa,
    GEN6_LOGICOP_OR_INVERTED				      = 0xb,
    GEN6_LOGICOP_COPY					      = 0xc,
    GEN6_LOGICOP_OR_REVERSE				      = 0xd,
    GEN6_LOGICOP_OR					      = 0xe,
    GEN6_LOGICOP_SET					      = 0xf,
};

enum gen_sampler_mip_filter {
    GEN6_MIPFILTER_NONE					      = 0x0,
    GEN6_MIPFILTER_NEAREST				      = 0x1,
    GEN6_MIPFILTER_LINEAR				      = 0x3,
};

enum gen_sampler_map_filter {
    GEN6_MAPFILTER_NEAREST				      = 0x0,
    GEN6_MAPFILTER_LINEAR				      = 0x1,
    GEN6_MAPFILTER_ANISOTROPIC				      = 0x2,
    GEN6_MAPFILTER_MONO					      = 0x6,
};

enum gen_sampler_aniso_ratio {
    GEN6_ANISORATIO_2					      = 0x0,
    GEN6_ANISORATIO_4					      = 0x1,
    GEN6_ANISORATIO_6					      = 0x2,
    GEN6_ANISORATIO_8					      = 0x3,
    GEN6_ANISORATIO_10					      = 0x4,
    GEN6_ANISORATIO_12					      = 0x5,
    GEN6_ANISORATIO_14					      = 0x6,
    GEN6_ANISORATIO_16					      = 0x7,
};

enum gen_sampler_texcoord_mode {
    GEN6_TEXCOORDMODE_WRAP				      = 0x0,
    GEN6_TEXCOORDMODE_MIRROR				      = 0x1,
    GEN6_TEXCOORDMODE_CLAMP				      = 0x2,
    GEN6_TEXCOORDMODE_CUBE				      = 0x3,
    GEN6_TEXCOORDMODE_CLAMP_BORDER			      = 0x4,
    GEN6_TEXCOORDMODE_MIRROR_ONCE			      = 0x5,
    GEN8_TEXCOORDMODE_HALF_BORDER			      = 0x6,
};

enum gen_sampler_key_filter {
    GEN6_KEYFILTER_KILL_ON_ANY_MATCH			      = 0x0,
    GEN6_KEYFILTER_REPLACE_BLACK			      = 0x1,
};

#define GEN6_COLOR_CALC_STATE__SIZE				6

#define GEN6_CC_DW0_STENCIL0_REF__MASK				0xff000000
#define GEN6_CC_DW0_STENCIL0_REF__SHIFT				24
#define GEN6_CC_DW0_STENCIL1_REF__MASK				0x00ff0000
#define GEN6_CC_DW0_STENCIL1_REF__SHIFT				16
#define GEN6_CC_DW0_ROUND_DISABLE_DISABLE			(0x1 << 15)
#define GEN6_CC_DW0_ALPHATEST__MASK				0x00000001
#define GEN6_CC_DW0_ALPHATEST__SHIFT				0
#define GEN6_CC_DW0_ALPHATEST_UNORM8				0x0
#define GEN6_CC_DW0_ALPHATEST_FLOAT32				0x1






#define GEN6_DEPTH_STENCIL_STATE__SIZE				3

#define GEN6_ZS_DW0_STENCIL_TEST_ENABLE				(0x1 << 31)
#define GEN6_ZS_DW0_STENCIL0_FUNC__MASK				0x70000000
#define GEN6_ZS_DW0_STENCIL0_FUNC__SHIFT			28
#define GEN6_ZS_DW0_STENCIL0_FAIL_OP__MASK			0x0e000000
#define GEN6_ZS_DW0_STENCIL0_FAIL_OP__SHIFT			25
#define GEN6_ZS_DW0_STENCIL0_ZFAIL_OP__MASK			0x01c00000
#define GEN6_ZS_DW0_STENCIL0_ZFAIL_OP__SHIFT			22
#define GEN6_ZS_DW0_STENCIL0_ZPASS_OP__MASK			0x00380000
#define GEN6_ZS_DW0_STENCIL0_ZPASS_OP__SHIFT			19
#define GEN6_ZS_DW0_STENCIL_WRITE_ENABLE			(0x1 << 18)
#define GEN6_ZS_DW0_STENCIL1_ENABLE				(0x1 << 15)
#define GEN6_ZS_DW0_STENCIL1_FUNC__MASK				0x00007000
#define GEN6_ZS_DW0_STENCIL1_FUNC__SHIFT			12
#define GEN6_ZS_DW0_STENCIL1_FAIL_OP__MASK			0x00000e00
#define GEN6_ZS_DW0_STENCIL1_FAIL_OP__SHIFT			9
#define GEN6_ZS_DW0_STENCIL1_ZFAIL_OP__MASK			0x000001c0
#define GEN6_ZS_DW0_STENCIL1_ZFAIL_OP__SHIFT			6
#define GEN6_ZS_DW0_STENCIL1_ZPASS_OP__MASK			0x00000038
#define GEN6_ZS_DW0_STENCIL1_ZPASS_OP__SHIFT			3

#define GEN6_ZS_DW1_STENCIL0_VALUEMASK__MASK			0xff000000
#define GEN6_ZS_DW1_STENCIL0_VALUEMASK__SHIFT			24
#define GEN6_ZS_DW1_STENCIL0_WRITEMASK__MASK			0x00ff0000
#define GEN6_ZS_DW1_STENCIL0_WRITEMASK__SHIFT			16
#define GEN6_ZS_DW1_STENCIL1_VALUEMASK__MASK			0x0000ff00
#define GEN6_ZS_DW1_STENCIL1_VALUEMASK__SHIFT			8
#define GEN6_ZS_DW1_STENCIL1_WRITEMASK__MASK			0x000000ff
#define GEN6_ZS_DW1_STENCIL1_WRITEMASK__SHIFT			0

#define GEN6_ZS_DW2_DEPTH_TEST_ENABLE				(0x1 << 31)
#define GEN6_ZS_DW2_DEPTH_FUNC__MASK				0x38000000
#define GEN6_ZS_DW2_DEPTH_FUNC__SHIFT				27
#define GEN6_ZS_DW2_DEPTH_WRITE_ENABLE				(0x1 << 26)

#define GEN6_BLEND_STATE__SIZE					17


#define GEN6_RT_DW0_BLEND_ENABLE				(0x1 << 31)
#define GEN6_RT_DW0_INDEPENDENT_ALPHA_ENABLE			(0x1 << 30)
#define GEN6_RT_DW0_ALPHA_FUNC__MASK				0x1c000000
#define GEN6_RT_DW0_ALPHA_FUNC__SHIFT				26
#define GEN6_RT_DW0_SRC_ALPHA_FACTOR__MASK			0x01f00000
#define GEN6_RT_DW0_SRC_ALPHA_FACTOR__SHIFT			20
#define GEN6_RT_DW0_DST_ALPHA_FACTOR__MASK			0x000f8000
#define GEN6_RT_DW0_DST_ALPHA_FACTOR__SHIFT			15
#define GEN6_RT_DW0_COLOR_FUNC__MASK				0x00003800
#define GEN6_RT_DW0_COLOR_FUNC__SHIFT				11
#define GEN6_RT_DW0_SRC_COLOR_FACTOR__MASK			0x000003e0
#define GEN6_RT_DW0_SRC_COLOR_FACTOR__SHIFT			5
#define GEN6_RT_DW0_DST_COLOR_FACTOR__MASK			0x0000001f
#define GEN6_RT_DW0_DST_COLOR_FACTOR__SHIFT			0

#define GEN6_RT_DW1_ALPHA_TO_COVERAGE				(0x1 << 31)
#define GEN6_RT_DW1_ALPHA_TO_ONE				(0x1 << 30)
#define GEN6_RT_DW1_ALPHA_TO_COVERAGE_DITHER			(0x1 << 29)
#define GEN6_RT_DW1_WRITE_DISABLE_A				(0x1 << 27)
#define GEN6_RT_DW1_WRITE_DISABLE_R				(0x1 << 26)
#define GEN6_RT_DW1_WRITE_DISABLE_G				(0x1 << 25)
#define GEN6_RT_DW1_WRITE_DISABLE_B				(0x1 << 24)
#define GEN6_RT_DW1_LOGICOP_ENABLE				(0x1 << 22)
#define GEN6_RT_DW1_LOGICOP_FUNC__MASK				0x003c0000
#define GEN6_RT_DW1_LOGICOP_FUNC__SHIFT				18
#define GEN6_RT_DW1_ALPHA_TEST_ENABLE				(0x1 << 16)
#define GEN6_RT_DW1_ALPHA_TEST_FUNC__MASK			0x0000e000
#define GEN6_RT_DW1_ALPHA_TEST_FUNC__SHIFT			13
#define GEN6_RT_DW1_DITHER_ENABLE				(0x1 << 12)
#define GEN6_RT_DW1_X_DITHER_OFFSET__MASK			0x00000c00
#define GEN6_RT_DW1_X_DITHER_OFFSET__SHIFT			10
#define GEN6_RT_DW1_Y_DITHER_OFFSET__MASK			0x00000300
#define GEN6_RT_DW1_Y_DITHER_OFFSET__SHIFT			8
#define GEN6_RT_DW1_COLORCLAMP__MASK				0x0000000c
#define GEN6_RT_DW1_COLORCLAMP__SHIFT				2
#define GEN6_RT_DW1_COLORCLAMP_UNORM				(0x0 << 2)
#define GEN6_RT_DW1_COLORCLAMP_SNORM				(0x1 << 2)
#define GEN6_RT_DW1_COLORCLAMP_RTFORMAT				(0x2 << 2)
#define GEN6_RT_DW1_PRE_BLEND_CLAMP				(0x1 << 1)
#define GEN6_RT_DW1_POST_BLEND_CLAMP				(0x1 << 0)


#define GEN8_BLEND_DW0_ALPHA_TO_COVERAGE			(0x1 << 31)
#define GEN8_BLEND_DW0_INDEPENDENT_ALPHA_ENABLE			(0x1 << 30)
#define GEN8_BLEND_DW0_ALPHA_TO_ONE				(0x1 << 29)
#define GEN8_BLEND_DW0_ALPHA_TO_COVERAGE_DITHER			(0x1 << 28)
#define GEN8_BLEND_DW0_ALPHA_TEST_ENABLE			(0x1 << 27)
#define GEN8_BLEND_DW0_ALPHA_TEST_FUNC__MASK			0x07000000
#define GEN8_BLEND_DW0_ALPHA_TEST_FUNC__SHIFT			24
#define GEN8_BLEND_DW0_DITHER_ENABLE				(0x1 << 23)
#define GEN8_BLEND_DW0_X_DITHER_OFFSET__MASK			0x00600000
#define GEN8_BLEND_DW0_X_DITHER_OFFSET__SHIFT			21
#define GEN8_BLEND_DW0_Y_DITHER_OFFSET__MASK			0x00180000
#define GEN8_BLEND_DW0_Y_DITHER_OFFSET__SHIFT			19


#define GEN8_RT_DW0_BLEND_ENABLE				(0x1 << 31)
#define GEN8_RT_DW0_SRC_COLOR_FACTOR__MASK			0x7c000000
#define GEN8_RT_DW0_SRC_COLOR_FACTOR__SHIFT			26
#define GEN8_RT_DW0_DST_COLOR_FACTOR__MASK			0x03e00000
#define GEN8_RT_DW0_DST_COLOR_FACTOR__SHIFT			21
#define GEN8_RT_DW0_COLOR_FUNC__MASK				0x001c0000
#define GEN8_RT_DW0_COLOR_FUNC__SHIFT				18
#define GEN8_RT_DW0_SRC_ALPHA_FACTOR__MASK			0x0003e000
#define GEN8_RT_DW0_SRC_ALPHA_FACTOR__SHIFT			13
#define GEN8_RT_DW0_DST_ALPHA_FACTOR__MASK			0x00001f00
#define GEN8_RT_DW0_DST_ALPHA_FACTOR__SHIFT			8
#define GEN8_RT_DW0_ALPHA_FUNC__MASK				0x000000e0
#define GEN8_RT_DW0_ALPHA_FUNC__SHIFT				5
#define GEN8_RT_DW0_WRITE_DISABLE_A				(0x1 << 3)
#define GEN8_RT_DW0_WRITE_DISABLE_R				(0x1 << 2)
#define GEN8_RT_DW0_WRITE_DISABLE_G				(0x1 << 1)
#define GEN8_RT_DW0_WRITE_DISABLE_B				(0x1 << 0)

#define GEN8_RT_DW1_LOGICOP_ENABLE				(0x1 << 31)
#define GEN8_RT_DW1_LOGICOP_FUNC__MASK				0x78000000
#define GEN8_RT_DW1_LOGICOP_FUNC__SHIFT				27
#define GEN8_RT_DW1_PRE_BLEND_CLAMP_SRC_ONLY			(0x1 << 4)
#define GEN8_RT_DW1_COLORCLAMP__MASK				0x0000000c
#define GEN8_RT_DW1_COLORCLAMP__SHIFT				2
#define GEN8_RT_DW1_COLORCLAMP_UNORM				(0x0 << 2)
#define GEN8_RT_DW1_COLORCLAMP_SNORM				(0x1 << 2)
#define GEN8_RT_DW1_COLORCLAMP_RTFORMAT				(0x2 << 2)
#define GEN8_RT_DW1_PRE_BLEND_CLAMP				(0x1 << 1)
#define GEN8_RT_DW1_POST_BLEND_CLAMP				(0x1 << 0)

#define GEN6_CLIP_VIEWPORT__SIZE				64






#define GEN6_SF_VIEWPORT__SIZE					128










#define GEN7_SF_CLIP_VIEWPORT__SIZE				256
























#define GEN6_CC_VIEWPORT__SIZE					32




#define GEN6_SCISSOR_RECT__SIZE					32


#define GEN6_SCISSOR_DW0_MIN_Y__MASK				0xffff0000
#define GEN6_SCISSOR_DW0_MIN_Y__SHIFT				16
#define GEN6_SCISSOR_DW0_MIN_X__MASK				0x0000ffff
#define GEN6_SCISSOR_DW0_MIN_X__SHIFT				0

#define GEN6_SCISSOR_DW1_MAX_Y__MASK				0xffff0000
#define GEN6_SCISSOR_DW1_MAX_Y__SHIFT				16
#define GEN6_SCISSOR_DW1_MAX_X__MASK				0x0000ffff
#define GEN6_SCISSOR_DW1_MAX_X__SHIFT				0

#define GEN6_SAMPLER_BORDER_COLOR_STATE__SIZE			20

#define GEN6_BORDER_COLOR_DW0_A__MASK				0xff000000
#define GEN6_BORDER_COLOR_DW0_A__SHIFT				24
#define GEN6_BORDER_COLOR_DW0_B__MASK				0x00ff0000
#define GEN6_BORDER_COLOR_DW0_B__SHIFT				16
#define GEN6_BORDER_COLOR_DW0_G__MASK				0x0000ff00
#define GEN6_BORDER_COLOR_DW0_G__SHIFT				8
#define GEN6_BORDER_COLOR_DW0_R__MASK				0x000000ff
#define GEN6_BORDER_COLOR_DW0_R__SHIFT				0





#define GEN6_BORDER_COLOR_DW5_G__MASK				0xffff0000
#define GEN6_BORDER_COLOR_DW5_G__SHIFT				16
#define GEN6_BORDER_COLOR_DW5_R__MASK				0x0000ffff
#define GEN6_BORDER_COLOR_DW5_R__SHIFT				0

#define GEN6_BORDER_COLOR_DW6_A__MASK				0xffff0000
#define GEN6_BORDER_COLOR_DW6_A__SHIFT				16
#define GEN6_BORDER_COLOR_DW6_B__MASK				0x0000ffff
#define GEN6_BORDER_COLOR_DW6_B__SHIFT				0

#define GEN6_BORDER_COLOR_DW7_G__MASK				0xffff0000
#define GEN6_BORDER_COLOR_DW7_G__SHIFT				16
#define GEN6_BORDER_COLOR_DW7_R__MASK				0x0000ffff
#define GEN6_BORDER_COLOR_DW7_R__SHIFT				0

#define GEN6_BORDER_COLOR_DW8_A__MASK				0xffff0000
#define GEN6_BORDER_COLOR_DW8_A__SHIFT				16
#define GEN6_BORDER_COLOR_DW8_B__MASK				0x0000ffff
#define GEN6_BORDER_COLOR_DW8_B__SHIFT				0

#define GEN6_BORDER_COLOR_DW9_G__MASK				0xffff0000
#define GEN6_BORDER_COLOR_DW9_G__SHIFT				16
#define GEN6_BORDER_COLOR_DW9_R__MASK				0x0000ffff
#define GEN6_BORDER_COLOR_DW9_R__SHIFT				0

#define GEN6_BORDER_COLOR_DW10_A__MASK				0xffff0000
#define GEN6_BORDER_COLOR_DW10_A__SHIFT				16
#define GEN6_BORDER_COLOR_DW10_B__MASK				0x0000ffff
#define GEN6_BORDER_COLOR_DW10_B__SHIFT				0

#define GEN6_BORDER_COLOR_DW11_A__MASK				0xff000000
#define GEN6_BORDER_COLOR_DW11_A__SHIFT				24
#define GEN6_BORDER_COLOR_DW11_B__MASK				0x00ff0000
#define GEN6_BORDER_COLOR_DW11_B__SHIFT				16
#define GEN6_BORDER_COLOR_DW11_G__MASK				0x0000ff00
#define GEN6_BORDER_COLOR_DW11_G__SHIFT				8
#define GEN6_BORDER_COLOR_DW11_R__MASK				0x000000ff
#define GEN6_BORDER_COLOR_DW11_R__SHIFT				0








#define GEN6_SAMPLER_STATE__SIZE				4

#define GEN6_SAMPLER_DW0_DISABLE				(0x1 << 31)
#define GEN7_SAMPLER_DW0_BORDER_COLOR_MODE__MASK		0x20000000
#define GEN7_SAMPLER_DW0_BORDER_COLOR_MODE__SHIFT		29
#define GEN7_SAMPLER_DW0_BORDER_COLOR_MODE_DX10_OGL		(0x0 << 29)
#define GEN7_SAMPLER_DW0_BORDER_COLOR_MODE_DX9			(0x1 << 29)
#define GEN6_SAMPLER_DW0_LOD_PRECLAMP_ENABLE			(0x1 << 28)
#define GEN6_SAMPLER_DW0_MIN_MAG_NOT_EQUAL			(0x1 << 27)
#define GEN8_SAMPLER_DW0_LOD_PRECLAMP_ENABLE__MASK		0x18000000
#define GEN8_SAMPLER_DW0_LOD_PRECLAMP_ENABLE__SHIFT		27
#define GEN6_SAMPLER_DW0_BASE_LOD__MASK				0x07c00000
#define GEN6_SAMPLER_DW0_BASE_LOD__SHIFT			22
#define GEN6_SAMPLER_DW0_MIP_FILTER__MASK			0x00300000
#define GEN6_SAMPLER_DW0_MIP_FILTER__SHIFT			20
#define GEN6_SAMPLER_DW0_MAG_FILTER__MASK			0x000e0000
#define GEN6_SAMPLER_DW0_MAG_FILTER__SHIFT			17
#define GEN6_SAMPLER_DW0_MIN_FILTER__MASK			0x0001c000
#define GEN6_SAMPLER_DW0_MIN_FILTER__SHIFT			14
#define GEN6_SAMPLER_DW0_LOD_BIAS__MASK				0x00003ff8
#define GEN6_SAMPLER_DW0_LOD_BIAS__SHIFT			3
#define GEN6_SAMPLER_DW0_LOD_BIAS__RADIX			6
#define GEN6_SAMPLER_DW0_SHADOW_FUNC__MASK			0x00000007
#define GEN6_SAMPLER_DW0_SHADOW_FUNC__SHIFT			0
#define GEN7_SAMPLER_DW0_LOD_BIAS__MASK				0x00003ffe
#define GEN7_SAMPLER_DW0_LOD_BIAS__SHIFT			1
#define GEN7_SAMPLER_DW0_LOD_BIAS__RADIX			8
#define GEN7_SAMPLER_DW0_ANISO_ALGO__MASK			0x00000001
#define GEN7_SAMPLER_DW0_ANISO_ALGO__SHIFT			0
#define GEN7_SAMPLER_DW0_ANISO_ALGO_LEGACY			0x0
#define GEN7_SAMPLER_DW0_ANISO_ALGO_EWA				0x1

#define GEN6_SAMPLER_DW1_MIN_LOD__MASK				0xffc00000
#define GEN6_SAMPLER_DW1_MIN_LOD__SHIFT				22
#define GEN6_SAMPLER_DW1_MIN_LOD__RADIX				6
#define GEN6_SAMPLER_DW1_MAX_LOD__MASK				0x003ff000
#define GEN6_SAMPLER_DW1_MAX_LOD__SHIFT				12
#define GEN6_SAMPLER_DW1_MAX_LOD__RADIX				6
#define GEN6_SAMPLER_DW1_CUBECTRLMODE__MASK			0x00000200
#define GEN6_SAMPLER_DW1_CUBECTRLMODE__SHIFT			9
#define GEN6_SAMPLER_DW1_CUBECTRLMODE_PROGRAMMED		(0x0 << 9)
#define GEN6_SAMPLER_DW1_CUBECTRLMODE_OVERRIDE			(0x1 << 9)
#define GEN6_SAMPLER_DW1_U_WRAP__MASK				0x000001c0
#define GEN6_SAMPLER_DW1_U_WRAP__SHIFT				6
#define GEN6_SAMPLER_DW1_V_WRAP__MASK				0x00000038
#define GEN6_SAMPLER_DW1_V_WRAP__SHIFT				3
#define GEN6_SAMPLER_DW1_R_WRAP__MASK				0x00000007
#define GEN6_SAMPLER_DW1_R_WRAP__SHIFT				0

#define GEN7_SAMPLER_DW1_MIN_LOD__MASK				0xfff00000
#define GEN7_SAMPLER_DW1_MIN_LOD__SHIFT				20
#define GEN7_SAMPLER_DW1_MIN_LOD__RADIX				8
#define GEN7_SAMPLER_DW1_MAX_LOD__MASK				0x000fff00
#define GEN7_SAMPLER_DW1_MAX_LOD__SHIFT				8
#define GEN7_SAMPLER_DW1_MAX_LOD__RADIX				8
#define GEN8_SAMPLER_DW1_CHROMAKEY_ENABLE			(0x1 << 7)
#define GEN8_SAMPLER_DW1_CHROMAKEY_INDEX__MASK			0x00000060
#define GEN8_SAMPLER_DW1_CHROMAKEY_INDEX__SHIFT			5
#define GEN8_SAMPLER_DW1_CHROMAKEY_MODE__MASK			0x00000010
#define GEN8_SAMPLER_DW1_CHROMAKEY_MODE__SHIFT			4
#define GEN7_SAMPLER_DW1_SHADOW_FUNC__MASK			0x0000000e
#define GEN7_SAMPLER_DW1_SHADOW_FUNC__SHIFT			1
#define GEN7_SAMPLER_DW1_CUBECTRLMODE__MASK			0x00000001
#define GEN7_SAMPLER_DW1_CUBECTRLMODE__SHIFT			0
#define GEN7_SAMPLER_DW1_CUBECTRLMODE_PROGRAMMED		0x0
#define GEN7_SAMPLER_DW1_CUBECTRLMODE_OVERRIDE			0x1

#define GEN6_SAMPLER_DW2_BORDER_COLOR_ADDR__MASK		0xffffffe0
#define GEN6_SAMPLER_DW2_BORDER_COLOR_ADDR__SHIFT		5
#define GEN6_SAMPLER_DW2_BORDER_COLOR_ADDR__SHR			5

#define GEN8_SAMPLER_DW2_SEP_FILTER_COEFF_TABLE_SIZE__MASK	0xc0000000
#define GEN8_SAMPLER_DW2_SEP_FILTER_COEFF_TABLE_SIZE__SHIFT	30
#define GEN8_SAMPLER_DW2_SEP_FILTER_WIDTH__MASK			0x30000000
#define GEN8_SAMPLER_DW2_SEP_FILTER_WIDTH__SHIFT		28
#define GEN8_SAMPLER_DW2_SEP_FILTER_HEIGHT__MASK		0x0c000000
#define GEN8_SAMPLER_DW2_SEP_FILTER_HEIGHT__SHIFT		26
#define GEN8_SAMPLER_DW2_INDIRECT_STATE_ADDR__MASK		0x00ffffc0
#define GEN8_SAMPLER_DW2_INDIRECT_STATE_ADDR__SHIFT		6
#define GEN8_SAMPLER_DW2_INDIRECT_STATE_ADDR__SHR		6
#define GEN8_SAMPLER_DW2_FLEXIBLE_FILTER_MODE			(0x1 << 4)
#define GEN8_SAMPLER_DW2_FLEXIBLE_FILTER_COEFF_SIZE		(0x1 << 3)
#define GEN8_SAMPLER_DW2_FLEXIBLE_FILTER_HALIGN			(0x1 << 2)
#define GEN8_SAMPLER_DW2_FLEXIBLE_FILTER_VALIGN			(0x1 << 1)
#define GEN8_SAMPLER_DW2_LOD_CLAMP_MAG_MODE			(0x1 << 0)

#define GEN8_SAMPLER_DW3_NON_SEP_FILTER_FOOTPRINT_MASK__MASK	0xff000000
#define GEN8_SAMPLER_DW3_NON_SEP_FILTER_FOOTPRINT_MASK__SHIFT	24
#define GEN6_SAMPLER_DW3_CHROMAKEY_ENABLE			(0x1 << 25)
#define GEN6_SAMPLER_DW3_CHROMAKEY_INDEX__MASK			0x01800000
#define GEN6_SAMPLER_DW3_CHROMAKEY_INDEX__SHIFT			23
#define GEN6_SAMPLER_DW3_CHROMAKEY_MODE__MASK			0x00400000
#define GEN6_SAMPLER_DW3_CHROMAKEY_MODE__SHIFT			22
#define GEN6_SAMPLER_DW3_MAX_ANISO__MASK			0x00380000
#define GEN6_SAMPLER_DW3_MAX_ANISO__SHIFT			19
#define GEN6_SAMPLER_DW3_U_MAG_ROUND				(0x1 << 18)
#define GEN6_SAMPLER_DW3_U_MIN_ROUND				(0x1 << 17)
#define GEN6_SAMPLER_DW3_V_MAG_ROUND				(0x1 << 16)
#define GEN6_SAMPLER_DW3_V_MIN_ROUND				(0x1 << 15)
#define GEN6_SAMPLER_DW3_R_MAG_ROUND				(0x1 << 14)
#define GEN6_SAMPLER_DW3_R_MIN_ROUND				(0x1 << 13)
#define GEN7_SAMPLER_DW3_TRIQUAL__MASK				0x00001800
#define GEN7_SAMPLER_DW3_TRIQUAL__SHIFT				11
#define GEN7_SAMPLER_DW3_TRIQUAL_FULL				(0x0 << 11)
#define GEN75_SAMPLER_DW3_TRIQUAL_HIGH				(0x1 << 11)
#define GEN7_SAMPLER_DW3_TRIQUAL_MED				(0x2 << 11)
#define GEN7_SAMPLER_DW3_TRIQUAL_LOW				(0x3 << 11)
#define GEN7_SAMPLER_DW3_NON_NORMALIZED_COORD			(0x1 << 10)
#define GEN7_SAMPLER_DW3_U_WRAP__MASK				0x000001c0
#define GEN7_SAMPLER_DW3_U_WRAP__SHIFT				6
#define GEN7_SAMPLER_DW3_V_WRAP__MASK				0x00000038
#define GEN7_SAMPLER_DW3_V_WRAP__SHIFT				3
#define GEN7_SAMPLER_DW3_R_WRAP__MASK				0x00000007
#define GEN7_SAMPLER_DW3_R_WRAP__SHIFT				0
#define GEN6_SAMPLER_DW3_NON_NORMALIZED_COORD			(0x1 << 0)


#endif /* GEN_RENDER_DYNAMIC_XML */
