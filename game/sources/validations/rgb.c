/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:29:32 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/07 18:07:55 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_rgb_range(const char *line)
{
	int	value;

	value = ft_atoi(line);
	if (value > -1 && value < 256)
		return (SUCCESS);
	return (FAILURE);
}

int	is_numeric_string(const char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (FAILURE);
	while (line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (FAILURE);
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}


int	check_rgb_value(const char *line)
{
	char	**aux_split;
	int		i;
	int		status;

	aux_split = ft_split(line, ',');
	i = 0;
	status = SUCCESS;
	while (aux_split[i])
	{
		if (is_numeric_string(aux_split[i]) == FAILURE)
			status = FAILURE;
		if (validate_rgb_range(aux_split[i]) == FAILURE)
			status = FAILURE;
		i++;
	}
	free_string_array(aux_split);
	if (i != 3 || line[ft_strlen(line) - 1] == ',')
		return (FAILURE);
	return (status);
}

int	check_rgb(char *line)
{
	char	*aux_trim;
	int		status;

	status = FAILURE;
	aux_trim = ft_strtrim(line, "\n ");
	status = check_rgb_value(aux_trim + 1);
	free_string(aux_trim);
	return (status);
}
