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

INC_DIR = ../../inc/VirtualMachine_2
SRC_DIR = ../../src/VirtualMachine_2

TARGET = VirtualMachine
OBJS = VirtualMachine.o \



all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v


VirtualMachine: VirtualMachine.cpp \
 $(INC_DIR)/Ip.hpp \
 $(SRC_DIR)/Ip.cpp \
 $(INC_DIR)/Stack.hpp \
 $(SRC_DIR)/Stack.cpp \
 $(INC_DIR)/Memory.hpp \
 $(SRC_DIR)/Memory.cpp \
 $(SRC_DIR)/Mapper.cpp \
 $(SRC_DIR)/Loader.cpp \
 $(SRC_DIR)/Parcer.cpp \
 $(SRC_DIR)/FileError.cpp \
 $(SRC_DIR)/MachineError.cpp \
 $(INC_DIR)/Mapper.hpp \
 $(INC_DIR)/Loader.hpp \
 $(INC_DIR)/Parcer.hpp \
 $(INC_DIR)/FileError.hpp \
 $(INC_DIR)/MachineError.hpp \
 $(SRC_DIR)/UnderFlowError.cpp \
 $(INC_DIR)/UnderFlowError.hpp \
 $(SRC_DIR)/OverFlowError.cpp \
 $(INC_DIR)/OverFlowError.hpp \
 $(SRC_DIR)/OutOfRangeError.cpp \
 $(INC_DIR)/OutOfRangeError.hpp \
 $(SRC_DIR)/Bus.cpp \
 $(INC_DIR)/Bus.hpp 
 
 


vala: $(TARGET)
	valgrind --leak-check=yes --track-origins=yes ./$(TARGET)

clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala