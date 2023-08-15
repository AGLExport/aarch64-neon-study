/**
 * SPDX-License-Identifier: 0BSD
 *
 * @file	smixer.c
 */
#include "smixer.h"
#include <string.h>

int smixer(mixer_args_t *args)
{
	int length = args->buflength;
	int16_t *indata[4];

	indata[0] = args->inbuf[0];
	indata[1] = args->inbuf[1];
	indata[2] = args->inbuf[2];
	indata[3] = args->inbuf[3];


	for(int j=0;j < length;j++) {
		int32_t macval = 0;

		for(int i=0;i < 4;i++) {
			int32_t val = (int32_t)(*(indata[i]));
			val = (val * (int32_t)args->volume[i]);
			macval += val;
			indata[i]++;
		}
		macval = macval / 256;

		macval = ((macval > INT16_MAX) ? INT16_MAX : ((macval < INT16_MIN) ? INT16_MIN : macval));

		args->outbuf[j*2] = (int16_t)macval;
		args->outbuf[j*2+1] = (int16_t)macval;
	}

	return 0;
}
