/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:25:33 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/08 15:36:41 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_map_vertical(char **map, int i, int j)
{
	int	line;

	line = 0;
	while (map[line])
		line++;
	if (i == 0 || i == line - 1)
		return (FAILURE);
	if (ft_strchr("NSEW10", map[i + 1][j]) == NULL)
		return (FAILURE);
	if (ft_strchr("NSEW10", map[i - 1][j]) == NULL)
		return (FAILURE);
	return (SUCCESS);
}

int	handle_map_horizontal(char **map, int i, int j)
{
	if (j == 0 || j + 1 == (int)ft_strlen(map[i]))
		return (FAILURE);
	if (ft_strchr("NSEW10", map[i][j - 1]) == NULL)
		return (FAILURE);
	if (ft_strchr("NSEW10", map[i][j + 1]) == NULL)
		return (FAILURE);
	return (SUCCESS);
}

int	check_is_closed(char **map)
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
				if (handle_map_horizontal(map, i, j) == FAILURE)
					return (FAILURE);
				if (handle_map_vertical(map, i, j) == FAILURE)
					return (FAILURE);
			}
		}
	}
	return (SUCCESS);
}
