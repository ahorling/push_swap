/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 17:17:46 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/30 19:34:00 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libraries/libft/includes/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	struct s_node	*prev;
	int				data;
	struct s_node	*next;
}	t_node;

//main function
void	push_swap(int length, char **arguments);

//parsing and checker functions
bool	check_input(int length, char **arguments);
bool	check_dupes(int length, char **args, int argnum);
bool	check_nonint(char *string);
bool	check_zeros(t_node **head_a);

//list based functions
t_node	*create_node(int value);
void	insert_begin(int value, t_node **head);
void	insert_end(int value, t_node **head);
int		list_size(t_node **head);
void	free_list(t_node **head);

//swap functions
void	swap(t_node **head);
void	swap_a(t_node **head);
void	swap_b(t_node **head);
void	swap_both(t_node **head_a, t_node **head_b);

//rotate functions
void	rotate_a(t_node **head);
void	rotate_b(t_node **head);
void	rotate_both(t_node **head_a, t_node **head_b);
void	r_rotate_a(t_node **head);
void	r_rotate_b(t_node **head);
void	r_rotate_both(t_node **head_a, t_node **head_b);

//push functions
void	push_node(t_node **head_a, t_node **head_b);
void	push_to_a(t_node **head_a, t_node **head_b);
void	push_to_b(t_node **head_a, t_node **head_b);

//algorithm functions
void	begin_algos(t_node **head_a, t_node **head_b);
void	two_nums(t_node **head);
void	three_nums(t_node **head_a);
void	four_nums(t_node **head_a, t_node **head_b);
void	five_nums(t_node **head_a, t_node **head_b);

//utility functions
bool	check_ordered(t_node **head);
void	raise_lowest(t_node **head);
int		find_lowest(t_node **head_a);
int		find_next_lowest(t_node **head_a, int data);

//radix functions
int		count_bits(int number);
bool	convert_nums(t_node **head_a, int size);
void	reset_nums(t_node **head_a, int size, int *array);
void	begin_sort(t_node **head_a, t_node **head_b, int size, int iter);
void	radix_sort(t_node **head_a, t_node **head_b, int size);

#endif
