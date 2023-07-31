/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:29:32 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/19 11:33:21 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_rgb_range(const char *str)
{
	int	nb;

	nb = ft_atoi(str);
	if (nb < -1 || nb > 255)
		return (FAILURE);
	return (SUCCESS);
}

int	check_rgb(char *line)
{
	int		status;
	char	*aux_trim;

	status = FAILURE;
	aux_trim = ft_strtrim(line, "\n ");
	status = check_rgb_value(aux_trim + 1);
	free_string(aux_trim);
	return (status);
}

int	check_rgb_cf(char *ceiling, char *floor)
{
	int		res;
	char	**temp_c;
	char	**temp_f;

	temp_c = ft_split(ceiling, ' ');
	temp_f = ft_split(floor, ' ');
	res = ft_strncmp(temp_c[1], temp_f[1], ft_strlen(temp_c[1]));
	free_string_array(temp_c);
	free_string_array(temp_f);
	return (res);
}

int	check_rgb_aux(char **line)
{
	int		i;
	char	*ceiling;
	char	*floor;

	i = 0;
	while (line[i])
	{
		if (line[i][0] == 'C')
			ceiling = ft_strdup(line[i]);
		else if (line[i][0] == 'F')
			floor = ft_strdup(line[i]);
		i++;
	}
	i = check_rgb_cf(ceiling, floor);
	free_string(ceiling);
	free_string(floor);
	return (i);
}

int	check_rgb_value(const char *line)
{
	int		i;
	int		status;
	char	**aux_split;

	i = 0;
	status = SUCCESS;
	aux_split = ft_split(line, ',');
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
		status = FAILURE;
	return (status);
}
