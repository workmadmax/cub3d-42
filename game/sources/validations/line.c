/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:34:06 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/10 16:54:43 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	check_first_word(char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (get_line_code(line[i]) == FAILURE)
		{
			printf("entrou aqui\n");
			error_msg(line[i], ERROR_LINE);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

t_bool	check_line_position(char **map)
{
	int	i;
	int	map_started;
	int	status;

	i = 0;
	map_started = 0;
	while (map[i])
	{
		status = get_line_code(map[i]);
		if (status == WALL && !map_started)
			map_started = 1;
		if (map_started)
		{
			if (status != WALL)
				map_started = 2;
			if (map_started == 2 && status != NEW_LINE && status != END)
			{
				error_msg(map[i], ERROR_LINE_WRONG_POSITION);
				return (FALSE);
			}
		}
		i++;
	}
	return (TRUE);
}
