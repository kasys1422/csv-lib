# csv-lib

experimental csv library of  c++

## Feature

- Easy to load
- You can change the delimiter
- CSV files with BOM are available

## How to use

```c++:sample.cpp
//include library file(csv-lib.h)
# include "csv-lib.h"
//choose CSV file
LoadCSV csv = LoadCSV(path);
//get data
std::vector<std::vector<std::string>> list = csv.Load();
```

## Sample

The "csv-test" is a sample csv-lib using OpenSiv3d.

You can use sample app [here](https://github.com/kasys1422/csv-lib/blob/main/csv-test/csv-test/App/csv-test.exe). (windows10, x64)
