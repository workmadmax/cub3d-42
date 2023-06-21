/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:39:16 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/21 11:16:30 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	validate_required_fields(const t_map *map)
{
	if (map->no_texture == NULL
		|| map->so_texture == NULL
		|| map->we_texture == NULL
		|| map->ea_texture == NULL
		|| map->floor_color == NULL)
	{
		printf("Algumas informações estão faltando no mapa (texturas).\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool	validate_texture_extension(const char *texture)
{
	size_t		length;
	size_t		extension_length;
	const char	*extension;

	length = ft_strlen(texture);
	extension = ".xpm";
	extension_length = ft_strlen(extension);
	if (length < extension_length
		|| ft_strcmp(texture + length - extension_length, extension) != 0)
		return (FALSE);
	return (TRUE);
}

t_bool	validate_texture(const t_cub3d *cub3d)
{
	if (!validate_texture_extension(cub3d->map.no_texture)
		|| !validate_texture_extension(cub3d->map.so_texture)
		|| !validate_texture_extension(cub3d->map.we_texture)
		|| !validate_texture_extension(cub3d->map.ea_texture))
	{
		printf("As texturas devem ter extensão .xpm.\n");
		return (FALSE);
	}
	return (TRUE);
}
