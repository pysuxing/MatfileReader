CXX = clang++
CXXFLAGS = -std=c++11
LIBS = -lz

ALL = test

all: $(ALL)

test: test.cpp MatfileReader.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

clean:
	-rm -f $(ALL) *.o *~
