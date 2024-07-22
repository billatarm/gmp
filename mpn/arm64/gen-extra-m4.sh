#!/bin/sh
#
# A script for dynamically generating m4 definitions for aarch64 based on compilation flags.
#
# Copyright 2024 ARM Ltd.
#
#  This file is part of the GNU MP Library.
#
#  The GNU MP Library is free software; you can redistribute it and/or modify
#  it under the terms of either:
#
#    * the GNU Lesser General Public License as published by the Free
#      Software Foundation; either version 3 of the License, or (at your
#      option) any later version.
#
#  or
#
#    * the GNU General Public License as published by the Free Software
#      Foundation; either version 2 of the License, or (at your option) any
#      later version.
#
#  or both in parallel, as here.
#
#  The GNU MP Library is distributed in the hope that it will be useful, but
#  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
#  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
#  for more details.
#
#  You should have received copies of the GNU General Public License and the
#  GNU Lesser General Public License along with the GNU MP Library.  If not,
#  see https://www.gnu.org/licenses/.

# Usage: ./gen-extra-m4.sh "$CC"
# Returns: valid M4 to stdout.

if test "$#" -ne 1; then
  echo "Expected 1 argument, the CC. Got: $#"
  exit 1
fi

CC=$1

ARM64_FEATURE_BTI_DEFAULT="0"
ARM64_FEATURE_PAC_DEFAULT="0"
ARM64_ELF="0"

# strip -o from CC line so -dM works
_CC=$(echo "$CC" | sed 's/-o [^ ]*//')
output=$($_CC -dM -E - < /dev/null || exit $?)
while IFS= read -r line; do
  # Skip empty lines
  if test -z "$line"; then
    continue
  fi
  # Match the #define pattern and extract the macro name and value
  case "$line" in
    \#define\ *\ *)
      macro_name=`echo "$line" | awk '{print $2}'`
      macro_value=`echo "$line" | cut -d ' ' -f 3- | sed 's/^"\(.*\)"$/\1/'`
      # map's would be nice in POSIX shell, could use eval to simplify, but
      # I won't do that to others.
      case "$macro_name" in
        __ARM_FEATURE_BTI_DEFAULT)
          ARM64_FEATURE_BTI_DEFAULT="$macro_value"
        ;;
        __ARM_FEATURE_PAC_DEFAULT)
          ARM64_FEATURE_PAC_DEFAULT="$macro_value"
        ;;
        __ELF__)
          ARM64_ELF="$macro_value"
        ;;
      esac # end assignments
      ;;
  esac # end define
done <<< "$output"

# Output the M4 define statement. To make m4 simpler always output something so we can
# use an ifelse without needing to nest it within an ifdef.
echo "define(\`ARM64_FEATURE_BTI_DEFAULT', \`$ARM64_FEATURE_BTI_DEFAULT')"
echo "define(\`ARM64_FEATURE_PAC_DEFAULT', \`$ARM64_FEATURE_PAC_DEFAULT')"
echo "define(\`ARM64_ELF', \`$ARM64_ELF')"
