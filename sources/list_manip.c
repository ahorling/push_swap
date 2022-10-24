/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_manip.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 16:40:50 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/24 15:56:58 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

node_t	*init_list(node_t** start, int value)
{
	node_t *new_node;

	new_node = malloc(sizeof(node_t));
	if (!new_node)
		return(NULL);
	new_node->data = value;
	new_node->next = new_node;
	new_node->prev = new_node;
	*start = new_node;
	return;
}

node_t	*add_node(int value, node_t *first, node_t *last)
{
	node_t *new_node;

	new_node = malloc(sizeof(node_t));
	if (!new_node)
		return(NULL);
	new_node->data = value;
	new_node->next = first;
	new_node->prev = last;
	first->prev = new_node;
	last->next = new_node;
}

node_t	*insert_node(int value, node_t *next, node_t *previous)
{
	node_t *new_node;

	new_node = malloc(sizeof(node_t));
	if (!new_node)
		return(NULL);
	new_node->data = value;
	new_node->next = next;
	new_node->prev = previous;
	next->prev = new_node;
	previous->next = new_node;
}
