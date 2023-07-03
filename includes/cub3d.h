/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:03:56 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/03 18:07:12 by madmax42         ###   ########.fr       */
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
# include <string.h>


/* ====== handle map file ====== */

t_bool	open_map_file(const char *filename, int *fd);
t_bool	read_map_file_data(t_cub3d *cub3d, int fd);
t_bool	process_map_data(t_cub3d *cub3d, char *line);
t_bool	copy_map_content(t_cub3d *cub3d, int map_line);


/* ======= handle player ====== */

void	set_info_player(int x, int y, int dir_x, int dir_y);
void	update_player_position(t_cub3d *cub3d, int x, int y, char tile);
void	find_player_position(t_cub3d *cub3d);


/* ====== utils map ====== */

t_bool	update_map_dimensions(const char *line, t_cub3d *cub3d);
t_bool	remove_newlines(char *str);
void	apply_flood_fill(t_cub3d *cub3d);

/* ====== validate map ====== */

t_bool	validate_map_characters(t_cub3d *cub3d);

/* ====== validate texture ====== */

t_bool	validate_required_fields(const t_map *map);
t_bool	validate_texture_extension(const char *texture);
t_bool	validate_texture(const t_cub3d *cub3d);

/* ====== utils ====== */

/* ====== clean data ====== */
void	free_map(char **map_data);



/* ====== libft ====== */

int		ft_strcmp(const char *str1, const char *str2);
void	flood_fill(t_cub3d *cub3d, int x, int y);
t_bool	ft_array_dup(char **array, char ***cpy);

/* ====== testes ====== */

t_bool	ft_array_dup(char **array, char ***cpy);


/* free data */

void	ft_free_map(t_map *map);
void	ft_free_array(t_cub3d *cub3d);

#endif