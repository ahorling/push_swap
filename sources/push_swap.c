/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 17:00:05 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/30 19:32:07 by ahorling      ########   odam.nl         */
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
	int 	temp1;
	int		temp2;
	t_node	*temp;

	temp = *head_a;
	temp1 = 0;
	if (temp->data == 0)
		temp1++;
	temp = temp->next;
	while (temp != *head_a)
	{
		if (temp->data == 0)
			temp1++;
		temp = temp->next;
	}
	if (temp1 != 1 && temp1 != 0)
		return (false);
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
		ft_printf("Error\n");
		return ;
	}
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
