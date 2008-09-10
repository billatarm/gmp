/* gmp-mparam.h -- Compiler/machine parameter header file.

Copyright 1991, 1993, 1994, 1999, 2000, 2001, 2002, 2004, 2005 Free Software
Foundation, Inc.

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

#define BITS_PER_MP_LIMB 64
#define BYTES_PER_MP_LIMB 8

/* 1000 MHz 21164B */

/* Generated by tuneup.c, 2005-11-10, gcc 3.3 */

#define MUL_KARATSUBA_THRESHOLD          34
#define MUL_TOOM3_THRESHOLD             105

#define SQR_BASECASE_THRESHOLD            5
#define SQR_KARATSUBA_THRESHOLD          64
#define SQR_TOOM3_THRESHOLD             119

#define MULLOW_BASECASE_THRESHOLD         0  /* always */
#define MULLOW_DC_THRESHOLD              96
#define MULLOW_MUL_N_THRESHOLD          626

#define DIV_SB_PREINV_THRESHOLD           0  /* preinv always */
#define DIV_DC_THRESHOLD                116
#define POWM_THRESHOLD                  212

#define HGCD_THRESHOLD                  407
#define GCD_ACCEL_THRESHOLD               3
#define GCD_SCHOENHAGE_THRESHOLD        867
#define GCDEXT_SCHOENHAGE_THRESHOLD     867
#define JACOBI_BASE_METHOD                1

#define DIVREM_1_NORM_THRESHOLD           0  /* preinv always */
#define DIVREM_1_UNNORM_THRESHOLD         0  /* always */
#define MOD_1_NORM_THRESHOLD              0  /* always */
#define MOD_1_UNNORM_THRESHOLD            0  /* always */
#define USE_PREINV_DIVREM_1               1  /* preinv always */
#define USE_PREINV_MOD_1                  1  /* preinv always */
#define DIVREM_2_THRESHOLD                0  /* preinv always */
#define DIVEXACT_1_THRESHOLD              0  /* always */
#define MODEXACT_1_ODD_THRESHOLD          0  /* always */

#define GET_STR_DC_THRESHOLD             20
#define GET_STR_PRECOMPUTE_THRESHOLD     25
#define SET_STR_THRESHOLD             29473

#define MUL_FFT_TABLE  { 528, 1184, 2624, 5376, 13312, 36864, 81920, 327680, 0 }
#define MUL_FFT_MODF_THRESHOLD          544
#define MUL_FFT_THRESHOLD              3456

#define SQR_FFT_TABLE  { 592, 1312, 2624, 5888, 13312, 28672, 81920, 327680, 786432, 0 }
#define SQR_FFT_MODF_THRESHOLD          552
#define SQR_FFT_THRESHOLD              3968
