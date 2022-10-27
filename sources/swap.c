/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 20:20:10 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/27 20:59:18 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	swap_a(t_node **head)
{
	t_node *temp;

	if (head == NULL)
		return;
	temp = *head;
	temp->prev = (*head)->prev;
	(*head)->prev->next = (*head)->next;
	(*head)->prev = (*head)->next;
	(*head) = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
	ft_printf("sa\n");
}

void	swap_b(t_node **head)
{
	t_node *temp;

	if (head == NULL)
		return;
	temp = *head;
	temp->prev = (*head)->prev;
	(*head)->prev->next = (*head)->next;
	(*head)->prev = (*head)->next;
	(*head) = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
	ft_printf("sb\n");
}

void	swap_both(t_node **head_a, t_node **head_b)
{
	t_node *temp;

	if (head_a == NULL || head_b == NULL)
		return;
	temp = *head_a;
	temp->prev = (*head_a)->prev;
	(*head_a)->prev->next = (*head_a)->next;
	(*head_a)->prev = (*head_a)->next;
	(*head_a) = (*head_a)->next;
	temp->next = (*head_a)->next;
	(*head_a)->next = temp;
	temp = *head_b;
	temp->prev = (*head_b)->prev;
	(*head_b)->prev->next = (*head_b)->next;
	(*head_b)->prev = (*head_b)->next;
	(*head_b) = (*head_b)->next;
	temp->next = (*head_b)->next;
	(*head_b)->next = temp;
	ft_printf("ss\n");
}
