/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:11:55 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/18 15:25:20 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H


typedef struct s_player
{
	int		x;
	int		y;
	int		dir_x;
	int		dir_y;
}	t_player;

typedef struct s_map
{
	int			width;
	int			height;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char		*floor_color;
	t_player	player;
}	t_map;

typedef struct s_cub3d
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
}	t_cub3d;

#endif