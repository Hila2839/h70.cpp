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

INC_DIR = ../../inc/VirtualMachine
SRC_DIR = ../../src/VirtualMachine

TARGET = VirtualMachine
OBJS = VirtualMachine.o $(SRC_DIR)/NOP.o $(SRC_DIR)/Ip.o $(SRC_DIR)/Stack.o $(SRC_DIR)/Memory.o $(SRC_DIR)/Instruction.o $(SRC_DIR)/Mapper.o $(SRC_DIR)/Loader.o $(SRC_DIR)/Parcer.o $(SRC_DIR)/FileError.o $(SRC_DIR)/MachineError.o

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

VirtualMachine : VirtualMachine.cpp $(INC_DIR)/NOP.hpp $(SRC_DIR)/NOP.cpp $(INC_DIR)/Ip.hpp $(SRC_DIR)/Ip.cpp $(INC_DIR)/Stack.hpp $(SRC_DIR)/Stack.cpp $(INC_DIR)/Memory.hpp $(SRC_DIR)/Memory.cpp $(SRC_DIR)/Instruction.cpp $(SRC_DIR)/Mapper.cpp $(SRC_DIR)/Loader.cpp $(SRC_DIR)/Parcer.cpp $(SRC_DIR)/FileError.cpp $(SRC_DIR)/MachineError.cpp $(INC_DIR)/Instruction.hpp $(INC_DIR)/Mapper.hpp $(INC_DIR)/Loader.hpp $(INC_DIR)/Parcer.hpp $(INC_DIR)/FileError.hpp $(INC_DIR)/MachineError.hpp

vala: $(TARGET)
	valgrind --leak-check=yes --track-origins=yes ./$(TARGET)

clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala