CXX=g++

# flags configured by CMake
ifeq (unix,macos)
  EXTRA_LIB_FLAGS = -framework Accelerate
endif

#EXTRA_LIB_FLAGS = -library=sunperf
## When using the Sun Studio compiler


ifeq (true,true)
  BOOST_INCLUDE_FLAG = -I /usr/local/include
endif



LIB_FLAGS = -llapack -lblas $(EXTRA_LIB_FLAGS)

DEBUG = -Wall

OPT = -O2

CXXFLAGS = $(BOOST_INCLUDE_FLAG) $(DEBUG) $(FINAL) $(OPT) $(EXTRA_OPT)

out=main
obj=ex1.o computeCost.o gradientDescent.o  gradientDescentMulti.o featureNormalize.o normalEqn.o
all: testarmadillo computeCost gradientDescent featureNormalize
	gradientDescentMulti ex1 normalEqn

testarmadillo: testarmadillo.cpp
	$(CXX) $(CXXFLAGS) -o $@  $< $(LIB_FLAGS)
computeCost: computeCost.cpp
	$(CXX) $(CXXFLAGS) -c $< $(LIB_FLAGS)
gradientDescent: gradientDescent.cpp
	$(CXX) $(CXXFLAGS) -c $< $(LIB_FLAGS)
featureNormalize:featureNormalize.cpp
	$(CXX) $(CXXFLAGS) -c $< $(LIB_FLAGS)
normalEqn: normalEqn.cpp
	$(CXX) $(CXXFLAGS) -c $< $(LIB_FLAGS)
gradientDescentMulti:gradientDescentMulti.cpp
	$(CXX) $(CXXFLAGS) -c $< $(LIB_FLAGS)
ex1: ex1.cpp computeCost.o gradientDescent.o
	$(CXX) $(CXXFLAGS) -c $< $(LIB_FLAGS)

$(out):$(obj)
	$(CXX) $(CXXFLAGS) -o $(out) $(obj) $(LIB_FLAGS)
.PHONY: clean

clean:
	rm -f testarmadillo main $(obj) *~