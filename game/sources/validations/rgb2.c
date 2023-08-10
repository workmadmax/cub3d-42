/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:56:18 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/10 17:00:06 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	compare_rgb(const char *color1, const char *color2)
{
	return (ft_strncmp(color1 + 2, color2 + 2, ft_strlen(color1 + 2)));
}

int	check_rgb_aux(char **line)
{
	int		i;
	int		res;
	char	*ceiling;
	char	*floor;

	ceiling = NULL;
	floor = NULL;
	i = 0;
	while (line[i])
	{
		if (line[i][0] == 'C')
			ceiling = ft_strdup(line[i]);
		else if (line[i][0] == 'F')
			floor = ft_strdup(line[i]);
		i++;
	}
	res = compare_rgb(ceiling, floor);
	free_string(ceiling);
	free_string(floor);
	return (res);
}

int	check_rgb_cf(char *ceiling, char *floor)
{
	char	**aux_ceiling;
	char	**aux_floor;
	int		res;

	aux_ceiling = ft_split(ceiling, ' ');
	aux_floor = ft_split(floor, ' ');
	res = ft_strncmp(aux_ceiling[1], aux_floor[1], ft_strlen(aux_ceiling[1]));
	free_string_array(aux_ceiling);
	free_string_array(aux_floor);
	return (res);
}

int	check_value_flag(char **line)
{
	int	i;
	int	res;

	i = -1;
	while (line[++i])
	{
		res = get_line_code(line[i]);
		if (res == F || res == C)
		{
			if (check_rgb(line[i]) != SUCCESS)
				return (error_msg(line[i], ERROR_RGB));
		}
		if (res == NO || res == SO || res == WE || res == EA)
		{
			if (check_texture(line[i]) != SUCCESS)
				return (FAILURE);
		}
		if (res == WALL)
			break ;
	}
	if (check_rgb_aux(line) == 0)
		return (error_msg("rgb ceiling and floor are equal!", ERROR_MSG));
	return (SUCCESS);
}
