/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 17:00:05 by ahorling      #+#    #+#                 */
/*   Updated: 2022/11/11 19:29:13 by ahorling      ########   odam.nl         */
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

bool	check_zeros(t_node **head_a)
{
	int		i;
	int		size;
	int		compnum;
	t_node	*temp;

	size = list_size(head_a);
	temp = *head_a;
	compnum = (*head_a)->data;
	i = 1;
	temp = temp->next;
	while (i <= size)
	{
		while (temp != *head_a)
		{
			if (temp->data == compnum)
				return (false);
			temp = temp->next;
		}
		*head_a = (*head_a)->next;
		i++;
		compnum = (*head_a)->data;
	}
	return (true);
}

void	push_swap(int length, char **arguments)
{
	t_node	*head_a;
	t_node	*head_b;

	head_b = NULL;
	head_a = NULL;
	generate_list(length, arguments, &head_a);
	if (check_zeros(&head_a) == false)
	{
		free_list(&head_a);
		write(2, "Error\n", 6);
		exit(1);
	}
	if (check_ordered(&head_a) == true)
	{
		free_list(&head_a);
		return ;
	}
	begin_algos(&head_a, &head_b);
	if (check_ordered(&head_a) == 1)
	{
		free_list(&head_a);
		return ;
	}
}
