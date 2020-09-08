//
//    FILE: fastMapIntSpeed.ino
//  AUTHOR: Bryan White (Brewmanz), based on Rob Tillaart code
// VERSION: 0.1.1
// PURPOSE: demo of speed of FastMapInt/FastMapLong class
//    DATE: 2020-08-08
//     URL: https://github.com/RobTillaart/FastMap

#include "FastMap.h"

uint32_t tStart, tStop, refTime, fastMapIntTime, fastMapLongTime;
volatile int x;

FastMapInt fastMapInt;
FastMapLong fastMapLong;
int nRefCalls = 0, nFastMapIntCalls = 0, nFastMapLongCalls = 0;

void setup()
{
  delay(1000); // give clocks time to settle down
  Serial.begin(115200);
  Serial.println(F(__DATE__ " @ " __TIME__));
  Serial.println(__FILE__);
  Serial.print(F("lib version: "));
  Serial.println(FASTMAP_LIB_VERSION);
  Serial.println();

  // REFERENCE
  Serial.flush(); // stop Serial cycle stealing during timing loops
  tStart = micros();
  for (int j = 0; j < 10; ++j)	// loop up to 10K
  {
    for (volatile int i = 0; i < 1000; ++i)	// just use 'sensible' values for map call
    {
      ++nRefCalls;
      x = map(i, 0, 1024, 0, 256); //typical mapping of ADC 0-1023 to DAC 0-255
    }
  }
  tStop = micros();
  refTime = tStop-tStart;
  Serial.println(F("Original map(long)"));
  Serial.print(F("  "));Serial.print(nRefCalls, DEC);Serial.print(F(" calls, uS=")); Serial.println(refTime);
  Serial.print(F("  final x="));Serial.println(x);
  Serial.println();

  // FastMapInt
  Serial.flush(); // stop Serial cycle stealing during timing loops
  fastMapInt.init(0, 1024, 0, 256); //typical mapping of ADC 0-1023 to DAC 0-255
  tStart = micros();
  for (int j = 0; j < 10; ++j)  // loop up to 10K
  {
    for (volatile int i = 0; i < 1000; ++i)  // just use 'sensible' values for map call
    {
      ++nFastMapIntCalls;
      x = fastMapInt.map(i);
    }
  }
  tStop = micros();
  fastMapIntTime = tStop-tStart;
  Serial.println(F("fastMapInt::map"));Serial.print(F("  "));Serial.print(nFastMapIntCalls, DEC);Serial.print(F(" calls, uS="));Serial.println(fastMapIntTime);
  Serial.print(F("  final x="));Serial.println(x);
  Serial.println();

  // FastMapLong
  Serial.flush(); // stop Serial cycle stealing during timing loops
  fastMapLong.init(0, 1024, 0, 256); //typical mapping of ADC 0-1023 to DAC 0-255
  tStart = micros();
  for (int j = 0; j < 10; ++j)  // loop up to 10K
  {
    for (volatile int i = 0; i < 1000; ++i)  // just use 'sensible' values for map call
    {
      ++nFastMapLongCalls;
      x = fastMapLong.map(i);
    }
  }
  tStop = micros();
  fastMapLongTime = tStop-tStart;
  Serial.println(F("fastMapLong::map"));Serial.print(F("  "));Serial.print(nFastMapLongCalls, DEC);Serial.print(F(" calls, uS="));Serial.println(fastMapLongTime);
  Serial.print(F("  final x="));Serial.println(x);
  Serial.println();

  // SUMMARY
  Serial.print(F(" Speed-up Ratio (Int):\t"));
  Serial.println(1.0 * refTime / fastMapIntTime, 3);
  Serial.print(F(" Speed-up Ratio (Long):\t"));
  Serial.println(1.0 * refTime / fastMapLongTime, 3);
  Serial.println();

  Serial.println(F("\n...Done"));
}

void loop()
{
}

// -- END OF FILE --
