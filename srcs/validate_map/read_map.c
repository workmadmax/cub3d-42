/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:50:46 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/15 11:08:00 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_map_lines(char ***map, const char *filename, int num_lines)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	*map = (char **)malloc((num_lines + 1) * sizeof(char *));
	if (*map == NULL)
	{
		printf("Erro de alocação de memória.\n");
		close(fd);
		return ;
	}
	i = 0;
	while (line)
	{
		(*map)[i] = remove_newlines(line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	(*map)[i] = NULL;
	close(fd);
}
