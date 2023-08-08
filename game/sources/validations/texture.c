/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:20:44 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/08 15:37:54 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_texture(char *line)
{
	char	*ax_trim;
	char	**ax_split;

	ax_trim = ft_strtrim(line, " \n");
	ax_split = ft_split(ax_trim, ' ');
	if (ax_split[1] == NULL || ax_split[2] != NULL)
	{
		free_string(ax_trim);
		free_string_array(ax_split);
		return (error_msg(line, ERROR_TEXTURE));
	}
	if (check_file_path(ax_split[1]) != SUCCESS)
	{
		error_msg(ax_split[1], ERROR_LINE);
		free_string(ax_trim);
		free_string_array(ax_split);
		return (FAILURE);
	}
	free_string(ax_trim);
	free_string_array(ax_split);
	return (SUCCESS);
}

