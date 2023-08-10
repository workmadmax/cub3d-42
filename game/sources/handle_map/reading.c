/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:44:59 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/09 19:09:53 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**read_file_lines(const char *file)
{
	int		fd;
	int		idx;
	int		size;
	char	*line;
	char	**content;

	size = count_file_lines(file);
	fd = open(file, O_RDWR);
	if (fd < 1)
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
