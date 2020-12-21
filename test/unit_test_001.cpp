//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2020-12-21
// PURPOSE: unit tests for the FastMap
//          https://github.com/RobTillaart/
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// https://github.com/Arduino-CI/arduino_ci/blob/master/cpp/unittest/Assertion.h#L33-L42
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)
// assertNotNull(actual)

#include <ArduinoUnitTests.h>

#define assertEqualFloat(arg1, arg2, arg3)  assertOp("assertEqualFloat", "expected", fabs(arg1 - arg2), compareLessOrEqual, "<=", "actual", arg3)
#define assertEqualINF(arg)  assertOp("assertEqualINF", "expected", INFINITY, compareEqual, "==", "actual", arg)
#define assertEqualNAN(arg)  assertOp("assertEqualNAN", "expected", true, compareEqual, "==", "actual", isnan(arg))


#include "Arduino.h"
#include "FastMap.h"



unittest_setup()
{
}

unittest_teardown()
{
}

/*
unittest(test_new_operator)
{
  assertEqualINF(exp(800));
  assertEqualINF(0.0/0.0);
  assertEqualINF(42);
  
  assertEqualNAN(INFINITY - INFINITY);
  assertEqualNAN(0.0/0.0);
  assertEqualNAN(42);
}
*/


unittest(test_all)
{
  FastMap fm;

  fprintf(stderr, "VERSION:\t%s", FASTMAP_LIB_VERSION);
  fm.init(-2, 12, 17, 42);

  fprintf(stderr, "map()");
  assertEqualFloat(17, fm.map(-5), 0.001);
  assertEqualFloat(17, fm.map(-2), 0.001);
  assertEqualFloat(20, fm.map(0), 0.001);
  assertEqualFloat(22, fm.map(PI), 0.001);
  assertEqualFloat(42, fm.map(12), 0.001);
  assertEqualFloat(42, fm.map(15), 0.001);
  assertEqualFloat(42, fm.map(15), 0.001);

  fprintf(stderr, "back()");
  assertEqualFloat(00, fm.back(-5), 0.001);
  assertEqualFloat(00, fm.back(0), 0.001);
  assertEqualFloat(00, fm.back(10), 0.001);
  assertEqualFloat(-2, fm.back(17), 0.001);
  assertEqualFloat(00, fm.back(25), 0.001);
  assertEqualFloat(12, fm.back(42), 0.001);
  assertEqualFloat(00, fm.back(65), 0.001);

  fprintf(stderr, "constrainedMap()");
  assertEqualFloat(17, fm.constrainedMap(-5), 0.001);
  assertEqualFloat(17, fm.constrainedMap(-2), 0.001);
  assertEqualFloat(20, fm.constrainedMap(0), 0.001);
  assertEqualFloat(22, fm.constrainedMap(PI), 0.001);
  assertEqualFloat(42, fm.constrainedMap(12), 0.001);
  assertEqualFloat(42, fm.constrainedMap(15), 0.001);
  assertEqualFloat(42, fm.constrainedMap(15), 0.001);

  fprintf(stderr, "lowerConstrainedMap()");
  assertEqualFloat(17, fm.lowerConstrainedMap(-5), 0.001);
  assertEqualFloat(17, fm.lowerConstrainedMap(-2), 0.001);
  assertEqualFloat(20, fm.lowerConstrainedMap(0), 0.001);
  assertEqualFloat(22, fm.lowerConstrainedMap(PI), 0.001);
  assertEqualFloat(42, fm.lowerConstrainedMap(12), 0.001);
  assertEqualFloat(42, fm.lowerConstrainedMap(15), 0.001);
  assertEqualFloat(42, fm.lowerConstrainedMap(15), 0.001);

  fprintf(stderr, "upperConstrainedMap()");
  assertEqualFloat(17, fm.upperConstrainedMap(-5), 0.001);
  assertEqualFloat(17, fm.upperConstrainedMap(-2), 0.001);
  assertEqualFloat(20, fm.upperConstrainedMap(0), 0.001);
  assertEqualFloat(22, fm.upperConstrainedMap(PI), 0.001);
  assertEqualFloat(42, fm.upperConstrainedMap(12), 0.001);
  assertEqualFloat(42, fm.upperConstrainedMap(15), 0.001);
  assertEqualFloat(42, fm.upperConstrainedMap(15), 0.001);
}

unittest_main()

// --------
