/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 20:20:10 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/26 20:45:47 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	swap_a(t_node *head)
{
	int temp;

	if (head == NULL)
		return;
	temp = head->data;
	head->data = head->next->data;
	head->next->data = temp;
	ft_printf("sa\n");
}

void	swap_b(t_node *head)
{
	int temp;

	if (head == NULL)
		return;
	temp = head->data;
	head->data = head->next->data;
	head->next->data = temp;
	ft_printf("sb\n");
}

void	swap_both(t_node *head_a, t_node *head_b)
{
	int	temp;

	if (head_a == NULL || head_b == NULL)
		return;
	temp = head_a->data;
	head_a->data = head_a->next->data;
	head_a->next->data = temp;
	temp = head_b->data;
	head_b->data = head_b->next->data;
	head_b->next->data = temp;
	ft_printf("ss\n");
}
