/* Cray T90 CFP gmp-mparam.h -- Compiler/machine parameter header file.

Copyright 1991, 1993, 1994, 1996, 2000, 2001, 2002 Free Software Foundation,
Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or (at your
option) any later version.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the GNU MP Library; see the file COPYING.LIB.  If not, write to
the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
MA 02111-1307, USA. */

#define BITS_PER_MP_LIMB 64
#define BYTES_PER_MP_LIMB 8

#if 0
#define UMUL_TIME	 519
#define UDIV_TIME	2360
#endif

/* T90 Unicos 10.0.X in CFP mode */

/* Generated by tuneup.c, 2001-11-28, system compiler */

#define MUL_KARATSUBA_THRESHOLD       71
#define MUL_TOOM3_THRESHOLD          131

#define SQR_BASECASE_THRESHOLD         0
#define SQR_KARATSUBA_THRESHOLD      199
#define SQR_TOOM3_THRESHOLD          363

#define DIV_SB_PREINV_THRESHOLD            0  /* (preinv always) */
#define DIV_DC_THRESHOLD                 577
#define POWM_THRESHOLD               601

#define GCD_ACCEL_THRESHOLD            3
#define GCDEXT_THRESHOLD              25

#define DIVREM_1_NORM_THRESHOLD        0  /* (preinv always) */
#define DIVREM_1_UNNORM_THRESHOLD      0
#define MOD_1_NORM_THRESHOLD           0
#define MOD_1_UNNORM_THRESHOLD         0
#define USE_PREINV_MOD_1               1  /* (preinv always) */
#define DIVREM_2_THRESHOLD             0  /* (preinv always) */
#define DIVEXACT_1_THRESHOLD           0
#define MODEXACT_1_ODD_THRESHOLD       0

#define MUL_FFT_TABLE  { 368, 736, 1472, 2816, 7168, 12288, 49152, 0 }
#define MUL_FFT_MODF_THRESHOLD       184
#define MUL_FFT_THRESHOLD            864

#define SQR_FFT_TABLE  { 1008, 2080, 4544, 8960, 19456, 45056, 0 }
#define SQR_FFT_MODF_THRESHOLD       600
#define SQR_FFT_THRESHOLD           2976
