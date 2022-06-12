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

INC_DIR = ../../inc/message
SRC_DIR = ../../src/message

TARGET = utest
OBJS = utest.o $(SRC_DIR)/CreateMap.o $(SRC_DIR)/factory.o $(SRC_DIR)/multi.o $(SRC_DIR)/message.o $(SRC_DIR)/Rot13.o $(SRC_DIR)/UpperCase.o $(SRC_DIR)/LowerCase.o $(SRC_DIR)/Censor.o $(SRC_DIR)/ToFile.o $(SRC_DIR)/ToUser.o $(SRC_DIR)/FromFile.o $(SRC_DIR)/FromUser.o 

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

utest : utest.cpp $(SRC_DIR)/TextTransformer.cpp $(SRC_DIR)/TextInput.cpp $(SRC_DIR)/TextOutput.cpp $(INC_DIR)/CreateMap.hpp $(SRC_DIR)/CreateMap.cpp $(INC_DIR)/factory.hpp $(SRC_DIR)/factory.cpp $(INC_DIR)/multi.hpp $(SRC_DIR)/multi.cpp $(INC_DIR)/message.hpp $(SRC_DIR)/message.cpp $(INC_DIR)/Rot13.hpp $(SRC_DIR)/Rot13.cpp $(INC_DIR)/UpperCase.hpp $(INC_DIR)/LowerCase.hpp $(INC_DIR)/Censor.hpp $(INC_DIR)/ToFile.hpp $(INC_DIR)/ToUser.hpp $(INC_DIR)/FromFile.hpp $(INC_DIR)/FromUser.hpp $(INC_DIR)/TextTransformer.hpp $(INC_DIR)/TextInput.hpp $(INC_DIR)/TextOutput.hpp $(SRC_DIR)/UpperCase.cpp $(SRC_DIR)/LowerCase.cpp $(SRC_DIR)/Censor.cpp $(SRC_DIR)/ToFile.cpp $(SRC_DIR)/ToUser.cpp $(SRC_DIR)/FromFile.cpp $(SRC_DIR)/FromUser.cpp 

vala: $(TARGET)
	valgrind --leak-check=yes --track-origins=yes ./$(TARGET)

clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala