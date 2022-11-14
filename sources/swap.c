/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 20:20:10 by ahorling      #+#    #+#                 */
/*   Updated: 2022/11/14 16:54:34 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	swap(t_node **head)
{
	t_node	*temp;

	if (head == NULL)
		return ;
	temp = *head;
	(*head)->prev->next = (*head)->next;
	(*head)->next->prev = (*head)->prev;
	(*head)->prev = (*head)->next;
	(*head) = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
	if ((*head)->prev == *head)
		(*head)->prev = temp->prev->next;
}

void	swap_a(t_node **head_a)
{
	swap(head_a);
	ft_printf("sa\n");
}

void	swap_b(t_node **head_b)
{
	swap(head_b);
	ft_printf("sb\n");
}

void	swap_both(t_node **head_a, t_node **head_b)
{
	swap(head_a);
	swap(head_b);
	ft_printf("ss\n");
}
