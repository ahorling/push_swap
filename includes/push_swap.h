#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libraries/libft/includes/libft.h"
# include <stdio.h>

typedef struct s_node
{
	struct s_node	*prev;
	int		data;
	struct s_node	*next;
}	t_node;

//main function
void	push_swap(int length, char** arguments);

//parsing and checker functions
int		check_input(int length, char** arguments);
int		check_ordered(t_node *head);

//list based functions
t_node	*create_node(int value);
void	insert_begin(int value, t_node *head);
void	insert_end(int value, t_node *head);
int		list_size(t_node *head);
void	delete_begin(t_node **head);
void	delete_end(t_node **head);

//swap functions
void	swap_a(t_node **head);
void	swap_b(t_node **head);
void	swap_both(t_node **head_a, t_node **head_b);

//rotate functions
void	rotate_a(t_node **head);
void	rotate_b(t_node **head);
void	rotate_both(t_node **head_a, t_node **head_b);

//push functions
void	push_a(t_node **head_a, t_node **head_b);
void	push_b(t_node **head_a, t_node **head_b);

#endif
