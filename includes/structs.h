/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:11:55 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/01 11:19:39 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef struct s_player
{
	int		x;
	int		y;
	int		dir_x;
	int		dir_y;
}	t_player;

typedef struct s_info_map
{
	int			width;
	int			height;
	int			lines;
	t_player	player;
}	t_map;

typedef struct s_cub3d
{
	void		*mlx;
	void		*mlx_win;
	char		**map_file_content;
	char		**map_file_copy;
	t_map		map;
	t_player	*player;
}	t_cub3d;

#endif