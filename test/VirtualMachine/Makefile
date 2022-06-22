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

INC_DIR = ../../inc/VirtualMachine
SRC_DIR = ../../src/VirtualMachine

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
 $(SRC_DIR)/Instruction.cpp \
 $(SRC_DIR)/Mapper.cpp \
 $(SRC_DIR)/Loader.cpp \
 $(SRC_DIR)/Parcer.cpp \
 $(SRC_DIR)/FileError.cpp \
 $(SRC_DIR)/MachineError.cpp \
 $(INC_DIR)/Instruction.hpp \
 $(INC_DIR)/Mapper.hpp \
 $(INC_DIR)/Loader.hpp \
 $(INC_DIR)/Parcer.hpp \
 $(INC_DIR)/FileError.hpp \
 $(INC_DIR)/MachineError.hpp \
 $(INC_DIR)/Nop.hpp \
 $(SRC_DIR)/Nop.cpp \
 $(INC_DIR)/Outnum.hpp \
 $(SRC_DIR)/Add.cpp \
 $(INC_DIR)/Add.hpp \
 $(SRC_DIR)/Sub.cpp \
 $(INC_DIR)/Sub.hpp \
 $(SRC_DIR)/And.cpp \
 $(INC_DIR)/And.hpp \
 $(SRC_DIR)/Or.cpp \
 $(INC_DIR)/Or.hpp \
 $(SRC_DIR)/Xor.cpp \
 $(INC_DIR)/Xor.hpp \
 $(SRC_DIR)/Not.cpp \
 $(INC_DIR)/Not.hpp  \
 $(SRC_DIR)/In.cpp \
 $(INC_DIR)/In.hpp \
 $(SRC_DIR)/Out.cpp \
 $(INC_DIR)/Out.hpp \
 $(SRC_DIR)/Load.cpp \
 $(INC_DIR)/Load.hpp \
 $(SRC_DIR)/Hlt.cpp \
 $(INC_DIR)/Hlt.hpp \
 $(SRC_DIR)/Drop.cpp \
 $(INC_DIR)/Drop.hpp \
 $(SRC_DIR)/UnderFlowError.cpp \
 $(INC_DIR)/UnderFlowError.hpp \
 $(SRC_DIR)/OverFlowError.cpp \
 $(INC_DIR)/OverFlowError.hpp \
 $(SRC_DIR)/OutOfRangeError.cpp \
 $(INC_DIR)/OutOfRangeError.hpp \
 $(SRC_DIR)/Stor.cpp \
 $(INC_DIR)/Stor.hpp \
 $(SRC_DIR)/Dup.cpp \
 $(INC_DIR)/Dup.hpp \
 $(SRC_DIR)/Swap.cpp \
 $(INC_DIR)/Swap.hpp \
 $(SRC_DIR)/Rol3.cpp \
 $(INC_DIR)/Rol3.hpp \
 $(INC_DIR)/Outnum.hpp \
 $(SRC_DIR)/Innum.cpp \
 $(INC_DIR)/Outnum.hpp \
 $(INC_DIR)/Innum.hpp \
 $(INC_DIR)/Outnum.hpp \
 $(SRC_DIR)/Outnum.cpp \
 $(SRC_DIR)/Push.cpp \
 $(INC_DIR)/Push.hpp \
 $(SRC_DIR)/Compl.cpp \
 $(INC_DIR)/Compl.hpp \
 $(SRC_DIR)/Num.cpp \
 $(INC_DIR)/Num.hpp \
 $(SRC_DIR)/Bus.cpp \
 $(INC_DIR)/Bus.hpp \
 $(SRC_DIR)/BiInstruction.cpp \
 $(INC_DIR)/BiInstruction.hpp \
 $(SRC_DIR)/IpInstruction.cpp \
 $(INC_DIR)/IpInstruction.hpp \
 $(SRC_DIR)/JmpInstruction.cpp \
 $(INC_DIR)/JmpInstruction.hpp \
 $(SRC_DIR)/Jmp.cpp \
 $(INC_DIR)/Jmp.hpp \
 $(SRC_DIR)/Jz.cpp \
 $(INC_DIR)/Jz.hpp \
 $(SRC_DIR)/Jnz.cpp \
 $(INC_DIR)/Jnz.hpp \
 $(SRC_DIR)/Popip.cpp \
 $(INC_DIR)/Popip.hpp \
 $(SRC_DIR)/Dropip.cpp \
 $(INC_DIR)/Dropip.hpp \
 $(SRC_DIR)/Ippush.cpp \
 $(INC_DIR)/Ippush.hpp \
 $(SRC_DIR)/Label.cpp \
 $(INC_DIR)/Label.hpp \
 $(SRC_DIR)/Jg.cpp \
 $(INC_DIR)/Jg.hpp \
 $(SRC_DIR)/Je.cpp \
 $(INC_DIR)/Je.hpp \
 $(SRC_DIR)/Jl.cpp \
 $(INC_DIR)/Jl.hpp \
 $(SRC_DIR)/Jle.cpp \
 $(INC_DIR)/Jle.hpp \
 $(SRC_DIR)/Num.cpp \
 $(INC_DIR)/Num.hpp \
 $(SRC_DIR)/AddrNum.cpp \
 $(INC_DIR)/AddrNum.hpp \
 $(SRC_DIR)/AddrInstruction.cpp \
 $(INC_DIR)/AddrInstruction.hpp \
 $(SRC_DIR)/Jgi.cpp \
 $(INC_DIR)/Jgi.hpp \
 $(SRC_DIR)/Jei.cpp \
 $(INC_DIR)/Jei.hpp
 
 


vala: $(TARGET)
	valgrind --leak-check=yes --track-origins=yes ./$(TARGET)

clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala