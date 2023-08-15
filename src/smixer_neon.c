/**
 * SPDX-License-Identifier: 0BSD
 *
 * @file	smixer_neon.c
 */
#include "smixer.h"
#include <stddef.h>

#include <arm_neon.h>

int smixer_neon(mixer_args_t *args)
{
	int length = args->buflength / 4;
	int16_t *indata[4];
	int32x4_t volume[4];
	int32x4_t bitmasku,bitmaskl;


	indata[0] = args->inbuf[0];	//ch0 buffer
	indata[1] = args->inbuf[1];	//ch1 buffer
	indata[2] = args->inbuf[2];	//ch2 buffer
	indata[3] = args->inbuf[3];	//ch3 buffer

	volume[0] = vmovq_n_s32(args->volume[0]);	// ch0 volume
	volume[1] = vmovq_n_s32(args->volume[1]);	// ch1 volume
	volume[2] = vmovq_n_s32(args->volume[2]);	// ch2 volume
	volume[3] = vmovq_n_s32(args->volume[3]);	// ch3 volume

	bitmasku = vmovq_n_s32(0xffff0000);	// upper side bit mask
	bitmaskl = vmovq_n_s32(0x0000ffff);	// lower side bit mask

	for(int j=0;j < length;j++) {
		int32x4_t macval = vmovq_n_s32(0);	// zero clear

		for(int i=0;i < 4;i++) {
			int16x4_t src16x4 = vld1_s16(indata[i]);	// load 4 samples into register.
			indata[i] += 4;
			int32x4_t src32x4 = vmovl_s16(src16x4);	//convert from 16bitx4 signed to 32bitx4 signed

			macval = vmlaq_s32(macval, src32x4, volume[i]);	// macval[4] = samples[4] * volume
		}

		int32x4_t macvalu = vqshlq_n_s32(macval,8);	// Signed saturating left 8 bit shift : saturating(macval *256)
		uint32x4_t macvall = vshrq_n_u32((uint32x4_t)macvalu,16);	//macval / 256 / 256 by 16bit right sift

		macvalu = vandq_s32(macvalu,bitmasku);
		macval = vorrq_s32(macvalu,(int32x4_t)macvall);

		vst1q_s16(&(args->outbuf[j*8]), (int16x8_t)macval);
	}

	return 0;
}
