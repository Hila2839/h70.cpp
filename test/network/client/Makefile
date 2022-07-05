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

INC_DIR = ../../../inc/tcp
SRC_DIR = ../../../src/tcp

TARGET = client_run
OBJS = client_run.o \



all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v


client_run: client_run.cpp \
$(SRC_DIR)/tcp_server.cpp \
$(INC_DIR)/tcp_server.hpp \
$(SRC_DIR)/tcp_server_socket.cpp \
$(INC_DIR)/tcp_server_socket.hpp \
$(SRC_DIR)/server_handler_string.cpp \
$(INC_DIR)/server_handler_string.hpp \
$(SRC_DIR)/tcp_client_socket.cpp \
$(INC_DIR)/tcp_client_socket.hpp \
$(SRC_DIR)/tcp_selector.cpp \
$(INC_DIR)/tcp_selector.hpp \
$(SRC_DIR)/adress.cpp \
$(INC_DIR)/adress.hpp \
$(SRC_DIR)/handler.cpp \
$(INC_DIR)/handler.hpp \
 
 
 
 


vala: $(TARGET)
	valgrind --leak-check=yes --track-origins=yes ./$(TARGET)

clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala