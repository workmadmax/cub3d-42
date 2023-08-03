/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:34:06 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/02 20:34:00 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	check_first_word(char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (get_line_code(line[i]) == FALSE)
		{
			error_msg("Error\n**line invalid", ERROR_LINE);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

t_bool	check_line_position(char **line)
{
	int	i;
	int	map;
	int	status;

	i = -1;
	map = 0;
	while (line[++i])
	{
		status = get_line_code(line[i]);
		if (status == WALL && map == 0)
			map = 1;
		if (map == 1 && status != WALL)
			map = 2;
		if (map == 2 && status != NEW_LINE && status != END)
			return (error_msg(line[i], ERROR_LINE));
	}
	return (TRUE);
}
