/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_manip.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 16:40:50 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/26 20:19:22 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_node	*create_node(int value)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return(NULL);
	new_node->data = value;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

void	*insert_begin(int value, t_node *head)
{
	t_node *new_node;

	new_node = create_node(value);
	if (new_node)
	{
		if (head == NULL)
		{
			new_node->next = new_node;
			new_node->prev = new_node;
			head = new_node;
			return (0);
		}
		head->prev->next = new_node;
		new_node->prev = head->prev;
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
	return (0);
}

void	*insert_end(int value, t_node *head)
{
	t_node *new_node;

	new_node = create_node(value);
	if (new_node)
	{
		if (head == NULL)
		{
			new_node->next = new_node;
			new_node->prev = new_node;
			head = new_node;
			return (0);
		}
		head->prev->next = new_node;
		new_node->prev = head->prev;
		new_node->next = head;
		head->prev = new_node;
	}
	return (0);
}

int		list_size(t_node *head)
{
	t_node *temp;
	int count;

	temp = head;
	if (head == NULL)
		return (0);
	count = 1;
	temp = temp->next;
	while (temp != head)
	{
		count += 1;
		temp = temp->next;
	}
	return (count);
}
