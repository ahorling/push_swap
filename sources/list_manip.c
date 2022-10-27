/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_manip.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 16:40:50 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/27 19:14:19 by ahorling      ########   odam.nl         */
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

void	insert_begin(int value, t_node *head)
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
			return;
		}
		head->prev->next = new_node;
		new_node->prev = head->prev;
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
	return;
}

void	insert_end(int value, t_node *head)
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
			return;
		}
		head->prev->next = new_node;
		new_node->prev = head->prev;
		new_node->next = head;
		head->prev = new_node;
	}
	return;
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

// void	delete_begin(t_node **head)
// {
// 	if (*head == NULL)
// 		return;
// 	else if ((*head)->next == *head)
// 	{
// 		free(head);
// 		return;
// 	}
// 	(*head)->prev->next = (*head)->next;
// 	(*head)->next->prev = (*head)->prev;
// 	(*head) = (*head)->next;
// }

// void	delete_end(t_node **head)
// {
// 	t_node *last;

// 	if (head == NULL)
// 		return;
// 	else if ((*head)->next == *head)
// 	{
// 		free(head);
// 		return;
// 	}
// 	last = (*head)->prev;
// 	last->prev->next = *head;
// 	(*head)->prev = last->prev;
// 	free(last);
// }