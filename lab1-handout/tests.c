/* Testing Code */

#include <limits.h>
#include <math.h>

/* Routines used by floation point test code */

/* Convert from bit level representation to floating point number */
float u2f(unsigned u) {
  union {
    unsigned u;
    float f;
  } a;
  a.u = u;
  return a.f;
}

/* Convert from floating point number to bit-level representation */
unsigned f2u(float f) {
  union {
    unsigned u;
    float f;
  } a;
  a.f = f;
  return a.u;
}

/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
// integer problems
// 1 pts
int test_nuaa_question1(int n) {
  int shift = n << 3;
  int byte = 0x55;
  return byte << shift;
}
// 2 pts
int test_nuaa_question2(int x, int n)
{
  union {
  int xs;
  char b[4];
 }exp;
 exp.xs=x;
 exp.b[n]=~exp.b[n];
 return x=exp.xs;
}
int test_nuaa_question3(int x, int y, int n) {
  union {
  int xs;
  char b[4];
 }exp1,exp2;
 exp1.xs=x;
 exp2.xs=y;
 return (exp1.b[n] - exp2.b[n]) != 0;
}
// 3 pts
int test_nuaa_question4(int x, int y, int n) {
  union {
  int xs;
  char b[4];
 }exp1,exp2;
 exp1.xs=x;
 exp2.xs=y;
 exp1.b[n]=exp1.b[n] & exp2.b[n];
 return x=exp1.xs;
}
// 4 pts
int test_nuaa_question5(int x)
{
  return !x;
}
// floating problems
// 4 pts
unsigned test_nuaa_question6(unsigned uf) {
  float f = u2f(uf);
  float tf = 2*f;
  if (isnan(f))
    return uf;
  else
    return f2u(tf);
}
