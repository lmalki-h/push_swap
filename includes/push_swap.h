#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"
# define DEBUG 0
# define DEFAULT_SIZE 50
# define NB_INSTRUCTIONS 11
typedef struct s_stack
{
	int			n;
	struct s_stack *next;
}				t_stack;

//SORT
void		sort_three(t_stack **a);
void		sort_big(t_stack **a, size_t size);

//UTILS
size_t		get_index(t_stack *s, int value);
int			get_max(t_stack *a);
int			get_min(t_stack *a);

//OPERATIONS
void		swap(t_stack **a);
void		rotate(t_stack **a);
void		reverse_rotate(t_stack **a);
void		push(t_stack **a, t_stack **b);

t_stack 	*last_stack(t_stack *head);
void		parse_arguments(t_stack **head, char **av);
void		exit_error(t_stack *head);
t_stack		*create_node(int n);
void		add_stack(t_stack **head, t_stack *new);
void		free_stack(t_stack *head);
size_t		get_size(t_stack *s);
bool		is_increasing(t_stack *s);
void    	print_stack(t_stack *a, t_stack *b);
bool		is_decreasing(t_stack *s);

//CHECKER
t_lst		*get_instructions(void);
void		check(t_lst *lst, t_stack *a);

#endif