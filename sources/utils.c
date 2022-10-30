/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 21:30:08 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/30 18:37:01 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"includes/push_swap.h"

bool	check_ordered(t_node **head)
{
	t_node	*temp;
	int		size;
	int		i;

	if (head == NULL)
		return (0);
	i = 0;
	temp = *head;
	size = list_size(head);
	if (size == 0)
		return (false);
	while (i < size - 1)
	{
		if (temp->data < temp->next->data)
		{
			temp = temp->next;
			i++;
		}
		else
			return (false);
	}
	return (true);
}

int	find_lowest(t_node **head_a)
{
	int		tempnum;
	t_node	*temp;

	tempnum = (*head_a)->data;
	temp = *head_a;
	if (tempnum > temp->data)
		tempnum = temp->data;
	temp = temp->next;
	while (temp != *(head_a))
	{
		if (tempnum > temp->data)
			tempnum = temp->data;
		temp = temp->next;
	}
	return (tempnum);
}

int	find_next_lowest(t_node **head_a, int previous)
{
	int		tempnum;
	t_node	*temp;

	tempnum = (*head_a)->data;
	temp = *head_a;
	while (tempnum <= previous)
	{
		temp = temp->next;
		tempnum = temp->data;
	}
	if (tempnum > temp->data && temp->data > previous)
		tempnum = temp->data;
	temp = temp->next;
	while (temp != *(head_a))
	{
		if (tempnum > temp->data && temp->data > previous)
			tempnum = temp->data;
		temp = temp->next;
	}
	return (tempnum);
}

void	raise_lowest(t_node **head_a)
{
	int	tempnum;

	tempnum = find_lowest(head_a);
	if (tempnum == (*head_a)->prev->data)
		r_rotate_a(head_a);
	while ((*head_a)->data != tempnum)
		rotate_a(head_a);
}
