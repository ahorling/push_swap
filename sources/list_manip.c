/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_manip.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 16:40:50 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/23 21:48:28 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	*init_list(node_t** start, int value)
{
	node_t *new_node;

	if (*start == NULL)
	{
		new_node = malloc(sizeof(node_t));
		new_node->data = value;
		new_node->next = new_node;
		new_node->prev = new_node;
		*start = new_node;
		return
	}
	node *last = *start->prev;
	new_node = malloc(sizeof(node_t));
	new_node->data = value;
	new_node->next = *start;
	*start->prev = new_node;
	new_node->prev = last;
	last->next = new_node;
}
