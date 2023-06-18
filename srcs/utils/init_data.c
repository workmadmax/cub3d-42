/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:22:24 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/18 15:34:08 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void initialize_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->north_texture = "north.xpm";
	map->south_texture = "south.xpm";
	map->west_texture = "west.xpm";
	map->east_texture = "east.xpm";
	map->floor_color = "148,109,80";
	map->player.x = 5;
	map->player.y = 5;
	map->player.dir_x = 1;
	map->player.dir_y = 0;
}

void	initialize_cub3d(t_cub3d *cub3d)
{
	cub3d->mlx = NULL; // Preencha com o valor desejado
	cub3d->mlx_win = NULL; // Preencha com o valor desejado
	initialize_map(&(cub3d->map));
}
