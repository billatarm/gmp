dnl  Intel Atom  mpn_bdiv_dbm1.

dnl  Contributed to the GNU project by Torbjorn Granlund and Marco Bodrato.
dnl
dnl  Copyright 2011 Free Software Foundation, Inc.
dnl
dnl  This file is part of the GNU MP Library.
dnl
dnl  The GNU MP Library is free software; you can redistribute it and/or
dnl  modify it under the terms of the GNU Lesser General Public License as
dnl  published by the Free Software Foundation; either version 3 of the
dnl  License, or (at your option) any later version.
dnl
dnl  The GNU MP Library is distributed in the hope that it will be useful,
dnl  but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
dnl  Lesser General Public License for more details.
dnl
dnl  You should have received a copy of the GNU Lesser General Public License
dnl  along with the GNU MP Library.  If not, see http://www.gnu.org/licenses/.

include(`../config.m4')

C			    cycles/limb
C			    cycles/limb
C P5				 -
C P6 model 0-8,10-12		 -
C P6 model 9  (Banias)		 9.75
C P6 model 13 (Dothan)
C P4 model 0  (Willamette)
C P4 model 1  (?)
C P4 model 2  (Northwood)
C P4 model 3  (Prescott)
C P4 model 4  (Nocona)
C Intel Atom			 8
C AMD K6			 -
C AMD K7			 -
C AMD K8
C AMD K10

defframe(PARAM_CARRY,20)
defframe(PARAM_MUL,  16)
defframe(PARAM_SIZE, 12)
defframe(PARAM_SRC,  8)
defframe(PARAM_DST,  4)

define(`rp', `%edi')
define(`up', `%esi')
define(`n',  `%ecx')
define(`reg', `%edx')
define(`cy', `%eax')	C contains the return value

ASM_START()
	TEXT
	ALIGN(16)
deflit(`FRAME',0)

PROLOGUE(mpn_bdiv_dbm1c)
	push	%edi			FRAME_pushl()
	push	%esi			FRAME_pushl()
	mov	PARAM_DST, rp
	mov	PARAM_SRC, up
	mov	PARAM_SIZE, n		C size
	movd	PARAM_MUL, %mm7
	mov	PARAM_CARRY, cy

	movd	(up), %mm0
	pmuludq	%mm7, %mm0
	shr	n
	jz	L(eq1)

	movd	4(up), %mm1
	jc	L(odd)

	pmuludq	%mm7, %mm1
	movd	%mm0, reg
	psrlq	$32, %mm0
	sub	reg, cy
	movd	%mm0, reg
	movq	%mm1, %mm0
	mov	cy, (rp)
	lea	4(rp), rp
	lea	4(up), up
	dec	n
	jz	L(end)

C	ALIGN(16)
L(top):	movd	4(up), %mm1
	sbb	reg, cy
L(odd):	movd	%mm0, reg
	psrlq	$32, %mm0
	pmuludq	%mm7, %mm1
	sub	reg, cy
	lea	8(up), up
	movd	%mm0, reg
	movd	(up), %mm0
	mov	cy, (rp)
	sbb	reg, cy
	movd	%mm1, reg
	psrlq	$32, %mm1
	sub	reg, cy
	movd	%mm1, reg
	pmuludq	%mm7, %mm0
	dec	n
	mov	cy, 4(rp)
	lea	8(rp), rp
	jnz	L(top)

L(end):	sbb	reg, cy

L(eq1):	movd	%mm0, reg
	psrlq	$32, %mm0
	sub	reg, cy
	movd	%mm0, reg
	mov	cy, (rp)
	sbb	reg, cy

	emms
	pop	%esi			FRAME_popl()
	pop	%edi			FRAME_popl()
	ret
EPILOGUE()
ASM_END()
