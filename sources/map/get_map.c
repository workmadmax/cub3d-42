/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:47:17 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/13 16:03:55 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_line(char *line)
{
	int		status;
	char	**split;

	split = ft_split(line, ' ');
	status = get_flag_code(split[0]);
	free_string_array(split);
	return (status);
}

int	get_flag_code(char *str)
{
	if (str[0] == '1')
		return (WALL);
	if (str[0] == '\0')
		return (END);
	if (str[0] == '\n')
		return (NEW_LINE);
	if (ft_strncmp(str, "C", ft_strlen(str)) == 0)
		return (C);
	if (ft_strncmp(str, "F", ft_strlen(str)) == 0)
		return (F);
	if (ft_strncmp(str, "NO", ft_strlen(str)) == 0)
		return (NO);
	if (ft_strncmp(str, "SO", ft_strlen(str)) == 0)
		return (SO);
	if (ft_strncmp(str, "WE", ft_strlen(str)) == 0)
		return (WE);
	if (ft_strncmp(str, "EA", ft_strlen(str)) == 0)
		return (EA);
	return (FAILURE);
}

static int	map_count_line(char **map)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (map[i])
	{
		if (get_line(map[i]) == WALL)
			size++;
		i++;
	}
	return (size);
}

static int	max_colum(char **map)
{
	int	i;
	int	size;
	int	max;

	i = 0;
	size = 0;
	max = 0;
	while (map[i])
	{
		if (get_line(map[i]) == WALL)
		{
			size = ft_strlen(map[i]);
			if (size > max)
				max = size;
		}
		i++;
	}
	return (max);
}

char	**get_map(char **map)
{
	int		i;
	int		j;
	char	**content;

	content = ft_calloc(map_count_line(map) + 1, sizeof(char *));
	i = -1;
	j = 0;
	while (map[++i])
	{
		if (get_line(map[i]) == WALL)
		{
			content[j] = ft_calloc(max_colum(map) + 1, sizeof(char));
			ft_strlcpy(content[j], map[i], ft_strlen(map[i]) + 1);
			j++;
		}
	}
	return (map);
}
