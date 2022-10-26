/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 17:00:05 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/26 21:40:32 by ahorling      ########   odam.nl         */
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
	t_node *point_a;

	head_a = create_node(ft_atoi(arguments[1]));
	point_a = head_a;
	generate_list(length, arguments, head_a);
	if (check_ordered(head_a) == 1)
	{
		ft_printf("list already ordered");
		return;
	}
	print_list(point_a);
	ft_printf("\n");
	swap_a(&head_a);
	print_list(head_a);
	// ft_printf("\n");
	// rotate_a(&head_a);
	// print_list(head_a);
	// ft_printf("\n");
}