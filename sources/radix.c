/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 17:17:26 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/30 18:37:01 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	count_bits(int number)
{
	int	bits;

	bits = 0;
	while ((number >> bits) != 0)
		bits++;
	return (bits);
}

void	reset_nums(t_node **head_a, int size, int *array)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = *head_a;
	while (temp->data != array[i])
		i++;
	temp->data = i;
	temp = temp->next;
	while (temp != *head_a)
	{
		i = 0;
		while (temp->data != array[i])
			i++;
		temp->data = i;
		temp = temp->next;
	}
	free(array);
}

bool	convert_nums(t_node **head_a, int size)
{
	int	i;
	int	num;
	int	numprev;
	int	*array;

	i = 1;
	array = malloc(size * sizeof(int));
	if (!array)
		return (false);
	num = find_lowest(head_a);
	numprev = num;
	array[i - 1] = num;
	i++;
	while (i <= size)
	{
		num = find_next_lowest(head_a, numprev);
		array[i - 1] = num;
		i++;
		numprev = num;
	}
	i = 0;
	reset_nums(head_a, size, array);
	return (true);
}

void	begin_sort(t_node **head_a, t_node **head_b, int size, int i)
{
	int	j;
	int	num;

	j = 0;
	while (j < size)
	{
		num = (*head_a)->data;
		if (((num >> i) & 1) == 1)
			rotate_a(head_a);
		else
			push_to_b(head_a, head_b);
		j++;
	}
	while (*head_b != NULL)
		push_to_a(head_a, head_b);
}

void	radix_sort(t_node **head_a, t_node **head_b, int size)
{
	int	max;
	int	bits;
	int	i;

	i = 0;
	max = size - 1;
	bits = count_bits(max);
	if (convert_nums(head_a, size) == false)
		return ;
	while (i < bits)
	{
		begin_sort(head_a, head_b, size, i);
		i++;
	}
}
