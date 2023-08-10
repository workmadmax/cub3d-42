/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:11:55 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/09 11:59:22 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;


typedef struct s_check
{
	int		no;
	int		so;
	int		we;
	int		ea;
	int		f;
	int		c;
	int		i;
	int		status;
}	t_check;

typedef struct s_check_player
{
	int	loc_x;
	int	loc_y;
	int	count;
}	t_check_p;


typedef struct s_color
{
	int	floor_r;
	int	floor_g;
	int	floor_b;
	int	ceil_r;
	int	ceil_g;
	int	ceil_b;
}	t_color;
typedef struct s_player
{
	int		vertical_walk; // -1 for back, +1 for front
	int		turn_direction; // -1 for left, +1 for right
	int		horizontal_walk; // -1 for left, +1 for right
	float	x;
	float	y;
	float	width;
	float	height;
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
}  	t_player;

typedef struct s_data
{
	char	**map;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	t_color	color;
}	t_data;

typedef struct s_cub
{
	t_data		data;
	t_player	player;
}	t_cub;


#endif