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
OUT_DIR = bin

#include files
INC_DIR = .
INC_OBJ_DIR = bin
INCLUDE = $(foreach dir, $(INC_DIR) $(INC_OBJ_DIR), -I$(dir))
SRC_DIR = .

#objects
INC_OBJ_T = \
union_find.o

INC_OBJ = $(addprefix $(INC_OBJ_DIR)/, $(INC_OBJ_T))

default: lib

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