CXX = g++
CC = $(CXX)

CPPFLAGS = -I$(INC_DIR)
# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++17
CXXFLAGS+= -Wall -pedantic
# CXXFLAGS+= -Werror
CXXFLAGS+= -g3


LDFLAGS =
LDLIBS =

INC_DIR = ../../inc
SRC_DIR = ../../src

TARGET = bubble_sort_vector
OBJS = bubble_sort_vector.o

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

bubble_sort_vector : bubble_sort_vector.cpp 

clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean