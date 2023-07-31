/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:17:53 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/31 15:41:18 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	extract_path(char *line, char **path)
{
	char	*aux_path;
	char	**aux_split;

	aux_split = ft_split(line, ' ');
	if (!aux_split)
		return (FAILURE);
	aux_path = ft_strtrim(aux_split[1], " \n");
	if (!aux_path)
	{
		free_string_array(aux_split);
		return (FAILURE);
	}
	*path = ft_strdup(aux_path);
	if (!(*path))
	{
		free_string(aux_path);
		free_string_array(aux_split);
		return (FAILURE);
	}
	free_string(aux_path);
	free_string_array(aux_split);
	printf("Extracted Path: %s\n", *path);
	return (TRUE);
}

void	extract_rgb(char *line, int *r, int *g, int *b)
{
	char	*temp;
	char	*aux_rgb;
	char	**aux_split;

	aux_rgb = ft_strtrim(line, " \n");
	temp = ft_strchr(aux_rgb, ' ');
	aux_split = ft_split(temp, ',');
	*r = ft_atoi(aux_split[0]);
	*g = ft_atoi(aux_split[1]);
	*b = ft_atoi(aux_split[2]);
	free_string(aux_rgb);
	free_string_array(aux_split);
	printf("Extracted RGB: R=%d, G=%d, B=%d\n", *r, *g, *b);
}

void	set_value(t_cub *game, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (get_line_code(map[i]) == NO)
			extract_path(map[i], &(game->data.no_path));
		if (get_line_code(map[i]) == SO)
			extract_path(map[i], &(game->data.so_path));
		if (get_line_code(map[i]) == WE)
			extract_path(map[i], &(game->data.we_path));
		if (get_line_code(map[i]) == EA)
			extract_path(map[i], &(game->data.ea_path));
		if (get_line_code(map[i]) == F)
			extract_rgb(map[i], &game->data.color.floor_r,
				&game->data.color.floor_g, &game->data.color.floor_b);
		if (get_line_code(map[i]) == C)
			extract_rgb(map[i], &game->data.color.ceil_r,
				&game->data.color.ceil_g, &game->data.color.ceil_b);
		i++;
	}
	game->data.map = get_map(map);
}
