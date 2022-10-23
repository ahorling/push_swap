#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libraries/libft/includes/libft.h"
# include <stdio.h>

typedef struct	s_node
{
	t_node	*prev;
	int		data;
	t_node	*next;
}	t_node;

int	check_input(int length, char** arguments);

#endif
