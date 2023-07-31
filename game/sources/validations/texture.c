/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:20:44 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/18 10:21:02 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_texture(char *line)
{
	int		file_check;
	char	*aux_trim;
	char	**aux_split;

	aux_trim = ft_strtrim(line, " ");
	aux_split = ft_split(aux_trim, ' ');
	if (aux_split[1] == NULL || aux_split[2] != NULL)
	{
		free_string(aux_trim);
		free_string_array(aux_split);
		printf("Error\nInvalid texture\n");
		return (FAILURE);
	}
	file_check = check_file_extension(aux_split[1]);
	if (file_check != SUCCESS)
	{
		free_string(aux_trim);
		free_string_array(aux_split);
		printf("Error\nInvalid texture 2\n");
		return (FAILURE);
	}
	free_string(aux_trim);
	free_string_array(aux_split);
	return (SUCCESS);
}
