/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:45:07 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/10 11:34:04 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	max_line_maze(char **maze)
{
	int	max;

	max = 0;
	while (maze[max] != NULL)
		max++;
	return (max);
}

int	map_count_line(char **map)
{
	int	i;
	int	size;
	int	found_first_wall;

	i = 0;
	size = 0;
	found_first_wall = 0;
	while (map[i])
	{
		if (get_line_code(map[i]) == WALL || found_first_wall)
		{
			size++;
			found_first_wall = 1;
		}
		i++;
	}
	return (size);
}

int	max_colum(char **map)
{
	int	i;
	int	size;
	int	found_first_wall;
	int	len;

	i = 0;
	size = 0;
	found_first_wall = 0;
	while (map[i])
	{
		if (get_line_code(map[i]) == WALL || found_first_wall)
		{
			len = ft_strlen(map[i]);
			if (len > size)
				size = len;
			found_first_wall = 1;
		}
		i++;
	}
	return (size);
}

int	count_file_lines(const char *file)
{
	int		result;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (FAILURE);
	result = -1;
	while (++result > -1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free_string(line);
	}
	free_string(line);
	close (fd);
	return (result);
}

t_bool	remove_newlines(char *str)
{
	char	*nl_position;

	nl_position = ft_strchr(str, '\n');
	if (nl_position != NULL)
	{
		*nl_position = '\0';
		return (TRUE);
	}
	return (FALSE);
}
