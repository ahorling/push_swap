/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 07:43:35 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/26 20:29:56 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	ft_isnum(char c)
{
	if(c == '-' || c == '+' || (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

int	num_checker(const char *argument)
{
	int i;
	int	temp;

	i = 0;
	temp = 1;
	while (argument[i] != '\0')
	{
		if (i == 0)
		{
			if (ft_isnum(argument[i]) == 0)
				return (ft_printf("Error\n"));
			temp = ft_isdigit(argument[i]);
		}
		else if (ft_isdigit(argument[i]) == 0)
			return (ft_printf("Error\n"));
		i++;
	}
	return (1);
}

int	check_input(int length, char **args)
{
	int	i;

	i = 1;
	if (length == 0)
		return (ft_printf("Error\n"));
	while (i <= length)
	{
		if (num_checker(args[i]) != 1)
			return (1);
		i++;
	}
	return (0);
}

int check_ordered(t_node *head)
{
	t_node *temp;
	int		size;
	int		i;

	if (head == NULL)
		return (0);
	i = 0;
	temp = head;
	size = list_size(head);
	while (i <= size)
	{
		if (temp->data < temp->next->data)
		{
			temp = temp->next;
			i++;
		}
		else
			return (0);
		i++;
	}
	return (1);
}