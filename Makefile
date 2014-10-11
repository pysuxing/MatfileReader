CXX = clang++
CXXFLAGS = -std=c++11
LIBS = -lz

ALL = test

all: $(ALL)

test: test.cpp MatlabMatrixReader.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

clean:
	-rm -f $(ALL) *.o *~
