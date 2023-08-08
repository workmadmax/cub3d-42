/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:16:28 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/08 15:38:04 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_arguments(int argc, char **argv)
{
	if (argc != 2)
		exit (error_msg("Error\nInvalid amount arguments\n", ERROR_MSG));
	if (check_file_extension(argv[1], ".cub") == FAILURE)
		exit (error_msg("Error\nInvalid file extension\n", ERROR_MSG));
	if (check_file_path(argv[1]) == FAILURE)
		exit (error_msg("Error\nInvalid file map\n", ERROR_FILE));
	return (SUCCESS);
}
