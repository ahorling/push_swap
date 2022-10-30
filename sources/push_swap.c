/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 17:00:05 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/30 18:10:03 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	generate_list(int length, char **arguments, t_node **head)
{
	int	i;

	i = 1;
	while (i <= length)
	{
		insert_end(ft_atoi(arguments[i]), head);
		i++;
	}
}

void	push_swap(int length, char **arguments)
{
	t_node	*head_a;
	t_node	*head_b;

	head_b = NULL;
	head_a = NULL;
	generate_list(length, arguments, &head_a);
	if (check_ordered(&head_a) == true)
		return ;
	begin_algos(&head_a, &head_b);
	if (check_ordered(&head_a) == 1)
	{
		free_list(&head_a);
		free_list(&head_b);
		return ;
	}
}
