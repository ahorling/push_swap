/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   basic_algos.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 15:08:42 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/30 18:37:32 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	two_nums(t_node **head)
{
	if (check_ordered(head) == true)
		return ;
	else
		swap_a(head);
}

void	three_nums(t_node **head_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*head_a)->data;
	middle = (*head_a)->next->data;
	bottom = (*head_a)->prev->data;
	if (top > middle && middle < bottom && top < bottom)
		swap_a(head_a);
	else if (top < middle && middle > bottom && top > bottom)
		r_rotate_a(head_a);
	else if (top > middle && middle < bottom && top > bottom)
		rotate_a(head_a);
	else if (top > middle && middle > bottom && top > bottom)
	{
		rotate_a(head_a);
		swap_a(head_a);
	}
	else if (top < middle && middle > bottom & top < bottom)
	{
		r_rotate_a(head_a);
		swap_a(head_a);
	}
}

void	four_nums(t_node **head_a, t_node **head_b)
{
	raise_lowest(head_a);
	push_to_b(head_a, head_b);
	three_nums(head_a);
	push_to_a(head_a, head_b);
}

void	five_nums(t_node **head_a, t_node **head_b)
{
	raise_lowest(head_a);
	push_to_b(head_a, head_b);
	raise_lowest(head_a);
	push_to_b(head_a, head_b);
	three_nums(head_a);
	push_to_a(head_a, head_b);
	push_to_a(head_a, head_b);
}

void	begin_algos(t_node **head_a, t_node **head_b)
{
	int	size;

	size = list_size(head_a);
	if (size == 2)
		two_nums(head_a);
	if (size == 3)
		three_nums(head_a);
	if (size == 4)
		four_nums(head_a, head_b);
	if (size == 5)
		five_nums(head_a, head_b);
	if (size > 5)
		radix_sort(head_a, head_b, size);
}
