/* gmp-mparam.h -- Compiler/machine parameter header file.

Copyright (C) 1991, 1993, 1994, 2000 Free Software Foundation, Inc.

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
#define BITS_PER_LONGINT 64
#define BITS_PER_INT 32
#define BITS_PER_SHORTINT 16
#define BITS_PER_CHAR 8

/* Generated by tuneup.c, 2000-08-02. */

#ifndef KARATSUBA_MUL_THRESHOLD
#define KARATSUBA_MUL_THRESHOLD     47
#endif
#ifndef TOOM3_MUL_THRESHOLD
#define TOOM3_MUL_THRESHOLD         70
#endif

#ifndef KARATSUBA_SQR_THRESHOLD
#define KARATSUBA_SQR_THRESHOLD     94
#endif
#ifndef TOOM3_SQR_THRESHOLD
#define TOOM3_SQR_THRESHOLD        101
#endif

#ifndef BZ_THRESHOLD
#define BZ_THRESHOLD                33
#endif

#ifndef FIB_THRESHOLD
#define FIB_THRESHOLD               70
#endif

#ifndef POWM_THRESHOLD
#define POWM_THRESHOLD             256
#endif

#ifndef GCD_ACCEL_THRESHOLD
#define GCD_ACCEL_THRESHOLD         46
#endif
#ifndef GCDEXT_THRESHOLD
#define GCDEXT_THRESHOLD            33
#endif

#ifndef FFT_MUL_TABLE
#define FFT_MUL_TABLE  { 720, 1760, 4032, 7936, 17408, 45056, 0 }
#endif
#ifndef FFT_MODF_MUL_THRESHOLD
#define FFT_MODF_MUL_THRESHOLD    1008
#endif
#ifndef FFT_MUL_THRESHOLD
#define FFT_MUL_THRESHOLD        10752
#endif

#ifndef FFT_SQR_TABLE
#define FFT_SQR_TABLE  { 752, 1632, 3904, 7936, 19456, 53248, 0 }
#endif
#ifndef FFT_MODF_SQR_THRESHOLD
#define FFT_MODF_SQR_THRESHOLD     976
#endif
#ifndef FFT_SQR_THRESHOLD
#define FFT_SQR_THRESHOLD         8320
#endif
