/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:38:31 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/08 15:37:19 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	check_file_extension(char *file, char *extension)
{
	if (ft_strlen(file) <= ft_strlen(extension))
		return (FAILURE);
	if (ft_strncmp(extension, file + ft_strlen(file) - ft_strlen(extension),
			ft_strlen(extension)) != 0)
		return (FAILURE);
	return (SUCCESS);
}

int	check_file_path(const char *file)
{
	int		fd;

	fd = open(file, O_RDWR);
	if (fd == -1)
	{
		printf("veio da qui\n");
		return (FAILURE);
	}
	close(fd);
	return (SUCCESS);
}
