//
//    FILE: fastMapIntegerArithmeticTest.ino
//  AUTHOR: Brewmanz (Bryan White)
// VERSION: 0.1.0
// PURPOSE: Test of FastMapInt helper functions
//    DATE: 2020-09-06
//     URL: https://github.com/RobTillaart/FastMap

//#include <AUnitVerbose.h> // too much for Nano!
#include <AUnit.h>
#include <FastMap.h>

volatile int i, j;

test(T1136MultiplyByFixedPointFraction_5DivM9_Neg) {
  long FPF;
  RatioToFixedPointFraction(5, -9, nullptr, &FPF);
  assertEqual(MultiplyByFixedPointFraction(0, FPF), 0);

  assertEqual(MultiplyByFixedPointFraction(-1, FPF), 1);
  assertEqual(MultiplyByFixedPointFraction(-2, FPF), 2);
  assertEqual(MultiplyByFixedPointFraction(-3, FPF), 2);
  assertEqual(MultiplyByFixedPointFraction(-4, FPF), 3);
  assertEqual(MultiplyByFixedPointFraction(-5, FPF), 3);
  assertEqual(MultiplyByFixedPointFraction(-6, FPF), 4);
  assertEqual(MultiplyByFixedPointFraction(-7, FPF), 4);
  assertEqual(MultiplyByFixedPointFraction(-8, FPF), 5);
  assertEqual(MultiplyByFixedPointFraction(-9, FPF), 5);

  assertEqual(MultiplyByFixedPointFraction(-10, FPF), 6);
  assertEqual(MultiplyByFixedPointFraction(-100, FPF), 56);
  assertEqual(MultiplyByFixedPointFraction(-1000, FPF), 556);

  assertEqual(MultiplyByFixedPointFraction(-2000, FPF), 1112);
  assertEqual(MultiplyByFixedPointFraction(-3000, FPF), 1667);
  assertEqual(MultiplyByFixedPointFraction(-4000, FPF), 2223);
  assertEqual(MultiplyByFixedPointFraction(-5000, FPF), 2778);
  assertEqual(MultiplyByFixedPointFraction(-6000, FPF), 3334);
  assertEqual(MultiplyByFixedPointFraction(-7000, FPF), 3889);
  assertEqual(MultiplyByFixedPointFraction(-8000, FPF), 4445);
  assertEqual(MultiplyByFixedPointFraction(-9000, FPF), 5000);
}
test(T1135MultiplyByFixedPointFraction_5DivM9_Pos) {
  long FPF;
  RatioToFixedPointFraction(5, -9, &FPF, nullptr);
  assertEqual(MultiplyByFixedPointFraction(0, FPF), 0);

  assertEqual(MultiplyByFixedPointFraction(1, FPF), 0);
  assertEqual(MultiplyByFixedPointFraction(2, FPF), -1);
  assertEqual(MultiplyByFixedPointFraction(3, FPF), -1);
  assertEqual(MultiplyByFixedPointFraction(4, FPF), -2);
  assertEqual(MultiplyByFixedPointFraction(5, FPF), -2);
  assertEqual(MultiplyByFixedPointFraction(6, FPF), -3);
  assertEqual(MultiplyByFixedPointFraction(7, FPF), -3);
  assertEqual(MultiplyByFixedPointFraction(8, FPF), -4);
  assertEqual(MultiplyByFixedPointFraction(9, FPF), -5);

  assertEqual(MultiplyByFixedPointFraction(10, FPF), -5);
  assertEqual(MultiplyByFixedPointFraction(100, FPF), -55);
  assertEqual(MultiplyByFixedPointFraction(1000, FPF), -555);

  assertEqual(MultiplyByFixedPointFraction(2000, FPF), -1111);
  assertEqual(MultiplyByFixedPointFraction(3000, FPF), -1666);
  assertEqual(MultiplyByFixedPointFraction(4000, FPF), -2222);
  assertEqual(MultiplyByFixedPointFraction(5000, FPF), -2777);
  assertEqual(MultiplyByFixedPointFraction(6000, FPF), -3333);
  assertEqual(MultiplyByFixedPointFraction(7000, FPF), -3888);
  assertEqual(MultiplyByFixedPointFraction(8000, FPF), -4444);
  assertEqual(MultiplyByFixedPointFraction(9000, FPF), -5000);
}
test(T1131MultiplyByFixedPointFraction_5Div9_Neg) {
  long FPF;
  RatioToFixedPointFraction(5, 9, nullptr, &FPF);
  assertEqual(MultiplyByFixedPointFraction(0, FPF), 0);

  assertEqual(MultiplyByFixedPointFraction(-1, FPF), -1);
  assertEqual(MultiplyByFixedPointFraction(-2, FPF), -2);
  assertEqual(MultiplyByFixedPointFraction(-3, FPF), -2);
  assertEqual(MultiplyByFixedPointFraction(-4, FPF), -3);
  assertEqual(MultiplyByFixedPointFraction(-5, FPF), -3);
  assertEqual(MultiplyByFixedPointFraction(-6, FPF), -4);
  assertEqual(MultiplyByFixedPointFraction(-7, FPF), -4);
  assertEqual(MultiplyByFixedPointFraction(-8, FPF), -5);
  assertEqual(MultiplyByFixedPointFraction(-9, FPF), -5);

  assertEqual(MultiplyByFixedPointFraction(-10, FPF), -6);
  assertEqual(MultiplyByFixedPointFraction(-100, FPF), -56);
  assertEqual(MultiplyByFixedPointFraction(-1000, FPF), -556);

  assertEqual(MultiplyByFixedPointFraction(-2000, FPF), -1112);
  assertEqual(MultiplyByFixedPointFraction(-3000, FPF), -1667);
  assertEqual(MultiplyByFixedPointFraction(-4000, FPF), -2223);
  assertEqual(MultiplyByFixedPointFraction(-5000, FPF), -2778);
  assertEqual(MultiplyByFixedPointFraction(-6000, FPF), -3334);
  assertEqual(MultiplyByFixedPointFraction(-7000, FPF), -3889);
  assertEqual(MultiplyByFixedPointFraction(-8000, FPF), -4445);
  assertEqual(MultiplyByFixedPointFraction(-9000, FPF), -5000);
}
test(T1130MultiplyByFixedPointFraction_5Div9_Pos) {
  long FPF;
  RatioToFixedPointFraction(5, 9, &FPF, nullptr);
  assertEqual(MultiplyByFixedPointFraction(0, FPF), 0);

  assertEqual(MultiplyByFixedPointFraction(1, FPF), 0);
  assertEqual(MultiplyByFixedPointFraction(2, FPF), 1);
  assertEqual(MultiplyByFixedPointFraction(3, FPF), 1);
  assertEqual(MultiplyByFixedPointFraction(4, FPF), 2);
  assertEqual(MultiplyByFixedPointFraction(5, FPF), 2);
  assertEqual(MultiplyByFixedPointFraction(6, FPF), 3);
  assertEqual(MultiplyByFixedPointFraction(7, FPF), 3);
  assertEqual(MultiplyByFixedPointFraction(8, FPF), 4);
  assertEqual(MultiplyByFixedPointFraction(9, FPF), 5);

  assertEqual(MultiplyByFixedPointFraction(10, FPF), 5);
  assertEqual(MultiplyByFixedPointFraction(100, FPF), 55);
  assertEqual(MultiplyByFixedPointFraction(1000, FPF), 555);

  assertEqual(MultiplyByFixedPointFraction(2000, FPF), 1111);
  assertEqual(MultiplyByFixedPointFraction(3000, FPF), 1666);
  assertEqual(MultiplyByFixedPointFraction(4000, FPF), 2222);
  assertEqual(MultiplyByFixedPointFraction(5000, FPF), 2777);
  assertEqual(MultiplyByFixedPointFraction(6000, FPF), 3333);
  assertEqual(MultiplyByFixedPointFraction(7000, FPF), 3888);
  assertEqual(MultiplyByFixedPointFraction(8000, FPF), 4444);
  assertEqual(MultiplyByFixedPointFraction(9000, FPF), 5000);
}

test(T1126MultiplyByFixedPointFraction_1DivM3_Neg) {
  long FPF;
  RatioToFixedPointFraction(1, -3, nullptr, &FPF);
  assertEqual(MultiplyByFixedPointFraction(0, FPF), 0);

  assertEqual(MultiplyByFixedPointFraction(-1, FPF), 1);
  assertEqual(MultiplyByFixedPointFraction(-2, FPF), 1);
  assertEqual(MultiplyByFixedPointFraction(-3, FPF), 1);
  assertEqual(MultiplyByFixedPointFraction(-4, FPF), 2);
  assertEqual(MultiplyByFixedPointFraction(-5, FPF), 2);
  assertEqual(MultiplyByFixedPointFraction(-6, FPF), 2);
  assertEqual(MultiplyByFixedPointFraction(-7, FPF), 3);
  assertEqual(MultiplyByFixedPointFraction(-8, FPF), 3);
  assertEqual(MultiplyByFixedPointFraction(-9, FPF), 3);

  assertEqual(MultiplyByFixedPointFraction(-10, FPF), 4);
  assertEqual(MultiplyByFixedPointFraction(-100, FPF), 34);
  assertEqual(MultiplyByFixedPointFraction(-1000, FPF), 334);

  assertEqual(MultiplyByFixedPointFraction(-2000, FPF), 667);
  assertEqual(MultiplyByFixedPointFraction(-3000, FPF), 1000);
  assertEqual(MultiplyByFixedPointFraction(-4000, FPF), 1334);
  assertEqual(MultiplyByFixedPointFraction(-5000, FPF), 1667);
  assertEqual(MultiplyByFixedPointFraction(-6000, FPF), 2000);
  assertEqual(MultiplyByFixedPointFraction(-7000, FPF), 2334);
  assertEqual(MultiplyByFixedPointFraction(-8000, FPF), 2667);
  assertEqual(MultiplyByFixedPointFraction(-9000, FPF), 3000);
}
test(T1125MultiplyByFixedPointFraction_1DivM3_Pos) {
  long FPF;
  RatioToFixedPointFraction(1, -3, &FPF, nullptr);
  assertEqual(MultiplyByFixedPointFraction(0, FPF), 0);

  assertEqual(MultiplyByFixedPointFraction(1, FPF), 0);
  assertEqual(MultiplyByFixedPointFraction(2, FPF), 0);
  assertEqual(MultiplyByFixedPointFraction(3, FPF), -1);
  assertEqual(MultiplyByFixedPointFraction(4, FPF), -1);
  assertEqual(MultiplyByFixedPointFraction(5, FPF), -1);
  assertEqual(MultiplyByFixedPointFraction(6, FPF), -2);
  assertEqual(MultiplyByFixedPointFraction(7, FPF), -2);
  assertEqual(MultiplyByFixedPointFraction(8, FPF), -2);
  assertEqual(MultiplyByFixedPointFraction(9, FPF), -3);

  assertEqual(MultiplyByFixedPointFraction(10, FPF), -3);
  assertEqual(MultiplyByFixedPointFraction(100, FPF), -33);
  assertEqual(MultiplyByFixedPointFraction(1000, FPF), -333);

  assertEqual(MultiplyByFixedPointFraction(2000, FPF), -666);
  assertEqual(MultiplyByFixedPointFraction(3000, FPF), -1000);
  assertEqual(MultiplyByFixedPointFraction(4000, FPF), -1333);
  assertEqual(MultiplyByFixedPointFraction(5000, FPF), -1666);
  assertEqual(MultiplyByFixedPointFraction(6000, FPF), -2000);
  assertEqual(MultiplyByFixedPointFraction(7000, FPF), -2333);
  assertEqual(MultiplyByFixedPointFraction(8000, FPF), -2666);
  assertEqual(MultiplyByFixedPointFraction(9000, FPF), -3000);
}
test(T1121MultiplyByFixedPointFraction_1Div3_Neg) {
  long FPF;
  RatioToFixedPointFraction(1, 3, nullptr, &FPF);
  assertEqual(MultiplyByFixedPointFraction(0, FPF), 0);

  assertEqual(MultiplyByFixedPointFraction(-1, FPF), -1);
  assertEqual(MultiplyByFixedPointFraction(-2, FPF), -1);
  assertEqual(MultiplyByFixedPointFraction(-3, FPF), -1);
  assertEqual(MultiplyByFixedPointFraction(-4, FPF), -2);
  assertEqual(MultiplyByFixedPointFraction(-5, FPF), -2);
  assertEqual(MultiplyByFixedPointFraction(-6, FPF), -2);
  assertEqual(MultiplyByFixedPointFraction(-7, FPF), -3);
  assertEqual(MultiplyByFixedPointFraction(-8, FPF), -3);
  assertEqual(MultiplyByFixedPointFraction(-9, FPF), -3);

  assertEqual(MultiplyByFixedPointFraction(-10, FPF), -4);
  assertEqual(MultiplyByFixedPointFraction(-100, FPF), -34);
  assertEqual(MultiplyByFixedPointFraction(-1000, FPF), -334);

  assertEqual(MultiplyByFixedPointFraction(-2000, FPF), -667);
  assertEqual(MultiplyByFixedPointFraction(-3000, FPF), -1000);
  assertEqual(MultiplyByFixedPointFraction(-4000, FPF), -1334);
  assertEqual(MultiplyByFixedPointFraction(-5000, FPF), -1667);
  assertEqual(MultiplyByFixedPointFraction(-6000, FPF), -2000);
  assertEqual(MultiplyByFixedPointFraction(-7000, FPF), -2334);
  assertEqual(MultiplyByFixedPointFraction(-8000, FPF), -2667);
  assertEqual(MultiplyByFixedPointFraction(-9000, FPF), -3000);
}
test(T1120MultiplyByFixedPointFraction_1Div3_Pos) {
  long FPF;
  RatioToFixedPointFraction(1, 3, &FPF, nullptr);
  assertEqual(MultiplyByFixedPointFraction(0, FPF), 0);

  assertEqual(MultiplyByFixedPointFraction(1, FPF), 0);
  assertEqual(MultiplyByFixedPointFraction(2, FPF), 0);
  assertEqual(MultiplyByFixedPointFraction(3, FPF), 1);
  assertEqual(MultiplyByFixedPointFraction(4, FPF), 1);
  assertEqual(MultiplyByFixedPointFraction(5, FPF), 1);
  assertEqual(MultiplyByFixedPointFraction(6, FPF), 2);
  assertEqual(MultiplyByFixedPointFraction(7, FPF), 2);
  assertEqual(MultiplyByFixedPointFraction(8, FPF), 2);
  assertEqual(MultiplyByFixedPointFraction(9, FPF), 3);

  assertEqual(MultiplyByFixedPointFraction(10, FPF), 3);
  assertEqual(MultiplyByFixedPointFraction(100, FPF), 33);
  assertEqual(MultiplyByFixedPointFraction(1000, FPF), 333);

  assertEqual(MultiplyByFixedPointFraction(2000, FPF), 666);
  assertEqual(MultiplyByFixedPointFraction(3000, FPF), 1000);
  assertEqual(MultiplyByFixedPointFraction(4000, FPF), 1333);
  assertEqual(MultiplyByFixedPointFraction(5000, FPF), 1666);
  assertEqual(MultiplyByFixedPointFraction(6000, FPF), 2000);
  assertEqual(MultiplyByFixedPointFraction(7000, FPF), 2333);
  assertEqual(MultiplyByFixedPointFraction(8000, FPF), 2666);
  assertEqual(MultiplyByFixedPointFraction(9000, FPF), 3000);
}

test(T1116MultiplyByFixedPointFraction_1DivM4_Neg) {
  long FPF;
  RatioToFixedPointFraction(1, -4, nullptr, &FPF);
  assertEqual(MultiplyByFixedPointFraction(0, FPF), 0);

  assertEqual(MultiplyByFixedPointFraction(-1, FPF), 1);
  assertEqual(MultiplyByFixedPointFraction(-2, FPF), 1);
  assertEqual(MultiplyByFixedPointFraction(-3, FPF), 1);
  assertEqual(MultiplyByFixedPointFraction(-4, FPF), 1);
  assertEqual(MultiplyByFixedPointFraction(-5, FPF), 2);
  assertEqual(MultiplyByFixedPointFraction(-6, FPF), 2);
  assertEqual(MultiplyByFixedPointFraction(-7, FPF), 2);
  assertEqual(MultiplyByFixedPointFraction(-8, FPF), 2);
  assertEqual(MultiplyByFixedPointFraction(-9, FPF), 3);

  assertEqual(MultiplyByFixedPointFraction(-10, FPF), 3);
  assertEqual(MultiplyByFixedPointFraction(-100, FPF), 25);
  assertEqual(MultiplyByFixedPointFraction(-1000, FPF), 250);

  assertEqual(MultiplyByFixedPointFraction(-2000, FPF), 500);
  assertEqual(MultiplyByFixedPointFraction(-3000, FPF), 750);
  assertEqual(MultiplyByFixedPointFraction(-4000, FPF), 1000);
  assertEqual(MultiplyByFixedPointFraction(-5000, FPF), 1250);
  assertEqual(MultiplyByFixedPointFraction(-6000, FPF), 1500);
  assertEqual(MultiplyByFixedPointFraction(-7000, FPF), 1750);
  assertEqual(MultiplyByFixedPointFraction(-8000, FPF), 2000);
  assertEqual(MultiplyByFixedPointFraction(-9000, FPF), 2250);
}
test(T1115MultiplyByFixedPointFraction_1DivM4_Pos) {
  long FPF;
  RatioToFixedPointFraction(1, -4, &FPF, nullptr);
  assertEqual(MultiplyByFixedPointFraction(0, FPF), 0);

  assertEqual(MultiplyByFixedPointFraction(1, FPF), 0);
  assertEqual(MultiplyByFixedPointFraction(2, FPF), 0);
  assertEqual(MultiplyByFixedPointFraction(3, FPF), 0);
  assertEqual(MultiplyByFixedPointFraction(4, FPF), -1);
  assertEqual(MultiplyByFixedPointFraction(5, FPF), -1);
  assertEqual(MultiplyByFixedPointFraction(6, FPF), -1);
  assertEqual(MultiplyByFixedPointFraction(7, FPF), -1);
  assertEqual(MultiplyByFixedPointFraction(8, FPF), -2);
  assertEqual(MultiplyByFixedPointFraction(9, FPF), -2);

  assertEqual(MultiplyByFixedPointFraction(10, FPF), -2);
  assertEqual(MultiplyByFixedPointFraction(100, FPF), -25);
  assertEqual(MultiplyByFixedPointFraction(1000, FPF), -250);

  assertEqual(MultiplyByFixedPointFraction(2000, FPF), -500);
  assertEqual(MultiplyByFixedPointFraction(3000, FPF), -750);
  assertEqual(MultiplyByFixedPointFraction(4000, FPF), -1000);
  assertEqual(MultiplyByFixedPointFraction(5000, FPF), -1250);
  assertEqual(MultiplyByFixedPointFraction(6000, FPF), -1500);
  assertEqual(MultiplyByFixedPointFraction(7000, FPF), -1750);
  assertEqual(MultiplyByFixedPointFraction(8000, FPF), -2000);
  assertEqual(MultiplyByFixedPointFraction(9000, FPF), -2250);
}
test(T1111MultiplyByFixedPointFraction_1Div4_Neg) {
  long FPF;
  RatioToFixedPointFraction(1, 4, nullptr, &FPF);
  assertEqual(MultiplyByFixedPointFraction(0, FPF), 0);

  assertEqual(MultiplyByFixedPointFraction(-1, FPF), -1);
  assertEqual(MultiplyByFixedPointFraction(-2, FPF), -1);
  assertEqual(MultiplyByFixedPointFraction(-3, FPF), -1);
  assertEqual(MultiplyByFixedPointFraction(-4, FPF), -1);
  assertEqual(MultiplyByFixedPointFraction(-5, FPF), -2);
  assertEqual(MultiplyByFixedPointFraction(-6, FPF), -2);
  assertEqual(MultiplyByFixedPointFraction(-7, FPF), -2);
  assertEqual(MultiplyByFixedPointFraction(-8, FPF), -2);
  assertEqual(MultiplyByFixedPointFraction(-9, FPF), -3);

  assertEqual(MultiplyByFixedPointFraction(-10, FPF), -3);
  assertEqual(MultiplyByFixedPointFraction(-100, FPF), -25);
  assertEqual(MultiplyByFixedPointFraction(-1000, FPF), -250);

  assertEqual(MultiplyByFixedPointFraction(-2000, FPF), -500);
  assertEqual(MultiplyByFixedPointFraction(-3000, FPF), -750);
  assertEqual(MultiplyByFixedPointFraction(-4000, FPF), -1000);
  assertEqual(MultiplyByFixedPointFraction(-5000, FPF), -1250);
  assertEqual(MultiplyByFixedPointFraction(-6000, FPF), -1500);
  assertEqual(MultiplyByFixedPointFraction(-7000, FPF), -1750);
  assertEqual(MultiplyByFixedPointFraction(-8000, FPF), -2000);
  assertEqual(MultiplyByFixedPointFraction(-9000, FPF), -2250);
}
test(T1110MultiplyByFixedPointFraction_1Div4_Pos) {
  long FPF;
  RatioToFixedPointFraction(1, 4, &FPF, nullptr);
  assertEqual(MultiplyByFixedPointFraction(0, FPF), 0);

  assertEqual(MultiplyByFixedPointFraction(1, FPF), 0);
  assertEqual(MultiplyByFixedPointFraction(2, FPF), 0);
  assertEqual(MultiplyByFixedPointFraction(3, FPF), 0);
  assertEqual(MultiplyByFixedPointFraction(4, FPF), 1);
  assertEqual(MultiplyByFixedPointFraction(5, FPF), 1);
  assertEqual(MultiplyByFixedPointFraction(6, FPF), 1);
  assertEqual(MultiplyByFixedPointFraction(7, FPF), 1);
  assertEqual(MultiplyByFixedPointFraction(8, FPF), 2);
  assertEqual(MultiplyByFixedPointFraction(9, FPF), 2);

  assertEqual(MultiplyByFixedPointFraction(10, FPF), 2);
  assertEqual(MultiplyByFixedPointFraction(100, FPF), 25);
  assertEqual(MultiplyByFixedPointFraction(1000, FPF), 250);

  assertEqual(MultiplyByFixedPointFraction(2000, FPF), 500);
  assertEqual(MultiplyByFixedPointFraction(3000, FPF), 750);
  assertEqual(MultiplyByFixedPointFraction(4000, FPF), 1000);
  assertEqual(MultiplyByFixedPointFraction(5000, FPF), 1250);
  assertEqual(MultiplyByFixedPointFraction(6000, FPF), 1500);
  assertEqual(MultiplyByFixedPointFraction(7000, FPF), 1750);
  assertEqual(MultiplyByFixedPointFraction(8000, FPF), 2000);
  assertEqual(MultiplyByFixedPointFraction(9000, FPF), 2250);
}

test(T1100RatioToFixedPointFraction) {
  long fpfP, fpfN;

  // handling of 0
  fpfP = fpfN = -2468; RatioToFixedPointFraction(0, 0, &fpfP, &fpfN);
  assertEqual(fpfP, (long)0 * 0x10000 + 0x0000);
  assertEqual(fpfN, (long)0 * 0x10000 + 0x0000);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(0, 8, &fpfP, &fpfN);
  assertEqual(fpfP, (long)0 * 0x10000 + 0x0000);
  assertEqual(fpfN, (long)0 * 0x10000 + 0x0000);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(8, 0, &fpfP, &fpfN);
  assertEqual(fpfP, (long)0 * 0x10000 + 0x0000);
  assertEqual(fpfN, (long)0 * 0x10000 + 0x0000);

  // equal ratios
  fpfP = fpfN = -2468; RatioToFixedPointFraction(1, 1, &fpfP, &fpfN);
  assertEqual(fpfP, (long)1 * 0x10000 + 0x0000);
  assertEqual(fpfN, (long)1 * 0x10000 + 0x0000);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(12, 12, &fpfP, &fpfN);
  assertEqual(fpfP, (long)1 * 0x10000 + 0x0000);
  assertEqual(fpfN, (long)1 * 0x10000 + 0x0000);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(-2, 2, &fpfP, &fpfN);
  assertEqual(fpfP, (long)-1 * 0x10000 + 0x0000);
  assertEqual(fpfN, (long)-1 * 0x10000 + 0x0000);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(3, -3, &fpfP, &fpfN);
  assertEqual(fpfP, (long)-1 * 0x10000 + 0x0000);
  assertEqual(fpfN, (long)-1 * 0x10000 + 0x0000);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(-4, -4, &fpfP, &fpfN);
  assertEqual(fpfP, (long)1 * 0x10000 + 0x0000);
  assertEqual(fpfN, (long)1 * 0x10000 + 0x0000);

  // exact ratios
  fpfP = fpfN = -2468; RatioToFixedPointFraction(8, 2, &fpfP, &fpfN);
  assertEqual(fpfP, (long)4 * 0x10000 + 0x0000);
  assertEqual(fpfN, (long)4 * 0x10000 + 0x0000);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(-12, 4, &fpfP, &fpfN);
  assertEqual(fpfP, (long)-3 * 0x10000 + 0x0000);
  assertEqual(fpfN, (long)-3 * 0x10000 + 0x0000);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(30, -5, &fpfP, &fpfN);
  assertEqual(fpfP, (long)-6 * 0x10000 + 0x0000);
  assertEqual(fpfN, (long)-6 * 0x10000 + 0x0000);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(-56, -7, &fpfP, &fpfN);
  assertEqual(fpfP, (long)8 * 0x10000 + 0x0000);
  assertEqual(fpfN, (long)8 * 0x10000 + 0x0000);

  // theoretical exact ratios
  fpfP = fpfN = -2468; RatioToFixedPointFraction(1, 3, &fpfP, &fpfN);
  assertEqual(fpfP, (long)0 * 0x10000 + 0x5556);
  assertEqual(fpfN, (long)0 * 0x10000 + 0x5555);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(-1, 3, &fpfP, &fpfN);
  assertEqual(fpfP, (long)-1 * 0x10000 + 0xAAAA);
  assertEqual(fpfN, (long)-1 * 0x10000 + 0xAAAB);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(1, -3, &fpfP, &fpfN);
  assertEqual(fpfP, (long)-1 * 0x10000 + 0xAAAA);
  assertEqual(fpfN, (long)-1 * 0x10000 + 0xAAAB);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(-1, -3, &fpfP, &fpfN);
  assertEqual(fpfP, (long)0 * 0x10000 + 0x5556);
  assertEqual(fpfN, (long)0 * 0x10000 + 0x5555);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(2, 3, &fpfP, &fpfN);
  assertEqual(fpfP, (long)0 * 0x10000 + 0xAAAB);
  assertEqual(fpfN, (long)0 * 0x10000 + 0xAAAA);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(-2, 3, &fpfP, &fpfN);
  assertEqual(fpfP, (long)-1 * 0x10000 + 0x5555);
  assertEqual(fpfN, (long)-1 * 0x10000 + 0x5556);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(2, -3, &fpfP, &fpfN);
  assertEqual(fpfP, (long)-1 * 0x10000 + 0x5555);
  assertEqual(fpfN, (long)-1 * 0x10000 + 0x5556);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(-2, -3, &fpfP, &fpfN);
  assertEqual(fpfP, (long)0 * 0x10000 + 0xAAAB);
  assertEqual(fpfN, (long)0 * 0x10000 + 0xAAAA);

  // binary fraction
  fpfP = fpfN = -2468; RatioToFixedPointFraction(1, 2, &fpfP, &fpfN);
  assertEqual(fpfP, (long)0 * 0x10000 + 0x8000);
  assertEqual(fpfN, (long)0 * 0x10000 + 0x8000);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(-3, 4, &fpfP, &fpfN);
  assertEqual(fpfP, (long)-1 * 0x10000 + 0x4000);
  assertEqual(fpfN, (long)-1 * 0x10000 + 0x4000);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(3, -8, &fpfP, &fpfN);
  assertEqual(fpfP, (long)-1 * 0x10000 + 0xA000);
  assertEqual(fpfN, (long)-1 * 0x10000 + 0xA000);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(-3, -16, &fpfP, &fpfN);
  assertEqual(fpfP, (long)0 * 0x10000 + 0x3000);
  assertEqual(fpfN, (long)0 * 0x10000 + 0x3000);

  // binary vulgar fraction
  fpfP = fpfN = -2468; RatioToFixedPointFraction(3, 2, &fpfP, &fpfN);
  assertEqual(fpfP, (long)1 * 0x10000 + 0x8000);
  assertEqual(fpfN, (long)1 * 0x10000 + 0x8000);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(-7, 4, &fpfP, &fpfN);
  assertEqual(fpfP, (long)-2 * 0x10000 + 0x4000);
  assertEqual(fpfN, (long)-2 * 0x10000 + 0x4000);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(11, -8, &fpfP, &fpfN);
  assertEqual(fpfP, (long)-2 * 0x10000 + 0xA000);
  assertEqual(fpfN, (long)-2 * 0x10000 + 0xA000);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(-19, -16, &fpfP, &fpfN);
  assertEqual(fpfP, (long)1 * 0x10000 + 0x3000);
  assertEqual(fpfN, (long)1 * 0x10000 + 0x3000);

  // inexact fraction
  fpfP = fpfN = -2468; RatioToFixedPointFraction(5, 9, &fpfP, &fpfN);
  assertEqual(fpfP, (long)0 * 0x10000 + 0x8E39);
  assertEqual(fpfN, (long)0 * 0x10000 + 0x8E38);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(-5, 9, &fpfP, &fpfN);
  assertEqual(fpfP, (long)-1 * 0x10000 + 0x71C7);
  assertEqual(fpfN, (long)-1 * 0x10000 + 0x71C8);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(5, -9, &fpfP, &fpfN);
  assertEqual(fpfP, (long)-1 * 0x10000 + 0x71C7);
  assertEqual(fpfN, (long)-1 * 0x10000 + 0x71C8);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(-5, -9, &fpfP, &fpfN);
  assertEqual(fpfP, (long)0 * 0x10000 + 0x8E39);
  assertEqual(fpfN, (long)0 * 0x10000 + 0x8E38);

  // inexact vulgar fraction
  fpfP = fpfN = -2468; RatioToFixedPointFraction(9, 5, &fpfP, &fpfN);
  assertEqual(fpfP, (long)1 * 0x10000 + 0xCCCD);
  assertEqual(fpfN, (long)1 * 0x10000 + 0xCCCC);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(-9, 5, &fpfP, &fpfN);
  assertEqual(fpfP, (long)-2 * 0x10000 + 0x3333);
  assertEqual(fpfN, (long)-2 * 0x10000 + 0x3334);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(9, -5, &fpfP, &fpfN);
  assertEqual(fpfP, (long)-2 * 0x10000 + 0x3333);
  assertEqual(fpfN, (long)-2 * 0x10000 + 0x3334);

  fpfP = fpfN = -2468; RatioToFixedPointFraction(-9, -5, &fpfP, &fpfN);
  assertEqual(fpfP, (long)1 * 0x10000 + 0xCCCD);
  assertEqual(fpfN, (long)1 * 0x10000 + 0xCCCC);
}

test(T1000CalcGCD) {
  // handling of 0
  assertEqual(CalcGCD(0, 0), (long)0);
  assertEqual(CalcGCD(0, 8), (long)0);
  assertEqual(CalcGCD(8, 0), (long)0);

  // handling of coprimes
  assertEqual(CalcGCD(7, 13), (long)1);
  assertEqual(CalcGCD(7, 8), (long)1);
  assertEqual(CalcGCD(9, 16), (long)1);

  assertEqual(CalcGCD(-7, 13), (long)1);
  assertEqual(CalcGCD(7, -8), (long)1);
  assertEqual(CalcGCD(-9, -16), (long)1);

  // exact factors
  assertEqual(CalcGCD(12, 96), (long)12);
  assertEqual(CalcGCD(88, 11), (long)11);
  assertEqual(CalcGCD(1024, 48), (long)16);
  assertEqual(CalcGCD(48, 1024), (long)16);

  assertEqual(CalcGCD(-88, 11), (long)11);
  assertEqual(CalcGCD(1024, -48), (long)16);
  assertEqual(CalcGCD(-48, -1024), (long)16);

  // partial factors
  assertEqual(CalcGCD(36, 96), (long)12);
  assertEqual(CalcGCD(88, 33), (long)11);
  assertEqual(CalcGCD(1024, 144), (long)16);
  assertEqual(CalcGCD(144, 1024), (long)16);

  assertEqual(CalcGCD(88, -33), (long)11);
  assertEqual(CalcGCD(-1024, 144), (long)16);
  assertEqual(CalcGCD(-144, -1024), (long)16);
}

test(T0300DivByShifting) {
  i = 4862;
  assertEqual(i, (int)0x12FE);

  assertEqual(i / 16, (int)0x12F);
  assertEqual(i >> 4, (int)0x12F);
  assertEqual(i / 256, (int)0x12);
  assertEqual(i >> 8, (int)0x12);
  assertEqual(i / 4096, (int)0x1);
  assertEqual(i >> 12, (int)0x1);

  i = -4862;
  assertEqual(i, (int)0xED02);

  assertEqual(i / 16, (int)0xFED1); // rounds to zero
  assertEqual(i >> 4, (int)0xFED0); // rounds down

  assertEqual(i / 256, (int)0xFFEE); // rounds to zero
  assertEqual(i >> 8, (int)0xFFED); // rounds down

  assertEqual(i / 4096, (int)0xFFFF); // rounds to zero
  assertEqual(i >> 12, (int)0xFFFE); // rounds down
}

test(T0200MultByShifting) {
  i = 12;
  assertEqual(i, 0xC);
  assertEqual(i * 16, (int)0xC0);
  assertEqual(i << 4, (int)0xC0);
  assertEqual(i * 256, (int)0xC00);
  assertEqual(i << 8, (int)0xC00);
  assertEqual(i * 4096, (int)0xC000);
  assertEqual(i << 12, (int)0xC000);

  i = -12;
  assertEqual(i, (int)0xFFF4);
  assertEqual(i * 16, (int)0xFF40);
  assertEqual(i << 4, (int)0xFF40);
  assertEqual(i * 256, (int)0xF400);
  assertEqual(i << 8, (int)0xF400);
  assertEqual(i * 4096, (int)0x4000);
  assertEqual(i << 12, (int)0x4000);
}

test(T0100DivRounding) {
  i = 19; j = 5;
  assertEqual(i / j, 3);

  i = 19; j = -5;
  assertEqual(i / j, -3);

  i = -19; j = 5;
  assertEqual(i / j, -3);

  i = -19; j = -5;
  assertEqual(i / j, 3);
}

test(T0000SanitySizes) {
  // some might fail if not runnning on Arduino
  assertEqual((int)sizeof(byte), 1);
  assertEqual((int)sizeof(char), 1);
  assertEqual((int)sizeof(int), 2);
  assertEqual((int)sizeof(long), 4);

  assertEqual((int)sizeof(uint8_t), 1);
  assertEqual((int)sizeof(int8_t), 1);

  assertEqual((int)sizeof(uint16_t), 2);
  assertEqual((int)sizeof(int16_t), 2);

  assertEqual((int)sizeof(uint32_t), 4);
  assertEqual((int)sizeof(int32_t), 4);

  assertEqual((int)sizeof(size_t), 2);

  assertEqual((int)sizeof(float), 4);
  assertEqual((int)sizeof(double), 4); // Surprise!
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
