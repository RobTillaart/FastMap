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

  _d_in = in_max_excl - in_min_incl;
  _d_out = out_max_excl - out_min_incl;

  // can we simplify maths? eg in/out of 1024/256 can be refactored as 4/1
  _d_GCF = CalcGCD(_d_in, _d_out);
  if(_d_GCF > 1) {
    _d_in /= _d_GCF;
    _d_out /= _d_GCF;
  }

  _d_in_less1 = _d_in - (_d_in > 0 ? 1 : -1);
  _d_out_less1 = _d_out - (_d_out > 0 ? 1 : -1);

  double theRatio = 1.0 + (1.0 * abs(_d_out) ) / abs(_d_in);

  double factor8 = (__INT8_MAX__) / theRatio;
  if(factor8 > __INT8_MAX__) { factor8 = __INT8_MAX__; }
  if(max(abs(_d_in), abs(_d_out)) > __INT8_MAX__) { factor8 = 0; } // kill factor if numbers too big
  _d_FactorToMax8 = factor8 > __INT_MAX__? __INT_MAX__ : factor8;

  double factor16 = (__INT16_MAX__) / theRatio;
  if(factor16 > __INT16_MAX__) { factor16 = __INT16_MAX__; }
  if(max(abs(_d_in), abs(_d_out)) > __INT16_MAX__) { factor16 = 0; } // kill factor if numbers too big
  _d_FactorToMax16 = factor16 > __INT_MAX__? __INT_MAX__ : factor16;

  double factor32 = (__INT32_MAX__) / theRatio;
  if(factor32 > __INT32_MAX__) { factor32 = __INT32_MAX__; }
  if(max(abs(_d_in), abs(_d_out)) > __INT32_MAX__) { factor32 = 0; } // kill factor if numbers too big
  _d_FactorToMax32 = factor32 > __INT_MAX__? __INT_MAX__ : factor32;

  // some of the following may overflow; no-one cares
  Ratio8ToFixedPointFraction88(_d_out, _d_in, &_fixedPoint88Fraction_Pos, &_fixedPoint88Fraction_Neg);
  Ratio16ToFixedPointFraction1616(_d_out, _d_in, &_fixedPoint1616Fraction_Pos, &_fixedPoint1616Fraction_Neg);
  Ratio32ToFixedPointFraction3232(_d_out, _d_in, &_fixedPoint3232Fraction_Pos, &_fixedPoint3232Fraction_Neg);

#if 0 // DEBUG help
Serial.print("_d_in=");Serial.print(_d_in, DEC);Serial.print(", _d_out=");Serial.print(_d_out, DEC);Serial.print(", _d_GCF=");Serial.println(_d_GCF, DEC);
Serial.print("f8=");Serial.print(factor8, 6);Serial.print(", f16=");Serial.print(factor16, 6);Serial.print(", f32=");Serial.println(factor32, 6);
Serial.print("__INT8_MAX__=");Serial.print(__INT8_MAX__, DEC);Serial.print(", __INT16_MAX__=");Serial.print(__INT16_MAX__, DEC);Serial.print(", __INT32_MAX__=");Serial.println(__INT32_MAX__, DEC);
Serial.print("M8=");Serial.print(_d_FactorToMax8, DEC);Serial.print(", M16=");Serial.print(_d_FactorToMax16, DEC);Serial.print(", M32=");Serial.println(_d_FactorToMax32, DEC);
Serial.print("R8P=");Serial.print(_fixedPoint88Fraction_Pos / 256.0, 3);Serial.print(", R8N=");Serial.print(_fixedPoint88Fraction_Neg / 256.0, 3);
Serial.print(", R16P=");Serial.print(_fixedPoint1616Fraction_Pos / 65536.0, 3);Serial.print(", R8N=");Serial.print(_fixedPoint1616Fraction_Neg / 65536.0, 3);
Serial.print(", R32P=");Serial.print(_fixedPoint3232Fraction_Pos / 4294967296.0, 3);Serial.print(", R8N=");Serial.println(_fixedPoint3232Fraction_Neg / 4294967296.0, 3);
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

  _d_in = in_max_excl - in_min_incl;
  _d_out = out_max_excl - out_min_incl;

  // can we simplify maths? eg in/out of 1024/256 can be refactored as 4/1
  _d_GCF = CalcGCD(_d_in, _d_out);
  if(_d_GCF > 1) {
    _d_in /= _d_GCF;
    _d_out /= _d_GCF;
  }

  _d_in_less1 = _d_in - (_d_in > 0 ? 1 : -1);
  _d_out_less1 = _d_out - (_d_out > 0 ? 1 : -1);

  double theRatio = 1.0 + (1.0 * abs(_d_out) ) / abs(_d_in);

  double factor8 = (__INT8_MAX__) / theRatio;
  if(factor8 > __INT8_MAX__) { factor8 = __INT8_MAX__; }
  if(max(abs(_d_in), abs(_d_out)) > __INT8_MAX__) { factor8 = 0; } // kill factor if numbers too big
  _d_FactorToMax8 = factor8 > __INT_MAX__? __INT_MAX__ : factor8;

  double factor16 = (__INT16_MAX__) / theRatio;
  if(factor16 > __INT16_MAX__) { factor16 = __INT16_MAX__; }
  if(max(abs(_d_in), abs(_d_out)) > __INT16_MAX__) { factor16 = 0; } // kill factor if numbers too big
  _d_FactorToMax16 = factor16 > __INT_MAX__? __INT_MAX__ : factor16;

  double factor32 = (__INT32_MAX__) / theRatio;
  if(factor32 > __INT32_MAX__) { factor32 = __INT32_MAX__; }
  if(max(abs(_d_in), abs(_d_out)) > __INT32_MAX__) { factor32 = 0; } // kill factor if numbers too big
  _d_FactorToMax32 = factor32 > __INT_MAX__? __INT_MAX__ : factor32;

  // some of the following may overflow; no-one cares
  Ratio8ToFixedPointFraction88(_d_out, _d_in, &_fixedPoint88Fraction_Pos, &_fixedPoint88Fraction_Neg);
  Ratio16ToFixedPointFraction1616(_d_out, _d_in, &_fixedPoint1616Fraction_Pos, &_fixedPoint1616Fraction_Neg);
  Ratio32ToFixedPointFraction3232(_d_out, _d_in, &_fixedPoint3232Fraction_Pos, &_fixedPoint3232Fraction_Neg);
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

int8_t Multiply8ByFixedPointFraction88(int8_t factor, int16_t fixedPointFraction){
  if(factor == 0 || fixedPointFraction == 0) { return 0; }
  bool bFPFNeg = fixedPointFraction < 0;
  if(bFPFNeg){
    fixedPointFraction = -fixedPointFraction;
  }
  int16_t res = factor;
  res *= fixedPointFraction;
  res >>= 8;
  return bFPFNeg ? -res : res;
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
void Ratio8ToFixedPointFraction88(int8_t numerator, int8_t denominator, int16_t* fixedPointFraction_Pos, int16_t* fixedPointFraction_Neg){
  int16_t resP = 0, resN = 0;
  if(numerator != 0 && denominator != 0) {
    resP = numerator;
    resN = resP <<= 8;
    // round slightly to help truncated fraction for +ve numbers
    int8_t rounding = abs(denominator) - 1;
    resP += resP > 0 ? rounding : -rounding;
    resP /= denominator;
    resN /= denominator; // always need to round down for -ve numbers
  }
  if(fixedPointFraction_Pos) { *fixedPointFraction_Pos = resP; }
  if(fixedPointFraction_Neg) { *fixedPointFraction_Neg = resN; }
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
