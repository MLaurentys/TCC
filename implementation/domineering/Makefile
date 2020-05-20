CC = g++

OP1  = -Wall -Wextra -Wpedantic -Wshadow -pedantic 
OP2 = -Wno-unused-result -Wno-unused-function -Wsequence-point
OP3 = -g -O0

#You can change
CFLAGS  = $(OP1) $(OP2) $(OP3)
#Should NOT change
CFLAGS_ALL = $(CFLAGS)

#auxiliary variables
MKDIR = mkdir -p
OUT_DIR = out
EXEC_NAME = $(OUT_DIR)/domineering

#include files
INC_DIR = include
LIB_DIR = ../lib
LIB_OBJ_DIR = ../lib/bin
INC_OBJ_DIR = bin
INCLUDE_T = $(INC_DIR) $(LIB_DIR)
INCLUDE = $(foreach dir, $(INCLUDE_T) $(INC_OBJ_DIR), -I$(dir))
SRC_DIR = src

#objects
INC_OBJ_T = \
domineering.o \
dom_evaluator.o

LIB_OBJ_T = \
union_find.o

INC_OBJ = $(addprefix $(INC_OBJ_DIR)/, $(INC_OBJ_T))
LIB_OBJ = $(addprefix $(LIB_OBJ_DIR)/, $(LIB_OBJ_T))
default: lib
	$(MKDIR) $(OUT_DIR)
	$(CC) $(CFLAGS_ALL) $(INCLUDE) $(INC_OBJ) $(LIB_OBJ) src/main.cpp -o $(EXEC_NAME)

#compile the library
lib: $(INC_OBJ)

#compile library c files
$(INC_OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(MKDIR) $(INC_OBJ_DIR)
	$(CC) $(CFLAGS_ALL) $(INCLUDE) -c $< -o $@

print-%: ; @echo $* = $($*)

clean:
	rm -rf $(OUT_DIR) 
	rm -rf $(INC_OBJ_DIR) 