/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:16:28 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/13 16:17:04 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_amount_arguments(int argc)
{
	if (argc != 2)
	{
		printf("Error no número de argumentos...\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

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

int	check_arguments(int argc, char **argv)
{
	if (check_amount_arguments(argc) == FAILURE)
	{
		exit(0);
		return (FAILURE);
	}
	if (check_file_extension(argv[1]) == FAILURE)
	{
		exit(0);
		return (FAILURE);
	}
	if (check_file_exists(argv[1]) == FAILURE)
	{
		exit(0);
		return (FAILURE);
	}
	return (SUCCESS);
}
