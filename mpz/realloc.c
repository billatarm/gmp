/* _mpz_realloc -- make the mpz_t have NEW_ALLOC digits allocated.

Copyright 1991, 1993, 1994, 1995, 2000, 2001 Free Software Foundation, Inc.

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

#include "gmp.h"
#include "gmp-impl.h"

void *
_mpz_realloc (mpz_ptr m, mp_size_t new_alloc)
{
  mp_ptr mp;

  /* Never allocate zero space. */
  new_alloc = MAX (new_alloc, 1);

  mp = (mp_ptr) (*__gmp_reallocate_func) (PTR(m),
					  ALLOC(m) * BYTES_PER_MP_LIMB,
					  new_alloc * BYTES_PER_MP_LIMB);
  PTR(m) = mp;
  ALLOC(m) = new_alloc;

  /* Don't create an invalid number; if the current value doesn't fit after
     reallocation, clear it to 0.  */
  if (ABSIZ(m) > new_alloc)
    SIZ(m) = 0;

  return (void *) mp;
}
