//
//    FILE: fastMapInteger32ArithmeticTestA.ino
//  AUTHOR: Brewmanz (Bryan White)
// VERSION: 0.1.1
// PURPOSE: Test of FastMapInt(32) helper functions
//    DATE: 2020-09-08
//     URL: https://github.com/RobTillaart/FastMap

//#include <AUnitVerbose.h> // too much for Nano!
#include <AUnit.h>
#include <FastMap.h>

test(T1200Ratio32ToFixedPointFraction64) {
  FixedPointFraction64_t fpfP, fpfN;
#if FULL_DEBUG || 1
  Print* pPrintDebug = &Serial;
#else
  Print* pPrintDebug = nullptr;
#endif

  fpfP = fpfN = {-2468, 97, -42};
  assertEqual(fpfP.TheFraction, (int64_t)-2468);
  assertEqual(fpfN.TheFraction, (int64_t)-2468);
  assertEqual(fpfP.BitsToShift, 97);
  assertEqual(fpfN.BitsToShift, 97);
  assertEqual(fpfP.MaxInput, (int32_t)-42);
  assertEqual(fpfN.MaxInput, (int32_t)-42);

  // handling of 0
  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(0, 0, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (int64_t)0b00 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfN.TheFraction, (int64_t)0b00 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfP.BitsToShift, 32 - 32);
  assertEqual(fpfN.BitsToShift, 32 - 32);
  assertEqual(fpfP.MaxInput, (int32_t)0);
  assertEqual(fpfN.MaxInput, (int32_t)0);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(0, 8, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (int64_t)0b00 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfN.TheFraction, (int64_t)0b00 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfP.BitsToShift, 32 - 32);
  assertEqual(fpfN.BitsToShift, 32 - 32);
  assertEqual(fpfP.MaxInput, (int32_t)0);
  assertEqual(fpfN.MaxInput, (int32_t)0);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(8, 0, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (int64_t)0b00 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfN.TheFraction, (int64_t)0b00 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfP.BitsToShift, 32 - 32);
  assertEqual(fpfN.BitsToShift, 32 - 32);
  assertEqual(fpfP.MaxInput, (int32_t)0);
  assertEqual(fpfN.MaxInput, (int32_t)0);

  // equal ratios
  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(1, 1, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (int64_t)0b10 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfN.TheFraction, (int64_t)0b10 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfP.BitsToShift, 32 + 1);
  assertEqual(fpfN.BitsToShift, 32 + 1);
  assertEqual(fpfP.MaxInput, (int32_t)0x7fffffff/2);
  assertEqual(fpfN.MaxInput, (int32_t)1073741823);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(12, 12, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (int64_t)0b10 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfN.TheFraction, (int64_t)0b10 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfP.BitsToShift, 32 + 1);
  assertEqual(fpfN.BitsToShift, 32 + 1);
  assertEqual(fpfP.MaxInput, (int32_t)0x7fffffff/2);
  assertEqual(fpfN.MaxInput, (int32_t)1073741823);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(-2, 2, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((int64_t)0b10 * 0x100000000 + 0b00000000000000000000000000000000));
  assertEqual(fpfN.TheFraction, -((int64_t)0b10 * 0x100000000 + 0b00000000000000000000000000000000));
  assertEqual(fpfP.BitsToShift, 32 + 1);
  assertEqual(fpfN.BitsToShift, 32 + 1);
  assertEqual(fpfP.MaxInput, (int32_t)0x7fffffff/2);
  assertEqual(fpfN.MaxInput, (int32_t)1073741823);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(3, -3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((int64_t)0b10 * 0x100000000 + 0b00000000000000000000000000000000));
  assertEqual(fpfN.TheFraction, -((int64_t)0b10 * 0x100000000 + 0b00000000000000000000000000000000));
  assertEqual(fpfP.BitsToShift, 32 + 1);
  assertEqual(fpfN.BitsToShift, 32 + 1);
  assertEqual(fpfP.MaxInput, (int32_t)0x7fffffff/2);
  assertEqual(fpfN.MaxInput, (int32_t)1073741823);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(-4, -4, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (int64_t)0b10 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfN.TheFraction, (int64_t)0b10 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfP.BitsToShift, 32 + 1);
  assertEqual(fpfN.BitsToShift, 32 + 1);
  assertEqual(fpfP.MaxInput, (int32_t)0x7fffffff/2);
  assertEqual(fpfN.MaxInput, (int32_t)1073741823);

  // exact ratios
  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(8, 2, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (int64_t)0b10 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfN.TheFraction, (int64_t)0b10 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfP.BitsToShift, 32 - 1);
  assertEqual(fpfN.BitsToShift, 32 - 1);
  assertEqual(fpfP.MaxInput, (int32_t)0x7fffffff/4);
  assertEqual(fpfN.MaxInput, (int32_t)536870911);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(-12, 4, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((int64_t)0b11 * 0x100000000 + 0b00000000000000000000000000000000));
  assertEqual(fpfN.TheFraction, -((int64_t)0b11 * 0x100000000 + 0b00000000000000000000000000000000));
  assertEqual(fpfP.BitsToShift, 32 - 0);
  assertEqual(fpfN.BitsToShift, 32 - 0);
  assertEqual(fpfP.MaxInput, (int32_t)0x7fffffff/3);
  assertEqual(fpfN.MaxInput, (int32_t)715827882);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(30, -5, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((int64_t)0b11 * 0x100000000 + 0b00000000000000000000000000000000));
  assertEqual(fpfN.TheFraction, -((int64_t)0b11 * 0x100000000 + 0b00000000000000000000000000000000));
  assertEqual(fpfP.BitsToShift, 32 - 1);
  assertEqual(fpfN.BitsToShift, 32 - 1);
  assertEqual(fpfP.MaxInput, (int32_t)0x7fffffff/6);
  assertEqual(fpfN.MaxInput, (int32_t)357913941);


  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(-56, -7, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (int64_t)0b10 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfN.TheFraction, (int64_t)0b10 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfP.BitsToShift, 32 - 2);
  assertEqual(fpfN.BitsToShift, 32 - 2);
  assertEqual(fpfP.MaxInput, (int32_t)0x7fffffff/8);
  assertEqual(fpfN.MaxInput, (int32_t)268435455);

  // theoretical exact ratios
  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(1, 3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (int64_t)0b10 * 0x100000000 + 0b10101010101010101010101010101011);
  assertEqual(fpfN.TheFraction, (int64_t)0b10 * 0x100000000 + 0b10101010101010101010101010101010);
  assertEqual(fpfP.BitsToShift, 32 + 3);
  assertEqual(fpfN.BitsToShift, 32 + 3);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 3 / 8));
  assertEqual(fpfN.MaxInput, (int32_t)805306367);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(-1, 3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((int64_t)0b10 * 0x100000000 + 0b10101010101010101010101010101011));
  assertEqual(fpfN.TheFraction, -((int64_t)0b10 * 0x100000000 + 0b10101010101010101010101010101010));
  assertEqual(fpfP.BitsToShift, 32 + 3);
  assertEqual(fpfN.BitsToShift, 32 + 3);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 3 / 8));
  assertEqual(fpfN.MaxInput, (int32_t)805306367);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(1, -3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((int64_t)0b10 * 0x100000000 + 0b10101010101010101010101010101011));
  assertEqual(fpfN.TheFraction, -((int64_t)0b10 * 0x100000000 + 0b10101010101010101010101010101010));
  assertEqual(fpfP.BitsToShift, 32 + 3);
  assertEqual(fpfN.BitsToShift, 32 + 3);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 3 / 8));
  assertEqual(fpfN.MaxInput, (int32_t)805306367);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(-1, -3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (int64_t)0b10 * 0x100000000 + 0b10101010101010101010101010101011);
  assertEqual(fpfN.TheFraction, (int64_t)0b10 * 0x100000000 + 0b10101010101010101010101010101010);
  assertEqual(fpfP.BitsToShift, 32 + 3);
  assertEqual(fpfN.BitsToShift, 32 + 3);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 3 / 8));
  assertEqual(fpfN.MaxInput, (int32_t)805306367);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(2, 3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (int64_t)0b10 * 0x100000000 + 0b10101010101010101010101010101011);
  assertEqual(fpfN.TheFraction, (int64_t)0b10 * 0x100000000 + 0b10101010101010101010101010101010);
  assertEqual(fpfP.BitsToShift, 32 + 2);
  assertEqual(fpfN.BitsToShift, 32 + 2);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 3 / 8));
  assertEqual(fpfN.MaxInput, (int32_t)805306367);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(-2, 3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((int64_t)0b10 * 0x100000000 + 0b10101010101010101010101010101011));
  assertEqual(fpfN.TheFraction, -((int64_t)0b10 * 0x100000000 + 0b10101010101010101010101010101010));
  assertEqual(fpfP.BitsToShift, 32 + 2);
  assertEqual(fpfN.BitsToShift, 32 + 2);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 3 / 8));
  assertEqual(fpfN.MaxInput, (int32_t)805306367);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(2, -3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((int64_t)0b10 * 0x100000000 + 0b10101010101010101010101010101011));
  assertEqual(fpfN.TheFraction, -((int64_t)0b10 * 0x100000000 + 0b10101010101010101010101010101010));
  assertEqual(fpfP.BitsToShift, 32 + 2);
  assertEqual(fpfN.BitsToShift, 32 + 2);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 3 / 8));
  assertEqual(fpfN.MaxInput, (int32_t)805306367);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(-2, -3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (int64_t)0b10 * 0x100000000 + 0b10101010101010101010101010101011);
  assertEqual(fpfN.TheFraction, (int64_t)0b10 * 0x100000000 + 0b10101010101010101010101010101010);
  assertEqual(fpfP.BitsToShift, 32 + 2);
  assertEqual(fpfN.BitsToShift, 32 + 2);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 3 / 8));
  assertEqual(fpfN.MaxInput, (int32_t)805306367);

  // binary fraction
  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(1, 2, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (int64_t)0b10 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfN.TheFraction, (int64_t)0b10 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfP.BitsToShift, 32 + 2);
  assertEqual(fpfN.BitsToShift, 32 + 2);
  assertEqual(fpfP.MaxInput, (int32_t)0x7fffffff/2);
  assertEqual(fpfN.MaxInput, (int32_t)1073741823);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(-3, 4, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((int64_t)0b11 * 0x100000000 + 0b00000000000000000000000000000000));
  assertEqual(fpfN.TheFraction, -((int64_t)0b11 * 0x100000000 + 0b00000000000000000000000000000000));
  assertEqual(fpfP.BitsToShift, 32 + 2);
  assertEqual(fpfN.BitsToShift, 32 + 2);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 2 / 6));
  assertEqual(fpfN.MaxInput, (int32_t)715827882);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(3, -8, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((int64_t)0b11 * 0x100000000 + 0b00000000000000000000000000000000));
  assertEqual(fpfN.TheFraction, -((int64_t)0b11 * 0x100000000 + 0b00000000000000000000000000000000));
  assertEqual(fpfP.BitsToShift, 32 + 3);
  assertEqual(fpfN.BitsToShift, 32 + 3);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 2 / 6));
  assertEqual(fpfN.MaxInput, (int32_t)715827882);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(-3, -16, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (int64_t)0b11 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfN.TheFraction, (int64_t)0b11 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfP.BitsToShift, 32 + 4);
  assertEqual(fpfN.BitsToShift, 32 + 4);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 2 / 6));
  assertEqual(fpfN.MaxInput, (int32_t)715827882);

  // binary vulgar fraction
  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(3, 2, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (int64_t)0b11 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfN.TheFraction, (int64_t)0b11 * 0x100000000 + 0b00000000000000000000000000000000);
  assertEqual(fpfP.BitsToShift, 32 + 1);
  assertEqual(fpfN.BitsToShift, 32 + 1);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 2 / 6));
  assertEqual(fpfN.MaxInput, (int32_t)715827882);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(-7, 4, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((int64_t)0b11 * 0x100000000 + 0b10000000000000000000000000000000));
  assertEqual(fpfN.TheFraction, -((int64_t)0b11 * 0x100000000 + 0b10000000000000000000000000000000));
  assertEqual(fpfP.BitsToShift, 32 + 1);
  assertEqual(fpfN.BitsToShift, 32 + 1);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 4 / 14));
  assertEqual(fpfN.MaxInput, (int32_t)613566756);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(11, -8, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((int64_t)0b10 * 0x100000000 + 0b11000000000000000000000000000000));
  assertEqual(fpfN.TheFraction, -((int64_t)0b10 * 0x100000000 + 0b11000000000000000000000000000000));
  assertEqual(fpfP.BitsToShift, 32 + 1);
  assertEqual(fpfN.BitsToShift, 32 + 1);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 8 / 22));
  assertEqual(fpfN.MaxInput, (int32_t)780903144);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(-19, -16, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (int64_t)0b10 * 0x100000000 + 0b01100000000000000000000000000000);
  assertEqual(fpfN.TheFraction, (int64_t)0b10 * 0x100000000 + 0b01100000000000000000000000000000);
  assertEqual(fpfP.BitsToShift, 32 + 1);
  assertEqual(fpfN.BitsToShift, 32 + 1);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 16 / 38));
  assertEqual(fpfN.MaxInput, (int32_t)904203640);

  // inexact fraction
  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(5, 9, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (int64_t)0b10 * 0x100000000 + 0b00111000111000111000111000111001);
  assertEqual(fpfN.TheFraction, (int64_t)0b10 * 0x100000000 + 0b00111000111000111000111000111000);
  assertEqual(fpfP.BitsToShift, 32 + 2);
  assertEqual(fpfN.BitsToShift, 32 + 2);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 9 / 20));
  assertEqual(fpfN.MaxInput, (int32_t)966367641);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(-5, 9, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((int64_t)0b10 * 0x100000000 + 0b00111000111000111000111000111001));
  assertEqual(fpfN.TheFraction, -((int64_t)0b10 * 0x100000000 + 0b00111000111000111000111000111000));
  assertEqual(fpfP.BitsToShift, 32 + 2);
  assertEqual(fpfN.BitsToShift, 32 + 2);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 9 / 20));
  assertEqual(fpfN.MaxInput, (int32_t)966367641);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(5, -9, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((int64_t)0b10 * 0x100000000 + 0b00111000111000111000111000111001));
  assertEqual(fpfN.TheFraction, -((int64_t)0b10 * 0x100000000 + 0b00111000111000111000111000111000));
  assertEqual(fpfP.BitsToShift, 32 + 2);
  assertEqual(fpfN.BitsToShift, 32 + 2);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 9 / 20));
  assertEqual(fpfN.MaxInput, (int32_t)966367641);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(-5, -9, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (int64_t)0b10 * 0x100000000 + 0b00111000111000111000111000111001);
  assertEqual(fpfN.TheFraction, (int64_t)0b10 * 0x100000000 + 0b00111000111000111000111000111000);
  assertEqual(fpfP.BitsToShift, 32 + 2);
  assertEqual(fpfN.BitsToShift, 32 + 2);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 9 / 20));
  assertEqual(fpfN.MaxInput, (int32_t)966367641);

  // inexact vulgar fraction
  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(9, 5, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (int64_t)0b11 * 0x100000000 + 0b10011001100110011001100110011010);
  assertEqual(fpfN.TheFraction, (int64_t)0b11 * 0x100000000 + 0b10011001100110011001100110011001);
  assertEqual(fpfP.BitsToShift, 32 + 1);
  assertEqual(fpfN.BitsToShift, 32 + 1);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 5 / 18));
  assertEqual(fpfN.MaxInput, (int32_t)596523235);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(-9, 5, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((int64_t)0b11 * 0x100000000 + 0b10011001100110011001100110011010));
  assertEqual(fpfN.TheFraction, -((int64_t)0b11 * 0x100000000 + 0b10011001100110011001100110011001));
  assertEqual(fpfP.BitsToShift, 32 + 1);
  assertEqual(fpfN.BitsToShift, 32 + 1);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 5 / 18));
  assertEqual(fpfN.MaxInput, (int32_t)596523235);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(9, -5, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((int64_t)0b11 * 0x100000000 + 0b10011001100110011001100110011010));
  assertEqual(fpfN.TheFraction, -((int64_t)0b11 * 0x100000000 + 0b10011001100110011001100110011001));
  assertEqual(fpfP.BitsToShift, 32 + 1);
  assertEqual(fpfN.BitsToShift, 32 + 1);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 5 / 18));
  assertEqual(fpfN.MaxInput, (int32_t)596523235);

  fpfP = fpfN = {-2468, 97, -42}; Ratio32ToFixedPointFraction64(-9, -5, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (int64_t)0b11 * 0x100000000 + 0b10011001100110011001100110011010);
  assertEqual(fpfN.TheFraction, (int64_t)0b11 * 0x100000000 + 0b10011001100110011001100110011001);
  assertEqual(fpfP.BitsToShift, 32 + 1);
  assertEqual(fpfN.BitsToShift, 32 + 1);
  assertEqual(fpfP.MaxInput, (int32_t)((int64_t)0x7fffffff * 5 / 18));
  assertEqual(fpfN.MaxInput, (int32_t)596523235);
}

void setup() {
  delay(1000); // wait for stability on some boards to prevent garbage Serial
  Serial.begin(115200); // The baudrate of Serial monitor is set
  while(!Serial); // for the Arduino Leonardo/Micro only
  Serial.println(F(__DATE__ " @ " __TIME__));
  Serial.println(F(__FILE__));

  int toSecs = 1024;
  Serial.print(F("Setting aunit::TestRunner::setTimeout to ")); Serial.println(toSecs);
  aunit::TestRunner::setTimeout(toSecs); // 0 = infinite
}

void loop() {
  aunit::TestRunner::run();
}
