/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:20:59 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/19 21:13:09 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	update_map_dimensions(const char *line, t_cub3d *cub3d)
{
	int	line_width;

	line_width = ft_strlen(line);
	if (line_width > cub3d->map.width)
		cub3d->map.width = line_width;
	cub3d->map.height++;
	return (true);
}

bool	remove_newlines(char *str)
{
	char	*nl_position;

	nl_position = ft_strchr(str, '\n');
	if (nl_position != NULL)
	{
		*nl_position = '\0';
		return (true);
	}
	return (false);
}


