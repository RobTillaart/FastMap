# FastMap
Fast mapping and constraining

## Description
FastMap is an object that precalculates (internal) floats
to make the mapping function a.k.a. map() much faster. 
The implementation uses floats to minimize the operation, 
which might result in more memory usage.

Besides the **FastMap.map(value)** FastMap also has a **FastMap.back(value)** function to 'map in reverse'.

FastMap supports three versions of constraining the map function, as constrain() and map() often used together. 
- **FastMap.constrainedMap(value);**
- **FastMap.lowerConstrainedMap(value);**
- **FastMap.upperConstrainedMap(value);**

Note there are **no** constrain-versions for **FastMap.back(value)**

## Usage
When a sensor has to be read out frequently and one needs to map the 
value to another value e.g. to display or as control signal, the normal map() 
function is using more math operations than **FastMap.map()**



