/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:38:31 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/14 17:38:38 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file_extension(char *file)
{
	int		len;

	len = ft_strlen(file);
	if (len < 5 || ft_strncmp(file + len - 4, ".cub", 4))
	{
		printf("Error na extensão do arquivo...\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

int	check_file_exists(const char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error ao abrir o arquivo...\n");
		return (FAILURE);
	}
	close(fd);
	return (SUCCESS);
}
