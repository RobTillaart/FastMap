//
//    FILE: fastMapInteger16ArithmeticTestA.ino
//  AUTHOR: Brewmanz (Bryan White)
// VERSION: 0.1.1
// PURPOSE: Test of FastMapInt(16) helper functions
//    DATE: 2020-09-08
//     URL: https://github.com/RobTillaart/FastMap

//#include <AUnitVerbose.h> // too much for Nano!
#include <AUnit.h>
#include <FastMap.h>

volatile int i, j;

test(T1150Ratio16ToFixedPointFraction32) {
  FixedPointFraction32_t  fpfP, fpfN;
#if FULL_DEBUG
  Print* pPrintDebug = &Serial;
#else
  Print* pPrintDebug = nullptr;
#endif

  fpfP = fpfN = {-2468, 97, -42};
  assertEqual(fpfP.TheFraction, (long)-2468);
  assertEqual(fpfN.TheFraction, (long)-2468);
  assertEqual(fpfP.BitsToShift, 97);
  assertEqual(fpfN.BitsToShift, 97);
  assertEqual(fpfP.MaxInput, -42);
  assertEqual(fpfN.MaxInput, -42);

  // handling of 0
  Ratio16ToFixedPointFraction32(0, 0, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (long)0b00 * 0x10000 + 0b0000000000000000);
  assertEqual(fpfN.TheFraction, (long)0b00 * 0x10000 + 0b0000000000000000);
  assertEqual(fpfP.BitsToShift, 0);
  assertEqual(fpfN.BitsToShift, 0);
  assertEqual(fpfP.MaxInput, 0);
  assertEqual(fpfN.MaxInput, 0);

  Ratio16ToFixedPointFraction32(0, 8, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (long)0b00 * 0x10000 + 0b0000000000000000);
  assertEqual(fpfN.TheFraction, (long)0b00 * 0x10000 + 0b0000000000000000);
  assertEqual(fpfP.BitsToShift, 0);
  assertEqual(fpfN.BitsToShift, 0);
  assertEqual(fpfP.MaxInput, 0);
  assertEqual(fpfN.MaxInput, 0);

  Ratio16ToFixedPointFraction32(8, 0, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (long)0b00 * 0x10000 + 0b0000000000000000);
  assertEqual(fpfN.TheFraction, (long)0b00 * 0x10000 + 0b0000000000000000);
  assertEqual(fpfP.BitsToShift, 0);
  assertEqual(fpfN.BitsToShift, 0);
  assertEqual(fpfP.MaxInput, 0);
  assertEqual(fpfN.MaxInput, 0);

  // equal ratios
  Ratio16ToFixedPointFraction32(1, 1, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (long)0b10 * 0x8000 + 0b0000000000000000);
  assertEqual(fpfN.TheFraction, (long)0b10 * 0x8000 + 0b0000000000000000);
  assertEqual(fpfP.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfP.MaxInput, 32767 / 2 * 2);
  assertEqual(fpfN.MaxInput, 16383 * 2);

  Ratio16ToFixedPointFraction32(12, 12, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (long)0b10 * 0x8000 + 0b0000000000000000);
  assertEqual(fpfN.TheFraction, (long)0b10 * 0x8000 + 0b0000000000000000);
  assertEqual(fpfP.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfP.MaxInput, 32767 / 2 * 2);
  assertEqual(fpfN.MaxInput, 16383 * 2);

  Ratio16ToFixedPointFraction32(-2, 2, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((long)0b10 * 0x8000 + 0b0000000000000000));
  assertEqual(fpfN.TheFraction, -((long)0b10 * 0x8000 + 0b0000000000000000));
  assertEqual(fpfP.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfP.MaxInput, 32767 / 2 * 2);
  assertEqual(fpfN.MaxInput, 16383 * 2);

  Ratio16ToFixedPointFraction32(3, -3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((long)0b10 * 0x8000 + 0b0000000000000000));
  assertEqual(fpfN.TheFraction, -((long)0b10 * 0x8000 + 0b0000000000000000));
  assertEqual(fpfP.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfP.MaxInput, 32767 / 2 * 2);
  assertEqual(fpfN.MaxInput, 16383 * 2);

  Ratio16ToFixedPointFraction32(-4, -4, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (long)0b10 * 0x8000 + 0b0000000000000000);
  assertEqual(fpfN.TheFraction, (long)0b10 * 0x8000 + 0b0000000000000000);
  assertEqual(fpfP.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfP.MaxInput, 32767 / 2 * 2);
  assertEqual(fpfN.MaxInput, 16383 * 2);

  // exact ratios
  Ratio16ToFixedPointFraction32(8, 2, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (long)0b10 * 0x4000 + 0b0000000000000000);
  assertEqual(fpfN.TheFraction, (long)0b10 * 0x4000 + 0b0000000000000000);
  assertEqual(fpfP.BitsToShift, 16 - 1 - 2);
  assertEqual(fpfN.BitsToShift, 16 - 1 - 2);
  assertEqual(fpfP.MaxInput, 32767 / 4 * 4);
  assertEqual(fpfN.MaxInput, 8191 * 4);

  Ratio16ToFixedPointFraction32(-12, 4, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((long)0b11 * 0x8000 + 0b0000000000000000));
  assertEqual(fpfN.TheFraction, -((long)0b11 * 0x8000 + 0b0000000000000000));
  assertEqual(fpfP.BitsToShift, 16 - 0 - 1);
  assertEqual(fpfN.BitsToShift, 16 - 0 - 1);
  assertEqual(fpfP.MaxInput, 32767 / 3 * 2);
  assertEqual(fpfN.MaxInput, 10922 * 2);

  Ratio16ToFixedPointFraction32(30, -5, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((long)0b11 * 0x4000 + 0b0000000000000000));
  assertEqual(fpfN.TheFraction, -((long)0b11 * 0x4000 + 0b0000000000000000));
  assertEqual(fpfP.BitsToShift, 16 - 1 - 2);
  assertEqual(fpfN.BitsToShift, 16 - 1 - 2);
  assertEqual(fpfP.MaxInput, 32767 / 6 * 4);
  assertEqual(fpfN.MaxInput, 5461 * 4);

  Ratio16ToFixedPointFraction32(-56, -7, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (long)0b10 * 0x2000 + 0b0000000000000000);
  assertEqual(fpfN.TheFraction, (long)0b10 * 0x2000 + 0b0000000000000000);
  assertEqual(fpfP.BitsToShift, 16 - 2 - 3);
  assertEqual(fpfN.BitsToShift, 16 - 2 - 3);
  assertEqual(fpfP.MaxInput, 32767 / 8 * 8);
  assertEqual(fpfN.MaxInput, 4095 * 8);

  // theoretical exact ratios
  Ratio16ToFixedPointFraction32(1, 3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (long)0b10 * 0x10000 + 0b1010101010101011);
  assertEqual(fpfN.TheFraction, (long)0b10 * 0x8000 + 0b101010101010101);
  assertEqual(fpfP.BitsToShift, 16 + 3);
  assertEqual(fpfN.BitsToShift, 16 + 3 - 1);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 3 / 8));
  assertEqual(fpfN.MaxInput, (int)((long)32767 * 3 / 8 * 2));
  assertEqual(fpfP.MaxInput, 12287);
  assertEqual(fpfN.MaxInput, 12287 * 2);

  Ratio16ToFixedPointFraction32(-1, 3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((long)0b10 * 0x10000 + 0b1010101010101011));
  assertEqual(fpfN.TheFraction, -((long)0b10 * 0x8000 + 0b101010101010101));
  assertEqual(fpfP.BitsToShift, 16 + 3);
  assertEqual(fpfN.BitsToShift, 16 + 3 - 1);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 3 / 8));
  assertEqual(fpfN.MaxInput, (int)((long)32767 * 3 / 8 * 2));
  assertEqual(fpfP.MaxInput, 12287);
  assertEqual(fpfN.MaxInput, 12287 * 2);

  Ratio16ToFixedPointFraction32(1, -3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((long)0b10 * 0x10000 + 0b1010101010101011));
  assertEqual(fpfN.TheFraction, -((long)0b10 * 0x8000 + 0b101010101010101));
  assertEqual(fpfP.BitsToShift, 16 + 3);
  assertEqual(fpfN.BitsToShift, 16 + 3 - 1);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 3 / 8));
  assertEqual(fpfN.MaxInput, (int)((long)32767 * 3 / 8) * 2);
  assertEqual(fpfP.MaxInput, 12287);
  assertEqual(fpfN.MaxInput, 12287 * 2);

  Ratio16ToFixedPointFraction32(-1, -3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (long)0b10 * 0x10000 + 0b1010101010101011);
  assertEqual(fpfN.TheFraction, (long)0b10 * 0x8000 + 0b101010101010101);
  assertEqual(fpfP.BitsToShift, 16 + 3);
  assertEqual(fpfN.BitsToShift, 16 + 3 - 1);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 3 / 8));
  assertEqual(fpfN.MaxInput, (int)((long)32767 * 3 / 8) * 2);
  assertEqual(fpfP.MaxInput, 12287);
  assertEqual(fpfN.MaxInput, 12287 * 2);

  Ratio16ToFixedPointFraction32(2, 3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (long)0b10 * 0x10000 + 0b1010101010101011);
  assertEqual(fpfN.TheFraction, (long)0b10 * 0x8000 + 0b101010101010101);
  assertEqual(fpfP.BitsToShift, 16 + 2);
  assertEqual(fpfN.BitsToShift, 16 + 2 - 1);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 3 / 8));
  assertEqual(fpfN.MaxInput, (int)((long)32767 * 3 / 8) * 2);
  assertEqual(fpfP.MaxInput, 12287);
  assertEqual(fpfN.MaxInput, 12287 * 2);

  Ratio16ToFixedPointFraction32(-2, 3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((long)0b10 * 0x10000 + 0b1010101010101011));
  assertEqual(fpfN.TheFraction, -((long)0b10 * 0x8000 + 0b101010101010101));
  assertEqual(fpfP.BitsToShift, 16 + 2);
  assertEqual(fpfN.BitsToShift, 16 + 2 - 1);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 3 / 8));
  assertEqual(fpfN.MaxInput, (int)((long)32767 * 3 / 8) * 2);
  assertEqual(fpfP.MaxInput, 12287);
  assertEqual(fpfN.MaxInput, 12287 * 2);

  Ratio16ToFixedPointFraction32(2, -3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((long)0b10 * 0x10000 + 0b1010101010101011));
  assertEqual(fpfN.TheFraction, -((long)0b10 * 0x8000 + 0b101010101010101));
  assertEqual(fpfP.BitsToShift, 16 + 2);
  assertEqual(fpfN.BitsToShift, 16 + 2 - 1);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 3 / 8));
  assertEqual(fpfN.MaxInput, (int)((long)32767 * 3 / 8) * 2);
  assertEqual(fpfP.MaxInput, 12287);
  assertEqual(fpfN.MaxInput, 12287 * 2);

  Ratio16ToFixedPointFraction32(-2, -3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (long)0b10 * 0x10000 + 0b1010101010101011);
  assertEqual(fpfN.TheFraction, (long)0b10 * 0x8000 + 0b101010101010101);
  assertEqual(fpfP.BitsToShift, 16 + 2);
  assertEqual(fpfN.BitsToShift, 16 + 2 - 1);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 3 / 8));
  assertEqual(fpfN.MaxInput, (int)((long)32767 * 3 / 8) * 2);
  assertEqual(fpfP.MaxInput, 12287);
  assertEqual(fpfN.MaxInput, 12287 * 2);

  // binary fraction
  Ratio16ToFixedPointFraction32(1, 2, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (long)0b10 * 0x8000 + 0b0000000000000000);
  assertEqual(fpfN.TheFraction, (long)0b10 * 0x8000 + 0b0000000000000000);
  assertEqual(fpfP.BitsToShift, 16 + 2 - 1);
  assertEqual(fpfN.BitsToShift, 16 + 2 - 1);
  assertEqual(fpfP.MaxInput, 32767 / 2 * 2);
  assertEqual(fpfN.MaxInput, 16383 * 2);

  Ratio16ToFixedPointFraction32(-3, 4, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((long)0b11 * 0x8000 + 0b0000000000000000));
  assertEqual(fpfN.TheFraction, -((long)0b11 * 0x8000 + 0b0000000000000000));
  assertEqual(fpfP.BitsToShift, 16 + 2 - 1);
  assertEqual(fpfN.BitsToShift, 16 + 2 - 1);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 2 / 6) * 2);
  assertEqual(fpfN.MaxInput, 10922 * 2);

  Ratio16ToFixedPointFraction32(3, -8, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((long)0b11 * 0x8000 + 0b0000000000000000));
  assertEqual(fpfN.TheFraction, -((long)0b11 * 0x8000 + 0b0000000000000000));
  assertEqual(fpfP.BitsToShift, 16 + 3 - 1);
  assertEqual(fpfN.BitsToShift, 16 + 3 - 1);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 2 / 6) * 2);
  assertEqual(fpfN.MaxInput, 10922 * 2);

  Ratio16ToFixedPointFraction32(-3, -16, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (long)0b11 * 0x8000 + 0b0000000000000000);
  assertEqual(fpfN.TheFraction, (long)0b11 * 0x8000 + 0b0000000000000000);
  assertEqual(fpfP.BitsToShift, 16 + 4 - 1);
  assertEqual(fpfN.BitsToShift, 16 + 4 - 1);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 2 / 6) * 2);
  assertEqual(fpfN.MaxInput, (int)((long)32767 * 2 / 6) * 2);
  assertEqual(fpfP.MaxInput, 10922 * 2);
  assertEqual(fpfN.MaxInput, 10922 * 2);

  // binary vulgar fraction
  Ratio16ToFixedPointFraction32(3, 2, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (long)0b11 * 0x8000 + 0b0000000000000000);
  assertEqual(fpfN.TheFraction, (long)0b11 * 0x8000 + 0b0000000000000000);
  assertEqual(fpfP.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 2 / 6) * 2);
  assertEqual(fpfN.MaxInput, 10922 * 2);

  Ratio16ToFixedPointFraction32(-7, 4, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((long)0b11 * 0x8000 + 0b100000000000000));
  assertEqual(fpfN.TheFraction, -((long)0b11 * 0x8000 + 0b100000000000000));
  assertEqual(fpfP.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 4 / 14) * 2);
  assertEqual(fpfN.MaxInput, 9362 * 2);

  Ratio16ToFixedPointFraction32(11, -8, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((long)0b10 * 0x8000 + 0b110000000000000));
  assertEqual(fpfN.TheFraction, -((long)0b10 * 0x8000 + 0b110000000000000));
  assertEqual(fpfP.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 8 / 22) * 2);
  assertEqual(fpfN.MaxInput, 11915 * 2);

  Ratio16ToFixedPointFraction32(-19, -16, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (long)0b10 * 0x8000 + 0b011000000000000);
  assertEqual(fpfN.TheFraction, (long)0b10 * 0x8000 + 0b011000000000000);
  assertEqual(fpfP.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 16 / 38) * 2);
  assertEqual(fpfN.MaxInput, 13796 * 2);

  // inexact fraction
  Ratio16ToFixedPointFraction32(5, 9, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (long)0b10 * 0x8000 + 0b001110001110010);
  assertEqual(fpfN.TheFraction, (long)0b10 * 0x10000 + 0b0011100011100011);
  assertEqual(fpfP.BitsToShift, 16 + 2 - 1);
  assertEqual(fpfN.BitsToShift, 16 + 2);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 9 / 20) * 2);
  assertEqual(fpfN.MaxInput, (int)((long)32767 * 9 / 20));
  assertEqual(fpfP.MaxInput, 14745 * 2);
  assertEqual(fpfN.MaxInput, 14745);

  Ratio16ToFixedPointFraction32(-5, 9, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((long)0b10 * 0x8000 + 0b001110001110010));
  assertEqual(fpfN.TheFraction, -((long)0b10 * 0x10000 + 0b0011100011100011));
  assertEqual(fpfP.BitsToShift, 16 + 2 - 1);
  assertEqual(fpfN.BitsToShift, 16 + 2);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 9 / 20) * 2);
  assertEqual(fpfN.MaxInput, (int)((long)32767 * 9 / 20));
  assertEqual(fpfP.MaxInput, 14745 * 2);
  assertEqual(fpfN.MaxInput, 14745);

  Ratio16ToFixedPointFraction32(5, -9, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((long)0b10 * 0x8000 + 0b001110001110010));
  assertEqual(fpfN.TheFraction, -((long)0b10 * 0x10000 + 0b0011100011100011));
  assertEqual(fpfP.BitsToShift, 16 + 2 - 1);
  assertEqual(fpfN.BitsToShift, 16 + 2);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 9 / 20) * 2);
  assertEqual(fpfN.MaxInput, (int)((long)32767 * 9 / 20));
  assertEqual(fpfP.MaxInput, 14745 * 2);
  assertEqual(fpfN.MaxInput, 14745);

  Ratio16ToFixedPointFraction32(-5, -9, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (long)0b10 * 0x8000 + 0b001110001110010);
  assertEqual(fpfN.TheFraction, (long)0b10 * 0x10000 + 0b0011100011100011);
  assertEqual(fpfP.BitsToShift, 16 + 2 - 1);
  assertEqual(fpfN.BitsToShift, 16 + 2);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 9 / 20) * 2);
  assertEqual(fpfN.MaxInput, (int)((long)32767 * 9 / 20));
  assertEqual(fpfP.MaxInput, 14745 * 2);
  assertEqual(fpfN.MaxInput, 14745);

  // inexact vulgar fraction
  Ratio16ToFixedPointFraction32(9, 5, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (long)0b11 * 0x8000 + 0b100110011001101);
  assertEqual(fpfN.TheFraction, (long)0b11 * 0x10000 + 0b1001100110011001);
  assertEqual(fpfP.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 16 + 1);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 5 / 18 + 1) * 2);  // oops calc not quite the same
  assertEqual(fpfN.MaxInput, (int)((long)32767 * 5 / 18 + 1));  // oops calc not quite the same
  assertEqual(fpfP.MaxInput, 9102 * 2);
  assertEqual(fpfN.MaxInput, 9102);

  Ratio16ToFixedPointFraction32(-9, 5, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((long)0b11 * 0x8000 + 0b100110011001101));
  assertEqual(fpfN.TheFraction, -((long)0b11 * 0x10000 + 0b1001100110011001));
  assertEqual(fpfP.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 16 + 1);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 5 / 18 + 1) * 2);  // oops calc not quite the same
  assertEqual(fpfN.MaxInput, (int)((long)32767 * 5 / 18 + 1));  // oops calc not quite the same
  assertEqual(fpfP.MaxInput, 9102 * 2);
  assertEqual(fpfN.MaxInput, 9102);

  Ratio16ToFixedPointFraction32(9, -5, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, -((long)0b11 * 0x8000 + 0b100110011001101));
  assertEqual(fpfN.TheFraction, -((long)0b11 * 0x10000 + 0b1001100110011001));
  assertEqual(fpfP.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 16 + 1);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 5 / 18 + 1) * 2);  // oops calc not quite the same
  assertEqual(fpfN.MaxInput, (int)((long)32767 * 5 / 18 + 1));  // oops calc not quite the same
  assertEqual(fpfP.MaxInput, 9102 * 2);
  assertEqual(fpfN.MaxInput, 9102);

  Ratio16ToFixedPointFraction32(-9, -5, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); pPrintDebug->flush(); }
  assertEqual(fpfP.TheFraction, (long)0b11 * 0x8000 + 0b100110011001101);
  assertEqual(fpfN.TheFraction, (long)0b11 * 0x10000 + 0b1001100110011001);
  assertEqual(fpfP.BitsToShift, 16 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 16 + 1);
  assertEqual(fpfP.MaxInput, (int)((long)32767 * 5 / 18 + 1) * 2);  // oops calc not quite the same
  assertEqual(fpfN.MaxInput, (int)((long)32767 * 5 / 18 + 1));  // oops calc not quite the same
  assertEqual(fpfP.MaxInput, 9102 * 2);
  assertEqual(fpfN.MaxInput, 9102);
}

void setup() {
  delay(1000); // wait for stability on some boards to prevent garbage Serial
  Serial.begin(115200); // The baudrate of Serial monitor is set
  while(!Serial); // for the Arduino Leonardo/Micro only
  Serial.println(F(__DATE__ " @ " __TIME__));
  Serial.println(F(__FILE__));
}

void loop() {
  aunit::TestRunner::run();
}
