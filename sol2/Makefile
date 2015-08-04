OBJ = main.o IBookManager.o BookManager.o Book.o Order.o
CXXFLAGS = -std=c++11 -Wall -Wno-c++11-extensions

cross: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

.o: .cpp

clean:
	rm $(OBJ) cross

