/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:25:33 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/10 17:01:12 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool check_internal_walls(char **maze)
{
    int height = max_line_maze(maze);
    int width = max_colum(maze);

    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            if (maze[i][j] == ' ')
            {
                if ((maze[i - 1][j] == 'x' || maze[i + 1][j] == 'x') &&
                    (maze[i][j - 1] == 'x' || maze[i][j + 1] == 'x'))
                {
                    error_msg("error: ", WALL_ERROR);
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}


t_bool	check_vertical_walls(char **maze, int height, int width)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (maze[i][0] == 'x' || maze[i][width - 1] == 'x')
		{
			error_msg("error: ", WALL_ERROR);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

t_bool	check_horizontal_walls(char **maze, int height, int width)
{
	int	j;

	j = 0;
	while (j < width)
	{
		if (maze[0][j] == 'x' || maze[height - 1][j] == 'x')
		{
			error_msg("error: ", WALL_ERROR);
			return (TRUE);
		}
		j++;
	}
	return (FALSE);
}

t_bool	is_valid_exit(char **maze)
{
	int	height;
	int	width;

	height = max_line_maze(maze);
	width = max_colum(maze);
	if (check_vertical_walls(maze, height, width)
		|| check_horizontal_walls(maze, height, width))
		return (TRUE);
	if (check_internal_walls(maze))
		return (TRUE);
	return (FALSE);
}
