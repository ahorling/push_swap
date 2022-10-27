/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   r_rotate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 15:17:13 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/27 16:00:25 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	r_rotate_a(t_node **head)
{
	if (head == NULL)
		return;
	*head = (*head)->prev;
	ft_printf("rra\n");
}

void	r_rotate_b(t_node **head)
{
	if (head == NULL)
		return;
	*head = (*head)->prev;
	ft_printf("rrb\n");
}

void	r_rotate_both(t_node **head_a, t_node **head_b)
{
	if (head_b == NULL || head_b == NULL)
		return;
	*head_a = (*head_a)->prev;
	*head_b = (*head_b)->prev;
	ft_printf("rrr\n");
}