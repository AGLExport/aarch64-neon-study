/**
 * SPDX-License-Identifier: 0BSD
 *
 * @file	main.c
 */
#include <stdio.h>
#include "smixer.h"

#define PACKET_SAMPLES	(4096)

static int16_t outstream[PACKET_SAMPLES*2];

static int16_t ch0_stream[PACKET_SAMPLES];
static int16_t ch1_stream[PACKET_SAMPLES];
static int16_t ch2_stream[PACKET_SAMPLES];
static int16_t ch3_stream[PACKET_SAMPLES];

int test01_create(mixer_args_t *args);
int test01_validate(mixer_args_t *args);

int test02_create(mixer_args_t *args);
int test02_validate(mixer_args_t *args);

int test03_create(mixer_args_t *args);
int test03_validate(mixer_args_t *args);

int test04_create(mixer_args_t *args);
int test04_validate(mixer_args_t *args);

int test05_create(mixer_args_t *args);
int test05_validate(mixer_args_t *args);

int test06_create(mixer_args_t *args);
int test06_validate(mixer_args_t *args);

int test07_create(mixer_args_t *args);
int test07_validate(mixer_args_t *args);

int test08_create(mixer_args_t *args);
int test08_validate(mixer_args_t *args);

int test09_create(mixer_args_t *args);
int test09_validate(mixer_args_t *args);

int test0a_create(mixer_args_t *args);
int test0a_validate(mixer_args_t *args);

int test10_create(mixer_args_t *args);
int test10_validate(mixer_args_t *args);

int test11_create(mixer_args_t *args);
int test11_validate(mixer_args_t *args);

int test12_create(mixer_args_t *args);
int test12_validate(mixer_args_t *args);

int benchmark_nomal(mixer_args_t *args);
int benchmark_neon(mixer_args_t *args);

/**
 * The main function
 */
int main(int argc, char *argv[])
{
	mixer_args_t args;
	int ret = 0;

	args.outbuf = outstream;
	args.inbuf[0] = ch0_stream;
	args.inbuf[1] = ch1_stream;
	args.inbuf[2] = ch2_stream;
	args.inbuf[3] = ch3_stream;
	args.buflength = PACKET_SAMPLES;

	test01_create(&args);
	ret = smixer(&args);
	test01_validate(&args);

	test02_create(&args);
	ret = smixer(&args);
	test02_validate(&args);

	test03_create(&args);
	ret = smixer(&args);
	test03_validate(&args);

	test04_create(&args);
	ret = smixer(&args);
	test04_validate(&args);

	test05_create(&args);
	ret = smixer(&args);
	test05_validate(&args);

	test06_create(&args);
	ret = smixer(&args);
	test06_validate(&args);

	test07_create(&args);
	ret = smixer(&args);
	test07_validate(&args);

	test08_create(&args);
	ret = smixer(&args);
	test08_validate(&args);

	test09_create(&args);
	ret = smixer(&args);
	test09_validate(&args);

	test0a_create(&args);
	ret = smixer(&args);
	test0a_validate(&args);

	test10_create(&args);
	ret = smixer(&args);
	test10_validate(&args);

	test11_create(&args);
	ret = smixer(&args);
	test11_validate(&args);

	test12_create(&args);
	ret = smixer(&args);
	test12_validate(&args);

	test01_create(&args);
	ret = smixer_neon(&args);
	test01_validate(&args);

	test02_create(&args);
	ret = smixer_neon(&args);
	test02_validate(&args);

	test03_create(&args);
	ret = smixer_neon(&args);
	test03_validate(&args);

	test04_create(&args);
	ret = smixer_neon(&args);
	test04_validate(&args);

	test05_create(&args);
	ret = smixer_neon(&args);
	test05_validate(&args);

	test06_create(&args);
	ret = smixer_neon(&args);
	test06_validate(&args);

	test07_create(&args);
	ret = smixer_neon(&args);
	test07_validate(&args);

	test08_create(&args);
	ret = smixer_neon(&args);
	test08_validate(&args);

	test09_create(&args);
	ret = smixer_neon(&args);
	test09_validate(&args);

	test0a_create(&args);
	ret = smixer_neon(&args);
	test0a_validate(&args);

	test10_create(&args);
	ret = smixer_neon(&args);
	test10_validate(&args);

	test11_create(&args);
	ret = smixer_neon(&args);
	test11_validate(&args);

	test12_create(&args);
	ret = smixer_neon(&args);
	test12_validate(&args);

	ret = benchmark_nomal(&args);
	ret = benchmark_neon(&args);

	return 0;
}
//----------------------------------------------------------------------------------
int test01_create(mixer_args_t *args)
{
	fprintf(stderr, "test01: sum test {0,0,0,0} = 0\n");
	for (int i=0; i < PACKET_SAMPLES; i++) {
		args->inbuf[0][i] = 0;
		args->inbuf[1][i] = 0;
		args->inbuf[2][i] = 0;
		args->inbuf[3][i] = 0;
	}

	args->volume[0] = 256;
	args->volume[1] = 256;
	args->volume[2] = 256;
	args->volume[3] = 256;

	return 0;
}
int test01_validate(mixer_args_t *args)
{
	int errcount = 0;

	for (int i=0; i < PACKET_SAMPLES; i++) {
		if (args->outbuf[i*2] == 0 && args->outbuf[i*2] == args->outbuf[i*2+1]){
			// nop
		} else {
			fprintf(stderr,"invalid data outbuf[%d] =%d\n", i, args->outbuf[i*2]);
			errcount++;
		}
	}

	fprintf(stderr, "test01 error count = %d\n",errcount);

	return errcount;
}
//----------------------------------------------------------------------------------
int test02_create(mixer_args_t *args)
{
	fprintf(stderr, "test02: sum test {1,1,1,1} = 4\n");

	for (int i=0; i < PACKET_SAMPLES; i++) {
		args->inbuf[0][i] = 1;
		args->inbuf[1][i] = 1;
		args->inbuf[2][i] = 1;
		args->inbuf[3][i] = 1;
	}

	args->volume[0] = 256;
	args->volume[1] = 256;
	args->volume[2] = 256;
	args->volume[3] = 256;

	return 0;
}
int test02_validate(mixer_args_t *args)
{
	int errcount = 0;

	for (int i=0; i < PACKET_SAMPLES; i++) {
		if (args->outbuf[i*2] == 4 && args->outbuf[i*2] == args->outbuf[i*2+1]){
			// nop
		} else {
			fprintf(stderr,"invalid data outbuf[%d] =%d\n", i, args->outbuf[i*2]);
			errcount++;
		}
	}

	fprintf(stderr, "test02 error count = %d\n",errcount);

	return errcount;
}
//----------------------------------------------------------------------------------
int test03_create(mixer_args_t *args)
{
	fprintf(stderr, "test03: sum test {%d,%d,%d,%d} = %d\n",INT16_MAX,INT16_MAX,INT16_MAX,INT16_MAX,INT16_MAX);

	for (int i=0; i < PACKET_SAMPLES; i++) {
		args->inbuf[0][i] = INT16_MAX;
		args->inbuf[1][i] = INT16_MAX;
		args->inbuf[2][i] = INT16_MAX;
		args->inbuf[3][i] = INT16_MAX;
	}

	args->volume[0] = 256;
	args->volume[1] = 256;
	args->volume[2] = 256;
	args->volume[3] = 256;

	return 0;
}
int test03_validate(mixer_args_t *args)
{
	int errcount = 0;

	for (int i=0; i < PACKET_SAMPLES; i++) {
		if (args->outbuf[i*2] == INT16_MAX && args->outbuf[i*2] == args->outbuf[i*2+1]){
			// nop
		} else {
			fprintf(stderr,"invalid data outbuf[%d] =%d\n", i, args->outbuf[i*2]);
			errcount++;
		}
	}

	fprintf(stderr, "test03 error count = %d\n",errcount);

	return errcount;
}
//----------------------------------------------------------------------------------
int test04_create(mixer_args_t *args)
{
	fprintf(stderr, "test04: sum test {%d,%d,%d,%d} = %d\n", INT16_MIN,INT16_MIN,INT16_MIN,INT16_MIN,INT16_MIN);

	for (int i=0; i < PACKET_SAMPLES; i++) {
		args->inbuf[0][i] = INT16_MIN;
		args->inbuf[1][i] = INT16_MIN;
		args->inbuf[2][i] = INT16_MIN;
		args->inbuf[3][i] = INT16_MIN;
	}

	args->volume[0] = 256;
	args->volume[1] = 256;
	args->volume[2] = 256;
	args->volume[3] = 256;

	return 0;
}
int test04_validate(mixer_args_t *args)
{
	int errcount = 0;

	for (int i=0; i < PACKET_SAMPLES; i++) {
		if (args->outbuf[i*2] == INT16_MIN && args->outbuf[i*2] == args->outbuf[i*2+1]){
			// nop
		} else {
			fprintf(stderr,"invalid data outbuf[%d] =%d\n", i, args->outbuf[i*2]);
			errcount++;
		}
	}

	fprintf(stderr, "test04 error count = %d\n",errcount);

	return errcount;
}
//----------------------------------------------------------------------------------
int test05_create(mixer_args_t *args)
{
	fprintf(stderr, "test05: sum test {%d,%d,%d,%d} = %d\n",INT16_MAX,1,1,1,INT16_MAX);

	for (int i=0; i < PACKET_SAMPLES; i++) {
		args->inbuf[0][i] = INT16_MAX;
		args->inbuf[1][i] = 1;
		args->inbuf[2][i] = 1;
		args->inbuf[3][i] = 1;
	}

	args->volume[0] = 256;
	args->volume[1] = 256;
	args->volume[2] = 256;
	args->volume[3] = 256;

	return 0;
}
int test05_validate(mixer_args_t *args)
{
	int errcount = 0;

	for (int i=0; i < PACKET_SAMPLES; i++) {
		if (args->outbuf[i*2] == INT16_MAX && args->outbuf[i*2] == args->outbuf[i*2+1]){
			// nop
		} else {
			fprintf(stderr,"invalid data outbuf[%d] =%d\n", i, args->outbuf[i*2]);
			errcount++;
		}
	}

	fprintf(stderr, "test05 error count = %d\n",errcount);

	return errcount;
}
//----------------------------------------------------------------------------------
int test06_create(mixer_args_t *args)
{
	fprintf(stderr, "test06: sum test {%d,%d,%d,%d} = %d\n", INT16_MIN,-1,-1,-1,INT16_MIN);

	for (int i=0; i < PACKET_SAMPLES; i++) {
		args->inbuf[0][i] = INT16_MIN;
		args->inbuf[1][i] = -1;
		args->inbuf[2][i] = -1;
		args->inbuf[3][i] = -1;
	}

	args->volume[0] = 256;
	args->volume[1] = 256;
	args->volume[2] = 256;
	args->volume[3] = 256;

	return 0;
}
int test06_validate(mixer_args_t *args)
{
	int errcount = 0;

	for (int i=0; i < PACKET_SAMPLES; i++) {
		if (args->outbuf[i*2] == INT16_MIN && args->outbuf[i*2] == args->outbuf[i*2+1]){
			// nop
		} else {
			fprintf(stderr,"invalid data outbuf[%d] =%d\n", i, args->outbuf[i*2]);
			errcount++;
		}
	}

	fprintf(stderr, "test06 error count = %d\n",errcount);

	return errcount;
}
//----------------------------------------------------------------------------------
int test07_create(mixer_args_t *args)
{
	fprintf(stderr, "test07: sum test {%d,%d,%d,%d} = %d\n",INT16_MAX/2,INT16_MAX/2,INT16_MAX/2,INT16_MAX/2,INT16_MAX);

	for (int i=0; i < PACKET_SAMPLES; i++) {
		args->inbuf[0][i] = INT16_MAX/2;
		args->inbuf[1][i] = INT16_MAX/2;
		args->inbuf[2][i] = INT16_MAX/2;
		args->inbuf[3][i] = INT16_MAX/2;
	}

	args->volume[0] = 256;
	args->volume[1] = 256;
	args->volume[2] = 256;
	args->volume[3] = 256;

	return 0;
}
int test07_validate(mixer_args_t *args)
{
	int errcount = 0;

	for (int i=0; i < PACKET_SAMPLES; i++) {
		if (args->outbuf[i*2] == INT16_MAX && args->outbuf[i*2] == args->outbuf[i*2+1]){
			// nop
		} else {
			fprintf(stderr,"invalid data outbuf[%d] =%d\n", i, args->outbuf[i*2]);
			errcount++;
		}
	}

	fprintf(stderr, "test07 error count = %d\n",errcount);

	return errcount;
}
//----------------------------------------------------------------------------------
int test08_create(mixer_args_t *args)
{
	fprintf(stderr, "test08: sum test {%d,%d,%d,%d} = %d\n", INT16_MIN/2,INT16_MIN/2,INT16_MIN/2,INT16_MIN/2,INT16_MIN);

	for (int i=0; i < PACKET_SAMPLES; i++) {
		args->inbuf[0][i] = INT16_MIN/2;
		args->inbuf[1][i] = INT16_MIN/2;
		args->inbuf[2][i] = INT16_MIN/2;
		args->inbuf[3][i] = INT16_MIN/2;
	}

	args->volume[0] = 256;
	args->volume[1] = 256;
	args->volume[2] = 256;
	args->volume[3] = 256;

	return 0;
}
int test08_validate(mixer_args_t *args)
{
	int errcount = 0;

	for (int i=0; i < PACKET_SAMPLES; i++) {
		if (args->outbuf[i*2] == INT16_MIN && args->outbuf[i*2] == args->outbuf[i*2+1]){
			// nop
		} else {
			fprintf(stderr,"invalid data outbuf[%d] =%d\n", i, args->outbuf[i*2]);
			errcount++;
		}
	}

	fprintf(stderr, "test08 error count = %d\n",errcount);

	return errcount;
}
//----------------------------------------------------------------------------------
int test09_create(mixer_args_t *args)
{
	fprintf(stderr, "test09: sum test {%d,%d,%d,%d} = %d\n",INT16_MAX/2,1,1,1,INT16_MAX/2+1+1+1);

	for (int i=0; i < PACKET_SAMPLES; i++) {
		args->inbuf[0][i] = INT16_MAX/2;
		args->inbuf[1][i] = 1;
		args->inbuf[2][i] = 1;
		args->inbuf[3][i] = 1;
	}

	args->volume[0] = 256;
	args->volume[1] = 256;
	args->volume[2] = 256;
	args->volume[3] = 256;

	return 0;
}
int test09_validate(mixer_args_t *args)
{
	int errcount = 0;

	for (int i=0; i < PACKET_SAMPLES; i++) {
		if (args->outbuf[i*2] == (INT16_MAX/2+1+1+1) && args->outbuf[i*2] == args->outbuf[i*2+1]){
			// nop
		} else {
			fprintf(stderr,"invalid data outbuf[%d] =%d\n", i, args->outbuf[i*2]);
			errcount++;
		}
	}

	fprintf(stderr, "test09 error count = %d\n",errcount);

	return errcount;
}
//----------------------------------------------------------------------------------
int test0a_create(mixer_args_t *args)
{
	fprintf(stderr, "test0a: sum test {%d,%d,%d,%d} = %d\n", INT16_MIN/2,-1,-1,-1,INT16_MIN/2-1-1-1);

	for (int i=0; i < PACKET_SAMPLES; i++) {
		args->inbuf[0][i] = INT16_MIN/2;
		args->inbuf[1][i] = -1;
		args->inbuf[2][i] = -1;
		args->inbuf[3][i] = -1;
	}

	args->volume[0] = 256;
	args->volume[1] = 256;
	args->volume[2] = 256;
	args->volume[3] = 256;

	return 0;
}
int test0a_validate(mixer_args_t *args)
{
	int errcount = 0;

	for (int i=0; i < PACKET_SAMPLES; i++) {
		if (args->outbuf[i*2] == INT16_MIN/2-1-1-1 && args->outbuf[i*2] == args->outbuf[i*2+1]){
			// nop
		} else {
			fprintf(stderr,"invalid data outbuf[%d] =%d\n", i, args->outbuf[i*2]);
			errcount++;
		}
	}

	fprintf(stderr, "test0a error count = %d\n",errcount);

	return errcount;
}
