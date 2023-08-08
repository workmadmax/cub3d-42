/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:47:17 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/08 15:30:38 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**get_maze_map(char **file)
{
	char	**map;
	int		i;
	int		j;

	map = ft_calloc(map_count_line(file) + 1, sizeof(char *));
	i = -1;
	j = 0;
	while (file[++i])
	{
		if (get_line_code(file[i]) == WALL)
		{
			map[j] = ft_calloc(max_colum(file) + 1, sizeof(char));
			ft_strlcpy(map[j], file[i], ft_strlen(file[i]) + 1);
			j++;
		}
	}
	return (map);
}
