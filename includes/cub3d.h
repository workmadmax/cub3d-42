/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:03:56 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/21 10:13:35 by madmax42         ###   ########.fr       */
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
t_bool	read_map_file(int fd, t_cub3d *cub3d);
t_bool	process_map_line(char *line, t_cub3d *cub3d, int *map_lines);


/* ====== utils map ====== */

t_bool	update_map_dimensions(const char *line, t_cub3d *cub3d);
t_bool	remove_newlines(char *str);

/* ====== validate map ====== */

t_bool	validate_map(const t_cub3d *cub3d);

/* ====== validate texture ====== */

t_bool	validate_required_fields(const t_map *map);
t_bool	validate_texture_extension(const char *texture);
t_bool	validate_texture(const t_cub3d *cub3d);

/* ====== utils ====== */

/* ====== clean data ====== */
void	free_map(char **map_data);



/* ====== libft ====== */

int		ft_strcmp(const char *str1, const char *str2);

/* ====== testes ====== */

t_bool	ft_array_dup(char **array, char ***cpy);


/* free data */

void	ft_free_map(t_map *map);
void	ft_free_array(t_cub3d *cub3d);

#endif