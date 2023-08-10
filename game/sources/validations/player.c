/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:15:20 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/10 11:33:57 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	valid_char_player(const char *val_char)
{
	if (ft_strchr("NSEW", *val_char) == NULL)
		return (FAILURE);
	return (SUCCESS);
}




// flood fill in maze map
void	flood_fill(char **maze, int x, int y)
{
	if (maze[x][y] == '0' || valid_char_player(&maze[x][y]) == SUCCESS)
	{
		maze[x][y] = 'x';
		if (x > 0)
			flood_fill(maze, x - 1, y);
		if (y > 0)
			flood_fill(maze, x, y - 1);
		if (x < max_line_maze(maze) - 1)
			flood_fill(maze, x + 1, y);
		if (y < max_colum(maze) - 1)
			flood_fill(maze, x, y + 1);
	}
}


static void	update_player_loc(t_check_p *check_p, int x, int y)
{
	check_p->count = 1;
	check_p->loc_x = x;
	check_p->loc_y = y;
}

int	set_player_position(char **maze, t_check_p *check_p)
{
	int	i;
	int	j;

	i = -1;
	while (maze[++i])
	{
		j = -1;
		while (maze[i][++j])
		{
			if (valid_char_player(&maze[i][j]) == SUCCESS)
			{
				if (check_p->count == 0)
					update_player_loc(check_p, i, j);
				else
					return (error_msg("Error\nPlayer loc invalid\n", ERROR_MSG));
			}
		}
	}
	if (check_p->count != 1)
		return (error_msg("Error\nPlayer position is invalid\n", ERROR_MSG));
	return (SUCCESS);
}
