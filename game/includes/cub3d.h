/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:03:56 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/10 12:31:00 by madmax42         ###   ########.fr       */
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

/* handle map - get map */

char	**get_maze_map(char **file);

/* handle map - getters */

int		get_line_code(char *line);
int		get_flag_code(char *str);

/*  handle map - read map */

char	**read_file_lines(const char *file);

/* handle map - setters */

t_bool	extract_path(char *line, char **path);
void	extract_rgb(char *line, int *r, int *g, int *b);
void	set_value(t_cub *game, char **map);

/* validations - arguments */

int		check_arguments(int argc, char **argv);

/* validations - file */

int		check_file_extension(char *file, char *extension);
int		check_file_path(const char *file);

/* validations flags */

void	init_check_double_flag(t_check *data);
void	count_flag(t_check *data);
t_bool	check_count_flag(t_check *data);
t_bool	check_amount_flag(char **text);
int		check_value_flag(char **line);

/* validations line */

t_bool	check_first_word(char **line);
t_bool	check_line_position(char **line);

/* validation map.c */

int		check_char_map(char **map);
t_bool	check_maze_map(char **map);
void	check_cub_map_file(char **map);

/* validation player */

int		set_player_position(char **maze, t_check_p *check_p);
void	flood_fill(char **maze, int x, int y);

/* validation rgb */

int		validate_rgb_range(const char *str);
int		is_numeric_string(const char *str);
int		check_rgb_value(const char *line);
int		check_rgb(char *line);

/* validation rgb 2 */

int		check_rgb_cf(char *ceiling, char *floor);
int		check_rgb_aux(char **line);
int		check_value_flag(char **line);

/* validations texture */

int		check_texture(char *line);

/* validations wall */

t_bool	check_vertical_walls(char **maze, int height, int width);
t_bool	check_horizontal_walls(char **maze, int height, int width);
t_bool	is_valid_exit(char **maze);

/* utils assistant */

int		max_line_maze(char **maze);
int		map_count_line(char **map);
int		max_colum(char **map);
int		count_file_lines(const char *file);
t_bool	remove_newlines(char *str);

/* utils - clean data */

void	free_string(char *string);
void	free_string_array(char **string);
void	free_and_close(char **map);

/* utils error msg */

int		error_msg(const char *str, int code);

#endif