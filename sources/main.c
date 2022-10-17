/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 06:17:31 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/17 07:27:43 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_issign(int n)
{
	if(n == '-' || n == '+')
		return (1);
	else
		return (0);
}

int	num_checker(char *argument)
{
	int i;

	i = 0;
	while (argument[i])
	{
		if (i == 0)
		{
			if (ft_issign(argument[i] == 0))
				return(ft_printf("Error\n"));
			else if (ft_isdigit(argument[i]) == 0)
				return(ft_printf("Error\n"));
		}
		else if (ft_isdigit(argument[i] == 0))
			return (ft_printf("Error\n"));
		i++;
	}
	return (1);
}

int	check_input(int length, char **args)
{
	int	i;

	i = 1;
	while (i <= length)
	{
		if (num_checker(args[i]) == 0)
			return(ft_printf("Error\n"));
		i++;
	}
	return (0);
}

int	main(int argc, char** argv)
{
	if (argc <= 1)
		return(ft_printf("Error\n"));
	if (check_input(argc - 1, argv) == 1)
		return(ft_printf("Error\n"));
	return (0);
}