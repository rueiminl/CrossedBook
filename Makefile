CXXFLAGS = -std=c++11 -Wall -Wno-c++11-extensions

all : IBookManager.o BookManager.o main.o

main.o : main.cpp

IBookManager.o : IBookManager.cpp


BookManager.o : BookManager.cpp

clean :
	rm IBookManager.o BookManager.o main.o