/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 20:53:50 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/26 21:32:46 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	rotate_a(t_node **head)
{
	t_node temp;

	if (head == NULL)
		return;
	*head = (*head)->next;
	
	ft_printf("ra\n");
}

void	rotate_b(t_node *head)
{
	t_node *temp;

	if (head == NULL)
		return;
	temp = head;
	head = head->prev;
	head->prev = temp;
	ft_printf("rb\n");
}

void	rotate_both(t_node *head_a, t_node *head_b)
{
	t_node *temp;

	if (head_b == NULL || head_b == NULL)
		return;
	temp = head_a;
	head_a = head_a->prev;
	head_a->prev = temp;
	temp = head_b;
	head_b = head_b->prev;
	head_b->prev = temp;
	ft_printf("rr\n");
}