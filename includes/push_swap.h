#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libraries/libft/includes/libft.h"
# include <stdio.h>
# include <stdbool.h>

typedef struct s_node
{
	struct s_node	*prev;
	int		data;
	struct s_node	*next;
}	t_node;

//main function
void	push_swap(int length, char** arguments);

//parsing and checker functions
bool	check_input(int length, char** arguments);

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

#endif
