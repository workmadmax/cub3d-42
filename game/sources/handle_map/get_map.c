/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:47:17 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/30 15:36:30 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_line_code(char *line)
{
	int		status;
	char	**split;

	split = ft_split(line, ' ');
	status = get_flag_code(split[0]);
	free_string_array(split);
	return (status);
}

int	get_flag_from_string(char *str)
{
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

int	get_flag_code(char *str)
{
	if (str[0] == '\0')
		return (END);
	if (str[0] == '\n')
		return (NEW_LINE);
	if (str[0] == '1')
		return (WALL);
	return (get_flag_from_string(str));
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
		if (get_line_code(map[i]) == WALL)
		{
			content[j] = ft_calloc(max_colum(map) + 1, sizeof(char *));
			ft_strlcpy(content[j], map[i], ft_strlen(map[i]) + 1);
			remove_newlines(content[j]);
			j++;
		}
	}
	return (content);
}
