divert(-1)

dnl  m4 macros for ARM64 ELF assembler.

dnl  Copyright 2020 Free Software Foundation, Inc.

dnl  This file is part of the GNU MP Library.
dnl
dnl  The GNU MP Library is free software; you can redistribute it and/or modify
dnl  it under the terms of either:
dnl
dnl    * the GNU Lesser General Public License as published by the Free
dnl      Software Foundation; either version 3 of the License, or (at your
dnl      option) any later version.
dnl
dnl  or
dnl
dnl    * the GNU General Public License as published by the Free Software
dnl      Foundation; either version 2 of the License, or (at your option) any
dnl      later version.
dnl
dnl  or both in parallel, as here.
dnl
dnl  The GNU MP Library is distributed in the hope that it will be useful, but
dnl  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
dnl  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
dnl  for more details.
dnl
dnl  You should have received copies of the GNU General Public License and the
dnl  GNU Lesser General Public License along with the GNU MP Library.  If not,
dnl  see https://www.gnu.org/licenses/.


dnl  Standard commenting is with @, the default m4 # is for constants and we
dnl  don't want to disable macro expansions in or after them.

changecom

dnl use the hint instructions so they NOP on older machines.
dnl Add comments so the assembly is notated with the instruction


define(`BTI_C', `hint #34    /* bti c */')
define(`PACIASP', `hint #25  /* paciasp */')
define(`AUTIASP', `hint #29  /* autiasp */')
define(`PACIBSP', `hint #27  /* pacibsp */')
define(`AUTIBSP', `hint #31  /* autibsp */')

dnl if BTI is enabled we want the SIGN_LR to be a valid
dnl landing pad, we don't need VERIFY_LR and we need to
dnl indicate the valid BTI support for gnu notes.


ifelse(ARM64_FEATURE_BTI_DEFAULT, `1',
  `define(`SIGN_LR', `BTI_C')
   define(`GNU_PROPERTY_AARCH64_BTI', `1')
   define(`PAC_OR_BTI')',
   define(`GNU_PROPERTY_AARCH64_BTI', `0')'
')

dnl define instructions for PAC, which can use the A
dnl or the B key. PAC instructions are also valid BTI
dnl landing pads, so we re-define SIGN_LR if BTI is
dnl enabled.


ifelse(ARM64_FEATURE_PAC_DEFAULT, `1',
    `define(`SIGN_LR', `PACIASP')
     define(`VERIFY_LR', `AUTIASP')
     define(`GNU_PROPERTY_AARCH64_POINTER_AUTH', `2')
     define(`PAC_OR_BTI')',
   ARM64_FEATURE_PAC_DEFAULT, `2',
    `define(`SIGN_LR', `PACIBSP')
     define(`VERIFY_LR', `AUTIBSP')
     define(`GNU_PROPERTY_AARCH64_POINTER_AUTH', `2')
     define(`PAC_OR_BTI')',
    `ifdef(`SIGN_LR', , `define(`SIGN_LR', `')')
     define(`VERIFY_LR', `')
     define(`GNU_PROPERTY_AARCH64_POINTER_AUTH', `0')'
')

dnl ADD_GNU_NOTES_IF_NEEDED
dnl
dnl Conditionally add into ELF assembly files the GNU notes indicating if
dnl BTI or PAC is support. BTI is required by the linkers and loaders, however
dnl PAC is a nice to have for auditing. Use readelf -n to display.


define(`ADD_GNU_NOTES_IF_NEEDED', `
  ifdef(`ARM64_ELF', `
    ifdef(`PAC_OR_BTI', `
      .pushsection .note.gnu.property, "a";
      .balign 8;
      .long 4;
      .long 0x10;
      .long 0x5;
      .asciz "GNU";
      .long 0xc0000000; /* GNU_PROPERTY_AARCH64_FEATURE_1_AND */
      .long 4;
      .long eval(indir(`GNU_PROPERTY_AARCH64_POINTER_AUTH') + indir(`GNU_PROPERTY_AARCH64_BTI'));
      .long 0;
      .popsection;
    ')
  ')
')

dnl  LEA_HI(reg,gmp_symbol), LEA_LO(reg,gmp_symbol)
dnl
dnl  Load the address of gmp_symbol into a register. We split this into two
dnl  parts to allow separation for manual insn scheduling.

ifdef(`PIC',`dnl
define(`LEA_HI', `adrp	$1, :got:$2')dnl
define(`LEA_LO', `ldr	$1, [$1, #:got_lo12:$2]')dnl
',`dnl
define(`LEA_HI', `adrp	$1, $2')dnl
define(`LEA_LO', `add	$1, $1, :lo12:$2')dnl
')dnl

divert`'dnl
