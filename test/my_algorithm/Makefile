CXX = g++
CC = $(CXX)

CPPFLAGS = -I$(INC_DIR)
# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++03
CXXFLAGS+= -Wall -pedantic
# CXXFLAGS+= -Werror
CXXFLAGS+= -g3


LDFLAGS =
LDLIBS =

INC_DIR = ../../inc
SRC_DIR = ../../src

TARGET = utest
OBJS = utest.o $(SRC_DIR)/person.o $(SRC_DIR)/algorithms.o $(SRC_DIR)/point.o

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

utest : utest.cpp $(SRC_DIR)/person.cpp $(INC_DIR)/person.hpp $(SRC_DIR)/algorithms.cpp $(INC_DIR)/algorithms.hpp $(SRC_DIR)/point.cpp $(INC_DIR)/point.hpp

clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean