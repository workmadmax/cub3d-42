/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:39:57 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/08 15:44:01 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_char_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("01NSEW\n ", map[i][j]) == NULL)
				return (error_msg(map[i], ERROR_LINE));
		}
	}
	return (SUCCESS);
}

int	check_map_file(char **map)
{
	char	**map_aux;

	map_aux = get_maze_map(map);
	if (!map_aux)
		return (error_msg("Failed to alloc memory!", ERROR_MALLOC));
	if (check_char_map(map_aux) == FAILURE)
	{
		free_string_array(map_aux);
		return (FAILURE);
	}
	if (check_player(map_aux) == FAILURE)
	{
		free_string_array(map_aux);
		return (FAILURE);
	}
	if (check_is_closed(map_aux) == FAILURE)
	{
		free_string_array(map_aux);
		return (error_msg("The map need to be \
				surrounded by walls!!!", WALL_ERROR));
	}
	free_string_array(map_aux);
	return (SUCCESS);
}

void	check_cub_map_file(char **map)
{
	if (!check_first_word(map))
		free_and_close(map);
	if (!check_line_position(map))
		free_and_close(map);
	if (!check_amount_flag(map))
		free_and_close(map);
	if (check_value_flag(map) == FAILURE)
		free_and_close(map);
	if (check_map_file(map) == FAILURE)
		free_and_close(map);
}
