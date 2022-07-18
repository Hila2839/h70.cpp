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

INC_DIR = ../../../inc/tcp
INC_DIR2 = ../../../inc/queue
SRC_DIR = ../../../src/tcp
SRC_DIR2 = ../../../src/queue


TARGET = client_num
OBJS = client_num.o \



all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v


client_num: client_num.cpp \
$(SRC_DIR)/tcp_server.cpp \
$(INC_DIR)/tcp_server.hpp \
$(SRC_DIR)/tcp_server_socket.cpp \
$(INC_DIR)/tcp_server_socket.hpp \
$(SRC_DIR)/server_handler_push.cpp \
$(INC_DIR)/server_handler_push.hpp \
$(SRC_DIR)/tcp_client_socket.cpp \
$(INC_DIR)/tcp_client_socket.hpp \
$(SRC_DIR)/tcp_selector.cpp \
$(INC_DIR)/tcp_selector.hpp \
$(SRC_DIR)/adress.cpp \
$(INC_DIR)/adress.hpp \
$(SRC_DIR)/handler.cpp \
$(INC_DIR)/handler.hpp \
$(INC_DIR)/work.hpp \
$(INC_DIR2)/safe_q.hpp \
$(INC_DIR2)/semaphore.hpp \
$(SRC_DIR2)/semaphore.cpp \
$(INC_DIR2)/error.hpp \
$(SRC_DIR2)/error.cpp \
$(SRC_DIR)/process.cpp \
$(INC_DIR)/process.hpp \

 
 
 


vala: $(TARGET)
	valgrind --leak-check=yes --track-origins=yes ./$(TARGET)

clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala