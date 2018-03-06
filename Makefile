SOURCES = 

main: main.cpp
	g++ -o main main.cpp $(SOURCES) -std=c++11

clean:
	rm main
