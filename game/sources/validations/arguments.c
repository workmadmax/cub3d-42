/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:16:28 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/14 17:38:28 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_amount_arguments(int argc)
{
	if (argc != 2)
	{
		printf("Error no número de argumentos...\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

int	check_arguments(int argc, char **argv)
{
	if (check_amount_arguments(argc) == FAILURE)
	{
		exit(0);
		return (FAILURE);
	}
	if (check_file_extension(argv[1]) == FAILURE)
	{
		exit(0);
		return (FAILURE);
	}
	if (check_file_exists(argv[1]) == FAILURE)
	{
		exit(0);
		return (FAILURE);
	}
	return (SUCCESS);
}
