//
//    FILE: fastMapInteger64ArithmeticTest.ino
//  AUTHOR: Brewmanz (Bryan White)
// VERSION: 0.1.1
// PURPOSE: Test of FastMapInt(64) helper functions
//        : N.B. needs refactoring to properly handle int128_t
//    DATE: 2020-09-08
//     URL: https://github.com/RobTillaart/FastMap

//#include <AUnitVerbose.h> // too much for Nano!
#include <AUnit.h>
#include <FastMap.h>

volatile int i, j;

test(T1336Multiply64ByFixedPointFraction64_5DivM9_Neg) {
  FixedPointFraction64_t FPF;
  Ratio64ToFixedPointFraction64(5, -9, nullptr, &FPF);
  assertEqual(Multiply64ByFixedPointFraction64(0, &FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction64(-1, &FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction64(-2, &FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction64(-3, &FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction64(-4, &FPF), (int64_t)3);
  assertEqual(Multiply64ByFixedPointFraction64(-5, &FPF), (int64_t)3);
  assertEqual(Multiply64ByFixedPointFraction64(-6, &FPF), (int64_t)4);
  assertEqual(Multiply64ByFixedPointFraction64(-7, &FPF), (int64_t)4);
  assertEqual(Multiply64ByFixedPointFraction64(-8, &FPF), (int64_t)5);
  assertEqual(Multiply64ByFixedPointFraction64(-9, &FPF), (int64_t)5);

  assertEqual(Multiply64ByFixedPointFraction64(-10, &FPF), (int64_t)6);
  assertEqual(Multiply64ByFixedPointFraction64(-100, &FPF), (int64_t)56);
  assertEqual(Multiply64ByFixedPointFraction64(-1000, &FPF), (int64_t)556);

  assertEqual(Multiply64ByFixedPointFraction64(-2000, &FPF), (int64_t)1112);
  assertEqual(Multiply64ByFixedPointFraction64(-3000, &FPF), (int64_t)1667);
  assertEqual(Multiply64ByFixedPointFraction64(-4000, &FPF), (int64_t)2223);
  assertEqual(Multiply64ByFixedPointFraction64(-5000, &FPF), (int64_t)2778);
  assertEqual(Multiply64ByFixedPointFraction64(-6000, &FPF), (int64_t)3334);
  assertEqual(Multiply64ByFixedPointFraction64(-7000, &FPF), (int64_t)3889);
  assertEqual(Multiply64ByFixedPointFraction64(-8000, &FPF), (int64_t)4445);
  assertEqual(Multiply64ByFixedPointFraction64(-9000, &FPF), (int64_t)5000);
}
test(T1335Multiply64ByFixedPointFraction64_5DivM9_Pos) {
  FixedPointFraction64_t FPF;
  Ratio64ToFixedPointFraction64(5, -9, &FPF, nullptr);
  assertEqual(Multiply64ByFixedPointFraction64(0, &FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction64(1, &FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction64(2, &FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction64(3, &FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction64(4, &FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction64(5, &FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction64(6, &FPF), (int64_t)-3);
  assertEqual(Multiply64ByFixedPointFraction64(7, &FPF), (int64_t)-3);
  assertEqual(Multiply64ByFixedPointFraction64(8, &FPF), (int64_t)-4);
  assertEqual(Multiply64ByFixedPointFraction64(9, &FPF), (int64_t)-5);

  assertEqual(Multiply64ByFixedPointFraction64(10, &FPF), (int64_t)-5);
  assertEqual(Multiply64ByFixedPointFraction64(100, &FPF), (int64_t)-55);
  assertEqual(Multiply64ByFixedPointFraction64(1000, &FPF), (int64_t)-555);

  assertEqual(Multiply64ByFixedPointFraction64(2000, &FPF), (int64_t)-1111);
  assertEqual(Multiply64ByFixedPointFraction64(3000, &FPF), (int64_t)-1666);
  assertEqual(Multiply64ByFixedPointFraction64(4000, &FPF), (int64_t)-2222);
  assertEqual(Multiply64ByFixedPointFraction64(5000, &FPF), (int64_t)-2777);
  assertEqual(Multiply64ByFixedPointFraction64(6000, &FPF), (int64_t)-3333);
  assertEqual(Multiply64ByFixedPointFraction64(7000, &FPF), (int64_t)-3888);
  assertEqual(Multiply64ByFixedPointFraction64(8000, &FPF), (int64_t)-4444);
  assertEqual(Multiply64ByFixedPointFraction64(9000, &FPF), (int64_t)-5000);
}
test(T1331Multiply64ByFixedPointFraction64_5Div9_Neg) {
  FixedPointFraction64_t FPF;
  Ratio64ToFixedPointFraction64(5, 9, nullptr, &FPF);
  assertEqual(Multiply64ByFixedPointFraction64(0, &FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction64(-1, &FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction64(-2, &FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction64(-3, &FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction64(-4, &FPF), (int64_t)-3);
  assertEqual(Multiply64ByFixedPointFraction64(-5, &FPF), (int64_t)-3);
  assertEqual(Multiply64ByFixedPointFraction64(-6, &FPF), (int64_t)-4);
  assertEqual(Multiply64ByFixedPointFraction64(-7, &FPF), (int64_t)-4);
  assertEqual(Multiply64ByFixedPointFraction64(-8, &FPF), (int64_t)-5);
  assertEqual(Multiply64ByFixedPointFraction64(-9, &FPF), (int64_t)-5);

  assertEqual(Multiply64ByFixedPointFraction64(-10, &FPF), (int64_t)-6);
  assertEqual(Multiply64ByFixedPointFraction64(-100, &FPF), (int64_t)-56);
  assertEqual(Multiply64ByFixedPointFraction64(-1000, &FPF), (int64_t)-556);

  assertEqual(Multiply64ByFixedPointFraction64(-2000, &FPF), (int64_t)-1112);
  assertEqual(Multiply64ByFixedPointFraction64(-3000, &FPF), (int64_t)-1667);
  assertEqual(Multiply64ByFixedPointFraction64(-4000, &FPF), (int64_t)-2223);
  assertEqual(Multiply64ByFixedPointFraction64(-5000, &FPF), (int64_t)-2778);
  assertEqual(Multiply64ByFixedPointFraction64(-6000, &FPF), (int64_t)-3334);
  assertEqual(Multiply64ByFixedPointFraction64(-7000, &FPF), (int64_t)-3889);
  assertEqual(Multiply64ByFixedPointFraction64(-8000, &FPF), (int64_t)-4445);
  assertEqual(Multiply64ByFixedPointFraction64(-9000, &FPF), (int64_t)-5000);
}
test(T1330Multiply64ByFixedPointFraction64_5Div9_Pos) {
  FixedPointFraction64_t FPF;
  Ratio64ToFixedPointFraction64(5, 9, &FPF, nullptr);
  assertEqual(Multiply64ByFixedPointFraction64(0, &FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction64(1, &FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction64(2, &FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction64(3, &FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction64(4, &FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction64(5, &FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction64(6, &FPF), (int64_t)3);
  assertEqual(Multiply64ByFixedPointFraction64(7, &FPF), (int64_t)3);
  assertEqual(Multiply64ByFixedPointFraction64(8, &FPF), (int64_t)4);
  assertEqual(Multiply64ByFixedPointFraction64(9, &FPF), (int64_t)5);

  assertEqual(Multiply64ByFixedPointFraction64(10, &FPF), (int64_t)5);
  assertEqual(Multiply64ByFixedPointFraction64(100, &FPF), (int64_t)55);
  assertEqual(Multiply64ByFixedPointFraction64(1000, &FPF), (int64_t)555);

  assertEqual(Multiply64ByFixedPointFraction64(2000, &FPF), (int64_t)1111);
  assertEqual(Multiply64ByFixedPointFraction64(3000, &FPF), (int64_t)1666);
  assertEqual(Multiply64ByFixedPointFraction64(4000, &FPF), (int64_t)2222);
  assertEqual(Multiply64ByFixedPointFraction64(5000, &FPF), (int64_t)2777);
  assertEqual(Multiply64ByFixedPointFraction64(6000, &FPF), (int64_t)3333);
  assertEqual(Multiply64ByFixedPointFraction64(7000, &FPF), (int64_t)3888);
  assertEqual(Multiply64ByFixedPointFraction64(8000, &FPF), (int64_t)4444);
  assertEqual(Multiply64ByFixedPointFraction64(9000, &FPF), (int64_t)5000);
}

test(T1326Multiply64ByFixedPointFraction64_1DivM3_Neg) {
  FixedPointFraction64_t FPF;
  Ratio64ToFixedPointFraction64(1, -3, nullptr, &FPF);
  assertEqual(Multiply64ByFixedPointFraction64(0, &FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction64(-1, &FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction64(-2, &FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction64(-3, &FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction64(-4, &FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction64(-5, &FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction64(-6, &FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction64(-7, &FPF), (int64_t)3);
  assertEqual(Multiply64ByFixedPointFraction64(-8, &FPF), (int64_t)3);
  assertEqual(Multiply64ByFixedPointFraction64(-9, &FPF), (int64_t)3);

  assertEqual(Multiply64ByFixedPointFraction64(-10, &FPF), (int64_t)4);
  assertEqual(Multiply64ByFixedPointFraction64(-100, &FPF), (int64_t)34);
  assertEqual(Multiply64ByFixedPointFraction64(-1000, &FPF), (int64_t)334);

  assertEqual(Multiply64ByFixedPointFraction64(-2000, &FPF), (int64_t)667);
  assertEqual(Multiply64ByFixedPointFraction64(-3000, &FPF), (int64_t)1000);
  assertEqual(Multiply64ByFixedPointFraction64(-4000, &FPF), (int64_t)1334);
  assertEqual(Multiply64ByFixedPointFraction64(-5000, &FPF), (int64_t)1667);
  assertEqual(Multiply64ByFixedPointFraction64(-6000, &FPF), (int64_t)2000);
  assertEqual(Multiply64ByFixedPointFraction64(-7000, &FPF), (int64_t)2334);
  assertEqual(Multiply64ByFixedPointFraction64(-8000, &FPF), (int64_t)2667);
  assertEqual(Multiply64ByFixedPointFraction64(-9000, &FPF), (int64_t)3000);
}
test(T1325Multiply64ByFixedPointFraction64_1DivM3_Pos) {
  FixedPointFraction64_t FPF;
  Ratio64ToFixedPointFraction64(1, -3, &FPF, nullptr);
  assertEqual(Multiply64ByFixedPointFraction64(0, &FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction64(1, &FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction64(2, &FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction64(3, &FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction64(4, &FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction64(5, &FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction64(6, &FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction64(7, &FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction64(8, &FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction64(9, &FPF), (int64_t)-3);

  assertEqual(Multiply64ByFixedPointFraction64(10, &FPF), (int64_t)-3);
  assertEqual(Multiply64ByFixedPointFraction64(100, &FPF), (int64_t)-33);
  assertEqual(Multiply64ByFixedPointFraction64(1000, &FPF), (int64_t)-333);

  assertEqual(Multiply64ByFixedPointFraction64(2000, &FPF), (int64_t)-666);
  assertEqual(Multiply64ByFixedPointFraction64(3000, &FPF), (int64_t)-1000);
  assertEqual(Multiply64ByFixedPointFraction64(4000, &FPF), (int64_t)-1333);
  assertEqual(Multiply64ByFixedPointFraction64(5000, &FPF), (int64_t)-1666);
  assertEqual(Multiply64ByFixedPointFraction64(6000, &FPF), (int64_t)-2000);
  assertEqual(Multiply64ByFixedPointFraction64(7000, &FPF), (int64_t)-2333);
  assertEqual(Multiply64ByFixedPointFraction64(8000, &FPF), (int64_t)-2666);
  assertEqual(Multiply64ByFixedPointFraction64(9000, &FPF), (int64_t)-3000);
}
test(T1321Multiply64ByFixedPointFraction64_1Div3_Neg) {
  FixedPointFraction64_t FPF;
  Ratio64ToFixedPointFraction64(1, 3, nullptr, &FPF);
  assertEqual(Multiply64ByFixedPointFraction64(0, &FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction64(-1, &FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction64(-2, &FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction64(-3, &FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction64(-4, &FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction64(-5, &FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction64(-6, &FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction64(-7, &FPF), (int64_t)-3);
  assertEqual(Multiply64ByFixedPointFraction64(-8, &FPF), (int64_t)-3);
  assertEqual(Multiply64ByFixedPointFraction64(-9, &FPF), (int64_t)-3);

  assertEqual(Multiply64ByFixedPointFraction64(-10, &FPF), (int64_t)-4);
  assertEqual(Multiply64ByFixedPointFraction64(-100, &FPF), (int64_t)-34);
  assertEqual(Multiply64ByFixedPointFraction64(-1000, &FPF), (int64_t)-334);

  assertEqual(Multiply64ByFixedPointFraction64(-2000, &FPF), (int64_t)-667);
  assertEqual(Multiply64ByFixedPointFraction64(-3000, &FPF), (int64_t)-1000);
  assertEqual(Multiply64ByFixedPointFraction64(-4000, &FPF), (int64_t)-1334);
  assertEqual(Multiply64ByFixedPointFraction64(-5000, &FPF), (int64_t)-1667);
  assertEqual(Multiply64ByFixedPointFraction64(-6000, &FPF), (int64_t)-2000);
  assertEqual(Multiply64ByFixedPointFraction64(-7000, &FPF), (int64_t)-2334);
  assertEqual(Multiply64ByFixedPointFraction64(-8000, &FPF), (int64_t)-2667);
  assertEqual(Multiply64ByFixedPointFraction64(-9000, &FPF), (int64_t)-3000);
}
test(T1320Multiply64ByFixedPointFraction64_1Div3_Pos) {
  FixedPointFraction64_t FPF;
  Ratio64ToFixedPointFraction64(1, 3, &FPF, nullptr);
  assertEqual(Multiply64ByFixedPointFraction64(0, &FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction64(1, &FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction64(2, &FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction64(3, &FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction64(4, &FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction64(5, &FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction64(6, &FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction64(7, &FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction64(8, &FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction64(9, &FPF), (int64_t)3);

  assertEqual(Multiply64ByFixedPointFraction64(10, &FPF), (int64_t)3);
  assertEqual(Multiply64ByFixedPointFraction64(100, &FPF), (int64_t)33);
  assertEqual(Multiply64ByFixedPointFraction64(1000, &FPF), (int64_t)333);

  assertEqual(Multiply64ByFixedPointFraction64(2000, &FPF), (int64_t)666);
  assertEqual(Multiply64ByFixedPointFraction64(3000, &FPF), (int64_t)1000);
  assertEqual(Multiply64ByFixedPointFraction64(4000, &FPF), (int64_t)1333);
  assertEqual(Multiply64ByFixedPointFraction64(5000, &FPF), (int64_t)1666);
  assertEqual(Multiply64ByFixedPointFraction64(6000, &FPF), (int64_t)2000);
  assertEqual(Multiply64ByFixedPointFraction64(7000, &FPF), (int64_t)2333);
  assertEqual(Multiply64ByFixedPointFraction64(8000, &FPF), (int64_t)2666);
  assertEqual(Multiply64ByFixedPointFraction64(9000, &FPF), (int64_t)3000);
}

test(T1316Multiply64ByFixedPointFraction64_1DivM4_Neg) {
  FixedPointFraction64_t FPF;
  Ratio64ToFixedPointFraction64(1, -4, nullptr, &FPF);
  assertEqual(Multiply64ByFixedPointFraction64(0, &FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction64(-1, &FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction64(-2, &FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction64(-3, &FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction64(-4, &FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction64(-5, &FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction64(-6, &FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction64(-7, &FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction64(-8, &FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction64(-9, &FPF), (int64_t)3);

  assertEqual(Multiply64ByFixedPointFraction64(-10, &FPF), (int64_t)3);
  assertEqual(Multiply64ByFixedPointFraction64(-100, &FPF), (int64_t)25);
  assertEqual(Multiply64ByFixedPointFraction64(-1000, &FPF), (int64_t)250);

  assertEqual(Multiply64ByFixedPointFraction64(-2000, &FPF), (int64_t)500);
  assertEqual(Multiply64ByFixedPointFraction64(-3000, &FPF), (int64_t)750);
  assertEqual(Multiply64ByFixedPointFraction64(-4000, &FPF), (int64_t)1000);
  assertEqual(Multiply64ByFixedPointFraction64(-5000, &FPF), (int64_t)1250);
  assertEqual(Multiply64ByFixedPointFraction64(-6000, &FPF), (int64_t)1500);
  assertEqual(Multiply64ByFixedPointFraction64(-7000, &FPF), (int64_t)1750);
  assertEqual(Multiply64ByFixedPointFraction64(-8000, &FPF), (int64_t)2000);
  assertEqual(Multiply64ByFixedPointFraction64(-9000, &FPF), (int64_t)2250);
}
test(T1315Multiply64ByFixedPointFraction64_1DivM4_Pos) {
  FixedPointFraction64_t FPF;
  Ratio64ToFixedPointFraction64(1, -4, &FPF, nullptr);
  assertEqual(Multiply64ByFixedPointFraction64(0, &FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction64(1, &FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction64(2, &FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction64(3, &FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction64(4, &FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction64(5, &FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction64(6, &FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction64(7, &FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction64(8, &FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction64(9, &FPF), (int64_t)-2);

  assertEqual(Multiply64ByFixedPointFraction64(10, &FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction64(100, &FPF), (int64_t)-25);
  assertEqual(Multiply64ByFixedPointFraction64(1000, &FPF), (int64_t)-250);

  assertEqual(Multiply64ByFixedPointFraction64(2000, &FPF), (int64_t)-500);
  assertEqual(Multiply64ByFixedPointFraction64(3000, &FPF), (int64_t)-750);
  assertEqual(Multiply64ByFixedPointFraction64(4000, &FPF), (int64_t)-1000);
  assertEqual(Multiply64ByFixedPointFraction64(5000, &FPF), (int64_t)-1250);
  assertEqual(Multiply64ByFixedPointFraction64(6000, &FPF), (int64_t)-1500);
  assertEqual(Multiply64ByFixedPointFraction64(7000, &FPF), (int64_t)-1750);
  assertEqual(Multiply64ByFixedPointFraction64(8000, &FPF), (int64_t)-2000);
  assertEqual(Multiply64ByFixedPointFraction64(9000, &FPF), (int64_t)-2250);
}
test(T1311Multiply64ByFixedPointFraction64_1Div4_Neg) {
  FixedPointFraction64_t FPF;
  Ratio64ToFixedPointFraction64(1, 4, nullptr, &FPF);
  assertEqual(Multiply64ByFixedPointFraction64(0, &FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction64(-1, &FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction64(-2, &FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction64(-3, &FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction64(-4, &FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction64(-5, &FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction64(-6, &FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction64(-7, &FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction64(-8, &FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction64(-9, &FPF), (int64_t)-3);

  assertEqual(Multiply64ByFixedPointFraction64(-10, &FPF), (int64_t)-3);
  assertEqual(Multiply64ByFixedPointFraction64(-100, &FPF), (int64_t)-25);
  assertEqual(Multiply64ByFixedPointFraction64(-1000, &FPF), (int64_t)-250);

  assertEqual(Multiply64ByFixedPointFraction64(-2000, &FPF), (int64_t)-500);
  assertEqual(Multiply64ByFixedPointFraction64(-3000, &FPF), (int64_t)-750);
  assertEqual(Multiply64ByFixedPointFraction64(-4000, &FPF), (int64_t)-1000);
  assertEqual(Multiply64ByFixedPointFraction64(-5000, &FPF), (int64_t)-1250);
  assertEqual(Multiply64ByFixedPointFraction64(-6000, &FPF), (int64_t)-1500);
  assertEqual(Multiply64ByFixedPointFraction64(-7000, &FPF), (int64_t)-1750);
  assertEqual(Multiply64ByFixedPointFraction64(-8000, &FPF), (int64_t)-2000);
  assertEqual(Multiply64ByFixedPointFraction64(-9000, &FPF), (int64_t)-2250);
}
test(T1310Multiply64ByFixedPointFraction64_1Div4_Pos) {
  FixedPointFraction64_t FPF;
  Ratio64ToFixedPointFraction64(1, 4, &FPF, nullptr);
  assertEqual(Multiply64ByFixedPointFraction64(0, &FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction64(1, &FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction64(2, &FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction64(3, &FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction64(4, &FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction64(5, &FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction64(6, &FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction64(7, &FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction64(8, &FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction64(9, &FPF), (int64_t)2);

  assertEqual(Multiply64ByFixedPointFraction64(10, &FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction64(100, &FPF), (int64_t)25);
  assertEqual(Multiply64ByFixedPointFraction64(1000, &FPF), (int64_t)250);

  assertEqual(Multiply64ByFixedPointFraction64(2000, &FPF), (int64_t)500);
  assertEqual(Multiply64ByFixedPointFraction64(3000, &FPF), (int64_t)750);
  assertEqual(Multiply64ByFixedPointFraction64(4000, &FPF), (int64_t)1000);
  assertEqual(Multiply64ByFixedPointFraction64(5000, &FPF), (int64_t)1250);
  assertEqual(Multiply64ByFixedPointFraction64(6000, &FPF), (int64_t)1500);
  assertEqual(Multiply64ByFixedPointFraction64(7000, &FPF), (int64_t)1750);
  assertEqual(Multiply64ByFixedPointFraction64(8000, &FPF), (int64_t)2000);
  assertEqual(Multiply64ByFixedPointFraction64(9000, &FPF), (int64_t)2250);
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
