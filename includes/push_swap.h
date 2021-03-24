/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:25:21 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/24 10:58:45 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define HUNDRED 100
# define FIFTY 50
# define TWENTYFIVE 25
# define NB_INSTRUCTIONS 11

typedef struct			s_stack
{
	int					n;
	struct s_stack		*next;
}						t_stack;

void					swap(t_stack **a);
void					rotate(t_stack **a);
void					reverse_rotate(t_stack **a);
void					push(t_stack **a, t_stack **b);
void					add_last(t_stack **head, int n);
bool					is_unique(t_stack *head, double n);
size_t					get_size(t_stack *s);
t_stack					*last_stack(t_stack *head);
void					parse_arguments(t_stack **head, char **av);
void					exit_error(t_stack *head);
t_stack					*create_node(int n);
void					free_stack(t_stack *head);
bool					is_increasing(t_stack *s);
void					print_stack(t_stack *a, t_stack *b);
bool					is_decreasing(t_stack *s);
size_t					get_index(t_stack *s, int value);
int						get_max(t_stack *a);
int						get_min(t_stack *a);
void					sort_three(t_stack **a);
void					sort_big(t_stack **a, size_t size);
int						get_pivot(t_stack *s, size_t unsorted, size_t divider);
void					push_back_sorted(t_stack **dst, t_stack **src);
void					sort_small(t_stack **a, size_t size);
void					check(t_lst *lst, t_stack *a);
int						get_divider(size_t size);

#endif
