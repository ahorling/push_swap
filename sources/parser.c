/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 07:43:35 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/29 16:12:08 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	ft_isnum(char c)
{
	if(c == '-' || c == '+' || (c >= '0' && c <= '9'))
		return (true);
	else
		return (false);
}

bool	num_checker(const char *argument)
{
	int 	i;
	bool	temp;

	i = 0;
	temp = true;
	if (argument[i] == '\0')
		return (false);
	while (argument[i] != '\0')
	{
		if (i == 0)
		{
			if (ft_isnum(argument[i]) == false)
				return (false);
			temp = ft_isdigit(argument[i]);
		}
		else if (ft_isdigit(argument[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

bool	check_dupes(int length, char **args, int argnum)
{
	int i;

	i = argnum + 1;
	while (i <= length)
	{
		if (ft_strcmp(args[argnum], args[i]) != 0)
			i++;
		else
			return (false);
	}
	return (true);
}

bool	check_input(int length, char **args)
{
	int	i;

	i = 1;
	if (length == 0)
		return (false);
	while (i <= length)
	{
		if (check_dupes(length, args, i) == false)
			return (false);
		if (num_checker(args[i]) == false)
			return (false);
		i++;
	}
	return (true);
}