Work with an old book "Local DBMS", the code style maybe very old.
This is a study project for improving skills.


Page 34


### Debug/Release build
```
cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build/Debug
cmake --build build/Debug
```

```
cmake -DCMAKE_BUILD_TYPE=Release -S . -B build/Release
cmake --build build/Release
```