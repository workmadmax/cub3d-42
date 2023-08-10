/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:39:57 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/10 16:49:45 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_char_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("01NSEW\t\n ", map[i][j]) == NULL)
				return (error_msg(map[i], ERROR_LINE));
		}
	}
	return (SUCCESS);
}



t_bool	check_maze_map(char **map)
{
	char		**copy_map;
	t_check_p	check_p;

	ft_memset(&check_p, 0, sizeof(t_check_p));
	copy_map = get_maze_map(map);
	if (check_char_map(copy_map) != SUCCESS)
	{
		free_string_array(copy_map);
		return (FALSE);
	}
	if (set_player_position(copy_map, &check_p) != SUCCESS)
	{
		free_string_array(copy_map);
		return (FALSE);
	}
	//printf("Map before flood fill:\n");
	/* for (int i = 0; copy_map[i]; i++)
    printf("%s\n", copy_map[i]); */
	flood_fill(copy_map, check_p.loc_x, check_p.loc_y);
	// print copy map
	printf("depois do flood fill: \n");
	for (int i = 0; copy_map[i]; i++)
		printf("%s\n", copy_map[i]);
	if (!is_valid_exit(copy_map))
	{
		free_string_array(copy_map);
		return (FALSE);
	}
	free_string_array(copy_map);
	return (TRUE);
}
