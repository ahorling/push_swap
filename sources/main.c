/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 06:17:31 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/26 19:23:12 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char** argv)
{
	if (check_input(argc - 1, argv) != 0)
		return (1);
	push_swap(argc - 1, argv);
	return (0);
}