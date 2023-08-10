/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:25:33 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/10 12:30:05 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	check_vertical_walls(char **maze, int height, int width)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (maze[i][0] == 'x' || maze[i][width - 1] == 'x')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	check_horizontal_walls(char **maze, int height, int width)
{
	int	j;

	j = 0;
	while (j < width)
	{
		if (maze[0][j] == 'x' || maze[height - 1][j] == 'x')
			return (FALSE);
		j++;
	}
	return (TRUE);
}

t_bool	is_valid_exit(char **maze)
{
	int	height;
	int	width;

	height = max_line_maze(maze);
	width = max_colum(maze);
	if (!check_vertical_walls(maze, height, width)
		|| !check_horizontal_walls(maze, height, width))
		return (FALSE);
	return (TRUE);
}
