/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:09:28 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/15 14:43:43 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_map_lines(const char *filename)
{
	int		num_lines;
	int		fd;
	char	*line;

	num_lines = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		num_lines++;
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (num_lines);
}

void	get_map_dimensions(char **map, t_map *dimensions)
{
	int		current_width;

	dimensions->width = 0;
	dimensions->height = 0;
	if (map == NULL || map[0] == NULL)
	{
		dimensions->width = -1;
		dimensions->height = -1;
		return ;
	}
	dimensions->height = 1;
	dimensions->width = ft_strlen(map[0]);
	while (map[dimensions->height] != NULL)
	{
		current_width = ft_strlen(map[dimensions->height]);
		if (current_width > dimensions->width)
			dimensions->width = current_width;
		dimensions->height++;
	}
}

