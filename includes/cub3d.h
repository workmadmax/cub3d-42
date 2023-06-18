/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:03:56 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/18 15:51:18 by madmax42         ###   ########.fr       */
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
# include <string.h>


/* handle file */

bool	open_file(const char *filename, int *fd);
bool	remove_newlines(char *str);
bool	update_map_dimensions(const char *line, t_map *map);
bool	read_file(int fd, t_map *map);
bool	process_map_file(const char *filename, t_cub3d *cub3d);

/* validate map */

bool	validate_required_fields(const t_map *map);
bool	validate_texture_extension(const char *texture);
bool	validate_texture_extensions(const t_cub3d *cub3d);
bool	validate_map(const t_cub3d *cub3d);

/* utils - init data */

void	initialize_cub3d(t_cub3d *cub3d);
void	initialize_map(t_map *map);

/* utils libft */

int		ft_strcmp(const char *str1, const char *str2);

#endif