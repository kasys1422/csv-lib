# csv-lib

experimental csv library of  c++

## How to use

```c++:sample.cpp
//include library
# include "csv-lib.h"
//choose csv file
LoadCSV csv = LoadCSV(path);
//get data
std::vector<std::vector<std::string>> list = csv.Load();
```
