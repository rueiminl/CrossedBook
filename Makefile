CXXFLAGS = -std=c++11 -Wall -Wno-c++11-extensions
all : main.o IBookManager.o BookManager.o Book.o Order.o
	c++ $(CXXFLAGS) main.o IBookManager.o BookManager.o Book.o Order.o
main.o : main.cpp
IBookManager.o : IBookManager.cpp
BookManager.o : BookManager.cpp
Book.o : Book.cpp
Order.o : Order.cpp

clean :
	rm Book.o Order.o IBookManager.o BookManager.o main.o a.out