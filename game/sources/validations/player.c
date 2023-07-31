/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:15:20 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/30 15:39:52 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_check_player(t_cp *data)
{
	data->loc_x = 0;
	data->loc_y = 0;
	data->count = 0;
}

t_bool	set_check_player(char **map)
{
	int		i;
	int		j;
	t_cp	data;

	init_check_player(&data);
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_strchr("NSEW", map[i][j]) != NULL)
			{
				data.loc_x = i;
				data.loc_y = j;
				data.count++;
			}
			j++;
		}
		i++;
	}
	printf("data.loc_x: %d\n", data.loc_x);
	printf("data.loc_y: %d\n", data.loc_y);
	if (data.count != 1)
		return (FALSE);
	return (TRUE);
}
