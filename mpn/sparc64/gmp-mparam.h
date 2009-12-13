/* Sparc64 gmp-mparam.h -- Compiler/machine parameter header file.

Copyright 1991, 1993, 1994, 1999, 2000, 2001, 2002, 2004, 2006, 2008, 2009
Free Software Foundation, Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or (at your
option) any later version.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the GNU MP Library.  If not, see http://www.gnu.org/licenses/.  */

#define GMP_LIMB_BITS 64
#define BYTES_PER_MP_LIMB 8

/* 500 MHz ultrasparc2 running GNU/Linux */

/* Generated by tuneup.c, 2009-11-29, gcc 4.1 */

#define MUL_TOOM22_THRESHOLD             30
#define MUL_TOOM33_THRESHOLD            171
#define MUL_TOOM44_THRESHOLD            256

#define SQR_BASECASE_THRESHOLD           10
#define SQR_TOOM2_THRESHOLD              71
#define SQR_TOOM3_THRESHOLD             116
#define SQR_TOOM4_THRESHOLD             336

#define MUL_FFT_TABLE  { 240, 608, 1600, 2816, 7168, 20480, 81920, 196608, 786432, 0 }
#define MUL_FFT_MODF_THRESHOLD          184
#define MUL_FFT_THRESHOLD              1664

#define SQR_FFT_TABLE  { 336, 672, 1600, 2816, 7168, 20480, 49152, 196608, 786432, 0 }
#define SQR_FFT_MODF_THRESHOLD          200
#define SQR_FFT_THRESHOLD              1536

#define MULLO_BASECASE_THRESHOLD         18
#define MULLO_DC_THRESHOLD               33
#define MULLO_MUL_N_THRESHOLD          3152

#define MULMOD_BNM1_THRESHOLD            16

#define DC_DIV_QR_THRESHOLD              26
#define DC_DIVAPPR_Q_THRESHOLD           77
#define DC_BDIV_QR_THRESHOLD             38
#define DC_BDIV_Q_THRESHOLD             120
#define BINV_NEWTON_THRESHOLD           390
#define REDC_1_TO_REDC_2_THRESHOLD       10
#define REDC_2_TO_REDC_N_THRESHOLD      117

#define MATRIX22_STRASSEN_THRESHOLD      12
#define HGCD_THRESHOLD                   58
#define GCD_DC_THRESHOLD                283
#define GCDEXT_DC_THRESHOLD             186
#define JACOBI_BASE_METHOD                3

#define DIVREM_1_NORM_THRESHOLD           3
#define DIVREM_1_UNNORM_THRESHOLD         3
#define MOD_1_NORM_THRESHOLD              3
#define MOD_1_UNNORM_THRESHOLD            3
#define MOD_1_1_THRESHOLD                 5
#define MOD_1_2_THRESHOLD             MP_SIZE_T_MAX  /* never */
#define MOD_1_4_THRESHOLD             MP_SIZE_T_MAX  /* never */
#define USE_PREINV_DIVREM_1               1
#define USE_PREINV_MOD_1                  1
#define DIVREM_2_THRESHOLD                7
#define DIVEXACT_1_THRESHOLD              0  /* always */
#define MODEXACT_1_ODD_THRESHOLD          0  /* always */

#define GET_STR_DC_THRESHOLD             12
#define GET_STR_PRECOMPUTE_THRESHOLD     17
#define SET_STR_DC_THRESHOLD            399
#define SET_STR_PRECOMPUTE_THRESHOLD   1659
