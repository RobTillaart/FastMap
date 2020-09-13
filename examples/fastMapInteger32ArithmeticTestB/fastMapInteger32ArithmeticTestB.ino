//
//    FILE: fastMapInteger32ArithmeticTestB.ino
//  AUTHOR: Brewmanz (Bryan White)
// VERSION: 0.1.1
// PURPOSE: Test of FastMapInt(32) helper functions
//    DATE: 2020-09-08
//     URL: https://github.com/RobTillaart/FastMap

//#include <AUnitVerbose.h> // too much for Nano!
#include <AUnit.h>
#include <FastMap.h>

//volatile int i, j;
const char* spinner[] = {"\b|", "\b/", "\b-", "\b\\" };

test(T1236Multiply32ByFixedPointFraction64_5DivM9_Neg) {
  FixedPointFraction64_t FPF;
  Ratio32ToFixedPointFraction64(5, -9, nullptr, &FPF);
  assertEqual(Multiply32ByFixedPointFraction64(0, &FPF), (int32_t)0);

  assertEqual(Multiply32ByFixedPointFraction64(-1, &FPF), (int32_t)1);
  assertEqual(Multiply32ByFixedPointFraction64(-2, &FPF), (int32_t)2);
  assertEqual(Multiply32ByFixedPointFraction64(-3, &FPF), (int32_t)2);
  assertEqual(Multiply32ByFixedPointFraction64(-4, &FPF), (int32_t)3);
  assertEqual(Multiply32ByFixedPointFraction64(-5, &FPF), (int32_t)3);
  assertEqual(Multiply32ByFixedPointFraction64(-6, &FPF), (int32_t)4);
  assertEqual(Multiply32ByFixedPointFraction64(-7, &FPF), (int32_t)4);
  assertEqual(Multiply32ByFixedPointFraction64(-8, &FPF), (int32_t)5);
  assertEqual(Multiply32ByFixedPointFraction64(-9, &FPF), (int32_t)5);

#if 0
  assertEqual(Multiply32ByFixedPointFraction64(-10, &FPF), (int32_t)6);
  assertEqual(Multiply32ByFixedPointFraction64(-100, &FPF), (int32_t)56);
  assertEqual(Multiply32ByFixedPointFraction64(-1000, &FPF), (int32_t)556);

  assertEqual(Multiply32ByFixedPointFraction64(-2000, &FPF), (int32_t)1112);
  assertEqual(Multiply32ByFixedPointFraction64(-3000, &FPF), (int32_t)1667);
  assertEqual(Multiply32ByFixedPointFraction64(-4000, &FPF), (int32_t)2223);
  assertEqual(Multiply32ByFixedPointFraction64(-5000, &FPF), (int32_t)2778);
  assertEqual(Multiply32ByFixedPointFraction64(-6000, &FPF), (int32_t)3334);
  assertEqual(Multiply32ByFixedPointFraction64(-7000, &FPF), (int32_t)3889);
  assertEqual(Multiply32ByFixedPointFraction64(-8000, &FPF), (int32_t)4445);
  assertEqual(Multiply32ByFixedPointFraction64(-9000, &FPF), (int32_t)5000);
#endif

  long failed = 0;
  for(int32_t ix = 0; ix > INT32_MIN / 4000; --ix){
    if(ix%1024 == 0) { Serial.print(spinner[abs((ix/1024)%4)]); }
    int32_t expVal = -(((ix * 5L) - 8) / 9);
    int32_t actVal = Multiply32ByFixedPointFraction64(ix, &FPF);
    if(expVal != actVal){
      ++failed;
      if(failed < 20){
        Serial.print(F("ix="));Serial.print(ix);
        Serial.print(F("\texp="));Serial.print(expVal);
        Serial.print(F("\tact="));Serial.print(actVal);
        Serial.print(F("\tdiff="));Serial.print(actVal - expVal);
        Serial.println();
      }
    }
  }
  Serial.println();
  assertEqual(failed, 0L);
}
test(T1235Multiply32ByFixedPointFraction64_5DivM9_Pos) {
  FixedPointFraction64_t FPF;
  Ratio32ToFixedPointFraction64(5, -9, &FPF, nullptr);
  assertEqual(Multiply32ByFixedPointFraction64(0, &FPF), (int32_t)0);

  assertEqual(Multiply32ByFixedPointFraction64(1, &FPF), (int32_t)0);
  assertEqual(Multiply32ByFixedPointFraction64(2, &FPF), (int32_t)-1);
  assertEqual(Multiply32ByFixedPointFraction64(3, &FPF), (int32_t)-1);
  assertEqual(Multiply32ByFixedPointFraction64(4, &FPF), (int32_t)-2);
  assertEqual(Multiply32ByFixedPointFraction64(5, &FPF), (int32_t)-2);
  assertEqual(Multiply32ByFixedPointFraction64(6, &FPF), (int32_t)-3);
  assertEqual(Multiply32ByFixedPointFraction64(7, &FPF), (int32_t)-3);
  assertEqual(Multiply32ByFixedPointFraction64(8, &FPF), (int32_t)-4);
  assertEqual(Multiply32ByFixedPointFraction64(9, &FPF), (int32_t)-5);

#if 0
  assertEqual(Multiply32ByFixedPointFraction64(10, &FPF), (int32_t)-5);
  assertEqual(Multiply32ByFixedPointFraction64(100, &FPF), (int32_t)-55);
  assertEqual(Multiply32ByFixedPointFraction64(1000, &FPF), (int32_t)-555);

  assertEqual(Multiply32ByFixedPointFraction64(2000, &FPF), (int32_t)-1111);
  assertEqual(Multiply32ByFixedPointFraction64(3000, &FPF), (int32_t)-1666);
  assertEqual(Multiply32ByFixedPointFraction64(4000, &FPF), (int32_t)-2222);
  assertEqual(Multiply32ByFixedPointFraction64(5000, &FPF), (int32_t)-2777);
  assertEqual(Multiply32ByFixedPointFraction64(6000, &FPF), (int32_t)-3333);
  assertEqual(Multiply32ByFixedPointFraction64(7000, &FPF), (int32_t)-3888);
  assertEqual(Multiply32ByFixedPointFraction64(8000, &FPF), (int32_t)-4444);
  assertEqual(Multiply32ByFixedPointFraction64(9000, &FPF), (int32_t)-5000);
#endif

  long failed = 0;
  for(int32_t ix = 0; ix < INT32_MAX / 4000; ++ix){
    if(ix%1024 == 0) { Serial.print(spinner[abs((ix/1024)%4)]); }
    int32_t expVal = -(((ix * 5L) - 0) / 9);
    int32_t actVal = Multiply32ByFixedPointFraction64(ix, &FPF);
    if(expVal != actVal){
      ++failed;
      if(failed < 20){
        Serial.print(F("ix="));Serial.print(ix);
        Serial.print(F("\texp="));Serial.print(expVal);
        Serial.print(F("\tact="));Serial.print(actVal);
        Serial.print(F("\tdiff="));Serial.print(actVal - expVal);
        Serial.println();
      }
    }
  }
  Serial.println();
  assertEqual(failed, 0L);
}
test(T1231Multiply32ByFixedPointFraction64_5Div9_Neg) {
  FixedPointFraction64_t FPF;
  Ratio32ToFixedPointFraction64(5, 9, nullptr, &FPF);
  assertEqual(Multiply32ByFixedPointFraction64(0, &FPF), (int32_t)0);

  assertEqual(Multiply32ByFixedPointFraction64(-1, &FPF), (int32_t)-1);
  assertEqual(Multiply32ByFixedPointFraction64(-2, &FPF), (int32_t)-2);
  assertEqual(Multiply32ByFixedPointFraction64(-3, &FPF), (int32_t)-2);
  assertEqual(Multiply32ByFixedPointFraction64(-4, &FPF), (int32_t)-3);
  assertEqual(Multiply32ByFixedPointFraction64(-5, &FPF), (int32_t)-3);
  assertEqual(Multiply32ByFixedPointFraction64(-6, &FPF), (int32_t)-4);
  assertEqual(Multiply32ByFixedPointFraction64(-7, &FPF), (int32_t)-4);
  assertEqual(Multiply32ByFixedPointFraction64(-8, &FPF), (int32_t)-5);
  assertEqual(Multiply32ByFixedPointFraction64(-9, &FPF), (int32_t)-5);

#if 0
  assertEqual(Multiply32ByFixedPointFraction64(-10, &FPF), (int32_t)-6);
  assertEqual(Multiply32ByFixedPointFraction64(-100, &FPF), (int32_t)-56);
  assertEqual(Multiply32ByFixedPointFraction64(-1000, &FPF), (int32_t)-556);

  assertEqual(Multiply32ByFixedPointFraction64(-2000, &FPF), (int32_t)-1112);
  assertEqual(Multiply32ByFixedPointFraction64(-3000, &FPF), (int32_t)-1667);
  assertEqual(Multiply32ByFixedPointFraction64(-4000, &FPF), (int32_t)-2223);
  assertEqual(Multiply32ByFixedPointFraction64(-5000, &FPF), (int32_t)-2778);
  assertEqual(Multiply32ByFixedPointFraction64(-6000, &FPF), (int32_t)-3334);
  assertEqual(Multiply32ByFixedPointFraction64(-7000, &FPF), (int32_t)-3889);
  assertEqual(Multiply32ByFixedPointFraction64(-8000, &FPF), (int32_t)-4445);
  assertEqual(Multiply32ByFixedPointFraction64(-9000, &FPF), (int32_t)-5000);
#endif

  long failed = 0;
  for(int32_t ix = 0; ix > INT32_MIN / 4000; --ix){
    if(ix%1024 == 0) { Serial.print(spinner[abs((ix/1024)%4)]); }
    int32_t expVal = (((ix * 5L) - 8) / 9);
    int32_t actVal = Multiply32ByFixedPointFraction64(ix, &FPF);
    if(expVal != actVal){
      ++failed;
      if(failed < 20){
        Serial.print(F("ix="));Serial.print(ix);
        Serial.print(F("\texp="));Serial.print(expVal);
        Serial.print(F("\tact="));Serial.print(actVal);
        Serial.print(F("\tdiff="));Serial.print(actVal - expVal);
        Serial.println();
      }
    }
  }
  Serial.println();
  assertEqual(failed, 0L);
}
test(T1230Multiply32ByFixedPointFraction64_5Div9_Pos) {
  FixedPointFraction64_t FPF;
  Ratio32ToFixedPointFraction64(5, 9, &FPF, nullptr);
  assertEqual(Multiply32ByFixedPointFraction64(0, &FPF), (int32_t)0);

  assertEqual(Multiply32ByFixedPointFraction64(1, &FPF), (int32_t)0);
  assertEqual(Multiply32ByFixedPointFraction64(2, &FPF), (int32_t)1);
  assertEqual(Multiply32ByFixedPointFraction64(3, &FPF), (int32_t)1);
  assertEqual(Multiply32ByFixedPointFraction64(4, &FPF), (int32_t)2);
  assertEqual(Multiply32ByFixedPointFraction64(5, &FPF), (int32_t)2);
  assertEqual(Multiply32ByFixedPointFraction64(6, &FPF), (int32_t)3);
  assertEqual(Multiply32ByFixedPointFraction64(7, &FPF), (int32_t)3);
  assertEqual(Multiply32ByFixedPointFraction64(8, &FPF), (int32_t)4);
  assertEqual(Multiply32ByFixedPointFraction64(9, &FPF), (int32_t)5);

#if 0
  assertEqual(Multiply32ByFixedPointFraction64(10, &FPF), (int32_t)5);
  assertEqual(Multiply32ByFixedPointFraction64(100, &FPF), (int32_t)55);
  assertEqual(Multiply32ByFixedPointFraction64(1000, &FPF), (int32_t)555);

  assertEqual(Multiply32ByFixedPointFraction64(2000, &FPF), (int32_t)1111);
  assertEqual(Multiply32ByFixedPointFraction64(3000, &FPF), (int32_t)1666);
  assertEqual(Multiply32ByFixedPointFraction64(4000, &FPF), (int32_t)2222);
  assertEqual(Multiply32ByFixedPointFraction64(5000, &FPF), (int32_t)2777);
  assertEqual(Multiply32ByFixedPointFraction64(6000, &FPF), (int32_t)3333);
  assertEqual(Multiply32ByFixedPointFraction64(7000, &FPF), (int32_t)3888);
  assertEqual(Multiply32ByFixedPointFraction64(8000, &FPF), (int32_t)4444);
  assertEqual(Multiply32ByFixedPointFraction64(9000, &FPF), (int32_t)5000);
#endif

  long failed = 0;
  for(int32_t ix = 0; ix < INT32_MAX / 4000; ++ix){
    if(ix%1024 == 0) { Serial.print(spinner[abs((ix/1024)%4)]); }
    int32_t expVal = (((ix * 5L) - 0) / 9);
    int32_t actVal = Multiply32ByFixedPointFraction64(ix, &FPF);
    if(expVal != actVal){
      ++failed;
      if(failed < 20){
        Serial.print(F("ix="));Serial.print(ix);
        Serial.print(F("\texp="));Serial.print(expVal);
        Serial.print(F("\tact="));Serial.print(actVal);
        Serial.print(F("\tdiff="));Serial.print(actVal - expVal);
        Serial.println();
      }
    }
  }
  Serial.println();
  assertEqual(failed, 0L);
}

test(T1226Multiply32ByFixedPointFraction64_1DivM3_Neg) {
  FixedPointFraction64_t FPF;
  Ratio32ToFixedPointFraction64(1, -3, nullptr, &FPF);
  assertEqual(Multiply32ByFixedPointFraction64(0, &FPF), (int32_t)0);

  assertEqual(Multiply32ByFixedPointFraction64(-1, &FPF), (int32_t)1);
  assertEqual(Multiply32ByFixedPointFraction64(-2, &FPF), (int32_t)1);
  assertEqual(Multiply32ByFixedPointFraction64(-3, &FPF), (int32_t)1);
  assertEqual(Multiply32ByFixedPointFraction64(-4, &FPF), (int32_t)2);
  assertEqual(Multiply32ByFixedPointFraction64(-5, &FPF), (int32_t)2);
  assertEqual(Multiply32ByFixedPointFraction64(-6, &FPF), (int32_t)2);
  assertEqual(Multiply32ByFixedPointFraction64(-7, &FPF), (int32_t)3);
  assertEqual(Multiply32ByFixedPointFraction64(-8, &FPF), (int32_t)3);
  assertEqual(Multiply32ByFixedPointFraction64(-9, &FPF), (int32_t)3);

#if 0
  assertEqual(Multiply32ByFixedPointFraction64(-10, &FPF), (int32_t)4);
  assertEqual(Multiply32ByFixedPointFraction64(-100, &FPF), (int32_t)34);
  assertEqual(Multiply32ByFixedPointFraction64(-1000, &FPF), (int32_t)334);

  assertEqual(Multiply32ByFixedPointFraction64(-2000, &FPF), (int32_t)667);
  assertEqual(Multiply32ByFixedPointFraction64(-3000, &FPF), (int32_t)1000);
  assertEqual(Multiply32ByFixedPointFraction64(-4000, &FPF), (int32_t)1334);
  assertEqual(Multiply32ByFixedPointFraction64(-5000, &FPF), (int32_t)1667);
  assertEqual(Multiply32ByFixedPointFraction64(-6000, &FPF), (int32_t)2000);
  assertEqual(Multiply32ByFixedPointFraction64(-7000, &FPF), (int32_t)2334);
  assertEqual(Multiply32ByFixedPointFraction64(-8000, &FPF), (int32_t)2667);
  assertEqual(Multiply32ByFixedPointFraction64(-9000, &FPF), (int32_t)3000);
#endif

  long failed = 0;
  for(int32_t ix = 0; ix > INT32_MIN / 4000; --ix){
    if(ix%1024 == 0) { Serial.print(spinner[abs((ix/1024)%4)]); }
    int32_t expVal = -(((ix * 1L) - 2) / 3);
    int32_t actVal = Multiply32ByFixedPointFraction64(ix, &FPF);
    if(expVal != actVal){
      ++failed;
      if(failed < 20){
        Serial.print(F("ix="));Serial.print(ix);
        Serial.print(F("\texp="));Serial.print(expVal);
        Serial.print(F("\tact="));Serial.print(actVal);
        Serial.print(F("\tdiff="));Serial.print(actVal - expVal);
        Serial.println();
      }
    }
  }
  Serial.println();
  assertEqual(failed, 0L);
}
test(T1225Multiply32ByFixedPointFraction64_1DivM3_Pos) {
  FixedPointFraction64_t FPF;
  Ratio32ToFixedPointFraction64(1, -3, &FPF, nullptr);
  assertEqual(Multiply32ByFixedPointFraction64(0, &FPF), (int32_t)0);

  assertEqual(Multiply32ByFixedPointFraction64(1, &FPF), (int32_t)0);
  assertEqual(Multiply32ByFixedPointFraction64(2, &FPF), (int32_t)0);
  assertEqual(Multiply32ByFixedPointFraction64(3, &FPF), (int32_t)-1);
  assertEqual(Multiply32ByFixedPointFraction64(4, &FPF), (int32_t)-1);
  assertEqual(Multiply32ByFixedPointFraction64(5, &FPF), (int32_t)-1);
  assertEqual(Multiply32ByFixedPointFraction64(6, &FPF), (int32_t)-2);
  assertEqual(Multiply32ByFixedPointFraction64(7, &FPF), (int32_t)-2);
  assertEqual(Multiply32ByFixedPointFraction64(8, &FPF), (int32_t)-2);
  assertEqual(Multiply32ByFixedPointFraction64(9, &FPF), (int32_t)-3);

#if 0
  assertEqual(Multiply32ByFixedPointFraction64(10, &FPF), (int32_t)-3);
  assertEqual(Multiply32ByFixedPointFraction64(100, &FPF), (int32_t)-33);
  assertEqual(Multiply32ByFixedPointFraction64(1000, &FPF), (int32_t)-333);

  assertEqual(Multiply32ByFixedPointFraction64(2000, &FPF), (int32_t)-666);
  assertEqual(Multiply32ByFixedPointFraction64(3000, &FPF), (int32_t)-1000);
  assertEqual(Multiply32ByFixedPointFraction64(4000, &FPF), (int32_t)-1333);
  assertEqual(Multiply32ByFixedPointFraction64(5000, &FPF), (int32_t)-1666);
  assertEqual(Multiply32ByFixedPointFraction64(6000, &FPF), (int32_t)-2000);
  assertEqual(Multiply32ByFixedPointFraction64(7000, &FPF), (int32_t)-2333);
  assertEqual(Multiply32ByFixedPointFraction64(8000, &FPF), (int32_t)-2666);
  assertEqual(Multiply32ByFixedPointFraction64(9000, &FPF), (int32_t)-3000);
#endif

  long failed = 0;
  for(int32_t ix = 0; ix < INT32_MAX / 4000; ++ix){
    if(ix%1024 == 0) { Serial.print(spinner[abs((ix/1024)%4)]); }
    int32_t expVal = -(((ix * 1L) - 0) / 3);
    int32_t actVal = Multiply32ByFixedPointFraction64(ix, &FPF);
    if(expVal != actVal){
      ++failed;
      if(failed < 20){
        Serial.print(F("ix="));Serial.print(ix);
        Serial.print(F("\texp="));Serial.print(expVal);
        Serial.print(F("\tact="));Serial.print(actVal);
        Serial.print(F("\tdiff="));Serial.print(actVal - expVal);
        Serial.println();
      }
    }
  }
  Serial.println();
  assertEqual(failed, 0L);
}
test(T1221Multiply32ByFixedPointFraction64_1Div3_Neg) {
  FixedPointFraction64_t FPF;
  Ratio32ToFixedPointFraction64(1, 3, nullptr, &FPF);
  assertEqual(Multiply32ByFixedPointFraction64(0, &FPF), (int32_t)0);

  assertEqual(Multiply32ByFixedPointFraction64(-1, &FPF), (int32_t)-1);
  assertEqual(Multiply32ByFixedPointFraction64(-2, &FPF), (int32_t)-1);
  assertEqual(Multiply32ByFixedPointFraction64(-3, &FPF), (int32_t)-1);
  assertEqual(Multiply32ByFixedPointFraction64(-4, &FPF), (int32_t)-2);
  assertEqual(Multiply32ByFixedPointFraction64(-5, &FPF), (int32_t)-2);
  assertEqual(Multiply32ByFixedPointFraction64(-6, &FPF), (int32_t)-2);
  assertEqual(Multiply32ByFixedPointFraction64(-7, &FPF), (int32_t)-3);
  assertEqual(Multiply32ByFixedPointFraction64(-8, &FPF), (int32_t)-3);
  assertEqual(Multiply32ByFixedPointFraction64(-9, &FPF), (int32_t)-3);

#if 0
  assertEqual(Multiply32ByFixedPointFraction64(-10, &FPF), (int32_t)-4);
  assertEqual(Multiply32ByFixedPointFraction64(-100, &FPF), (int32_t)-34);
  assertEqual(Multiply32ByFixedPointFraction64(-1000, &FPF), (int32_t)-334);

  assertEqual(Multiply32ByFixedPointFraction64(-2000, &FPF), (int32_t)-667);
  assertEqual(Multiply32ByFixedPointFraction64(-3000, &FPF), (int32_t)-1000);
  assertEqual(Multiply32ByFixedPointFraction64(-4000, &FPF), (int32_t)-1334);
  assertEqual(Multiply32ByFixedPointFraction64(-5000, &FPF), (int32_t)-1667);
  assertEqual(Multiply32ByFixedPointFraction64(-6000, &FPF), (int32_t)-2000);
  assertEqual(Multiply32ByFixedPointFraction64(-7000, &FPF), (int32_t)-2334);
  assertEqual(Multiply32ByFixedPointFraction64(-8000, &FPF), (int32_t)-2667);
  assertEqual(Multiply32ByFixedPointFraction64(-9000, &FPF), (int32_t)-3000);
#endif

  long failed = 0;
  for(int32_t ix = 0; ix > INT32_MIN / 4000; --ix){
    if(ix%1024 == 0) { Serial.print(spinner[abs((ix/1024)%4)]); }
    int32_t expVal = (((ix * 1L) - 2) / 3);
    int32_t actVal = Multiply32ByFixedPointFraction64(ix, &FPF);
    if(expVal != actVal){
      ++failed;
      if(failed < 20){
        Serial.print(F("ix="));Serial.print(ix);
        Serial.print(F("\texp="));Serial.print(expVal);
        Serial.print(F("\tact="));Serial.print(actVal);
        Serial.print(F("\tdiff="));Serial.print(actVal - expVal);
        Serial.println();
      }
    }
  }
  Serial.println();
  assertEqual(failed, 0L);
}
test(T1220Multiply32ByFixedPointFraction64_1Div3_Pos) {
  FixedPointFraction64_t FPF;
  Ratio32ToFixedPointFraction64(1, 3, &FPF, nullptr);
  assertEqual(Multiply32ByFixedPointFraction64(0, &FPF), (int32_t)0);

  assertEqual(Multiply32ByFixedPointFraction64(1, &FPF), (int32_t)0);
  assertEqual(Multiply32ByFixedPointFraction64(2, &FPF), (int32_t)0);
  assertEqual(Multiply32ByFixedPointFraction64(3, &FPF), (int32_t)1);
  assertEqual(Multiply32ByFixedPointFraction64(4, &FPF), (int32_t)1);
  assertEqual(Multiply32ByFixedPointFraction64(5, &FPF), (int32_t)1);
  assertEqual(Multiply32ByFixedPointFraction64(6, &FPF), (int32_t)2);
  assertEqual(Multiply32ByFixedPointFraction64(7, &FPF), (int32_t)2);
  assertEqual(Multiply32ByFixedPointFraction64(8, &FPF), (int32_t)2);
  assertEqual(Multiply32ByFixedPointFraction64(9, &FPF), (int32_t)3);

#if 0
  assertEqual(Multiply32ByFixedPointFraction64(10, &FPF), (int32_t)3);
  assertEqual(Multiply32ByFixedPointFraction64(100, &FPF), (int32_t)33);
  assertEqual(Multiply32ByFixedPointFraction64(1000, &FPF), (int32_t)333);

  assertEqual(Multiply32ByFixedPointFraction64(2000, &FPF), (int32_t)666);
  assertEqual(Multiply32ByFixedPointFraction64(3000, &FPF), (int32_t)1000);
  assertEqual(Multiply32ByFixedPointFraction64(4000, &FPF), (int32_t)1333);
  assertEqual(Multiply32ByFixedPointFraction64(5000, &FPF), (int32_t)1666);
  assertEqual(Multiply32ByFixedPointFraction64(6000, &FPF), (int32_t)2000);
  assertEqual(Multiply32ByFixedPointFraction64(7000, &FPF), (int32_t)2333);
  assertEqual(Multiply32ByFixedPointFraction64(8000, &FPF), (int32_t)2666);
  assertEqual(Multiply32ByFixedPointFraction64(9000, &FPF), (int32_t)3000);
#endif

  long failed = 0;
  for(int32_t ix = 0; ix < INT32_MAX / 4000; ++ix){
    if(ix%1024 == 0) { Serial.print(spinner[abs((ix/1024)%4)]); }
    int32_t expVal = (((ix * 1L) - 0) / 3);
    int32_t actVal = Multiply32ByFixedPointFraction64(ix, &FPF);
    if(expVal != actVal){
      ++failed;
      if(failed < 20){
        Serial.print(F("ix="));Serial.print(ix);
        Serial.print(F("\texp="));Serial.print(expVal);
        Serial.print(F("\tact="));Serial.print(actVal);
        Serial.print(F("\tdiff="));Serial.print(actVal - expVal);
        Serial.println();
      }
    }
  }
  Serial.println();
  assertEqual(failed, 0L);
}

test(T1216Multiply32ByFixedPointFraction64_1DivM4_Neg) {
  FixedPointFraction64_t FPF;
  Ratio32ToFixedPointFraction64(1, -4, nullptr, &FPF);
  assertEqual(Multiply32ByFixedPointFraction64(0, &FPF), (int32_t)0);

  assertEqual(Multiply32ByFixedPointFraction64(-1, &FPF), (int32_t)1);
  assertEqual(Multiply32ByFixedPointFraction64(-2, &FPF), (int32_t)1);
  assertEqual(Multiply32ByFixedPointFraction64(-3, &FPF), (int32_t)1);
  assertEqual(Multiply32ByFixedPointFraction64(-4, &FPF), (int32_t)1);
  assertEqual(Multiply32ByFixedPointFraction64(-5, &FPF), (int32_t)2);
  assertEqual(Multiply32ByFixedPointFraction64(-6, &FPF), (int32_t)2);
  assertEqual(Multiply32ByFixedPointFraction64(-7, &FPF), (int32_t)2);
  assertEqual(Multiply32ByFixedPointFraction64(-8, &FPF), (int32_t)2);
  assertEqual(Multiply32ByFixedPointFraction64(-9, &FPF), (int32_t)3);

#if 0
  assertEqual(Multiply32ByFixedPointFraction64(-10, &FPF), (int32_t)3);
  assertEqual(Multiply32ByFixedPointFraction64(-100, &FPF), (int32_t)25);
  assertEqual(Multiply32ByFixedPointFraction64(-1000, &FPF), (int32_t)250);

  assertEqual(Multiply32ByFixedPointFraction64(-2000, &FPF), (int32_t)500);
  assertEqual(Multiply32ByFixedPointFraction64(-3000, &FPF), (int32_t)750);
  assertEqual(Multiply32ByFixedPointFraction64(-4000, &FPF), (int32_t)1000);
  assertEqual(Multiply32ByFixedPointFraction64(-5000, &FPF), (int32_t)1250);
  assertEqual(Multiply32ByFixedPointFraction64(-6000, &FPF), (int32_t)1500);
  assertEqual(Multiply32ByFixedPointFraction64(-7000, &FPF), (int32_t)1750);
  assertEqual(Multiply32ByFixedPointFraction64(-8000, &FPF), (int32_t)2000);
  assertEqual(Multiply32ByFixedPointFraction64(-9000, &FPF), (int32_t)2250);
#endif

  long failed = 0;
  for(int32_t ix = 0; ix > INT32_MIN / 4000; --ix){
    if(ix%1024 == 0) { Serial.print(spinner[abs((ix/1024)%4)]); }
    int32_t expVal = -(((ix * 1L) - 3) / 4);
    int32_t actVal = Multiply32ByFixedPointFraction64(ix, &FPF);
    if(expVal != actVal){
      ++failed;
      if(failed < 20){
        Serial.print(F("ix="));Serial.print(ix);
        Serial.print(F("\texp="));Serial.print(expVal);
        Serial.print(F("\tact="));Serial.print(actVal);
        Serial.print(F("\tdiff="));Serial.print(actVal - expVal);
        Serial.println();
      }
    }
  }
  Serial.println();
  assertEqual(failed, 0L);
}
test(T1215Multiply32ByFixedPointFraction64_1DivM4_Pos) {
  FixedPointFraction64_t FPF;
  Ratio32ToFixedPointFraction64(1, -4, &FPF, nullptr);
  assertEqual(Multiply32ByFixedPointFraction64(0, &FPF), (int32_t)0);

  assertEqual(Multiply32ByFixedPointFraction64(1, &FPF), (int32_t)0);
  assertEqual(Multiply32ByFixedPointFraction64(2, &FPF), (int32_t)0);
  assertEqual(Multiply32ByFixedPointFraction64(3, &FPF), (int32_t)0);
  assertEqual(Multiply32ByFixedPointFraction64(4, &FPF), (int32_t)-1);
  assertEqual(Multiply32ByFixedPointFraction64(5, &FPF), (int32_t)-1);
  assertEqual(Multiply32ByFixedPointFraction64(6, &FPF), (int32_t)-1);
  assertEqual(Multiply32ByFixedPointFraction64(7, &FPF), (int32_t)-1);
  assertEqual(Multiply32ByFixedPointFraction64(8, &FPF), (int32_t)-2);
  assertEqual(Multiply32ByFixedPointFraction64(9, &FPF), (int32_t)-2);

#if 0
  assertEqual(Multiply32ByFixedPointFraction64(10, &FPF), (int32_t)-2);
  assertEqual(Multiply32ByFixedPointFraction64(100, &FPF), (int32_t)-25);
  assertEqual(Multiply32ByFixedPointFraction64(1000, &FPF), (int32_t)-250);

  assertEqual(Multiply32ByFixedPointFraction64(2000, &FPF), (int32_t)-500);
  assertEqual(Multiply32ByFixedPointFraction64(3000, &FPF), (int32_t)-750);
  assertEqual(Multiply32ByFixedPointFraction64(4000, &FPF), (int32_t)-1000);
  assertEqual(Multiply32ByFixedPointFraction64(5000, &FPF), (int32_t)-1250);
  assertEqual(Multiply32ByFixedPointFraction64(6000, &FPF), (int32_t)-1500);
  assertEqual(Multiply32ByFixedPointFraction64(7000, &FPF), (int32_t)-1750);
  assertEqual(Multiply32ByFixedPointFraction64(8000, &FPF), (int32_t)-2000);
  assertEqual(Multiply32ByFixedPointFraction64(9000, &FPF), (int32_t)-2250);
#endif

  long failed = 0;
  for(int32_t ix = 0; ix < INT32_MAX / 4000; ++ix){
    if(ix%1024 == 0) { Serial.print(spinner[abs((ix/1024)%4)]); }
    int32_t expVal = -(((ix * 1L) - 0) / 4);
    int32_t actVal = Multiply32ByFixedPointFraction64(ix, &FPF);
    if(expVal != actVal){
      ++failed;
      if(failed < 20){
        Serial.print(F("ix="));Serial.print(ix);
        Serial.print(F("\texp="));Serial.print(expVal);
        Serial.print(F("\tact="));Serial.print(actVal);
        Serial.print(F("\tdiff="));Serial.print(actVal - expVal);
        Serial.println();
      }
    }
  }
  Serial.println();
  assertEqual(failed, 0L);
}
test(T1211Multiply32ByFixedPointFraction64_1Div4_Neg) {
  FixedPointFraction64_t FPF;
  Ratio32ToFixedPointFraction64(1, 4, nullptr, &FPF);
  assertEqual(Multiply32ByFixedPointFraction64(0, &FPF), (int32_t)0);

  assertEqual(Multiply32ByFixedPointFraction64(-1, &FPF), (int32_t)-1);
  assertEqual(Multiply32ByFixedPointFraction64(-2, &FPF), (int32_t)-1);
  assertEqual(Multiply32ByFixedPointFraction64(-3, &FPF), (int32_t)-1);
  assertEqual(Multiply32ByFixedPointFraction64(-4, &FPF), (int32_t)-1);
  assertEqual(Multiply32ByFixedPointFraction64(-5, &FPF), (int32_t)-2);
  assertEqual(Multiply32ByFixedPointFraction64(-6, &FPF), (int32_t)-2);
  assertEqual(Multiply32ByFixedPointFraction64(-7, &FPF), (int32_t)-2);
  assertEqual(Multiply32ByFixedPointFraction64(-8, &FPF), (int32_t)-2);
  assertEqual(Multiply32ByFixedPointFraction64(-9, &FPF), (int32_t)-3);

#if 0
  assertEqual(Multiply32ByFixedPointFraction64(-10, &FPF), (int32_t)-3);
  assertEqual(Multiply32ByFixedPointFraction64(-100, &FPF), (int32_t)-25);
  assertEqual(Multiply32ByFixedPointFraction64(-1000, &FPF), (int32_t)-250);

  assertEqual(Multiply32ByFixedPointFraction64(-2000, &FPF), (int32_t)-500);
  assertEqual(Multiply32ByFixedPointFraction64(-3000, &FPF), (int32_t)-750);
  assertEqual(Multiply32ByFixedPointFraction64(-4000, &FPF), (int32_t)-1000);
  assertEqual(Multiply32ByFixedPointFraction64(-5000, &FPF), (int32_t)-1250);
  assertEqual(Multiply32ByFixedPointFraction64(-6000, &FPF), (int32_t)-1500);
  assertEqual(Multiply32ByFixedPointFraction64(-7000, &FPF), (int32_t)-1750);
  assertEqual(Multiply32ByFixedPointFraction64(-8000, &FPF), (int32_t)-2000);
  assertEqual(Multiply32ByFixedPointFraction64(-9000, &FPF), (int32_t)-2250);
#endif

  long failed = 0;
  for(int32_t ix = 0; ix > INT32_MIN / 4000; --ix){
    if(ix%1024 == 0) { Serial.print(spinner[abs((ix/1024)%4)]); }
    int32_t expVal = (((ix * 1L) - 3) / 4);
    int32_t actVal = Multiply32ByFixedPointFraction64(ix, &FPF);
    if(expVal != actVal){
      ++failed;
      if(failed < 20){
        Serial.print(F("ix="));Serial.print(ix);
        Serial.print(F("\texp="));Serial.print(expVal);
        Serial.print(F("\tact="));Serial.print(actVal);
        Serial.print(F("\tdiff="));Serial.print(actVal - expVal);
        Serial.println();
      }
    }
  }
  Serial.println();
  assertEqual(failed, 0L);
}
test(T1210Multiply32ByFixedPointFraction64_1Div4_Pos) {
  FixedPointFraction64_t FPF;
  Ratio32ToFixedPointFraction64(1, 4, &FPF, nullptr);
  assertEqual(Multiply32ByFixedPointFraction64(0, &FPF), (int32_t)0);

  assertEqual(Multiply32ByFixedPointFraction64(1, &FPF), (int32_t)0);
  assertEqual(Multiply32ByFixedPointFraction64(2, &FPF), (int32_t)0);
  assertEqual(Multiply32ByFixedPointFraction64(3, &FPF), (int32_t)0);
  assertEqual(Multiply32ByFixedPointFraction64(4, &FPF), (int32_t)1);
  assertEqual(Multiply32ByFixedPointFraction64(5, &FPF), (int32_t)1);
  assertEqual(Multiply32ByFixedPointFraction64(6, &FPF), (int32_t)1);
  assertEqual(Multiply32ByFixedPointFraction64(7, &FPF), (int32_t)1);
  assertEqual(Multiply32ByFixedPointFraction64(8, &FPF), (int32_t)2);
  assertEqual(Multiply32ByFixedPointFraction64(9, &FPF), (int32_t)2);

#if 0
  assertEqual(Multiply32ByFixedPointFraction64(10, &FPF), (int32_t)2);
  assertEqual(Multiply32ByFixedPointFraction64(100, &FPF), (int32_t)25);
  assertEqual(Multiply32ByFixedPointFraction64(1000, &FPF), (int32_t)250);

  assertEqual(Multiply32ByFixedPointFraction64(2000, &FPF), (int32_t)500);
  assertEqual(Multiply32ByFixedPointFraction64(3000, &FPF), (int32_t)750);
  assertEqual(Multiply32ByFixedPointFraction64(4000, &FPF), (int32_t)1000);
  assertEqual(Multiply32ByFixedPointFraction64(5000, &FPF), (int32_t)1250);
  assertEqual(Multiply32ByFixedPointFraction64(6000, &FPF), (int32_t)1500);
  assertEqual(Multiply32ByFixedPointFraction64(7000, &FPF), (int32_t)1750);
  assertEqual(Multiply32ByFixedPointFraction64(8000, &FPF), (int32_t)2000);
  assertEqual(Multiply32ByFixedPointFraction64(9000, &FPF), (int32_t)2250);
#endif

  long failed = 0;
  for(int32_t ix = 0; ix < INT32_MAX / 4000; ++ix){
    if(ix%1024 == 0) { Serial.print(spinner[abs((ix/1024)%4)]); }
    int32_t expVal = (((ix * 1L) - 0) / 4);
    int32_t actVal = Multiply32ByFixedPointFraction64(ix, &FPF);
    if(expVal != actVal){
      ++failed;
      if(failed < 20){
        Serial.print(F("ix="));Serial.print(ix);
        Serial.print(F("\texp="));Serial.print(expVal);
        Serial.print(F("\tact="));Serial.print(actVal);
        Serial.print(F("\tdiff="));Serial.print(actVal - expVal);
        Serial.println();
      }
    }
  }
  Serial.println();
  assertEqual(failed, 0L);
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
