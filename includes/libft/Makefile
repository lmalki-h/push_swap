NAME = libft.a

EXT = c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RF = -rf

SRCS = 	ft_isdigit.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strncmp.c \
		is_integer.c \
		ft_strlen.c \
		ft_lstnew.c \
		ft_lstadd_back.c \
		ft_lstlast.c \
		free_lst.c \
		get_next_line.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strlcat.c \
		ft_bzero.c \
		ft_memset.c \

OBJS = $(SRCS:.$(EXT)=.o)

all: $(NAME)

$(NAME): $(OBJS) libft.h
	ar rcs $@ $(OBJS)
	ranlib $@

clean: 
	$(RM) $(RF) $(OBJS)

fclean: clean
	$(RM) $(RF) $(NAME)

re: fclean all
.PHONY: all clean fclean re