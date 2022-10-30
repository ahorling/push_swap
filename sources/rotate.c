/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 20:53:50 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/30 18:39:19 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	rotate_a(t_node **head)
{
	if (head == NULL)
		return ;
	*head = (*head)->next;
	ft_printf("ra\n");
}

void	rotate_b(t_node **head)
{
	if (head == NULL)
		return ;
	*head = (*head)->next;
	ft_printf("rb\n");
}

void	rotate_both(t_node **head_a, t_node **head_b)
{
	if (head_b == NULL || head_b == NULL)
		return ;
	*head_a = (*head_a)->next;
	*head_b = (*head_b)->next;
	ft_printf("rr\n");
}
