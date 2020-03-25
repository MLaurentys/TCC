CC = gcc

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
INCLUDE = $(foreach dir, $(INC_DIR), -I$(dir))
SRC_DIR = src

#objects
INC_OBJ_T = \
domineering.o \
dom_evaluator.o
INC_OBJ = $(addprefix $(OUT_DIR)/, $(INC_OBJ_T))

default: lib
	$(CC) $(CFLAGS_ALL) $(INCLUDE) src/main.cpp -o $(EXEC_NAME)

#compile the library
lib: $(INC_OBJ)

#compile library c files
$(OUT_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(MKDIR) $(OUT_DIR)
	$(CC) $(CFLAGS_ALL) $(INCLUDE) -c $< -o $@

print-%: ; @echo $* = $($*)

clean:
	rm -rf $(OUT_DIR) 