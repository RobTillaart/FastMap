//
//    FILE: fastMapIntSpeed.ino
//  AUTHOR: Bryan White (Brewmanz), based on Rob Tillaart code
// VERSION: 0.1.0
// PURPOSE: demo of speed of FastMapInt class
//    DATE: 2020-08-06
//     URL: https://github.com/RobTillaart/FastMap

#include "FastMap.h"

uint32_t tStart, tStop, reference, fastTime;
volatile int x;

FastMapInt mapper;

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
      x = map(i, 0, 1024, 0, 256); //typical mapping of ADC 0-1023 to DAC 0-255
    }
  }
  tStop = micros();
  reference = tStop-tStart;
  Serial.println(F("Original map"));
  Serial.print(F("  10000 calls, uS="));
  Serial.println(reference);
  Serial.print(F("  final x="));
  Serial.println(x);
  Serial.println();

  // FASTMAP
  Serial.flush(); // stop Serial cycle stealing during timing loops
  mapper.init(0, 1024, 0, 256); //typical mapping of ADC 0-1023 to DAC 0-255
  tStart = micros();
  for (int j = 0; j < 10; ++j)  // loop up to 10K
  {
    for (volatile int i = 0; i < 1000; ++i)  // just use 'sensible' values for map call
    {
      x = mapper.map(i);
    }
  }
  tStop = micros();
  fastTime = tStop-tStart;
  Serial.println(F("FastMapInt::map"));
  Serial.print(F("  10000 calls, uS="));
  Serial.println(fastTime);
  Serial.print(F("  final x="));
  Serial.println(x);
  Serial.println();

  // SUMMARY
  Serial.print(F(" Speed-up Ratio:\t"));
  Serial.println(1.0 * reference / fastTime, 3);
  Serial.println();

  Serial.println(F("\n...Done"));
}

void loop()
{
}

// -- END OF FILE --
