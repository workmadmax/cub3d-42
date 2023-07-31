/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:39:57 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/29 10:30:22 by madmax42         ###   ########.fr       */
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
			if (ft_strchr("01NSEW\n\t ", map[i][j]) == NULL)
				return (error_msg("error line char map!", ERROR_LINE));
		}
	}
	return (SUCCESS);
}

int	check_player(char **map)
{
	int	i;
	int	j;
	int	player;

	i = -1;
	player = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSEW", map[i][j]) != NULL)
				player++;
		}
	}
	if (player == 1)
		return (SUCCESS);
	return (error_msg("number player wrong!!!", ERROR_MSG));
}

int	check_map(char **map)
{
	char	**map_aux;

	map_aux = get_map(map);
	if (!map_aux)
		return (error_msg("map is null!!!", ERROR_MALLOC));
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
	/* if (check_wall_map(map_aux) == FAILURE)
	{
		free_string_array(map_aux);
		return (error_msg("map is not closed!!!", ERROR_MSG));
	} */
	free_string_array(map_aux);
	return (SUCCESS);
}

void	check_cub_map_file(char **map)
{
	if (check_first_word(map) == FAILURE)
		free_and_close(map);
	if (check_double_flag(map) == FAILURE)
		free_and_close(map);
	if (check_line_position(map) == FAILURE)
		free_and_close(map);
	if (check_value_flag(map) == FAILURE)
		free_and_close(map);
	if (check_map(map) == FAILURE)
		free_and_close(map);
}
