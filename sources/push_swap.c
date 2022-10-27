/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 17:00:05 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/27 21:00:17 by ahorling      ########   odam.nl         */
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

void generate_list(int length, char **arguments, t_node *head)
{
	int i;

	i = 2;
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
	head_a = create_node(ft_atoi(arguments[1]));
	generate_list(length, arguments, head_a);
	if (check_ordered(head_a) == 1)
	{
		ft_printf("list already ordered");
		return;
	}
	push_b(&head_a, &head_b);
	push_b(&head_a, &head_b);
	print_list(head_a);
	print_list(head_b);
	swap_both(&head_a, &head_b);
	print_list(head_a);
	print_list(head_b);
}