/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 17:00:05 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/29 21:52:50 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	print_list(t_node *head)
{
	t_node *temp;

	if (head == NULL)
	{
		ft_printf("\nList is empty");
		return;
	}
	temp = head;
	ft_printf("%d ", temp->data);
	temp = temp->next;
	while (temp != head)
	{
		ft_printf("%d ", temp->data);
		temp = temp->next;
	}
	ft_printf("\n");
}

void generate_list(int length, char **arguments, t_node **head)
{
	int i;

	i = 1;
	while (i <= length)
	{
		insert_end(ft_atoi(arguments[i]), head);
		i++;
	}
}

void	push_swap(int length, char **arguments)
{
	t_node *head_a;
	t_node *head_b;

	head_b = NULL;
	head_a = NULL;
	generate_list(length, arguments, &head_a);
	if (check_ordered(&head_a) == true)
	{
		print_list(head_a);
		return;
	}
	begin_algos(&head_a, &head_b);
	if (check_ordered(&head_a) == 1)
	{
		free_list(&head_a);
		free_list(&head_b);
		return;
	}
}