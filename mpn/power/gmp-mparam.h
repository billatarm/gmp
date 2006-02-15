/* POWER gmp-mparam.h -- Compiler/machine parameter header file.

Copyright 2002, 2003, 2004 Free Software Foundation, Inc.

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
the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
MA 02110-1301, USA. */

/* Generated by tuneup.c, 2003-02-10, gcc 3.2, POWER2 66.7MHz */

#define MUL_KARATSUBA_THRESHOLD          12
#define MUL_TOOM3_THRESHOLD              75

#define SQR_BASECASE_THRESHOLD            7
#define SQR_KARATSUBA_THRESHOLD          28
#define SQR_TOOM3_THRESHOLD              86

#define DIV_SB_PREINV_THRESHOLD       MP_SIZE_T_MAX  /* never */
#define DIV_DC_THRESHOLD                 36
#define POWM_THRESHOLD                   69

#define HGCD_SCHOENHAGE_THRESHOLD        97
#define GCD_ACCEL_THRESHOLD               3
#define GCD_SCHOENHAGE_THRESHOLD        590
#define GCDEXT_THRESHOLD                 41
#define JACOBI_BASE_METHOD                2

#define DIVREM_1_NORM_THRESHOLD          12
#define DIVREM_1_UNNORM_THRESHOLD     MP_SIZE_T_MAX  /* never */
#define MOD_1_NORM_THRESHOLD             10
#define MOD_1_UNNORM_THRESHOLD        MP_SIZE_T_MAX  /* never */
#define USE_PREINV_DIVREM_1               0
#define USE_PREINV_MOD_1                  1
#define DIVREM_2_THRESHOLD               11
#define DIVEXACT_1_THRESHOLD              0  /* always */
#define MODEXACT_1_ODD_THRESHOLD          0  /* always */

#define GET_STR_DC_THRESHOLD             10
#define GET_STR_PRECOMPUTE_THRESHOLD     20
#define SET_STR_THRESHOLD              2899

#define MUL_FFT_TABLE  { 336, 800, 1408, 3584, 10240, 24576, 0 }
#define MUL_FFT_MODF_THRESHOLD          296
#define MUL_FFT_THRESHOLD              2304

#define SQR_FFT_TABLE  { 336, 800, 1408, 3584, 10240, 24576, 0 }
#define SQR_FFT_MODF_THRESHOLD          296
#define SQR_FFT_THRESHOLD              2304
