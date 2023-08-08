/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:15:20 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/08 15:39:32 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_player(char **map)
{
	int	i;
	int	j;
	int	value;

	i = -1;
	value = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSEW", map[i][j]))
				value++;
		}
	}
	if (value == 1)
		return (SUCCESS);
	return (error_msg("number player wrong!!!", ERROR_MSG));
}
