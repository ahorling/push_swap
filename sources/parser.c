/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 07:43:35 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/30 19:27:31 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

bool	num_checker(const char *argument)
{
	int		i;
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
	int	i;

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

bool	check_nonint(char *str)
{
	long	value;
	long	i;
	int		neg;

	i = ft_whtspce(str);
	value = 0;
	neg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10;
		value = value + str[i] - '0';
		i++;
	}
	value = value * neg;
	if (value > INT_MAX || value < INT_MIN)
		return (false);
	else
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
		if (check_nonint(args[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
