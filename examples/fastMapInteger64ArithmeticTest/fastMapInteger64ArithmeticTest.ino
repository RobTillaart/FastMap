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

test(T1336Multiply64ByFixedPointFraction3232_5DivM9_Neg) {
  int64_t FPF;
  Ratio64ToFixedPointFraction3232(5, -9, nullptr, &FPF);
  assertEqual(Multiply64ByFixedPointFraction3232(0, FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction3232(-1, FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction3232(-2, FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction3232(-3, FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction3232(-4, FPF), (int64_t)3);
  assertEqual(Multiply64ByFixedPointFraction3232(-5, FPF), (int64_t)3);
  assertEqual(Multiply64ByFixedPointFraction3232(-6, FPF), (int64_t)4);
  assertEqual(Multiply64ByFixedPointFraction3232(-7, FPF), (int64_t)4);
  assertEqual(Multiply64ByFixedPointFraction3232(-8, FPF), (int64_t)5);
  assertEqual(Multiply64ByFixedPointFraction3232(-9, FPF), (int64_t)5);

  assertEqual(Multiply64ByFixedPointFraction3232(-10, FPF), (int64_t)6);
  assertEqual(Multiply64ByFixedPointFraction3232(-100, FPF), (int64_t)56);
  assertEqual(Multiply64ByFixedPointFraction3232(-1000, FPF), (int64_t)556);

  assertEqual(Multiply64ByFixedPointFraction3232(-2000, FPF), (int64_t)1112);
  assertEqual(Multiply64ByFixedPointFraction3232(-3000, FPF), (int64_t)1667);
  assertEqual(Multiply64ByFixedPointFraction3232(-4000, FPF), (int64_t)2223);
  assertEqual(Multiply64ByFixedPointFraction3232(-5000, FPF), (int64_t)2778);
  assertEqual(Multiply64ByFixedPointFraction3232(-6000, FPF), (int64_t)3334);
  assertEqual(Multiply64ByFixedPointFraction3232(-7000, FPF), (int64_t)3889);
  assertEqual(Multiply64ByFixedPointFraction3232(-8000, FPF), (int64_t)4445);
  assertEqual(Multiply64ByFixedPointFraction3232(-9000, FPF), (int64_t)5000);
}
test(T1335Multiply64ByFixedPointFraction3232_5DivM9_Pos) {
  int64_t FPF;
  Ratio64ToFixedPointFraction3232(5, -9, &FPF, nullptr);
  assertEqual(Multiply64ByFixedPointFraction3232(0, FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction3232(1, FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction3232(2, FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction3232(3, FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction3232(4, FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction3232(5, FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction3232(6, FPF), (int64_t)-3);
  assertEqual(Multiply64ByFixedPointFraction3232(7, FPF), (int64_t)-3);
  assertEqual(Multiply64ByFixedPointFraction3232(8, FPF), (int64_t)-4);
  assertEqual(Multiply64ByFixedPointFraction3232(9, FPF), (int64_t)-5);

  assertEqual(Multiply64ByFixedPointFraction3232(10, FPF), (int64_t)-5);
  assertEqual(Multiply64ByFixedPointFraction3232(100, FPF), (int64_t)-55);
  assertEqual(Multiply64ByFixedPointFraction3232(1000, FPF), (int64_t)-555);

  assertEqual(Multiply64ByFixedPointFraction3232(2000, FPF), (int64_t)-1111);
  assertEqual(Multiply64ByFixedPointFraction3232(3000, FPF), (int64_t)-1666);
  assertEqual(Multiply64ByFixedPointFraction3232(4000, FPF), (int64_t)-2222);
  assertEqual(Multiply64ByFixedPointFraction3232(5000, FPF), (int64_t)-2777);
  assertEqual(Multiply64ByFixedPointFraction3232(6000, FPF), (int64_t)-3333);
  assertEqual(Multiply64ByFixedPointFraction3232(7000, FPF), (int64_t)-3888);
  assertEqual(Multiply64ByFixedPointFraction3232(8000, FPF), (int64_t)-4444);
  assertEqual(Multiply64ByFixedPointFraction3232(9000, FPF), (int64_t)-5000);
}
test(T1331Multiply64ByFixedPointFraction3232_5Div9_Neg) {
  int64_t FPF;
  Ratio64ToFixedPointFraction3232(5, 9, nullptr, &FPF);
  assertEqual(Multiply64ByFixedPointFraction3232(0, FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction3232(-1, FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction3232(-2, FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction3232(-3, FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction3232(-4, FPF), (int64_t)-3);
  assertEqual(Multiply64ByFixedPointFraction3232(-5, FPF), (int64_t)-3);
  assertEqual(Multiply64ByFixedPointFraction3232(-6, FPF), (int64_t)-4);
  assertEqual(Multiply64ByFixedPointFraction3232(-7, FPF), (int64_t)-4);
  assertEqual(Multiply64ByFixedPointFraction3232(-8, FPF), (int64_t)-5);
  assertEqual(Multiply64ByFixedPointFraction3232(-9, FPF), (int64_t)-5);

  assertEqual(Multiply64ByFixedPointFraction3232(-10, FPF), (int64_t)-6);
  assertEqual(Multiply64ByFixedPointFraction3232(-100, FPF), (int64_t)-56);
  assertEqual(Multiply64ByFixedPointFraction3232(-1000, FPF), (int64_t)-556);

  assertEqual(Multiply64ByFixedPointFraction3232(-2000, FPF), (int64_t)-1112);
  assertEqual(Multiply64ByFixedPointFraction3232(-3000, FPF), (int64_t)-1667);
  assertEqual(Multiply64ByFixedPointFraction3232(-4000, FPF), (int64_t)-2223);
  assertEqual(Multiply64ByFixedPointFraction3232(-5000, FPF), (int64_t)-2778);
  assertEqual(Multiply64ByFixedPointFraction3232(-6000, FPF), (int64_t)-3334);
  assertEqual(Multiply64ByFixedPointFraction3232(-7000, FPF), (int64_t)-3889);
  assertEqual(Multiply64ByFixedPointFraction3232(-8000, FPF), (int64_t)-4445);
  assertEqual(Multiply64ByFixedPointFraction3232(-9000, FPF), (int64_t)-5000);
}
test(T1330Multiply64ByFixedPointFraction3232_5Div9_Pos) {
  int64_t FPF;
  Ratio64ToFixedPointFraction3232(5, 9, &FPF, nullptr);
  assertEqual(Multiply64ByFixedPointFraction3232(0, FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction3232(1, FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction3232(2, FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction3232(3, FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction3232(4, FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction3232(5, FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction3232(6, FPF), (int64_t)3);
  assertEqual(Multiply64ByFixedPointFraction3232(7, FPF), (int64_t)3);
  assertEqual(Multiply64ByFixedPointFraction3232(8, FPF), (int64_t)4);
  assertEqual(Multiply64ByFixedPointFraction3232(9, FPF), (int64_t)5);

  assertEqual(Multiply64ByFixedPointFraction3232(10, FPF), (int64_t)5);
  assertEqual(Multiply64ByFixedPointFraction3232(100, FPF), (int64_t)55);
  assertEqual(Multiply64ByFixedPointFraction3232(1000, FPF), (int64_t)555);

  assertEqual(Multiply64ByFixedPointFraction3232(2000, FPF), (int64_t)1111);
  assertEqual(Multiply64ByFixedPointFraction3232(3000, FPF), (int64_t)1666);
  assertEqual(Multiply64ByFixedPointFraction3232(4000, FPF), (int64_t)2222);
  assertEqual(Multiply64ByFixedPointFraction3232(5000, FPF), (int64_t)2777);
  assertEqual(Multiply64ByFixedPointFraction3232(6000, FPF), (int64_t)3333);
  assertEqual(Multiply64ByFixedPointFraction3232(7000, FPF), (int64_t)3888);
  assertEqual(Multiply64ByFixedPointFraction3232(8000, FPF), (int64_t)4444);
  assertEqual(Multiply64ByFixedPointFraction3232(9000, FPF), (int64_t)5000);
}

test(T1326Multiply64ByFixedPointFraction3232_1DivM3_Neg) {
  int64_t FPF;
  Ratio64ToFixedPointFraction3232(1, -3, nullptr, &FPF);
  assertEqual(Multiply64ByFixedPointFraction3232(0, FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction3232(-1, FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction3232(-2, FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction3232(-3, FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction3232(-4, FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction3232(-5, FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction3232(-6, FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction3232(-7, FPF), (int64_t)3);
  assertEqual(Multiply64ByFixedPointFraction3232(-8, FPF), (int64_t)3);
  assertEqual(Multiply64ByFixedPointFraction3232(-9, FPF), (int64_t)3);

  assertEqual(Multiply64ByFixedPointFraction3232(-10, FPF), (int64_t)4);
  assertEqual(Multiply64ByFixedPointFraction3232(-100, FPF), (int64_t)34);
  assertEqual(Multiply64ByFixedPointFraction3232(-1000, FPF), (int64_t)334);

  assertEqual(Multiply64ByFixedPointFraction3232(-2000, FPF), (int64_t)667);
  assertEqual(Multiply64ByFixedPointFraction3232(-3000, FPF), (int64_t)1000);
  assertEqual(Multiply64ByFixedPointFraction3232(-4000, FPF), (int64_t)1334);
  assertEqual(Multiply64ByFixedPointFraction3232(-5000, FPF), (int64_t)1667);
  assertEqual(Multiply64ByFixedPointFraction3232(-6000, FPF), (int64_t)2000);
  assertEqual(Multiply64ByFixedPointFraction3232(-7000, FPF), (int64_t)2334);
  assertEqual(Multiply64ByFixedPointFraction3232(-8000, FPF), (int64_t)2667);
  assertEqual(Multiply64ByFixedPointFraction3232(-9000, FPF), (int64_t)3000);
}
test(T1325Multiply64ByFixedPointFraction3232_1DivM3_Pos) {
  int64_t FPF;
  Ratio64ToFixedPointFraction3232(1, -3, &FPF, nullptr);
  assertEqual(Multiply64ByFixedPointFraction3232(0, FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction3232(1, FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction3232(2, FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction3232(3, FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction3232(4, FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction3232(5, FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction3232(6, FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction3232(7, FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction3232(8, FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction3232(9, FPF), (int64_t)-3);

  assertEqual(Multiply64ByFixedPointFraction3232(10, FPF), (int64_t)-3);
  assertEqual(Multiply64ByFixedPointFraction3232(100, FPF), (int64_t)-33);
  assertEqual(Multiply64ByFixedPointFraction3232(1000, FPF), (int64_t)-333);

  assertEqual(Multiply64ByFixedPointFraction3232(2000, FPF), (int64_t)-666);
  assertEqual(Multiply64ByFixedPointFraction3232(3000, FPF), (int64_t)-1000);
  assertEqual(Multiply64ByFixedPointFraction3232(4000, FPF), (int64_t)-1333);
  assertEqual(Multiply64ByFixedPointFraction3232(5000, FPF), (int64_t)-1666);
  assertEqual(Multiply64ByFixedPointFraction3232(6000, FPF), (int64_t)-2000);
  assertEqual(Multiply64ByFixedPointFraction3232(7000, FPF), (int64_t)-2333);
  assertEqual(Multiply64ByFixedPointFraction3232(8000, FPF), (int64_t)-2666);
  assertEqual(Multiply64ByFixedPointFraction3232(9000, FPF), (int64_t)-3000);
}
test(T1321Multiply64ByFixedPointFraction3232_1Div3_Neg) {
  int64_t FPF;
  Ratio64ToFixedPointFraction3232(1, 3, nullptr, &FPF);
  assertEqual(Multiply64ByFixedPointFraction3232(0, FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction3232(-1, FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction3232(-2, FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction3232(-3, FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction3232(-4, FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction3232(-5, FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction3232(-6, FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction3232(-7, FPF), (int64_t)-3);
  assertEqual(Multiply64ByFixedPointFraction3232(-8, FPF), (int64_t)-3);
  assertEqual(Multiply64ByFixedPointFraction3232(-9, FPF), (int64_t)-3);

  assertEqual(Multiply64ByFixedPointFraction3232(-10, FPF), (int64_t)-4);
  assertEqual(Multiply64ByFixedPointFraction3232(-100, FPF), (int64_t)-34);
  assertEqual(Multiply64ByFixedPointFraction3232(-1000, FPF), (int64_t)-334);

  assertEqual(Multiply64ByFixedPointFraction3232(-2000, FPF), (int64_t)-667);
  assertEqual(Multiply64ByFixedPointFraction3232(-3000, FPF), (int64_t)-1000);
  assertEqual(Multiply64ByFixedPointFraction3232(-4000, FPF), (int64_t)-1334);
  assertEqual(Multiply64ByFixedPointFraction3232(-5000, FPF), (int64_t)-1667);
  assertEqual(Multiply64ByFixedPointFraction3232(-6000, FPF), (int64_t)-2000);
  assertEqual(Multiply64ByFixedPointFraction3232(-7000, FPF), (int64_t)-2334);
  assertEqual(Multiply64ByFixedPointFraction3232(-8000, FPF), (int64_t)-2667);
  assertEqual(Multiply64ByFixedPointFraction3232(-9000, FPF), (int64_t)-3000);
}
test(T1320Multiply64ByFixedPointFraction3232_1Div3_Pos) {
  int64_t FPF;
  Ratio64ToFixedPointFraction3232(1, 3, &FPF, nullptr);
  assertEqual(Multiply64ByFixedPointFraction3232(0, FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction3232(1, FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction3232(2, FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction3232(3, FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction3232(4, FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction3232(5, FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction3232(6, FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction3232(7, FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction3232(8, FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction3232(9, FPF), (int64_t)3);

  assertEqual(Multiply64ByFixedPointFraction3232(10, FPF), (int64_t)3);
  assertEqual(Multiply64ByFixedPointFraction3232(100, FPF), (int64_t)33);
  assertEqual(Multiply64ByFixedPointFraction3232(1000, FPF), (int64_t)333);

  assertEqual(Multiply64ByFixedPointFraction3232(2000, FPF), (int64_t)666);
  assertEqual(Multiply64ByFixedPointFraction3232(3000, FPF), (int64_t)1000);
  assertEqual(Multiply64ByFixedPointFraction3232(4000, FPF), (int64_t)1333);
  assertEqual(Multiply64ByFixedPointFraction3232(5000, FPF), (int64_t)1666);
  assertEqual(Multiply64ByFixedPointFraction3232(6000, FPF), (int64_t)2000);
  assertEqual(Multiply64ByFixedPointFraction3232(7000, FPF), (int64_t)2333);
  assertEqual(Multiply64ByFixedPointFraction3232(8000, FPF), (int64_t)2666);
  assertEqual(Multiply64ByFixedPointFraction3232(9000, FPF), (int64_t)3000);
}

test(T1316Multiply64ByFixedPointFraction3232_1DivM4_Neg) {
  int64_t FPF;
  Ratio64ToFixedPointFraction3232(1, -4, nullptr, &FPF);
  assertEqual(Multiply64ByFixedPointFraction3232(0, FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction3232(-1, FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction3232(-2, FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction3232(-3, FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction3232(-4, FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction3232(-5, FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction3232(-6, FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction3232(-7, FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction3232(-8, FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction3232(-9, FPF), (int64_t)3);

  assertEqual(Multiply64ByFixedPointFraction3232(-10, FPF), (int64_t)3);
  assertEqual(Multiply64ByFixedPointFraction3232(-100, FPF), (int64_t)25);
  assertEqual(Multiply64ByFixedPointFraction3232(-1000, FPF), (int64_t)250);

  assertEqual(Multiply64ByFixedPointFraction3232(-2000, FPF), (int64_t)500);
  assertEqual(Multiply64ByFixedPointFraction3232(-3000, FPF), (int64_t)750);
  assertEqual(Multiply64ByFixedPointFraction3232(-4000, FPF), (int64_t)1000);
  assertEqual(Multiply64ByFixedPointFraction3232(-5000, FPF), (int64_t)1250);
  assertEqual(Multiply64ByFixedPointFraction3232(-6000, FPF), (int64_t)1500);
  assertEqual(Multiply64ByFixedPointFraction3232(-7000, FPF), (int64_t)1750);
  assertEqual(Multiply64ByFixedPointFraction3232(-8000, FPF), (int64_t)2000);
  assertEqual(Multiply64ByFixedPointFraction3232(-9000, FPF), (int64_t)2250);
}
test(T1315Multiply64ByFixedPointFraction3232_1DivM4_Pos) {
  int64_t FPF;
  Ratio64ToFixedPointFraction3232(1, -4, &FPF, nullptr);
  assertEqual(Multiply64ByFixedPointFraction3232(0, FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction3232(1, FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction3232(2, FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction3232(3, FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction3232(4, FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction3232(5, FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction3232(6, FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction3232(7, FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction3232(8, FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction3232(9, FPF), (int64_t)-2);

  assertEqual(Multiply64ByFixedPointFraction3232(10, FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction3232(100, FPF), (int64_t)-25);
  assertEqual(Multiply64ByFixedPointFraction3232(1000, FPF), (int64_t)-250);

  assertEqual(Multiply64ByFixedPointFraction3232(2000, FPF), (int64_t)-500);
  assertEqual(Multiply64ByFixedPointFraction3232(3000, FPF), (int64_t)-750);
  assertEqual(Multiply64ByFixedPointFraction3232(4000, FPF), (int64_t)-1000);
  assertEqual(Multiply64ByFixedPointFraction3232(5000, FPF), (int64_t)-1250);
  assertEqual(Multiply64ByFixedPointFraction3232(6000, FPF), (int64_t)-1500);
  assertEqual(Multiply64ByFixedPointFraction3232(7000, FPF), (int64_t)-1750);
  assertEqual(Multiply64ByFixedPointFraction3232(8000, FPF), (int64_t)-2000);
  assertEqual(Multiply64ByFixedPointFraction3232(9000, FPF), (int64_t)-2250);
}
test(T1311Multiply64ByFixedPointFraction3232_1Div4_Neg) {
  int64_t FPF;
  Ratio64ToFixedPointFraction3232(1, 4, nullptr, &FPF);
  assertEqual(Multiply64ByFixedPointFraction3232(0, FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction3232(-1, FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction3232(-2, FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction3232(-3, FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction3232(-4, FPF), (int64_t)-1);
  assertEqual(Multiply64ByFixedPointFraction3232(-5, FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction3232(-6, FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction3232(-7, FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction3232(-8, FPF), (int64_t)-2);
  assertEqual(Multiply64ByFixedPointFraction3232(-9, FPF), (int64_t)-3);

  assertEqual(Multiply64ByFixedPointFraction3232(-10, FPF), (int64_t)-3);
  assertEqual(Multiply64ByFixedPointFraction3232(-100, FPF), (int64_t)-25);
  assertEqual(Multiply64ByFixedPointFraction3232(-1000, FPF), (int64_t)-250);

  assertEqual(Multiply64ByFixedPointFraction3232(-2000, FPF), (int64_t)-500);
  assertEqual(Multiply64ByFixedPointFraction3232(-3000, FPF), (int64_t)-750);
  assertEqual(Multiply64ByFixedPointFraction3232(-4000, FPF), (int64_t)-1000);
  assertEqual(Multiply64ByFixedPointFraction3232(-5000, FPF), (int64_t)-1250);
  assertEqual(Multiply64ByFixedPointFraction3232(-6000, FPF), (int64_t)-1500);
  assertEqual(Multiply64ByFixedPointFraction3232(-7000, FPF), (int64_t)-1750);
  assertEqual(Multiply64ByFixedPointFraction3232(-8000, FPF), (int64_t)-2000);
  assertEqual(Multiply64ByFixedPointFraction3232(-9000, FPF), (int64_t)-2250);
}
test(T1310Multiply64ByFixedPointFraction3232_1Div4_Pos) {
  int64_t FPF;
  Ratio64ToFixedPointFraction3232(1, 4, &FPF, nullptr);
  assertEqual(Multiply64ByFixedPointFraction3232(0, FPF), (int64_t)0);

  assertEqual(Multiply64ByFixedPointFraction3232(1, FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction3232(2, FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction3232(3, FPF), (int64_t)0);
  assertEqual(Multiply64ByFixedPointFraction3232(4, FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction3232(5, FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction3232(6, FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction3232(7, FPF), (int64_t)1);
  assertEqual(Multiply64ByFixedPointFraction3232(8, FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction3232(9, FPF), (int64_t)2);

  assertEqual(Multiply64ByFixedPointFraction3232(10, FPF), (int64_t)2);
  assertEqual(Multiply64ByFixedPointFraction3232(100, FPF), (int64_t)25);
  assertEqual(Multiply64ByFixedPointFraction3232(1000, FPF), (int64_t)250);

  assertEqual(Multiply64ByFixedPointFraction3232(2000, FPF), (int64_t)500);
  assertEqual(Multiply64ByFixedPointFraction3232(3000, FPF), (int64_t)750);
  assertEqual(Multiply64ByFixedPointFraction3232(4000, FPF), (int64_t)1000);
  assertEqual(Multiply64ByFixedPointFraction3232(5000, FPF), (int64_t)1250);
  assertEqual(Multiply64ByFixedPointFraction3232(6000, FPF), (int64_t)1500);
  assertEqual(Multiply64ByFixedPointFraction3232(7000, FPF), (int64_t)1750);
  assertEqual(Multiply64ByFixedPointFraction3232(8000, FPF), (int64_t)2000);
  assertEqual(Multiply64ByFixedPointFraction3232(9000, FPF), (int64_t)2250);
}

test(T1300Ratio64ToFixedPointFraction3232) {
  int64_t fpfP, fpfN;

  // handling of 0
  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(0, 0, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)0 * 0x100000000 + 0x00000000);
  assertEqual(fpfN, (int64_t)0 * 0x100000000 + 0x00000000);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(0, 8, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)0 * 0x100000000 + 0x00000000);
  assertEqual(fpfN, (int64_t)0 * 0x100000000 + 0x00000000);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(8, 0, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)0 * 0x100000000 + 0x00000000);
  assertEqual(fpfN, (int64_t)0 * 0x100000000 + 0x00000000);

  // equal ratios
  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(1, 1, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)1 * 0x100000000 + 0x00000000);
  assertEqual(fpfN, (int64_t)1 * 0x100000000 + 0x00000000);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(12, 12, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)1 * 0x100000000 + 0x00000000);
  assertEqual(fpfN, (int64_t)1 * 0x100000000 + 0x00000000);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(-2, 2, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)-1 * 0x100000000 + 0x00000000);
  assertEqual(fpfN, (int64_t)-1 * 0x100000000 + 0x00000000);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(3, -3, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)-1 * 0x100000000 + 0x00000000);
  assertEqual(fpfN, (int64_t)-1 * 0x100000000 + 0x00000000);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(-4, -4, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)1 * 0x100000000 + 0x00000000);
  assertEqual(fpfN, (int64_t)1 * 0x100000000 + 0x00000000);

  // exact ratios
  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(8, 2, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)4 * 0x100000000 + 0x00000000);
  assertEqual(fpfN, (int64_t)4 * 0x100000000 + 0x00000000);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(-12, 4, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)-3 * 0x100000000 + 0x00000000);
  assertEqual(fpfN, (int64_t)-3 * 0x100000000 + 0x00000000);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(30, -5, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)-6 * 0x100000000 + 0x00000000);
  assertEqual(fpfN, (int64_t)-6 * 0x100000000 + 0x00000000);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(-56, -7, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)8 * 0x100000000 + 0x00000000);
  assertEqual(fpfN, (int64_t)8 * 0x100000000 + 0x00000000);

  // theoretical exact ratios
  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(1, 3, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)0 * 0x100000000 + 0x55555556);
  assertEqual(fpfN, (int64_t)0 * 0x100000000 + 0x55555555);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(-1, 3, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)-1 * 0x100000000 + 0xAAAAAAAA);
  assertEqual(fpfN, (int64_t)-1 * 0x100000000 + 0xAAAAAAAB);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(1, -3, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)-1 * 0x100000000 + 0xAAAAAAAA);
  assertEqual(fpfN, (int64_t)-1 * 0x100000000 + 0xAAAAAAAB);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(-1, -3, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)0 * 0x100000000 + 0x55555556);
  assertEqual(fpfN, (int64_t)0 * 0x100000000 + 0x55555555);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(2, 3, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)0 * 0x100000000 + 0xAAAAAAAB);
  assertEqual(fpfN, (int64_t)0 * 0x100000000 + 0xAAAAAAAA);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(-2, 3, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)-1 * 0x100000000 + 0x55555555);
  assertEqual(fpfN, (int64_t)-1 * 0x100000000 + 0x55555556);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(2, -3, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)-1 * 0x100000000 + 0x55555555);
  assertEqual(fpfN, (int64_t)-1 * 0x100000000 + 0x55555556);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(-2, -3, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)0 * 0x100000000 + 0xAAAAAAAB);
  assertEqual(fpfN, (int64_t)0 * 0x100000000 + 0xAAAAAAAA);

  // binary fraction
  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(1, 2, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)0 * 0x100000000 + 0x80000000);
  assertEqual(fpfN, (int64_t)0 * 0x100000000 + 0x80000000);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(-3, 4, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)-1 * 0x100000000 + 0x40000000);
  assertEqual(fpfN, (int64_t)-1 * 0x100000000 + 0x40000000);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(3, -8, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)-1 * 0x100000000 + 0xA0000000);
  assertEqual(fpfN, (int64_t)-1 * 0x100000000 + 0xA0000000);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(-3, -16, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)0 * 0x100000000 + 0x30000000);
  assertEqual(fpfN, (int64_t)0 * 0x100000000 + 0x30000000);

  // binary vulgar fraction
  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(3, 2, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)1 * 0x100000000 + 0x80000000);
  assertEqual(fpfN, (int64_t)1 * 0x100000000 + 0x80000000);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(-7, 4, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)-2 * 0x100000000 + 0x40000000);
  assertEqual(fpfN, (int64_t)-2 * 0x100000000 + 0x40000000);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(11, -8, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)-2 * 0x100000000 + 0xA0000000);
  assertEqual(fpfN, (int64_t)-2 * 0x100000000 + 0xA0000000);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(-19, -16, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)1 * 0x100000000 + 0x30000000);
  assertEqual(fpfN, (int64_t)1 * 0x100000000 + 0x30000000);

  // inexact fraction
  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(5, 9, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)0 * 0x100000000 + 0x8E38E38F); // 32 = 0x8E39
  assertEqual(fpfN, (int64_t)0 * 0x100000000 + 0x8E38E38E); // 32 = 0x8E38

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(-5, 9, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)-1 * 0x100000000 + 0x71C71C71); // 32 = 0x71C7
  assertEqual(fpfN, (int64_t)-1 * 0x100000000 + 0x71C71C72); // 32 = 0x71C8

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(5, -9, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)-1 * 0x100000000 + 0x71C71C71); // 32 = 0x71C7
  assertEqual(fpfN, (int64_t)-1 * 0x100000000 + 0x71C71C72); // 32 = 0x71C8

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(-5, -9, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)0 * 0x100000000 + 0x8E38E38F); // 32 = 0x8E39
  assertEqual(fpfN, (int64_t)0 * 0x100000000 + 0x8E38E38E); // 32 = 0x8E38

  // inexact vulgar fraction
  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(9, 5, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)1 * 0x100000000 + 0xCCCCCCCD);
  assertEqual(fpfN, (int64_t)1 * 0x100000000 + 0xCCCCCCCC);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(-9, 5, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)-2 * 0x100000000 + 0x33333333);
  assertEqual(fpfN, (int64_t)-2 * 0x100000000 + 0x33333334);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(9, -5, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)-2 * 0x100000000 + 0x33333333);
  assertEqual(fpfN, (int64_t)-2 * 0x100000000 + 0x33333334);

  fpfP = fpfN = -2468; Ratio64ToFixedPointFraction3232(-9, -5, &fpfP, &fpfN);
  assertEqual(fpfP, (int64_t)1 * 0x100000000 + 0xCCCCCCCD);
  assertEqual(fpfN, (int64_t)1 * 0x100000000 + 0xCCCCCCCC);
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
