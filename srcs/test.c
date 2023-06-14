/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:32:12 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/14 17:40:23 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


// read and validate map.cub

/*
	function that will receive a map as an argument, 
	I will use open() to open the map and the function get_next_line to read the map
*/


#define MAX_LINES 100

void	read_map(char **map, const char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map[i] = strdup(line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
}

int	main(int argc, char *argv[])
{
	char	*filename;
	char	*map[MAX_LINES];
	int		i;

	i = 0;
	if (argc != 2)
	{
		printf("Uso: %s <nome_do_arquivo>\n", argv[0]);
		return (1);
	}
	filename = argv[1];
	while (i < MAX_LINES)
	{
		map[i] = NULL;
		i++;
	}
	read_map(map, filename);
	i = 0;
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	return (0);
}

