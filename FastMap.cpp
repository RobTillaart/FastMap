//
//    FILE: FastMap.cpp
//  AUTHOR: Rob Tillaart
// VERSION: 0.3.1
// PURPOSE: class with fast map function - library for Arduino
//     URL: https://github.com/RobTillaart/FastMap
//
// HISTORY:
// 0.X.X  2020-09-XX added FastMapInt, FastMapLong by Bryan White (Brewmanz)
// 0.3.1  2020-08-31 updated documentation
// 0.3.0  2020-07-04 added fastMapDouble + test sketch.
// 0.2.1  2020-06-10 fix library.json; rename license
// 0.2.0  2020-03-21 #pragma once; readme.md; license.md
//
// 0.1.8  2017-07-27 revert double to float (issue 33)
// 0.1.7  2017-04-28 cleaned up, get examples working again
// 0.1.06 2015-03-08 replaced float by double (support ARM)
// 0.1.05 2014-11-02 stripped of bit mask experimental code
// 0.1.04 add back() - the inverse map
//        tested with bit mask for constrain code (Perfomance was killed)
// 0.1.03 proper name
// 0.1.02 sqeezed the code (first public version)
// 0.1.01 refactor
// 0.1.00 initial version
//

#include "FastMap.h"

FastMap::FastMap()
{
    init(0, 1, 0, 1);
}

void FastMap::init(float in_min, float in_max, float out_min, float out_max)
{
    _in_min = in_min;
    _in_max = in_max;
    _out_min = out_min;
    _out_max = out_max;

    _factor = (out_max - out_min)/(in_max - in_min);
    _base = out_min - in_min * _factor;

    _backfactor = 1/_factor;
    _backbase = in_min - out_min * _backfactor;
}

float FastMap::constrainedMap(float value)
{
    if (value <= _in_min) return _out_min;
    if (value >= _in_max) return _out_max;
    return this->map(value);
}

float FastMap::lowerConstrainedMap(float value)
{
    if (value <= _in_min) return _out_min;
    return this->map(value);
}

float FastMap::upperConstrainedMap(float value)
{
    if (value >= _in_max) return _out_max;
    return this->map(value);
}

FastMapDouble::FastMapDouble()
{
    init(0, 1, 0, 1);
}

void FastMapDouble::init(double in_min, double in_max, double out_min, double out_max)
{
    _in_min = in_min;
    _in_max = in_max;
    _out_min = out_min;
    _out_max = out_max;

    _factor = (out_max - out_min)/(in_max - in_min);
    _base = out_min - in_min * _factor;

    _backfactor = 1/_factor;
    _backbase = in_min - out_min * _backfactor;
}

double FastMapDouble::constrainedMap(double value)
{
    if (value <= _in_min) return _out_min;
    if (value >= _in_max) return _out_max;
    return this->map(value);
}

double FastMapDouble::lowerConstrainedMap(double value)
{
    if (value <= _in_min) return _out_min;
    return this->map(value);
}

double FastMapDouble::upperConstrainedMap(double value)
{
    if (value >= _in_max) return _out_max;
    return this->map(value);
}

FastMapInt::FastMapInt()
{
    init(0, 1, 0, 1);
}

void FastMapInt::init(const int in_min_incl, const int in_max_excl, const int out_min_incl, const int out_max_excl)
{
  _in_min_incl = in_min_incl;
  _in_max_excl = in_max_excl;
  _out_min_incl = out_min_incl;
  _out_max_excl = out_max_excl;

  _d_in_wider = _d_in = in_max_excl - in_min_incl;
  _d_in_less1 = _d_in - (_d_in > 0 ? 1 : -1);

  _d_out_wider = _d_out = out_max_excl - out_min_incl;
  _d_out_less1 = _d_out - (_d_out > 0 ? 1 : -1);

#if   defined(__INT_WIDTH__) && (__INT_WIDTH__ == 8)
#pragma message("Good news: int width is " STRING(__INT_WIDTH__) )
  Ratio8ToFixedPointFraction88(_d_out, _d_in, &_fixedPointFraction_Pos, &_fixedPointFraction_Neg);
#elif   defined(__INT_WIDTH__) && (__INT_WIDTH__ == 16)
#pragma message("Good news: int width is " STRING(__INT_WIDTH__) )
  Ratio16ToFixedPointFraction1616(_d_out, _d_in, &_fixedPointFraction_Pos, &_fixedPointFraction_Neg);
#elif defined(__INT_WIDTH__) && (__INT_WIDTH__ == 32)
#pragma message("Good news: int width is " STRING(__INT_WIDTH__))
  Ratio32ToFixedPointFraction3232(_d_out, _d_in, &_fixedPointFraction_Pos, &_fixedPointFraction_Neg);
#elif defined(__INT_WIDTH__) && (__INT_WIDTH__ == 64)
#pragma message("Good news: int width is " STRING(__INT_WIDTH__))
#pragma message("Dodgy news: compromise because int width is " STRING(__INT_WIDTH__) )
  Ratio64ToFixedPointFraction3232(_d_out, _d_in, &_fixedPointFraction_Pos, &_fixedPointFraction_Neg);
#elif defined(__INT_WIDTH__)
#warning("Unexpected news: unexpected int widths of " STRING(__INT_WIDTH__) ". I hope that 'long' is wider")
#error "Cannot continue"
  RatioXXToFixedPointFractionXXXX(_d_out, _d_in, &_fixedPointFraction_Pos, &_fixedPointFraction_Neg);
#else
#warning("Unexpected news: Cannot find int width. Let's hope that 'long' is wider")
#error "Cannot continue"
  RatioXXToFixedPointFractionXXXX(_d_out, _d_in, &_fixedPointFraction_Pos, &_fixedPointFraction_Neg);
#endif
}

int FastMapInt::constrainedMap(int value)
{
    if (value <= _in_min_incl) return _out_min_incl;
    if (value >= _in_max_excl) return _out_max_excl - 1;
    return this->map(value);
}

int FastMapInt::lowerConstrainedMap(int value)
{
    if (value <= _in_min_incl) return _out_min_incl;
    return this->map(value);
}

int FastMapInt::upperConstrainedMap(int value)
{
    if (value >= _in_max_excl) return _out_max_excl - 1;
    return this->map(value);
}

FastMapLong::FastMapLong()
{
    init(0, 1, 0, 1);
}

void FastMapLong::init(const long in_min_incl, const long in_max_excl, const long out_min_incl, const long out_max_excl)
{
  _in_min_incl = in_min_incl;
  _in_max_excl = in_max_excl;
  _out_min_incl = out_min_incl;
  _out_max_excl = out_max_excl;

  _d_in_wider = _d_in = in_max_excl - in_min_incl;
  _d_in_less1 = _d_in - (_d_in > 0 ? 1 : -1);

  _d_out_wider = _d_out = out_max_excl - out_min_incl;
  _d_out_less1 = _d_out - (_d_out > 0 ? 1 : -1);

#if   defined(__LONG_WIDTH__) && (__LONG_WIDTH__ == 16)
  Ratio16ToFixedPointFraction1616(_d_out, _d_in, &_fixedPointFraction_Pos, &_fixedPointFraction_Neg);
#elif defined(__LONG_WIDTH__) && (__LONG_WIDTH__ == 32)
  Ratio32ToFixedPointFraction3232(_d_out, _d_in, &_fixedPointFraction_Pos, &_fixedPointFraction_Neg);
#elif defined(__LONG_WIDTH__) && (__LONG_WIDTH__ == 64)
#pragma message("Dodgy news: compromise because long width is " STRING(__LONG_WIDTH__) )
  Ratio64ToFixedPointFraction3232(_d_out, _d_in, &_fixedPointFraction_Pos, &_fixedPointFraction_Neg);
#elif defined(__LONG_WIDTH__)
#pragma message("Bad news: long width is " STRING(__LONG_WIDTH__) )
#error "Cannot continue"
  RatioXXToFixedPointFractionXXXX(_d_out, _d_in, &_fixedPointFraction_Pos, &_fixedPointFraction_Neg);
#else
#error "Oops: Unable to determine long width"
#error "Cannot continue"
  RatioXXToFixedPointFractionXXXX(_d_out, _d_in, &_fixedPointFraction_Pos, &_fixedPointFraction_Neg);
#endif
}

long FastMapLong::constrainedMap(long value)
{
    if (value <= _in_min_incl) return _out_min_incl;
    if (value >= _in_max_excl) return _out_max_excl - 1;
    return this->map(value);
}

long FastMapLong::lowerConstrainedMap(long value)
{
    if (value <= _in_min_incl) return _out_min_incl;
    return this->map(value);
}

long FastMapLong::upperConstrainedMap(long value)
{
    if (value >= _in_max_excl) return _out_max_excl - 1;
    return this->map(value);
}

int16_t Multiply16ByFixedPointFraction1616(int16_t factor, int32_t fixedPointFraction){
  if(factor == 0 || fixedPointFraction == 0) { return 0; }
  bool bFPFNeg = fixedPointFraction < 0;
  if(bFPFNeg){
    fixedPointFraction = -fixedPointFraction;
  }
  int32_t res = factor;
  res *= fixedPointFraction;
  res >>= 16;
  return bFPFNeg ? -res : res;
}
int32_t Multiply32ByFixedPointFraction3232(int32_t factor, int64_t fixedPointFraction){
  if(factor == 0 || fixedPointFraction == 0) { return 0; }
  bool bFPFNeg = fixedPointFraction < 0;
  if(bFPFNeg){
    fixedPointFraction = -fixedPointFraction;
  }
  int64_t res = factor;
  res *= fixedPointFraction;
  res >>= 32;
  return bFPFNeg ? -res : res;
}

int64_t Multiply64ByFixedPointFraction3232(int64_t factor, int64_t fixedPointFraction){
 if(factor == 0 || fixedPointFraction == 0) { return 0; }
  bool bFPFNeg = fixedPointFraction < 0;
  if(bFPFNeg){
    fixedPointFraction = -fixedPointFraction;
  }
  int64_t res = factor;
  res *= fixedPointFraction;
  res >>= 32;
  return bFPFNeg ? -res : res;
}

// we need two fractions, depending on whether we're multiplying a +ve or -ve factor later
void Ratio16ToFixedPointFraction1616(int16_t numerator, int16_t denominator, int32_t* fixedPointFraction_Pos, int32_t* fixedPointFraction_Neg){
  int32_t resP = 0, resN = 0;
  if(numerator != 0 && denominator != 0) {
    resP = numerator;
    resN = resP <<= 16;
    // round slightly to help truncated fraction for +ve numbers
    int16_t rounding = abs(denominator) - 1;
    resP += resP > 0 ? rounding : -rounding;
    resP /= denominator;
    resN /= denominator; // always need to round down for -ve numbers
  }
  if(fixedPointFraction_Pos) { *fixedPointFraction_Pos = resP; }
  if(fixedPointFraction_Neg) { *fixedPointFraction_Neg = resN; }
}

// we need two fractions, depending on whether we're multiplying a +ve or -ve factor later
void Ratio32ToFixedPointFraction3232(int32_t numerator, int32_t denominator, int64_t* fixedPointFraction_Pos, int64_t* fixedPointFraction_Neg){
  int64_t resP = 0, resN = 0;
  if(numerator != 0 && denominator != 0) {
    resP = numerator;
    resN = resP <<= 32;
    // round slightly to help truncated fraction for +ve numbers
    int32_t rounding = abs(denominator) - 1;
    resP += resP > 0 ? rounding : -rounding;
    resP /= denominator;
    resN /= denominator; // always need to round down for -ve numbers
  }
  if(fixedPointFraction_Pos) { *fixedPointFraction_Pos = resP; }
  if(fixedPointFraction_Neg) { *fixedPointFraction_Neg = resN; }
}

// we need two fractions, depending on whether we're multiplying a +ve or -ve factor later
// COMPROMISE s/b Ratio64ToFixedPointFraction6464
void Ratio64ToFixedPointFraction3232(int64_t numerator, int64_t denominator, int64_t* fixedPointFraction_Pos, int64_t* fixedPointFraction_Neg){
  int64_t resP = 0, resN = 0;
  if(numerator != 0 && denominator != 0) {
    resP = numerator;
    resN = resP <<= 32;
    // round slightly to help truncated fraction for +ve numbers
    int32_t rounding = abs(denominator) - 1;
    resP += resP > 0 ? rounding : -rounding;
    resP /= denominator;
    resN /= denominator; // always need to round down for -ve numbers
  }
  if(fixedPointFraction_Pos) { *fixedPointFraction_Pos = resP; }
  if(fixedPointFraction_Neg) { *fixedPointFraction_Neg = resN; }
}

long CalcGCD(long A, long B){
  if(A == 0 || B == 0) { return 0; }
  long res;
  while(B != 0){
    res = abs(B);
    B = A % B;
    A = abs(res);
  }
  return res;
}

// END OF FILE
