/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:04:16 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/16 14:50:05 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_player_position(char **map, t_map map_size, int *pos_x, int *pos_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_size.height)
	{
		j = 0;
		while (j < map_size.width)
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				*pos_x = j + 1;
				*pos_y = i + 1;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	set_player_direction(char **map, int pos_x, int pos_y, t_player *player)
{
	if (map[pos_y - 1][pos_x - 1] == 'E' || map[pos_y - 1][pos_x - 1] == 'W')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (map[pos_y - 1][pos_x - 1] == 'S'
			|| map[pos_y - 1][pos_x - 1] == 'N')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
}

void	get_player_position(char **map, t_map map_size, t_player *player)
{
	int	pos_x;
	int	pos_y;

	find_player_position(map, map_size, &pos_x, &pos_y);
	player->x = pos_x;
	player->y = pos_y;
	set_player_direction(map, pos_x, pos_y, player);
}
