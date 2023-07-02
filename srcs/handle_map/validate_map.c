/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:39:16 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/30 18:11:02 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	validate_map_characters(t_cub3d *cub3d)
{
	int		i;
	int		j;
	char	*valid_chars;
	char	curr_ch;

	i = 0;
	j = 0;
	valid_chars = "01NSEW";
	while (i < cub3d->map.lines)
	{
		while (j < cub3d->map.width)
		{
			curr_ch = cub3d->map_file_copy[i][j];
			if (curr_ch != ' ' && strchr(valid_chars, curr_ch) == NULL)
			{
				printf("Err: Char invalid  no mapa: %c\n", curr_ch);
				return (FALSE);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (TRUE);
}
