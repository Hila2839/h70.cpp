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

INC_DIR = ../../inc/tcp
SRC_DIR = ../../src/tcp

TARGET = tcp_server
OBJS = tcp_server.o \



all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v


tcp_server: tcp_server.cpp \
$(INC_DIR)/tcp_server.hpp \
$(SRC_DIR)/tcp_server_socket.cpp \
$(INC_DIR)/tcp_server_socket.hpp \
$(SRC_DIR)/tcp_client_socket.cpp \
$(INC_DIR)/tcp_client_socket.hpp \
$(SRC_DIR)/tcp_selector.cpp \
$(INC_DIR)/tcp_selector.hpp 
 
 
 
 
 


vala: $(TARGET)
	valgrind --leak-check=yes --track-origins=yes ./$(TARGET)

clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala