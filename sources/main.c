/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 06:17:31 by ahorling      #+#    #+#                 */
/*   Updated: 2022/11/09 13:39:46 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (check_input(argc - 1, argv) == false)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	push_swap(argc - 1, argv);
	return (0);
}
