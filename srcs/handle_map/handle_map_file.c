/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:00:23 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/30 14:56:29 by madmax42         ###   ########.fr       */
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
	printf("\n========= conteudo do mapa na variavel line =========\n\n");
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
		printf("%s\n", line);
		cub3d->map_file_content[map_line++] = line;
	}
	if (!copy_map_content(cub3d, map_line))
	{
		free(line);
		return (FALSE);
	}
	return (TRUE);
}





















/* t_bool	read_file(int fd, t_cub3d *cub3d)
{
	int		cnt_lines;
	char	*content;
	t_bool	continue_reading;

	cnt_lines = 0;
	continue_reading = TRUE;
	while (continue_reading)
	{
		content = get_next_line(fd);
		if (content)
		{
			remove_newlines(content);
			printf("%s\n", content);
			cnt_lines++;
			free(content);
		}
		else
			continue_reading = FALSE;
	}
	return (TRUE);
}

t_bool	handle_map_file(char *file_name, t_cub3d *cub3d)
{
	int	fd;

	if (!open_map_file(file_name, &fd))
	{
		printf("Falha ao abrir o arquivo.\n");
		return (FALSE);
	}
	if (!read_file(fd, cub3d))
	{
		printf("Falha ao ler o arquivo.\n");
		close(fd);
		return (FALSE);
	}
	close(fd);
	return (TRUE);
}


t_bool	process_map_line(char *line, t_cub3d *cub3d, int *map_lines)
{
	if (!remove_newlines(line))
	{
		printf("Erro ao remover quebras de linha.\n");
		free(line);
		return (FALSE);
	}
	if (!update_map_dimensions(line, cub3d))
	{
		printf("Erro ao atualizar as dimensões do mapa.\n");
		free(line);
		return (FALSE);
	}
	cub3d->map_file_content[(*map_lines)++] = line;
	if (!ft_array_dup(cub3d->map_file_content, &(cub3d->map_file_copy)))
	{
		printf("Erro ao duplicar o array de conteúdo do arquivo do mapa.\n");
		return (FALSE);
	}
	if (!validate_map(cub3d))
	{
		printf("Erro ao validar o mapa.\n");
		return (FALSE);
	}
	return (TRUE);
}
*/

/* t_bool	process_map_line(char *line, t_cub3d *cub3d, int *map_lines)
{
	if (!remove_newlines(line))
	{
		printf("Erro ao remover quebras de linha.\n");
		free(line);
		return (FALSE);
	}
	printf("%s\n", line);
	if (!update_map_dimensions(line, cub3d))
	{
		printf("Erro ao atualizar as dimensões do mapa.\n");
		free(line);
		return (FALSE);
	}
	cub3d->map_file_content[(*map_lines)++] = line;
	cub3d->map_file_copy = ft_array_dup(cub3d->map_file_content);
	return (TRUE);
}
 */