/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:00:23 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/19 21:32:04 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	open_map_file(const char *filename, int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
	{
		printf("Erro ao abrir o arquivo.\n");
		return (false);
	}
	return (true);
}

bool	read_map_file(int fd, t_cub3d *cub3d)
{
	int		map_lines;
	char	*ret;

	map_lines = 0;
	ret = NULL;
	while (true)
	{
		ret = get_next_line(fd);
		if (ret == NULL)
			break ;
		if (!process_map_line(ret, cub3d, &map_lines))
		{
			free(ret);
			return (false);
		}
	}
	cub3d->map.lines = map_lines;
	cub3d->map_file_content[map_lines] = NULL;
	return (true);
}

bool	process_map_line(char *line, t_cub3d *cub3d, int *map_lines)
{
	if (!remove_newlines(line))
	{
		printf("Erro ao remover quebras de linha.\n");
		free(line);
		return (false);
	}

	printf("%s\n", line);

	if (!update_map_dimensions(line, cub3d))
	{
		printf("Erro ao atualizar as dimensões do mapa.\n");
		free(line);
		return (false);
	}
	cub3d->map_file_content[(*map_lines)++] = line;
	return (true);
}


