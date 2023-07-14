/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:44:59 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/14 17:45:48 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_file_lines(const char *file)
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

char	**read_file_lines(const char *file)
{
	int		fd;
	int		idx;
	int		size;
	char	*line;
	char	**content;

	size = count_file_lines(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = ft_calloc(size + 1, sizeof(char *));
	if (!content)
		return (NULL);
	idx = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		content[idx++] = ft_strdup(line);
		free_string(line);
	}
	close (fd);
	return (content);
}
