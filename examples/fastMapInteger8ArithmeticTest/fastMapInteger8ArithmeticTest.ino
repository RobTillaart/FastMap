//
//    FILE: fastMapInteger8ArithmeticTest.ino
//  AUTHOR: Brewmanz (Bryan White)
// VERSION: 0.1.1
// PURPOSE: Test of FastMapInt(16) helper functions
//    DATE: 2020-09-08
//     URL: https://github.com/RobTillaart/FastMap

//#include <AUnitVerbose.h> // too much for Nano!
#include <AUnit.h>
#include <FastMap.h>

volatile int i, j;

test(T9130FastMapInt_F2C_M40To212) {
  FastMapInt mapper;
  mapper.init(-40, 212, -40, 100, &Serial);
  Serial.println();
  mapper.Dump(&Serial);
  Serial.println();
  int fails = 0;
  int outCalcInfo;
  for(int ix = 0; ix <= 500; ++ix){
    int valExp = (ix + 40 + 90) * 5 / 9 - 50 - 40;
    int valAct = mapper.map(ix, &outCalcInfo);
    if(valExp != valAct){
      ++fails;
      Serial.print(F("ix="));Serial.print(ix);
      Serial.print(F("\texp="));Serial.print(valExp);
      Serial.print(F("\tact="));Serial.print(valAct);
      Serial.print(F("\toCI="));Serial.print(outCalcInfo);
      Serial.println();
    }
  }
  Serial.println();
  assertEqual(fails, 0);
}

test(T1136Multiply8ByFixedPointFraction16_5DivM9_Neg) {
  FixedPointFraction16_t FPF;
  Ratio8ToFixedPointFraction16(5, -9, nullptr, &FPF);
  assertEqual(FPF.MaxInput, 57 * 2);
  assertEqual(Multiply8ByFixedPointFraction16(0, &FPF), 0);

  assertEqual(Multiply8ByFixedPointFraction16(-1, &FPF), 1);
  assertEqual(Multiply8ByFixedPointFraction16(-2, &FPF), 2);
  assertEqual(Multiply8ByFixedPointFraction16(-3, &FPF), 2);
  assertEqual(Multiply8ByFixedPointFraction16(-4, &FPF), 3);
  assertEqual(Multiply8ByFixedPointFraction16(-5, &FPF), 3);
  assertEqual(Multiply8ByFixedPointFraction16(-6, &FPF), 4);
  assertEqual(Multiply8ByFixedPointFraction16(-7, &FPF), 4);
  assertEqual(Multiply8ByFixedPointFraction16(-8, &FPF), 5);
  assertEqual(Multiply8ByFixedPointFraction16(-9, &FPF), 5);

  assertEqual(Multiply8ByFixedPointFraction16(-10, &FPF), 6);
  assertEqual(Multiply8ByFixedPointFraction16(-57, &FPF), 32);

  long failed = 0;
  Serial.print(F("@"));Serial.print(__LINE__);Serial.print(F(": FPF.MaxInput="));Serial.print(FPF.MaxInput);Serial.println(F("..."));
  for(int32_t ix = 0; ix >= -FPF.MaxInput; --ix){

    int16_t expVal = -(((ix * 5L) - 8) / 9);
    int16_t actVal = Multiply8ByFixedPointFraction16(ix, &FPF);
    if(expVal != actVal){
      ++failed;
      if(failed < 20) {
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

test(T1135Multiply8ByFixedPointFraction16_5DivM9_Pos) {
  FixedPointFraction16_t FPF;
  Ratio8ToFixedPointFraction16(5, -9, &FPF, nullptr, &Serial);
  assertEqual(FPF.MaxInput, 57);
  assertEqual(Multiply8ByFixedPointFraction16(0, &FPF), 0);

  assertEqual(Multiply8ByFixedPointFraction16(1, &FPF), 0);
  assertEqual(Multiply8ByFixedPointFraction16(2, &FPF), -1);
  assertEqual(Multiply8ByFixedPointFraction16(3, &FPF), -1);
  assertEqual(Multiply8ByFixedPointFraction16(4, &FPF), -2);
  assertEqual(Multiply8ByFixedPointFraction16(5, &FPF), -2);
  assertEqual(Multiply8ByFixedPointFraction16(6, &FPF), -3);
  assertEqual(Multiply8ByFixedPointFraction16(7, &FPF), -3);
  assertEqual(Multiply8ByFixedPointFraction16(8, &FPF), -4);
  assertEqual(Multiply8ByFixedPointFraction16(9, &FPF), -5);

  assertEqual(Multiply8ByFixedPointFraction16(10, &FPF), -5);
  assertEqual(Multiply8ByFixedPointFraction16(57, &FPF), -31);

  long failed = 0;
  Serial.print(F("@"));Serial.print(__LINE__);Serial.print(F(": FPF.MaxInput="));Serial.print(FPF.MaxInput);Serial.println(F("..."));
  for(int32_t ix = 0; ix - 1 < FPF.MaxInput; ++ix){
    int16_t expVal = -(((ix * 5L) - 0) / 9);
    int16_t actVal = Multiply8ByFixedPointFraction16(ix, &FPF);
    if(expVal != actVal){
      ++failed;
      if(failed < 20) {
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
test(T1131Multiply8ByFixedPointFraction16_5Div9_Neg) {
  FixedPointFraction16_t FPF;
  Ratio8ToFixedPointFraction16(5, 9, nullptr, &FPF);
  assertEqual(FPF.MaxInput, 57 * 2);
  assertEqual(Multiply8ByFixedPointFraction16(0, &FPF), 0);

  assertEqual(Multiply8ByFixedPointFraction16(-1, &FPF), -1);
  assertEqual(Multiply8ByFixedPointFraction16(-2, &FPF), -2);
  assertEqual(Multiply8ByFixedPointFraction16(-3, &FPF), -2);
  assertEqual(Multiply8ByFixedPointFraction16(-4, &FPF), -3);
  assertEqual(Multiply8ByFixedPointFraction16(-5, &FPF), -3);
  assertEqual(Multiply8ByFixedPointFraction16(-6, &FPF), -4);
  assertEqual(Multiply8ByFixedPointFraction16(-7, &FPF), -4);
  assertEqual(Multiply8ByFixedPointFraction16(-8, &FPF), -5);
  assertEqual(Multiply8ByFixedPointFraction16(-9, &FPF), -5);

  assertEqual(Multiply8ByFixedPointFraction16(-10, &FPF), -6);
  assertEqual(Multiply8ByFixedPointFraction16(-57, &FPF), -32);

  long failed = 0;
  Serial.print(F("@"));Serial.print(__LINE__);Serial.print(F(": FPF.MaxInput="));Serial.print(FPF.MaxInput);Serial.println(F("..."));
  for(int32_t ix = 0; ix >= -FPF.MaxInput; --ix){
    int16_t expVal = (((ix * 5L) - 8) / 9);
    int16_t actVal = Multiply8ByFixedPointFraction16(ix, &FPF);
    if(expVal != actVal){
      ++failed;
      if(failed < 20) {
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
test(T1130Multiply8ByFixedPointFraction16_5Div9_Pos) {
  FixedPointFraction16_t FPF;
  Ratio8ToFixedPointFraction16(5, 9, &FPF, nullptr, &Serial);
  assertEqual(FPF.MaxInput, 57);
  assertEqual(Multiply8ByFixedPointFraction16(0, &FPF), 0);

  assertEqual(Multiply8ByFixedPointFraction16(1, &FPF), 0);
  assertEqual(Multiply8ByFixedPointFraction16(2, &FPF), 1);
  assertEqual(Multiply8ByFixedPointFraction16(3, &FPF), 1);
  assertEqual(Multiply8ByFixedPointFraction16(4, &FPF), 2);
  assertEqual(Multiply8ByFixedPointFraction16(5, &FPF), 2);
  assertEqual(Multiply8ByFixedPointFraction16(6, &FPF), 3);
  assertEqual(Multiply8ByFixedPointFraction16(7, &FPF), 3);
  assertEqual(Multiply8ByFixedPointFraction16(8, &FPF), 4);
  assertEqual(Multiply8ByFixedPointFraction16(9, &FPF), 5);

  assertEqual(Multiply8ByFixedPointFraction16(10, &FPF), 5);
  assertEqual(Multiply8ByFixedPointFraction16(57, &FPF), 31);

  long failed = 0;
  Serial.print(F("@"));Serial.print(__LINE__);Serial.print(F(": FPF.MaxInput="));Serial.print(FPF.MaxInput);Serial.println(F("..."));
  for(int32_t ix = 0; ix - 1 < FPF.MaxInput; ++ix){
    int16_t expVal = (((ix * 5L) - 0) / 9);
    int16_t actVal = Multiply8ByFixedPointFraction16(ix, &FPF);
    if(expVal != actVal){
      ++failed;
      if(failed < 20) {
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

test(T1126Multiply8ByFixedPointFraction16_1DivM3_Neg) {
  FixedPointFraction16_t FPF;
  Ratio8ToFixedPointFraction16(1, -3, nullptr, &FPF);
  assertEqual(FPF.MaxInput, 47 * 2);
  assertEqual(Multiply8ByFixedPointFraction16(0, &FPF), 0);

  assertEqual(Multiply8ByFixedPointFraction16(-1, &FPF), 1);
  assertEqual(Multiply8ByFixedPointFraction16(-2, &FPF), 1);
  assertEqual(Multiply8ByFixedPointFraction16(-3, &FPF), 1);
  assertEqual(Multiply8ByFixedPointFraction16(-4, &FPF), 2);
  assertEqual(Multiply8ByFixedPointFraction16(-5, &FPF), 2);
  assertEqual(Multiply8ByFixedPointFraction16(-6, &FPF), 2);
  assertEqual(Multiply8ByFixedPointFraction16(-7, &FPF), 3);
  assertEqual(Multiply8ByFixedPointFraction16(-8, &FPF), 3);
  assertEqual(Multiply8ByFixedPointFraction16(-9, &FPF), 3);

  for(int ix = 0; ix <= FPF.MaxInput; ++ix){
    int exp = ((ix + 2) / 3);
    assertEqual(Multiply8ByFixedPointFraction16(-ix, &FPF), exp);
  }
}
test(T1125Multiply8ByFixedPointFraction16_1DivM3_Pos) {
  FixedPointFraction16_t FPF;
  Ratio8ToFixedPointFraction16(1, -3, &FPF, nullptr);
  assertEqual(FPF.MaxInput, 47);
  assertEqual(Multiply8ByFixedPointFraction16(0, &FPF), 0);

  assertEqual(Multiply8ByFixedPointFraction16(1, &FPF), 0);
  assertEqual(Multiply8ByFixedPointFraction16(2, &FPF), 0);
  assertEqual(Multiply8ByFixedPointFraction16(3, &FPF), -1);
  assertEqual(Multiply8ByFixedPointFraction16(4, &FPF), -1);
  assertEqual(Multiply8ByFixedPointFraction16(5, &FPF), -1);
  assertEqual(Multiply8ByFixedPointFraction16(6, &FPF), -2);
  assertEqual(Multiply8ByFixedPointFraction16(7, &FPF), -2);
  assertEqual(Multiply8ByFixedPointFraction16(8, &FPF), -2);
  assertEqual(Multiply8ByFixedPointFraction16(9, &FPF), -3);

  for(int ix = 0; ix <= FPF.MaxInput; ++ix){
    int exp = -((ix + 0) / 3);
    assertEqual(Multiply8ByFixedPointFraction16(ix, &FPF), exp);
  }
}
test(T1121Multiply8ByFixedPointFraction16_1Div3_Neg) {
  FixedPointFraction16_t FPF;
  Ratio8ToFixedPointFraction16(1, 3, nullptr, &FPF);
  assertEqual(FPF.MaxInput, 47 * 2);
  assertEqual(Multiply8ByFixedPointFraction16(0, &FPF), 0);

  assertEqual(Multiply8ByFixedPointFraction16(-1, &FPF), -1);
  assertEqual(Multiply8ByFixedPointFraction16(-2, &FPF), -1);
  assertEqual(Multiply8ByFixedPointFraction16(-3, &FPF), -1);
  assertEqual(Multiply8ByFixedPointFraction16(-4, &FPF), -2);
  assertEqual(Multiply8ByFixedPointFraction16(-5, &FPF), -2);
  assertEqual(Multiply8ByFixedPointFraction16(-6, &FPF), -2);
  assertEqual(Multiply8ByFixedPointFraction16(-7, &FPF), -3);
  assertEqual(Multiply8ByFixedPointFraction16(-8, &FPF), -3);
  assertEqual(Multiply8ByFixedPointFraction16(-9, &FPF), -3);

  for(int ix = 0; ix <= FPF.MaxInput; ++ix){
    int exp = -((ix + 2) / 3);
    assertEqual(Multiply8ByFixedPointFraction16(-ix, &FPF), exp);
  }
}
test(T1120Multiply8ByFixedPointFraction16_1Div3_Pos) {
#if FULL_DEBUG
  Print* pPrintDebug = &Serial;
#else
  Print* pPrintDebug = nullptr;
#endif
  FixedPointFraction16_t FPF;
  Ratio8ToFixedPointFraction16(1, 3, &FPF, nullptr);
  assertEqual(FPF.MaxInput, 47);
  assertEqual(Multiply8ByFixedPointFraction16(0, &FPF), 0);

  assertEqual(Multiply8ByFixedPointFraction16(1, &FPF), 0);
  assertEqual(Multiply8ByFixedPointFraction16(2, &FPF), 0);
  assertEqual(Multiply8ByFixedPointFraction16(3, &FPF), 1);
  assertEqual(Multiply8ByFixedPointFraction16(4, &FPF), 1);
  assertEqual(Multiply8ByFixedPointFraction16(5, &FPF), 1);
  assertEqual(Multiply8ByFixedPointFraction16(6, &FPF), 2);
  assertEqual(Multiply8ByFixedPointFraction16(7, &FPF), 2);
  assertEqual(Multiply8ByFixedPointFraction16(8, &FPF), 2);
  assertEqual(Multiply8ByFixedPointFraction16(9, &FPF), 3);

  for(int ix = 0; ix <= FPF.MaxInput; ++ix){
    int exp = ((ix + 0) / 3);
    assertEqual(Multiply8ByFixedPointFraction16(ix, &FPF), exp);
  }
}

test(T1116Multiply8ByFixedPointFraction16_1DivM4_Neg) {
  FixedPointFraction16_t FPF;
  Ratio8ToFixedPointFraction16(1, -4, nullptr, &FPF);
  assertEqual(FPF.MaxInput, 63 * 2);
  assertEqual(Multiply8ByFixedPointFraction16(0, &FPF), 0);

  assertEqual(Multiply8ByFixedPointFraction16(-1, &FPF), 1);
  assertEqual(Multiply8ByFixedPointFraction16(-2, &FPF), 1);
  assertEqual(Multiply8ByFixedPointFraction16(-3, &FPF), 1);
  assertEqual(Multiply8ByFixedPointFraction16(-4, &FPF), 1);
  assertEqual(Multiply8ByFixedPointFraction16(-5, &FPF), 2);
  assertEqual(Multiply8ByFixedPointFraction16(-6, &FPF), 2);
  assertEqual(Multiply8ByFixedPointFraction16(-7, &FPF), 2);
  assertEqual(Multiply8ByFixedPointFraction16(-8, &FPF), 2);
  assertEqual(Multiply8ByFixedPointFraction16(-9, &FPF), 3);

  for(int ix = 0; ix <= FPF.MaxInput; ++ix){
    int exp = ((ix + 3) / 4);
    assertEqual(Multiply8ByFixedPointFraction16(-ix, &FPF), exp);
  }
}
test(T1115Multiply8ByFixedPointFraction16_1DivM4_Pos) {
  FixedPointFraction16_t FPF;
  Ratio8ToFixedPointFraction16(1, -4, &FPF, nullptr);
  assertEqual(FPF.MaxInput, 63 * 2);
  assertEqual(Multiply8ByFixedPointFraction16(0, &FPF), 0);

  assertEqual(Multiply8ByFixedPointFraction16(1, &FPF), 0);
  assertEqual(Multiply8ByFixedPointFraction16(2, &FPF), 0);
  assertEqual(Multiply8ByFixedPointFraction16(3, &FPF), 0);
  assertEqual(Multiply8ByFixedPointFraction16(4, &FPF), -1);
  assertEqual(Multiply8ByFixedPointFraction16(5, &FPF), -1);
  assertEqual(Multiply8ByFixedPointFraction16(6, &FPF), -1);
  assertEqual(Multiply8ByFixedPointFraction16(7, &FPF), -1);
  assertEqual(Multiply8ByFixedPointFraction16(8, &FPF), -2);
  assertEqual(Multiply8ByFixedPointFraction16(9, &FPF), -2);

  for(int ix = 0; ix <= FPF.MaxInput; ++ix){
    int exp = -((ix + 0) / 4);
    assertEqual(Multiply8ByFixedPointFraction16(ix, &FPF), exp);
  }
}
test(T1111Multiply8ByFixedPointFraction16_1Div4_Neg) {
  FixedPointFraction16_t FPF;
  Ratio8ToFixedPointFraction16(1, 4, nullptr, &FPF);
  assertEqual(FPF.MaxInput, 63 * 2);
  assertEqual(Multiply8ByFixedPointFraction16(0, &FPF), 0);

  assertEqual(Multiply8ByFixedPointFraction16(-1, &FPF), -1);
  assertEqual(Multiply8ByFixedPointFraction16(-2, &FPF), -1);
  assertEqual(Multiply8ByFixedPointFraction16(-3, &FPF), -1);
  assertEqual(Multiply8ByFixedPointFraction16(-4, &FPF), -1);
  assertEqual(Multiply8ByFixedPointFraction16(-5, &FPF), -2);
  assertEqual(Multiply8ByFixedPointFraction16(-6, &FPF), -2);
  assertEqual(Multiply8ByFixedPointFraction16(-7, &FPF), -2);
  assertEqual(Multiply8ByFixedPointFraction16(-8, &FPF), -2);
  assertEqual(Multiply8ByFixedPointFraction16(-9, &FPF), -3);

  for(int ix = 0; ix <= FPF.MaxInput; ++ix){
    int exp = -((ix + 3) / 4);
    assertEqual(Multiply8ByFixedPointFraction16(-ix, &FPF), exp);
  }
}
test(T1110Multiply8ByFixedPointFraction16_1Div4_Pos) {
  FixedPointFraction16_t FPF;
  Ratio8ToFixedPointFraction16(1, 4, &FPF, nullptr);
  assertEqual(FPF.MaxInput, 63 * 2);
  assertEqual(Multiply8ByFixedPointFraction16(0, &FPF), 0);

  assertEqual(Multiply8ByFixedPointFraction16(1, &FPF), 0);
  assertEqual(Multiply8ByFixedPointFraction16(2, &FPF), 0);
  assertEqual(Multiply8ByFixedPointFraction16(3, &FPF), 0);
  assertEqual(Multiply8ByFixedPointFraction16(4, &FPF), 1);
  assertEqual(Multiply8ByFixedPointFraction16(5, &FPF), 1);
  assertEqual(Multiply8ByFixedPointFraction16(6, &FPF), 1);
  assertEqual(Multiply8ByFixedPointFraction16(7, &FPF), 1);
  assertEqual(Multiply8ByFixedPointFraction16(8, &FPF), 2);
  assertEqual(Multiply8ByFixedPointFraction16(9, &FPF), 2);

  for(int ix = 0; ix <= FPF.MaxInput; ++ix){
    int exp = ((ix + 0) / 4);
    assertEqual(Multiply8ByFixedPointFraction16(ix, &FPF), exp);
  }
}

test(T1100Ratio8ToFixedPointFraction16) {
  FixedPointFraction16_t fpfP, fpfN;
#if FULL_DEBUG || 1
  Print* pPrintDebug = &Serial;
#else
  Print* pPrintDebug = nullptr;
#endif

  fpfP = fpfN = {-2468, 97, -42};
  assertEqual(fpfP.TheFraction, -2468);
  assertEqual(fpfN.TheFraction, -2468);
  assertEqual(fpfP.BitsToShift, 97);
  assertEqual(fpfN.BitsToShift, 97);
  assertEqual(fpfP.MaxInput, -42);
  assertEqual(fpfN.MaxInput, -42);

  // handling of 0
  Ratio8ToFixedPointFraction16(0, 0, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, (int16_t)0b00 * 0x100 + 0B00000000);
  assertEqual(fpfN.TheFraction, (int16_t)0b00 * 0x100 + 0B00000000);
  assertEqual(fpfP.BitsToShift, 0);
  assertEqual(fpfN.BitsToShift, 0);
  assertEqual(fpfP.MaxInput, 0);
  assertEqual(fpfN.MaxInput, 0);

  Ratio8ToFixedPointFraction16(0, 8, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, (int16_t)0b00 * 0x100 + 0B00000000);
  assertEqual(fpfN.TheFraction, (int16_t)0b00 * 0x100 + 0B00000000);
  assertEqual(fpfP.BitsToShift, 0);
  assertEqual(fpfN.BitsToShift, 0);
  assertEqual(fpfP.MaxInput, 0);
  assertEqual(fpfN.MaxInput, 0);

  Ratio8ToFixedPointFraction16(8, 0, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, (int16_t)0b00 * 0x100 + 0B00000000);
  assertEqual(fpfN.TheFraction, (int16_t)0b00 * 0x100 + 0B00000000);
  assertEqual(fpfP.BitsToShift, 0);
  assertEqual(fpfN.BitsToShift, 0);
  assertEqual(fpfP.MaxInput, 0);
  assertEqual(fpfN.MaxInput, 0);

  // equal ratios
  Ratio8ToFixedPointFraction16(1, 1, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, (int16_t)0b10 * 0x80 + 0B00000000);
  assertEqual(fpfN.TheFraction, (int16_t)0b10 * 0x80 + 0B00000000);
  assertEqual(fpfP.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfP.MaxInput, 63 * 2);
  assertEqual(fpfN.MaxInput, 63 * 2);

  Ratio8ToFixedPointFraction16(12, 12, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, (int16_t)0b10 * 0x80 + 0B00000000);
  assertEqual(fpfN.TheFraction, (int16_t)0b10 * 0x80 + 0B00000000);
  assertEqual(fpfP.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfP.MaxInput, 63 * 2);
  assertEqual(fpfN.MaxInput, 63 * 2);

  Ratio8ToFixedPointFraction16(-2, 2, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, -((int16_t)0b10 * 0x80 + 0B00000000));
  assertEqual(fpfN.TheFraction, -((int16_t)0b10 * 0x80 + 0B00000000));
  assertEqual(fpfP.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfP.MaxInput, 63 * 2);
  assertEqual(fpfN.MaxInput, 63 * 2);

  Ratio8ToFixedPointFraction16(3, -3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, -((int16_t)0b10 * 0x80 + 0B00000000));
  assertEqual(fpfN.TheFraction, -((int16_t)0b10 * 0x80 + 0B00000000));
  assertEqual(fpfP.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfP.MaxInput, 63 * 2);
  assertEqual(fpfN.MaxInput, 63 * 2);

  Ratio8ToFixedPointFraction16(-4, -4, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, (int16_t)0b10 * 0x80 + 0B00000000);
  assertEqual(fpfN.TheFraction, (int16_t)0b10 * 0x80 + 0B00000000);
  assertEqual(fpfP.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfP.MaxInput, 63 * 2);
  assertEqual(fpfN.MaxInput, 63 * 2);

  // exact ratios
  Ratio8ToFixedPointFraction16(8, 2, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, (int16_t)0b10 * 0x40 + 0B00000000);
  assertEqual(fpfN.TheFraction, (int16_t)0b10 * 0x40 + 0B00000000);
  assertEqual(fpfP.BitsToShift, 8 - 1 - 2);
  assertEqual(fpfN.BitsToShift, 8 - 1 - 2);
  assertEqual(fpfP.MaxInput, 31 * 4);
  assertEqual(fpfN.MaxInput, 31 * 4);

  Ratio8ToFixedPointFraction16(-12, 4, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, -((int16_t)0b11 * 0x80 + 0B00000000));
  assertEqual(fpfN.TheFraction, -((int16_t)0b11 * 0x80 + 0B00000000));
  assertEqual(fpfP.BitsToShift, 8 - 0 - 1);
  assertEqual(fpfN.BitsToShift, 8 - 0 - 1);
  assertEqual(fpfP.MaxInput, 42 * 2);
  assertEqual(fpfN.MaxInput, 42 * 2);

  Ratio8ToFixedPointFraction16(30, -5, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, -((int16_t)0b11 * 0x40 + 0B00000000));
  assertEqual(fpfN.TheFraction, -((int16_t)0b11 * 0x40 + 0B00000000));
  assertEqual(fpfP.BitsToShift, 8 - 1 - 2);
  assertEqual(fpfN.BitsToShift, 8 - 1 - 2);
  assertEqual(fpfP.MaxInput, 21 * 4);
  assertEqual(fpfN.MaxInput, 21 * 4);

  Ratio8ToFixedPointFraction16(-56, -7, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, (int16_t)0b10 * 0x20 + 0B00000000);
  assertEqual(fpfN.TheFraction, (int16_t)0b10 * 0x20 + 0B00000000);
  assertEqual(fpfP.BitsToShift, 8 - 2 - 3);
  assertEqual(fpfN.BitsToShift, 8 - 2 - 3);
  assertEqual(fpfP.MaxInput, 15 * 8);
  assertEqual(fpfN.MaxInput, 15 * 8);

  // theoretical exact ratios
  Ratio8ToFixedPointFraction16(1, 3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, (int16_t)0b10 * 0x100 + 0B10101011);
  assertEqual(fpfN.TheFraction, (int16_t)0b10 * 0x80 + 0B1010101);
  assertEqual(fpfP.BitsToShift, 8 + 3);
  assertEqual(fpfN.BitsToShift, 8 + 3 - 1);
  assertEqual(fpfP.MaxInput, 47);
  assertEqual(fpfN.MaxInput, 47 * 2);

  Ratio8ToFixedPointFraction16(-1, 3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, -((int16_t)0b10 * 0x100 + 0B10101011));
  assertEqual(fpfN.TheFraction, -((int16_t)0b10 * 0x80 + 0B1010101));
  assertEqual(fpfP.BitsToShift, 8 + 3);
  assertEqual(fpfN.BitsToShift, 8 + 3 -1);
  assertEqual(fpfP.MaxInput, 47);
  assertEqual(fpfN.MaxInput, 47 * 2);

  Ratio8ToFixedPointFraction16(1, -3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, -((int16_t)0b10 * 0x100 + 0B10101011));
  assertEqual(fpfN.TheFraction, -((int16_t)0b10 * 0x80 + 0B1010101));
  assertEqual(fpfP.BitsToShift, 8 + 3);
  assertEqual(fpfN.BitsToShift, 8 + 3 - 1);
  assertEqual(fpfP.MaxInput, 47);
  assertEqual(fpfN.MaxInput, 47 * 2);

  Ratio8ToFixedPointFraction16(-1, -3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, (int16_t)0b10 * 0x100 + 0B10101011);
  assertEqual(fpfN.TheFraction, (int16_t)0b10 * 0x80 + 0B1010101);
  assertEqual(fpfP.BitsToShift, 8 + 3);
  assertEqual(fpfN.BitsToShift, 8 + 3 - 1);
  assertEqual(fpfP.MaxInput, 47);
  assertEqual(fpfN.MaxInput, 47 * 2);

  Ratio8ToFixedPointFraction16(2, 3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, (int16_t)0b10 * 0x100 + 0B10101011);
  assertEqual(fpfN.TheFraction, (int16_t)0b10 * 0x80 + 0B1010101);
  assertEqual(fpfP.BitsToShift, 8 + 2);
  assertEqual(fpfN.BitsToShift, 8 + 2 - 1);
  assertEqual(fpfP.MaxInput, 47);
  assertEqual(fpfN.MaxInput, 47 * 2);

  Ratio8ToFixedPointFraction16(-2, 3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, -((int16_t)0b10 * 0x100 + 0B10101011));
  assertEqual(fpfN.TheFraction, -((int16_t)0b10 * 0x80 + 0B1010101));
  assertEqual(fpfP.BitsToShift, 8 + 2);
  assertEqual(fpfN.BitsToShift, 8 + 2 - 1);
  assertEqual(fpfP.MaxInput, 47);
  assertEqual(fpfN.MaxInput, 47 * 2);

  Ratio8ToFixedPointFraction16(2, -3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, -((int16_t)0b10 * 0x100 + 0B10101011));
  assertEqual(fpfN.TheFraction, -((int16_t)0b10 * 0x80 + 0B1010101));
  assertEqual(fpfP.BitsToShift, 8 + 2);
  assertEqual(fpfN.BitsToShift, 8 + 2 - 1);
  assertEqual(fpfP.MaxInput, 47);
  assertEqual(fpfN.MaxInput, 47 * 2);

  Ratio8ToFixedPointFraction16(-2, -3, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, (int16_t)0b10 * 0x100 + 0B10101011);
  assertEqual(fpfN.TheFraction, (int16_t)0b10 * 0x80 + 0B1010101);
  assertEqual(fpfP.BitsToShift, 8 + 2);
  assertEqual(fpfN.BitsToShift, 8 + 2 - 1);
  assertEqual(fpfP.MaxInput, 47);
  assertEqual(fpfN.MaxInput, 47 * 2);

  // binary fraction
  Ratio8ToFixedPointFraction16(1, 2, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, (int16_t)0b10 * 0x80 + 0B00000000);
  assertEqual(fpfN.TheFraction, (int16_t)0b10 * 0x80 + 0B00000000);
  assertEqual(fpfP.BitsToShift, 8 + 2 - 1);
  assertEqual(fpfN.BitsToShift, 8 + 2 - 1);
  assertEqual(fpfP.MaxInput, 63 * 2);
  assertEqual(fpfN.MaxInput, 63 * 2);

  Ratio8ToFixedPointFraction16(-3, 4, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, -((int16_t)0b11 * 0x80 + 0B00000000));
  assertEqual(fpfN.TheFraction, -((int16_t)0b11 * 0x80 + 0B00000000));
  assertEqual(fpfP.BitsToShift, 8 + 2 - 1);
  assertEqual(fpfN.BitsToShift, 8 + 2 - 1);
  assertEqual(fpfP.MaxInput, 42 * 2);
  assertEqual(fpfN.MaxInput, 42 * 2);

  Ratio8ToFixedPointFraction16(3, -8, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, -((int16_t)0b11 * 0x80 + 0B00000000));
  assertEqual(fpfN.TheFraction, -((int16_t)0b11 * 0x80 + 0B00000000));
  assertEqual(fpfP.BitsToShift, 8 + 3 - 1);
  assertEqual(fpfN.BitsToShift, 8 + 3 - 1);
  assertEqual(fpfP.MaxInput, 42 * 2);
  assertEqual(fpfN.MaxInput, 42 * 2);

  Ratio8ToFixedPointFraction16(-3, -16, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, (int16_t)0b11 * 0x80 + 0B00000000);
  assertEqual(fpfN.TheFraction, (int16_t)0b11 * 0x80 + 0B00000000);
  assertEqual(fpfP.BitsToShift, 8 + 4 - 1);
  assertEqual(fpfN.BitsToShift, 8 + 4 - 1);
  assertEqual(fpfP.MaxInput, 42 * 2);
  assertEqual(fpfN.MaxInput, 42 * 2);

  // binary vulgar fraction
  Ratio8ToFixedPointFraction16(3, 2, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, (int16_t)0b11 * 0x80 + 0B00000000);
  assertEqual(fpfN.TheFraction, (int16_t)0b11 * 0x80 + 0B00000000);
  assertEqual(fpfP.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfP.MaxInput, 42 * 2);
  assertEqual(fpfN.MaxInput, 42 * 2);

  Ratio8ToFixedPointFraction16(-7, 4, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, -((int16_t)0b11 * 0x80 + 0B1000000));
  assertEqual(fpfN.TheFraction, -((int16_t)0b11 * 0x80 + 0B1000000));
  assertEqual(fpfP.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfP.MaxInput, 36 * 2);
  assertEqual(fpfN.MaxInput, 36 * 2);

  Ratio8ToFixedPointFraction16(11, -8, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, -((int16_t)0b10 * 0x80 + 0B1100000));
  assertEqual(fpfN.TheFraction, -((int16_t)0b10 * 0x80 + 0B1100000));
  assertEqual(fpfP.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfP.MaxInput, 46 * 2);
  assertEqual(fpfN.MaxInput, 46 * 2);

  Ratio8ToFixedPointFraction16(-19, -16, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, (int16_t)0b10 * 0x80 + 0B0110000);
  assertEqual(fpfN.TheFraction, (int16_t)0b10 * 0x80 + 0B0110000);
  assertEqual(fpfP.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfP.MaxInput, 53 * 2);
  assertEqual(fpfN.MaxInput, 53 * 2);

  // inexact fraction
  Ratio8ToFixedPointFraction16(5, 9, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, (int16_t)0b10 * 0x100 + 0B00111001);
  assertEqual(fpfN.TheFraction, (int16_t)0b10 * 0x80 + 0B0011100);
  assertEqual(fpfP.BitsToShift, 8 + 2);
  assertEqual(fpfN.BitsToShift, 8 + 2 - 1);
  assertEqual(fpfP.MaxInput, 57);
  assertEqual(fpfN.MaxInput, 57 * 2);

  Ratio8ToFixedPointFraction16(-5, 9, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, -((int16_t)0b10 * 0x100 + 0B00111001));
  assertEqual(fpfN.TheFraction, -((int16_t)0b10 * 0x80 + 0B0011100));
  assertEqual(fpfP.BitsToShift, 8 + 2);
  assertEqual(fpfN.BitsToShift, 8 + 2 - 1);
  assertEqual(fpfP.MaxInput, 57);
  assertEqual(fpfN.MaxInput, 57 * 2);

  Ratio8ToFixedPointFraction16(5, -9, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, -((int16_t)0b10 * 0x100 + 0B00111001));
  assertEqual(fpfN.TheFraction, -((int16_t)0b10 * 0x80 + 0B0011100));
  assertEqual(fpfP.BitsToShift, 8 + 2);
  assertEqual(fpfN.BitsToShift, 8 + 2 - 1);
  assertEqual(fpfP.MaxInput, 57);
  assertEqual(fpfN.MaxInput, 57 * 2);

  Ratio8ToFixedPointFraction16(-5, -9, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, (int16_t)0b10 * 0x100 + 0B00111001);
  assertEqual(fpfN.TheFraction, (int16_t)0b10 * 0x80 + 0B0011100);
  assertEqual(fpfP.BitsToShift, 8 + 2);
  assertEqual(fpfN.BitsToShift, 8 + 2 - 1);
  assertEqual(fpfP.MaxInput, 57);
  assertEqual(fpfN.MaxInput, 57 * 2);

  // inexact vulgar fraction
  Ratio8ToFixedPointFraction16(9, 5, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, (int16_t)0b11 * 0x80 + 0B1001101);
  assertEqual(fpfN.TheFraction, (int16_t)0b11 * 0x100 + 0B10011001);
  assertEqual(fpfP.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 8 + 1);
  assertEqual(fpfP.MaxInput, 35 * 2);
  assertEqual(fpfN.MaxInput, 35);

  Ratio8ToFixedPointFraction16(-9, 5, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, -((int16_t)0b11 * 0x80 + 0B1001101));
  assertEqual(fpfN.TheFraction, -((int16_t)0b11 * 0x100 + 0B10011001));
  assertEqual(fpfP.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 8 + 1);
  assertEqual(fpfP.MaxInput, 35 * 2);
  assertEqual(fpfN.MaxInput, 35);

  Ratio8ToFixedPointFraction16(9, -5, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, -((int16_t)0b11 * 0x80 + 0B1001101));
  assertEqual(fpfN.TheFraction, -((int16_t)0b11 * 0x100 + 0B10011001));
  assertEqual(fpfP.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 8 + 1);
  assertEqual(fpfP.MaxInput, 35 * 2);
  assertEqual(fpfN.MaxInput, 35);

  Ratio8ToFixedPointFraction16(-9, -5, &fpfP, &fpfN, pPrintDebug);
  if(pPrintDebug) { pPrintDebug->println(); }
  assertEqual(fpfP.TheFraction, (int16_t)0b11 * 0x80 + 0B1001101);
  assertEqual(fpfN.TheFraction, (int16_t)0b11 * 0x100 + 0B10011001);
  assertEqual(fpfP.BitsToShift, 8 + 1 - 1);
  assertEqual(fpfN.BitsToShift, 8 + 1);
  assertEqual(fpfP.MaxInput, 35 * 2);
  assertEqual(fpfN.MaxInput, 35);
}

test(T0810CheckMultAndShiftForRatio10) {
  Serial.print(F("BTW Mx="));Serial.print(114);Serial.println();
  int16_t rat8Plus = 0x11D;
  int16_t rat8Minus = 0x11C;
  int32_t rat16Plus = 0x11C72;
  int32_t rat16Minus = 0x11C71;
  for(int ix = -128; ix <= 127; ++ix){
    int16_t part8Plus = ix * rat8Plus;
    int16_t part8Minus = ix * rat8Minus;
    int32_t part16Plus = ix * rat16Plus;
    int32_t part16Minus = ix * rat16Minus;
    int act8Plus = part8Plus >> 9;
    int act8Minus = part8Minus >> 9;
    if(act8Plus != act8Minus){
      if(ix%9 == 0){Serial.print(F("*"));}
      Serial.print(F("ix="));Serial.print(ix);
      Serial.print(F(" \tp8+/=x"));Serial.print(part8Plus, HEX);Serial.print(F(" \tx"));Serial.print(part8Minus, HEX);
      Serial.print(F(" \tp16+/=x"));Serial.print(part16Plus, HEX);Serial.print(F(" \tx"));Serial.print(part16Minus, HEX);
      Serial.print(F(" \t+/="));Serial.print(act8Plus);Serial.print(F(" \t"));Serial.print(act8Minus);
      Serial.println();
    }
  }
}

test(T0800CheckMultAndShiftForRatio9) {
  Serial.print(F("BTW Mx="));Serial.print(114);Serial.println();
  int16_t rat8Plus = 0x11D;
  int16_t rat8Minus = 0x11C;
  int32_t rat16Plus = 0x11C72;
  int32_t rat16Minus = 0x11C71;
  for(int ix = -128; ix <= 127; ++ix){
    int16_t part8Plus = ix * rat8Plus;
    int16_t part8Minus = ix * rat8Minus;
    int32_t part16Plus = ix * rat16Plus;
    int32_t part16Minus = ix * rat16Minus;
    int act8Plus = part8Plus >> 9;
    int act8Minus = part8Minus >> 9;
    if(act8Plus != act8Minus){
      if(ix%9 == 0){Serial.print(F("*"));}
      Serial.print(F("ix="));Serial.print(ix);
      Serial.print(F(" \tp8+/=x"));Serial.print(part8Plus, HEX);Serial.print(F(" \tx"));Serial.print(part8Minus, HEX);
      Serial.print(F(" \tp16+/=x"));Serial.print(part16Plus, HEX);Serial.print(F(" \tx"));Serial.print(part16Minus, HEX);
      Serial.print(F(" \t+/="));Serial.print(act8Plus);Serial.print(F(" \t"));Serial.print(act8Minus);
      Serial.println();
    }
  }
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
