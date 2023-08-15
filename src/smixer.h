/**
 * SPDX-License-Identifier: 0BSD
 *
 * @file	smixer.h
 */
#ifndef SMIXER_H
#define SMIXER_H
//------------------------------------------------------------------------------
#include <stdint.h>


//------------------------------------------------------------------------------
struct s_mixer_args {
	int16_t *outbuf;
	int16_t *inbuf[4];
	int32_t buflength;
	int16_t volume[4];	//gain = volume / 255
};
typedef struct s_mixer_args mixer_args_t;

int smixer(mixer_args_t *args);
int smixer_neon(mixer_args_t *args);

//------------------------------------------------------------------------------
#endif //#ifndef SMIXER_H
