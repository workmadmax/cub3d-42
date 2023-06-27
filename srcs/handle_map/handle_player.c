/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:41:31 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/27 10:45:40 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


t_bool	is_player_character(char tile)
{
	return (tile == 'N' || tile == 'S' || tile == 'E' || tile == 'W');
}

// Função para encontrar as coordenadas iniciais e finais do labirinto na matriz
void	find_maze_bounds(t_cub3d *cub3d)
{
	cub3d->map.start_x = 0;
	cub3d->map.end_x = cub3d->map.width - 1;
	cub3d->map.start_y = 1;
}

// Função para encontrar a posição do jogador no labirinto
t_bool	find_player_position(t_cub3d *cub3d)
{
	int		i;
	int		j;
	char	tile;

	i = cub3d->map.start_y;
	while (i < cub3d->map.height)
	{
		j = cub3d->map.start_x;
		while (j <= cub3d->map.end_x)
		{
			tile = cub3d->map_file_content[i][j];
			if (is_player_character(tile))
			{
				cub3d->map.player.x = j;
				cub3d->map.player.y = i;
				return (TRUE);
			}
			j++;
		}
		i++;
	}
	return (FALSE);
}

// Função principal para obter a posição do jogador
t_bool	get_player_position(t_cub3d *cub3d)
{
	find_maze_bounds(cub3d);
	return (find_player_position(cub3d));
}
