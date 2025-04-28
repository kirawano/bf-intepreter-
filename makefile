OBJS = bfint.c

CC = clang

COMPILER_FLAGS = -Wall -Wextra

OBJ_NAME = bf

all: $(OJBS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME)
