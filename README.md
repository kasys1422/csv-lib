# csv-lib
experimental csv libraly of  c++
## How to use
```c++:sample.cpp
//choose csv file
LoadCSV csv = LoadCSV(path);
//get data
std::vector<std::vector<std::string>> list = csv.Load();
```
