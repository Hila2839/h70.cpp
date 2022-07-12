CXX = g++-11
CC = $(CXX)

CPPFLAGS = -I$(INC_DIR)
# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++20
CXXFLAGS+= -Wall -pedantic -pthread
#CXXFLAGS+= -Werror
CXXFLAGS+= -g3


LDFLAGS =
LDLIBS =

INC_DIR = ../../../inc
SRC_DIR = ../../../src

TARGET = safe_q
OBJS = safe_q.o \




all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v


safe_q: safe_q.cpp \
$(INC_DIR)/safe_q.hpp \
$(INC_DIR)/semaphore.hpp \
$(SRC_DIR)/semaphore.cpp \



 
 
 
 
 


vala: $(TARGET)
	valgrind --leak-check=yes --track-origins=yes ./$(TARGET)

clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala