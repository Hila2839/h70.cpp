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

INC_DIR = ../../inc/rush
SRC_DIR = ../../src/rush

TARGET = rush_main
OBJS = rush_main.o $(SRC_DIR)/game.o $(SRC_DIR)/car.o $(SRC_DIR)/board.o
 
all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

rush_main : rush_main.cpp $(SRC_DIR)/game.cpp $(SRC_DIR)/car.cpp $(SRC_DIR)/board.cpp $(INC_DIR)/game.hpp $(INC_DIR)/car.hpp $(INC_DIR)/board.hpp

vala: $(TARGET)
	valgrind --leak-check=yes --track-origins=yes ./$(TARGET)
clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala