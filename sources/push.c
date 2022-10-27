/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 18:11:56 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/27 20:25:14 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	push_a(t_node **head_a, t_node **head_b)
{
	t_node	*temp;

	if (*head_a == NULL)
	{
		(*head_a) = (*head_b);
		(*head_b)->next->prev = (*head_b)->prev;
		(*head_b)->prev->next = (*head_b)->next;
		(*head_b) = (*head_b)->next;
		(*head_a)->prev = (*head_a);
		(*head_a)->next = (*head_a);
		ft_printf("pa\n");
		return ;
	}
	temp = *head_b;
	(*head_b)->next->prev = (*head_b)->prev;
	(*head_b)->prev->next = (*head_b)->next;
	(*head_b) = (*head_b)->next;
	(*head_a)->prev->next = temp;
	temp->prev = (*head_a)->prev;
	(*head_a)->prev = temp;
	temp->next = (*head_a);
	(*head_a) = temp;
	if (*head_a == *head_b)
		(*head_b) = NULL;
	ft_printf("pb\n");
}

void	push_b(t_node **head_a, t_node **head_b)
{
	t_node	*temp;

	if (*head_b == NULL)
	{
		(*head_b) = (*head_a);
		(*head_a)->next->prev = (*head_a)->prev;
		(*head_a)->prev->next = (*head_a)->next;
		(*head_a) = (*head_a)->next;
		(*head_b)->prev = (*head_b);
		(*head_b)->next = (*head_b);
		ft_printf("pa\n");
		return ;
	}
	temp = *head_a;
	(*head_a)->next->prev = (*head_a)->prev;
	(*head_a)->prev->next = (*head_a)->next;
	(*head_a) = (*head_a)->next;
	(*head_b)->prev->next = temp;
	temp->prev = (*head_b)->prev;
	(*head_b)->prev = temp;
	temp->next = (*head_b);
	(*head_b) = temp;
	if (*head_a == *head_b)
		(*head_a) = NULL;
	ft_printf("pb\n");
}
