PUSH_SWAP = push_swap
CHECKER = checker
TESTER = tester

SH = sh
EXT = c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RF = -rf 

SRCS_PUSH_SWAP =	push_swap.c \
					get_min.c \
					get_max.c \
					get_index.c \
					sort_big.c \
					sort_three.c \
					sort_small.c \

SRCS_CHECKER =		checker.c \
					checker_utils.c \

SRCS_SHARED =		build_stack.c \
					exit_error.c \
					free_stack.c \
					get_size.c \
					is_increasing.c \
					print_stack.c \
					is_decreasing.c \
					swap.c \
					push.c \
					reverse_rotate.c \
					rotate.c \

OBJS_PUSH_SWAP = $(addprefix $(DIR_OBJ)/, $(SRCS_PUSH_SWAP:.c=.o))
OBJS_CHECKER = $(addprefix $(DIR_OBJ)/, $(SRCS_CHECKER:.c=.o))
OBJS_SHARED = $(addprefix $(DIR_OBJ)/, $(SRCS_SHARED:.c=.o))

DIR_SRC = sources
DIR_TESTER = $(DIR_SRC)/tester
DIR_PUSH_SWAP = $(DIR_SRC)/push_swap
DIR_CHECKER = $(DIR_SRC)/checker
DIR_SHARED = $(DIR_SRC)/shared
DIR_INCS = includes
DIR_OBJ = obj
DIR_LIB = $(DIR_INCS)/libft
LIB = $(DIR_LIB)/libft.a

all: $(LIB) $(DIR_OBJ) $(OBJS_SHARED) $(PUSH_SWAP) $(CHECKER)

vpath %.c $(DIR_PUSH_SWAP):$(DIR_SHARED):$(DIR_CHECKER)

$(DIR_OBJ):
	mkdir -p obj

$(PUSH_SWAP): $(OBJS_PUSH_SWAP) $(LIB) $(OBJS_SHARED)
	$(CC) -o $@ $(OBJS_PUSH_SWAP) $(OBJS_SHARED) $(LIB)

$(CHECKER): $(OBJS_CHECKER) $(LIB) $(OBJS_SHARED)
	$(CC) -o $@ $(OBJS_CHECKER) $(OBJS_SHARED) $(LIB)

$(DIR_OBJ)/%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIB): $(DIR_LIB)
	@make -C $(DIR_LIB)

test_100: all
	$(SH) $(DIR_TESTER)/$(TESTER).$(SH) . 100 100

test_500: all
	$(SH) $(DIR_TESTER)/$(TESTER).$(SH) . 500 100

clean:
	$(RM) $(RF) $(DIR_OBJ)
	@make clean -C $(DIR_LIB) 

fclean: clean
	$(RM) $(RF) $(PUSH_SWAP) $(CHECKER)
	@make fclean -C $(DIR_LIB) 

re: fclean all

.PHONY: all clean fclean re
