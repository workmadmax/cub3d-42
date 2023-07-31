/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:45:07 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/30 15:37:15 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_numeric_string(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (FAILURE);
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (FAILURE);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	map_count_line(char **map)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (map[i])
	{
		if (get_line_code(map[i]) == WALL)
			size++;
		i++;
	}
	return (size);
}

int	max_colum(char **map)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (map[i])
	{
		if (get_line_code(map[i]) == WALL)
		{
			if ((int)ft_strlen(map[i]) > size)
				size = ft_strlen(map[i]);
		}
		i++;
	}
	return (size);
}

int	count_file_lines(const char *file)
{
	int		result;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (FAILURE);
	result = -1;
	while (++result > -1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free_string(line);
	}
	free_string(line);
	close (fd);
	return (result);
}

t_bool	remove_newlines(char *str)
{
	char	*nl_position;

	nl_position = ft_strchr(str, '\n');
	if (nl_position != NULL)
	{
		*nl_position = '\0';
		return (TRUE);
	}
	return (FALSE);
}
