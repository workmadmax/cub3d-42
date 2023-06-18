/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:00:23 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/18 14:21:04 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	open_file(const char *filename, int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
	{
		printf("Erro ao abrir o arquivo.\n");
		return (false);
	}
	return (true);
}

bool	remove_newlines(char *str)
{
	char	*nl_position;

	nl_position = ft_strchr(str, '\n');
	if (nl_position != NULL)
	{
		*nl_position = '\0';
		return (true);
	}
	return (false);
}

bool	update_map_dimensions(const char *line, t_map *map)
{
	int	line_width;

	line_width = strlen(line);
	if (line_width > map->width)
		map->width = line_width;
	map->height++;
	return (true);
}

bool	read_file(int fd, t_map *map)
{
	char	*ret;

	while (true)
	{
		ret = get_next_line(fd);
		if (ret == NULL)
			break ;
		if (!remove_newlines(ret))
			return (false); // pensei que pode ser um exit_data com uma mensagem de erro
		printf("%s\n", ret);
		if (!update_map_dimensions(ret, map))
			return (false); // pensei que pode ser um exit_data com uma mensagem de erro
		free(ret);
	}
	return (true);
}

bool	process_map_file(const char *filename, t_cub3d *cub3d)
{
	int	fd;

	if (!open_file(filename, &fd))
		return (false);
	// Inicializar as informações do mapa nas structs
	cub3d->dimensions.width = 0;
	cub3d->dimensions.height = 0;
	if (!read_file(fd, &(cub3d->dimensions)))
		return (false);
	if (close(fd) == -1)
	{
		printf("Erro ao fechar o arquivo.\n");
		return (false);
	}
	return (true);
}
