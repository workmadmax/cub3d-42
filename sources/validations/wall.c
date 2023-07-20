/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:25:33 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/19 18:56:44 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_map_vertical(char **map, int i, int j)
{
	int	line;

	line = 0;
	while (map[line])
		line++;
	if (i == 0 || i == (line - 1))
		return (FAILURE);
	if (ft_strchr("NSEW10", map[i + 1][j]) == NULL)
		return (FAILURE);
	if (ft_strchr("NSEW10", map[i - 1][j]) == NULL)
		return (FAILURE);
	return (SUCCESS);
}

static int	check_map_horizontal(char **map, int i, int j)
{
	if (j == 0 || (j + 1) == (int)ft_strlen(map[i]))
		return (FAILURE);
	if (ft_strchr("NSEW10", map[i][j + 1]) == NULL)
		return (FAILURE);
	if (ft_strchr("NSEW10", map[i][j - 1]) == NULL)
		return (FAILURE);
	return (SUCCESS);
}

int	check_wall_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSEW0", map[i][j]) != NULL)
			{
				if (check_map_vertical(map, i, j) == FAILURE)
				{
					printf("foi aqui 1");
					return (FAILURE);
				}
				if (check_map_horizontal(map, i, j) == FAILURE)
				{
					printf("foi aqui 2\n");
					return (FAILURE);
				}
			}
		}
	}
	return (SUCCESS);
}
