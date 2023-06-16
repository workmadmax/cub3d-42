/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:03:56 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/16 14:11:03 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "structs.h"
# include "defines.h"

# include "../minilibx-linux/mlx.h"
# include "../libft/include/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <error.h>
# include <math.h>
# include <stdbool.h>


/* validae map */

void	read_map_lines(char ***map, const char *filename, int num_lines);
char	*remove_newlines(const char *string);

/* utils map */
int		count_map_lines(const char *filename);
void	get_map_dimensions(char **map, t_map *dimensions);

/* utils */

char	**ft_array_dup(char **array);

void	find_player_position(char **map, t_map map_size, int *pos_x, int *pos_y);
void	set_player_direction(char **map, int pos_x, int pos_y, t_player *player);
void	get_player_position(char **map, t_map map_size, t_player *player);

#endif