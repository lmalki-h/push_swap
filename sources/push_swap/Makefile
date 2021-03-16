NAME := push_swap

EXT := c
CC := gcc
CFLAGS := -Wall -Wextra -Werror
RM := rm

SRCS =			push_swap.c \
				push_swap_utils.c \
				quicksort.c \
				optimize.c \
				sort.c \

OPERATIONS := 	swap.c \
				push.c \
				reverse_rotate.c \
				rotate.c \

UTILS := 		create_node.c \
				last_stack.c \
				add_stack.c \
				build_stack.c \
				print_error.c \
				free_stack.c \
				get_size.c \
				is_ascending.c \
				print_stack.c \
				is_descending.c \

SRCS += $(OPERATIONS)
SRCS += $(UTILS)
OBJS = $(SRCS:.c=.o)

DIR_UTILS := ../utils
DIR_INCS := ../../includes
DIR_OPERATIONS := ../operations
DIR_OBJ := obj
DIR_LIB := $(DIR_INCS)/libft
LIB := $(DIR_LIB)/libft.a

all: $(NAME)

vpath %.c $(DIR_OPERATIONS):$(DIR_UTILS)

$(DIR_OBJ):
	mkdir -p obj

$(DIR_OBJ)/%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(DIR_OBJ) $(LIB) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB)
	mv $(OBJS) $(DIR_OBJ)

$(LIB): $(DIR_LIB)
	@make -C $(DIR_LIB)

clean:
	$(RM) -rf $(DIR_OBJ)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re