dnl  AMD K6 mpn_preinv_mod_1 -- mpn by 1 remainder, with pre-inverted divisor.
dnl
dnl  K6: 18.0 cycles/limb


include(`../config.m4')


C mp_limb_t mpn_preinv_mod_1 (mp_srcptr src, mp_size_t size, mp_limb_t divisor,
C                             mp_limb_t inverse);
C
C This code is only 2 c/l faster than a simple divl, but that's 10% so it's
C considered worthwhile (just).
C
C Future:
C
C In theory this code should be made available in mod_1 and mod_1c, but it
C would take quite a while to overcome the time to calculate an inverse.
C The threshold would probably be around 20 limbs, or around 30 for an
C unnormalized divisor.

defframe(PARAM_INVERSE,16)
defframe(PARAM_DIVISOR,12)
defframe(PARAM_SIZE,    8)
defframe(PARAM_SRC,     4)

	TEXT
	ALIGN(32)
PROLOGUE(mpn_preinv_mod_1)
deflit(`FRAME',0)

	ASSERT(ae,`cmpl $1, PARAM_SIZE')
	ASSERT(nz,`testl $0x80000000, PARAM_DIVISOR')

	movl	PARAM_SIZE, %ecx
	pushl	%ebp	FRAME_pushl()

	movl	PARAM_SRC, %ebp
	pushl	%edi	FRAME_pushl()

	movl	PARAM_DIVISOR, %eax
	pushl	%esi	FRAME_pushl()

	movl	-4(%ebp,%ecx,4), %esi	C src high limb
	pushl	%ebx	FRAME_pushl()

	movl	%edx, %edi		C first n2 to cancel
	subl	%eax, %esi		C first n1 = high-divisor

	decl	%ecx
	jz	L(done_sbbl)

L(top):
	C eax	scratch
	C ebx	n10, nadj, q1
	C ecx	counter, size to 1
	C edx	scratch
	C esi	n2
	C edi	old high, for underflow test
	C ebp	src

	sbbl	%edx, %edi	    C high n-(q1+1)*d, 0 or -1

L(entry):
	andl	PARAM_DIVISOR, %edi
L(q1_ff_top):
	movl	-4(%ebp,%ecx,4), %ebx

	addl	%esi, %edi	    C possible addback
	movl	%ebx, %esi	    C n10

	sarl	$31, %ebx	    C -n1 = 0 or -1
	movl	%edi, %eax	    C n2

	movl	PARAM_INVERSE, %edx
	subl	%ebx, %eax	    C n2+n1

	mull	%edx		    C m*(n2+n1)

	andl	PARAM_DIVISOR, %ebx C -n1 & d
	addl	%esi, %ebx	    C nadj = n10 + (-n1&d), ignoring overflow

	addl	%ebx, %eax	    C low m*(n2+n1) + nadj, giving carry flag
	leal	1(%edi), %ebx	    C n2+1

	adcl	%ebx, %edx	    C 1+high(n2<<32+m*(n2+n1)+nadj) = q1+1

	movl	PARAM_DIVISOR, %eax C d
	jz	L(q1_ff)

	mull	%edx		    C (q1+1)*d

	subl	%eax, %esi	    C low  n-(q1+1)*d
	loop	L(top)



L(done_sbbl):
	sbbl	%edx, %edi	    C high n-(q1+1)*d, 0 or -1

	andl	PARAM_DIVISOR, %edi
L(done_esi_edi):
	popl	%ebx

	leal	(%esi,%edi), %eax
	popl	%esi

	popl	%edi
	popl	%ebp

	ret


C Special case for q1=0xFFFFFFFF, giving q=0xFFFFFFFF meaning the low dword
C of q*d is simply -d and the remainder n-q*d = n10+d.  This is rarely
C reached.

L(q1_ff):
	movl	PARAM_DIVISOR, %edi
	loop	L(q1_ff_top)

	jmp	L(done_esi_edi)


EPILOGUE()
