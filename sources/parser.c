/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 07:43:35 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/17 08:09:18 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	ft_isnum(int n)
{
	if(n == '-' || n == '+' || (n >= '0' && n <= '9'))
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
	while (argument[i])
	{
		if (i == 0)
		{
			if (ft_isnum(argument[i] == 0))
				return (ft_printf("Error\n"));
			temp = ft_isdigit(argument[i]);
		}
		else if (ft_isdigit(argument[i] == 0))
			return (ft_printf("Error\n"));
		i++;
	}
	if (i == 1 && temp == 0)
		return(ft_printf("Error\n"));
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
		if (num_checker(args[i]) == 0)
			return (ft_printf("Error\n"));
		i++;
	}
	return (0);
}