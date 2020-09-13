//
//    FILE: fastMapIntegerArithmeticTest.ino
//  AUTHOR: Brewmanz (Bryan White)
// VERSION: 0.1.1
// PURPOSE: Test of FastMapInt(16) helper functions
//    DATE: 2020-09-08
//     URL: https://github.com/RobTillaart/FastMap

//#include <AUnitVerbose.h> // too much for Nano!
#include <AUnit.h>
#include <FastMap.h>

volatile int i, j;

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

  assertEqual(0 / 4, 0);

  assertEqual(1 / 4, 0);
  assertEqual(2 / 4, 0);
  assertEqual(3 / 4, 0);
  assertEqual(4 / 4, 1);
  assertEqual(5 / 4, 1);
  
  assertEqual(-1 / 4, 0);
  assertEqual(-2 / 4, 0);
  assertEqual(-3 / 4, 0);
  assertEqual(-4 / 4, -1);
  assertEqual(-5 / 4, -1);

  assertEqual(0 / -4, 0);

  assertEqual(1 / -4, 0);
  assertEqual(2 / -4, 0);
  assertEqual(3 / -4, 0);
  assertEqual(4 / -4, -1);
  assertEqual(5 / -4, -1);
  
  assertEqual(-1 / -4, 0);
  assertEqual(-2 / -4, 0);
  assertEqual(-3 / -4, 0);
  assertEqual(-4 / -4, 1);
  assertEqual(-5 / -4, 1);
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
