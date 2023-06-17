/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:00:23 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/17 18:20:12 by madmax42         ###   ########.fr       */
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

bool	read_file(int fd)
{
	char	*ret;

	while (true)
	{
		ret = get_next_line(fd);
		if (ret == NULL)
			break ;
		remove_newlines(ret);
		printf("%s\n", ret);
		free(ret);
	}
	return (true);
}

bool	process_map_file(const char *filename)
{
	int		fd;

	if (!open_file(filename, &fd))
		return (false);
	if (!read_file(fd))
		return (false);
	if (close(fd) == -1)
	{
		printf("Erro ao fechar o arquivo.\n");
		return (false);
	}
	return (true);
}
