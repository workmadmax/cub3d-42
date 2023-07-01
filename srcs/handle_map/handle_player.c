/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:33:29 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/01 12:05:56 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_info_player(int x, int y, int dir_x, int dir_y)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	player->x = x;
	player->y = y;
	player->dir_x = dir_x;
	player->dir_y = dir_y;
}

void	update_player_position(t_cub3d *cub3d, int x, int y, char tile)
{
	cub3d->player->x = x;
	cub3d->player->y = y;

	if (tile == 'N')
	{
		cub3d->player->dir_x = 0;
		cub3d->player->dir_y = -1;
	}
	else if (tile == 'S')
	{
		cub3d->player->dir_x = 0;
		cub3d->player->dir_y = 1;
	}
	else if (tile == 'E')
	{
		cub3d->player->dir_x = 1;
		cub3d->player->dir_y = 0;
	}
	else if (tile == 'W')
	{
		cub3d->player->dir_x = -1;
		cub3d->player->dir_y = 0;
	}
}

void	find_player_position(t_cub3d *cub3d)
{
	int		i;
	int		j;
	char	tile;

	i = 0;
	j = 0;
	while (i < cub3d->map.lines)
	{
		j = 0;
		while (j < cub3d->map.width)
		{
			tile = cub3d->map_file_content[i][j];
			if (tile == 'N' || tile == 'S' || tile == 'E' || tile == 'W')
			{
				update_player_position(cub3d, j, i, tile);
				return ;
			}
			j++;
		}
		i++;
	}
}
