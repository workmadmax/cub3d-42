/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:09:28 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/15 11:09:45 by madmax42         ###   ########.fr       */
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
