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
# define CENT 100
# define CINQUANTE 50
# define VINGTCINQ 25

# define NB_INSTRUCTIONS 11
typedef struct s_stack
{
	int			n;
	struct s_stack *next;
}				t_stack;

//SORT
void		sort_three(t_stack **a);
void		sort_big(t_stack **a, size_t size);
int			get_pivot(t_stack *s, size_t size);
void		move_top(t_stack **a, size_t unsorted, size_t size);
void		empty_b(t_stack **b, t_stack **a);

//UTILS
size_t		get_index(t_stack *s, int value);
int			get_max(t_stack *a);
int			get_min(t_stack *a);
void		push_back_sorted(t_stack **src, t_stack **dst);

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
void		sort_small(t_stack **a, size_t size);
void			get_next_value(t_stack *s, int *pivot, int size);

//CHECKER
t_lst		*get_instructions(void);
void		check(t_lst *lst, t_stack *a);
void		move_to_top(t_stack **s, size_t index);
t_stack		*last_stack(t_stack *head);
void		add_last(t_stack **head, int n);
bool		is_unique(t_stack *head, double n);

#endif