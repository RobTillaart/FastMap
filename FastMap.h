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

#define FMI_VER1 1 // VER1 = simple fix of rounding issue crossing below 0
class FastMapInt
{
public:
    FastMapInt();

    void init(const int in_min_incl, const int in_max_excl, const int out_min_incl, const int out_max_excl);
private:
    int _in_min_incl, _in_max_excl, _out_min_incl, _out_max_excl;
    int _d_in, _d_out;

public:
#if defined(FMI_VER1)
    int inline map (const int val)  {
      int inXS = val - _in_min_incl;
      if(inXS >= 0) { return ( _out_min_incl + (inXS * _d_out32) / _d_in); }
      return ( _out_min_incl + (inXS * _d_out32 - _d_in_less1) / _d_in);
    }
    int inline back (const int val) {
      int outXS = val - _out_min_incl;
      if(outXS >= 0) { return ( _in_min_incl + (outXS * _d_in32) / _d_out); }
      return ( _in_min_incl + (outXS * _d_in32 - _d_out_less1 ) / _d_out);
    }
private:
    int32_t _d_in32, _d_out32;
    int _d_in_less1, _d_out_less1;
#elif defined(FMI_VER2)
    int inline map (const int val);
    int inline back (const int val);
private:
    int32_t _d_in32, _d_out32;
    int _d_in_less1, _d_out_less1;
#endif
public:
    int constrainedMap(const int val);
    int lowerConstrainedMap(const int val);
    int upperConstrainedMap(const int val);
};
int MultiplyByFixedPointFraction(int factor, long fixedPointFraction, bool bDebug=false);
// we need two fractions, depending on whether we're multiplying a +ve or -ve factor later
void RatioToFixedPointFraction(int numerator, int denominator, long* fixedPointFraction_Pos, long* fixedPointFraction_Neg);
// Caluclate Greatest Common Denominator
long CalcGCD(long A, long B);

// -- END OF FILE --
