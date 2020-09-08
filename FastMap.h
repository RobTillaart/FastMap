#pragma once
//
//    FILE: FastMap.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.3.1
// PURPOSE: class with fast map function - library for Arduino
//     URL: https://github.com/RobTillaart/FastMap
//
// HISTORY:
// see FastMap.cpp file
//

#include <Arduino.h>

#define FASTMAP_LIB_VERSION (F("0.3.1"))
#define STRING2(x) #x
#define STRING(x) STRING2(x)

class FastMap
{
public:
    FastMap();

    void init(const float in_min, const float in_max, const float out_min, const float out_max);

    float inline map (const float value)  { return _base + value * _factor; }
    float inline back (const float value) { return _backbase + value * _backfactor; }

    float constrainedMap(const float value);
    float lowerConstrainedMap(const float value);
    float upperConstrainedMap(const float value);

private:
    float _in_min, _in_max, _out_min, _out_max;
    float _factor, _base;
    float _backfactor, _backbase;
};


class FastMapDouble
{
public:
    FastMapDouble();
    void init(const double in_min, const double in_max, const double out_min, const double out_max);

    double inline map (const double value)  { return _base + value * _factor; }
    double inline back (const double value) { return _backbase + value * _backfactor; }

    double constrainedMap(const double value);
    double lowerConstrainedMap(const double value);
    double upperConstrainedMap(const double value);

private:
    double _in_min, _in_max, _out_min, _out_max;
    double _factor, _base;
    double _backfactor, _backbase;
};

// fixedPointFraction is a 16.16 number
int16_t Multiply16ByFixedPointFraction1616(int16_t factor, int32_t fixedPointFraction);
// fixedPointFraction is a 32.32 number
int32_t Multiply32ByFixedPointFraction3232(int32_t factor, int64_t fixedPointFraction);
// COMPROMISE until int128_t defined // fixedPointFraction is a 32.32 number
int64_t Multiply64ByFixedPointFraction3232(int64_t factor, int64_t fixedPointFraction);

// we need two fractions, depending on whether we're multiplying a +ve or -ve factor later
void Ratio16ToFixedPointFraction1616(int16_t numerator, int16_t denominator, int32_t* fixedPointFraction_Pos, int32_t* fixedPointFraction_Neg);
void Ratio32ToFixedPointFraction3232(int32_t numerator, int32_t denominator, int64_t* fixedPointFraction_Pos, int64_t* fixedPointFraction_Neg);
// COMPROMISE until int128_t defined // Ratio64ToFixedPointFraction3232
void Ratio64ToFixedPointFraction3232(int64_t numerator, int64_t denominator, int64_t* fixedPointFraction_Pos, int64_t* fixedPointFraction_Neg);

// Calculate Greatest Common Denominator
long CalcGCD(long A, long B);

class FastMapInt
{
public:
    FastMapInt();

    void init(const int in_min_incl, const int in_max_excl, const int out_min_incl, const int out_max_excl);
    int inline map (const int val) {
      int inXS = val - _in_min_incl;
#if   defined(__INT_WIDTH__) && (__INT_WIDTH__ == 16)
      if(inXS >= 0) { return (_out_min_incl + Multiply16ByFixedPointFraction1616(inXS, _fixedPointFraction_Pos) ); }
      return ( _out_min_incl + Multiply16ByFixedPointFraction1616(inXS, _fixedPointFraction_Neg));
#elif defined(__INT_WIDTH__) && (__INT_WIDTH__ == 32)
      if(inXS >= 0) { return (_out_min_incl + Multiply32ByFixedPointFraction3232(inXS, _fixedPointFraction_Pos) ); }
      return ( _out_min_incl + Multiply32ByFixedPointFraction3232(inXS, _fixedPointFraction_Neg));
#elif defined(__INT_WIDTH__) && (__INT_WIDTH__ == 64)
#pragma message("Dodgy news: compromise because int width is " STRING(__INT_WIDTH__) )
      if(inXS >= 0) { return (_out_min_incl + Multiply64ByFixedPointFraction3232(inXS, _fixedPointFraction_Pos) ); }
      return ( _out_min_incl + Multiply64ByFixedPointFraction3232(inXS, _fixedPointFraction_Neg));
#elif defined(__INT_WIDTH__)
#pragma message("Bad news: int width is " STRING(__INT_WIDTH__) )
#error ("Oops: Code does not handle this int width"
      return (-1);
#else
#error "Oops: Unable to determine int width"
      return (-1);
#endif
    }
    int inline back (const int val) {
      int outXS = val - _out_min_incl;
      if(outXS >= 0) { return ( _in_min_incl + (outXS * _d_in_wider) / _d_out); }
      return ( _in_min_incl + (outXS * _d_in_wider - _d_out_less1 ) / _d_out);
    }
    int constrainedMap(const int val);
    int lowerConstrainedMap(const int val);
    int upperConstrainedMap(const int val);
private:
    int _in_min_incl, _in_max_excl, _out_min_incl, _out_max_excl;
    int _d_in, _d_out;
    int _d_in_less1, _d_out_less1;
#if   defined(__INT_WIDTH__) && (__INT_WIDTH__ == 8)
#pragma message("Good news: int width is " STRING(__INT_WIDTH__) )
    int16_t _d_in_wider, _d_out_wider;
    int16_t _fixedPointFraction_Pos, _fixedPointFraction_Neg;
#elif   defined(__INT_WIDTH__) && (__INT_WIDTH__ == 16)
#pragma message("Good news: int width is " STRING(__INT_WIDTH__) )
    int32_t _d_in_wider, _d_out_wider;
    int32_t _fixedPointFraction_Pos, _fixedPointFraction_Neg;
#elif defined(__INT_WIDTH__) && (__INT_WIDTH__ == 32)
#pragma message("Good news: int width is " STRING(__INT_WIDTH__))
    int64_t  _d_in_wider, _d_out_wider;
    int64_t _fixedPointFraction_Pos, _fixedPointFraction_Neg;
#elif defined(__INT_WIDTH__) && (__INT_WIDTH__ == 64)
#pragma message("Good news: int width is " STRING(__INT_WIDTH__))
    int128_t  _d_in_wider, _d_out_wider;
    int128_t _fixedPointFraction_Pos, _fixedPointFraction_Neg;
#elif defined(__INT_WIDTH__)
#warning("Unexpected news: unexpected int widths of " STRING(__INT_WIDTH__) ". I hope that 'long' is wider")
    long _d_in_wider, _d_out_wider;
    long _fixedPointFraction_Pos, _fixedPointFraction_Neg;
#else
#warning("Unexpected news: Cannot find int width. Let's hope that 'long' is wider")
    long _d_in_wider, _d_out_wider;
    long _fixedPointFraction_Pos, _fixedPointFraction_Neg;
#endif
};

class FastMapLong
{
public:
    FastMapLong();

    void init(const long in_min_incl, const long in_max_excl, const long out_min_incl, const long out_max_excl);
    long inline map (const long val) {
      long inXS = val - _in_min_incl;
#if   defined(__LONG_WIDTH__) && (__LONG_WIDTH__ == 16)
      if(inXS >= 0) { return (_out_min_incl + Multiply16ByFixedPointFraction1616(inXS, _fixedPointFraction_Pos) ); }
      return ( _out_min_incl + Multiply16ByFixedPointFraction1616(inXS, _fixedPointFraction_Neg));
#elif defined(__LONG_WIDTH__) && (__LONG_WIDTH__ == 32)
      if(inXS >= 0) { return (_out_min_incl + Multiply32ByFixedPointFraction3232(inXS, _fixedPointFraction_Pos) ); }
      return ( _out_min_incl + Multiply32ByFixedPointFraction3232(inXS, _fixedPointFraction_Neg));
#elif defined(__LONG_WIDTH__) && (__LONG_WIDTH__ == 64)
#pragma message("Dodgy news: compromise because long width is " STRING(__LONG_WIDTH__) )
      if(inXS >= 0) { return (_out_min_incl + Multiply64ByFixedPointFraction3232(inXS, _fixedPointFraction_Pos) ); }
      return ( _out_min_incl + Multiply64ByFixedPointFraction3232(inXS, _fixedPointFraction_Neg));
#elif defined(__LONG_WIDTH__)
#pragma message("Bad news: long width is " STRING(__LONG_WIDTH__) )
#error ("Oops: Code does not handle this long width"
      return (-1);
#else
#error "Oops: Unable to determine long width"
      return (-1);
#endif
    }
    long inline back (const long val) {
      long outXS = val - _out_min_incl;
      if(outXS >= 0) { return ( _in_min_incl + (outXS * _d_in_wider) / _d_out); }
      return ( _in_min_incl + (outXS * _d_in_wider - _d_out_less1 ) / _d_out);
    }
    long constrainedMap(const long val);
    long lowerConstrainedMap(const long val);
    long upperConstrainedMap(const long val);
private:
    int _in_min_incl, _in_max_excl, _out_min_incl, _out_max_excl;
    int _d_in, _d_out;
    int _d_in_less1, _d_out_less1;
#if   defined(__LONG_WIDTH__) && (__LONG_WIDTH__ == 16)
#pragma message("Good news: long width is " STRING(__LONG_WIDTH__))
    int32_t _d_in_wider, _d_out_wider;
    int32_t _fixedPointFraction_Pos, _fixedPointFraction_Neg;
#elif defined(__LONG_WIDTH__) && (__LONG_WIDTH__ == 32)
#pragma message("Good news: long width is " STRING(__LONG_WIDTH__))
    int64_t  _d_in_wider, _d_out_wider;
    int64_t _fixedPointFraction_Pos, _fixedPointFraction_Neg;
#elif defined(__LONG_WIDTH__) && (__LONG_WIDTH__ == 64)
#pragma message("Dodgy news: compromise because long width is " STRING(__LONG_WIDTH__) )
    int64_t  _d_in_wider, _d_out_wider;
    int64_t _fixedPointFraction_Pos, _fixedPointFraction_Neg;
#elif defined(__LONG_WIDTH__)
#warning("Unexpected news: unexpected long widths of " STRING(__LONG_WIDTH__) ". I hope that 'long long' is wider")
    long long _d_in_wider, _d_out_wider;
    long long _fixedPointFraction_Pos, _fixedPointFraction_Neg;
#else
#warning("Unexpected news: Cannot find int width. Let's hope that 'long long' is wider")
    long long _d_in_wider, _d_out_wider;
    long long _fixedPointFraction_Pos, _fixedPointFraction_Neg;
#endif
};
// -- END OF FILE --
