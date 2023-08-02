/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:16:28 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/02 11:34:35 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	check_amount_arguments(int argc)
{
	if (argc != 2)
		return (FALSE);
	return (TRUE);
}

t_bool	check_arguments(int argc, char **argv)
{
	if (!check_amount_arguments(argc))
	{
		exit (error_msg("	Error\nWrong amount of arguments\n", ERROR_MSG));
		return (FALSE);
	}
	if (check_file_extension(argv[1]) == FALSE)
	{
		exit (error_msg("	Error\nWrong file extension\n", ERROR_EXTENSION));
		return (FALSE);
	}
	if (check_file_exists(argv[1]) == FALSE)
	{
		exit (error_msg("	Error\nFile doesn't exist\n", ERROR_FILE));
		return (FALSE);
	}
	return (TRUE);
}
