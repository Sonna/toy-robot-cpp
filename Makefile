CC=gcc
CFLAGS=-g -Wall

CXX=g++
CXXFLAGS=-g -Wall -std=c++11 -I.
LDLIBS=-lm

RM=rm -f

TESTFLAGS=-I/usr/local/lib/include/
TESTLIBS=-lgtest

TARGET=main
TESTTARGET=test

# SRCS=src/hello_world.c
SRCS=src/robot.cpp
OBJS=$(subst .c,.o,$(SRCS)) $(subst .cpp,.o,$(SRCS))
TESTSRCS=$(SRCS) $(subst .cpp,_test.cpp,$(SRCS)) src/test_helpers.cpp
TESTOBJS=$(subst .cpp,.o,$(TESTSRCS)) src/robot_test.o src/test_helpers.o
# TESTOBJS=$(subst .c,_test.o,$(SRCS)) $(subst .cpp,_test.o,$(SRCS)) src/test_helpers.o

.PHONY: default all clean

default: $(TARGET)
all: default

.PRECIOUS: $(TARGET) $(OBJECTS)

# compile only, C source
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

# compile only, C++ source
%.o: %.cpp $(TEST)
	$(CXX) -c -o $@ $< $(CXXFLAGS)


main: main.o $(OBJ)
	$(CXX) -o bin/$@ $^ $(CXXFLAGS) $(LDLIBS)


test: $(TESTOBJS)
	$(CXX) $(CXXFLAGS) $(TESTFLAGS) -o bin/$@ $^ $(LDLIBS) $(TESTLIBS) && \
	./bin/$@

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) bin/$(TARGET)

testclean: clean
	$(RM) bin/$(TESTTARGET)

# http://stackoverflow.com/questions/1484817/how-do-i-make-a-simple-makefile-gcc-unix
