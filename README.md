# FastMap

Fast mapping and constraining

## Description
FastMap is an object that precalculates (internal) floats to make the mapping function a.k.a. map() much faster.
The preformance is the result of precalculate float values so actual mapping only has one multiply and add.
The implementation uses floats which might result in more memory usage and some loss of precision for mapping
with larger values.

Note the gain is only made when there are many calls to the same mapping.
If one alternates between different mappings it is better to create multiple fastMap objects.

The **init()** function calculates all needed values for the fastMapping and the constrains.
Note this function can be called again with new values when needed to do other mapping.

- **init(in_min, in_max, out_min, out_max);** defines the linear mapping parameters.


Besides the **map(value)** FastMap also has a **back(value)** function to 'map in reverse'.

FastMap supports three versions of constraining the map function, as constrain() and map() often used together. 
- **constrainedMap(value);** will return a value between outMin .. outMax
- **lowerConstrainedMap(value);** will return a value between outMin .. inf  (No upper limit)
- **upperConstrainedMap(value);** will return a value between -inf .. outMax

To change the constrain values call **init()** with new limits, or call the original constrain()

Note there are **no** constrain-versions for **back(value)**

## FastMapDouble

Version 3.0 adds **fastMapDouble** which has the same interface.
This additional class is meant to support 8 bytes doubles in their 
native accuracy and precision. 
To display doubles one might need the **sci()** function of my **printHelpers** class.

## Usage

When a sensor has to be read out frequently and one needs to map the 
value to another value e.g. to display or as control signal, the normal map() 
function is using more math operations than **FastMap.map()**



