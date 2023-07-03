/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:00:23 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/03 15:27:11 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


t_bool	open_map_file(const char *filename, int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
	{
		printf("Erro ao abrir o arquivo.\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool	copy_map_content(t_cub3d *cub3d, int map_line)
{
	cub3d->map.lines = map_line;
	cub3d->map_file_content[map_line] = NULL;
	if (!ft_array_dup(cub3d->map_file_content, &(cub3d->map_file_copy)))
	{
		printf("Erro ao duplicar o conteúdo do arquivo do mapa.\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool	read_map_file_data(t_cub3d *cub3d, int fd)
{
	int		map_line;
	char	*line;

	map_line = 0;
	line = NULL;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		remove_newlines(line);
		if (!process_map_data(cub3d, line))
		{
			free(line);
			return (FALSE);
		}
		cub3d->map_file_content[map_line++] = line;
	}
	if (!copy_map_content(cub3d, map_line))
	{
		free(line);
		return (FALSE);
	}
	return (TRUE);
}

void	apply_flood_fill(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub3d->map.lines)
	{
		j = 0;
		while (j < cub3d->map.width)
		{
			if (cub3d->map_file_copy[i][j] == '0')
			{
				flood_fill(cub3d, j, i);
			}
			j++;
		}
		i++;
	}
}
