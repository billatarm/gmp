# PowerPC-32  __mpn_sub_n -- Subtract two limb vectors of the same length > 0
# and store difference in a third limb vector.
#
# Copyright (C) 1995, 1997 Free Software Foundation, Inc.
#
# This file is part of the GNU MP Library.
#
# The GNU MP Library is free software; you can redistribute it and/or modify
# it under the terms of the GNU Library General Public License as published by
# the Free Software Foundation; either version 2 of the License, or (at your
# option) any later version.
#
# The GNU MP Library is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
# or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
# License for more details.
#
# You should have received a copy of the GNU Library General Public License
# along with the GNU MP Library; see the file COPYING.LIB.  If not, write to
# the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
# MA 02111-1307, USA.

# INPUT PARAMETERS
# res_ptr	r3
# s1_ptr	r4
# s2_ptr	r5
# size		r6

include(`../config.m4')

ASM_START()
PROLOGUE(mpn_sub_n)
	mtctr	r6		# copy size into CTR
	addic	r0,r6,-1	# set cy
	lwz	r8,0(r4)	# load least significant s1 limb
	lwz	r0,0(r5)	# load least significant s2 limb
	addi	r3,r3,-4	# offset res_ptr, it's updated before it's used
	bdz	L(end)		# If done, skip loop
L(loop):
	lwz	r9,4(r4)	# load s1 limb
	lwz	r10,4(r5)	# load s2 limb
	subfe	r7,r0,r8	# subtract limbs with cy, set cy
	stw	r7,4(r3)	# store result limb
	bdz	L(exit)		# decrement CTR and exit if done
	lwzu	r8,8(r4)	# load s1 limb and update s1_ptr
	lwzu	r0,8(r5)	# load s2 limb and update s2_ptr
	subfe	r7,r10,r9	# subtract limbs with cy, set cy
	stwu	r7,8(r3)	# store result limb and update res_ptr
	bdnz	L(loop)		# decrement CTR and loop back

L(end):	subfe	r7,r0,r8
	stw	r7,4(r3)	# store ultimate result limb
	subfe	r3,r0,r0	# load !cy into ...
	subfic	r3,r3,0		# ... return value register
	blr
L(exit):
	subfe	r7,r10,r9
	stw	r7,8(r3)
	subfe	r3,r0,r0	# load !cy into ...
	subfic	r3,r3,0		# ... return value register
	blr
EPILOGUE(mpn_sub_n)
