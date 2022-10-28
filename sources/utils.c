/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 21:30:08 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/28 21:38:22 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"includes/push_swap.h"

bool	check_ordered(t_node **head)
{
	t_node *temp;
	int		size;
	int		i;

	if (head == NULL)
		return (0);
	i = 0;
	temp = *head;
	size = list_size(head);
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

void	raise_lowest(t_node **head_a)
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
	while ((*head_a)->data != tempnum)
		rotate_a(head_a);
}