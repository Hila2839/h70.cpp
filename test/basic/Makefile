CXX = g++
CC = $(CXX)

CPPFLAGS = -I$(INC_DIR)
# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++03
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Werror
CXXFLAGS+= -g3


LDFLAGS =
LDLIBS =

INC_DIR = ../../inc
SRC_DIR = ../../src

TARGET = utestFirst.out
OBJS = utestFirst.o first.o

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

utestFirst : utestFirst.cpp first.cpp first.hpp

clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean