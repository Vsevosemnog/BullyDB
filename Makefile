build: include/CMyDBClass.h include/core.h src/CMyDBClass.cpp src/main.cpp
	g++ include/CMyDBClass.h include/core.h src/CMyDBClass.cpp src/main.cpp -o main

clean:
	rm main