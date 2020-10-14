//
//    FILE: fastMapIntTest.ino
//  AUTHOR: Bryan White (Brewmanz)
// VERSION: 0.1.1
// PURPOSE: proof of FastMapInt/FastMapLong class behaviour
//    DATE: 2020-08-08
//     URL: https://github.com/RobTillaart/FastMap

#include "FastMap.h"

int x, calcInfo;
long xx;
int nErrors = 0;
FastMapInt fastMapInt;
FastMapLong fastMapLong;
const int LogCalcInfo = 0;

long FindBorderValueInThisBand(FastMapLong* pFML, long value){
  return 0;
}

void setup()
{
  delay(1000); // give clocks time to settle down
  Serial.begin(115200);
  Serial.println(F(__DATE__ " @ " __TIME__));
  Serial.println(__FILE__);
  Serial.print(F("lib version: "));
  Serial.println(FASTMAP_LIB_VERSION);
  Serial.println();
  pinMode(LED_BUILTIN, OUTPUT);

  //typical mapping of ADC 0-1023 to DAC 0-255
  // confirm existing map function
  Serial.println(F("  map: i/4 ..."));
  for (int i = -1; i < 1024; ++i)
  {
    x = map(i, 0, 1024, 0, 256);
    if((x + 1000) != ((i + 4000) / 4)) {
      if(i == -1) {
        Serial.print(F("!!! map (We know about this anomaly as call goes below zero) : i/4 != x: i=")); Serial.print(i, DEC); Serial.print(F(", x=")); Serial.println(x, DEC);
      } else {
        Serial.print(F("!!! map: i/4 != x: i=")); Serial.print(i, DEC); Serial.print(F(", x=")); Serial.println(x, DEC);
        ++nErrors;
      }
    }
    if(nErrors > 99) { break; }
  }
  // check new FastMapInt function with exact 4:1 mapping
  Serial.println(F("  FastMapInt: i/4 ..."));
  fastMapInt.init(0, 1024, 0, 256);  // typical mapping of ADC 0-1023 to DAC 0-255
  for (int i = -20; i < 2048; ++i)
  {
    x = fastMapInt.map(i, &calcInfo);
    if((x + 1000) != ((i + 4000) / 4)) {
      Serial.print(F("!!! FastMapInt: i/4 != x: i=")); Serial.print(i, DEC); Serial.print(F(", cI=")); Serial.print(calcInfo, DEC); Serial.print(F(", x=")); Serial.println(x, DEC);
      ++nErrors;
    }
    // check back()
    int backVal = fastMapInt.map(fastMapInt.back(x));
    if(x != backVal) {
      Serial.print(F("!!! FastMapInt: bv != map(back(x)): bv=")); Serial.print(backVal, DEC); Serial.print(F(", i=")); Serial.print(i, DEC); Serial.print(F(", x=")); Serial.println(x, DEC);
      ++nErrors;
    }
    if(LogCalcInfo){
      Serial.print(F("    FastMapInt: i/4 i=")); Serial.print(i, DEC); Serial.print(F(", cI=")); Serial.print(calcInfo, DEC); Serial.print(F(", x=")); Serial.println(x, DEC);
    }
    if(nErrors > 99) { break; }
  }
  // check new FastMapLong function with exact 4:1 mapping
  Serial.println(F("  FastMapLong: i/4 ..."));
  fastMapLong.init(0, 1024, 0, 256);  // typical mapping of ADC 0-1023 to DAC 0-255
  for (int i = -20; i < 2048; ++i)
  {
    x = fastMapLong.map(i, &calcInfo);
    if((x + 1000) != ((i + 4000) / 4)) {
      Serial.print(F("!!! fastMapLong: i/4 != x: i=")); Serial.print(i, DEC); Serial.print(F(", x=")); Serial.println(x, DEC);
      ++nErrors;
    }
    // check back()
    int backVal = fastMapLong.map(fastMapLong.back(x));
    if(x != backVal) {
      Serial.print(F("!!! fastMapLong: bv != map(back(x)): bv=")); Serial.print(backVal, DEC); Serial.print(F(", i=")); Serial.print(i, DEC); Serial.print(F(", x=")); Serial.println(x, DEC);
      ++nErrors;
    }
    if(LogCalcInfo){
      Serial.print(F("    FastMapLong: i/4 i=")); Serial.print(i, DEC); Serial.print(F(", cI=")); Serial.print(calcInfo, DEC); Serial.print(F(", x=")); Serial.println(x, DEC);
    }
    if(nErrors > 99) { break; }
  }

  // mapping with offset and non-exact 3:1 (1/3) ratio
  // confirm existing map function
  Serial.println(F("  map: i/3 ..."));
  for (int i = 19; i < 1024; ++i)
  {
    x = map(i, 20, 320, 50, 150);
    if((x - 50 + 1000) != ((i - 20 + 3000) / 3)) {
      if(i == 19) {
        Serial.print(F("... map (We know about this anomaly as call goes below zero) : i/3 != x: i=")); Serial.print(i, DEC); Serial.print(F(", x=")); Serial.println(x, DEC);
      } else {
        Serial.print(F("!!! map: (i-20)/3 != x-50: i=")); Serial.print(i, DEC); Serial.print(F(", x=")); Serial.println(x, DEC);
        ++nErrors;
      }
    }
    if(nErrors > 99) { break; }
  }
  // check new FastMapInt function with odd 3:1 mapping
  Serial.println(F("  FastMapInt: i/3 ..."));
  fastMapInt.init(20, 320, 50, 150); // results in inexact 1/3 maths
  for (int i = -20; i < 400; ++i)
  {
    x = fastMapInt.map(i, &calcInfo);
    if((x - 50 + 1000) != ((i - 20 + 3000) / 3)) {
      Serial.print(F("!!! FastMapInt: i/3 != x: i=")); Serial.print(i, DEC); Serial.print(F(", x=")); Serial.println(x, DEC);
      ++nErrors;
    }
    // check back()
    int backVal = fastMapInt.map(fastMapInt.back(x));
    if(x != backVal) {
      Serial.print(F("!!! FastMapInt: bv != map(back(x)): bv=")); Serial.print(backVal, DEC); Serial.print(F(", i=")); Serial.print(i, DEC); Serial.print(F(", x=")); Serial.println(x, DEC);
      ++nErrors;
    }
    if(LogCalcInfo){
      Serial.print(F("    FastMapInt: i/3 i=")); Serial.print(i, DEC); Serial.print(F(", cI=")); Serial.print(calcInfo, DEC); Serial.print(F(", x=")); Serial.println(x, DEC);
    }
    if(nErrors > 99) { break; }
  }
  // check new FastMapInt function with odd 3:1 mapping
  Serial.println(F("  fastMapLong: i/3 ..."));
  fastMapLong.init(20, 320, 50, 150); // results in inexact 1/3 maths

  Serial.print(F("  Dump ..."));
  fastMapLong.Dump(&Serial); // dump internals
  Serial.println(F("  ... Done"));
  
  for (int i = -20; i < 400; ++i)
  {
    x = fastMapLong.map(i, &calcInfo);
    if((x - 50 + 1000) != ((i - 20 + 3000) / 3)) {
      Serial.print(F("!!! fastMapLong: i/3 != x: i=")); Serial.print(i, DEC); Serial.print(F(", x=")); Serial.println(x, DEC);
      ++nErrors;
    }
    // check back()
    int backVal = fastMapLong.map(fastMapLong.back(x));
    if(x != backVal) {
      Serial.print(F("!!! fastMapLong: bv != map(back(x)): bv=")); Serial.print(backVal, DEC); Serial.print(F(", i=")); Serial.print(i, DEC); Serial.print(F(", x=")); Serial.println(x, DEC);
      ++nErrors;
    }
    if(LogCalcInfo){
      Serial.print(F("    FastMapLong: i/3 i=")); Serial.print(i, DEC); Serial.print(F(", cI=")); Serial.print(calcInfo, DEC); Serial.print(F(", x=")); Serial.println(x, DEC);
    }
    if(nErrors > 99) { break; }
  }

  Serial.println(F("... FastMapLong: i/3: check cI changes from 4 to 8"));
  for (long ii = 24594; ii <= 24595; ii += 1)
  {
    xx = fastMapLong.map(ii, &calcInfo);
    if((xx - 50 + 1000000) != ((ii - 20 + 3000000) / 3)) {
      Serial.print(F("!!! fastMapLong: ii/3 != xx: ii=")); Serial.print(ii, DEC); Serial.print(F(", xx=")); Serial.println(xx, DEC);
      ++nErrors;
    }
    // check back()
    long backVal = fastMapLong.map(fastMapLong.back(xx));
    if(xx != backVal) {
      Serial.print(F("!!! fastMapLong: bv != map(back(xx)): bv=")); Serial.print(backVal, DEC); Serial.print(F(", ii=")); Serial.print(ii, DEC); Serial.print(F(", xx=")); Serial.println(xx, DEC);
      ++nErrors;
    }
    if(LogCalcInfo || 1){
      Serial.print(F("    FastMapLong: i/3 ii=")); Serial.print(ii, DEC); Serial.print(F(", cI=")); Serial.print(calcInfo, DEC); Serial.print(F(",x x=")); Serial.println(xx, DEC);
    }
    if(nErrors > 99) { break; }
  }

  Serial.println(F("... FastMapLong: i/3: check cI changes from 8 to 32"));
  for (long ii = 32786; ii <= 32787; ii += 1)
  {
    xx = fastMapLong.map(ii, &calcInfo);
    if((xx - 50 + 1000000) != ((ii - 20 + 3000000) / 3)) {
      Serial.print(F("!!! fastMapLong: ii/3 != xx: ii=")); Serial.print(ii, DEC); Serial.print(F(", xx=")); Serial.println(xx, DEC);
      ++nErrors;
    }
    // check back()
    long backVal = fastMapLong.map(fastMapLong.back(xx));
    if(xx != backVal) {
      Serial.print(F("!!! fastMapLong: bv != map(back(xx)): bv=")); Serial.print(backVal, DEC); Serial.print(F(", ii=")); Serial.print(ii, DEC); Serial.print(F(", xx=")); Serial.println(xx, DEC);
      ++nErrors;
    }
    if(LogCalcInfo || 1){
      Serial.print(F("    FastMapLong: i/3 ii=")); Serial.print(ii, DEC); Serial.print(F(", cI=")); Serial.print(calcInfo, DEC); Serial.print(F(",x x=")); Serial.println(xx, DEC);
    }
    if(nErrors > 99) { break; }
  }

  // how did it go?
  if(nErrors == 0){
    Serial.println(F("Test SUCCESS"));
  } else {
    Serial.println(F("Test ## FAILURE ##"));
  }
}

void loop()
{
#if defined(LED_BUILTIN)
  // no errors? then 2 quick blips every second
  // otherwise slow blinking
  if(nErrors == 0){
    // two quick blips
    for(uint8_t ix = 0; ix < 2; ++ix){
     digitalWrite(LED_BUILTIN, HIGH);
     delay(150);
     digitalWrite(LED_BUILTIN, LOW);
     delay(150);
    }
    delay(700);
  } else {
    // slow blinking
    digitalWrite(LED_BUILTIN, HIGH);
    delay(750);
    digitalWrite(LED_BUILTIN, LOW);
    delay(750);
  }
#endif
}
// -- END OF FILE --
