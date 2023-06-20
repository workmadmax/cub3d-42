/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:39:16 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/20 10:59:04 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	validate_required_fields(const t_map *map)
{
	if (map->north_texture == NULL
		|| map->south_texture == NULL
		|| map->west_texture == NULL
		|| map->east_texture == NULL
		|| map->floor_color == NULL)
	{
		printf("Algumas informações estão faltando no mapa (texturas).\n");
		return (false);
	}
	return (true);
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
		return (false);
	return (true);
}

t_bool	validate_texture(const t_cub3d *cub3d)
{
	if (!validate_texture_extension(cub3d->map.north_texture)
		|| !validate_texture_extension(cub3d->map.south_texture)
		|| !validate_texture_extension(cub3d->map.west_texture)
		|| !validate_texture_extension(cub3d->map.east_texture))
	{
		printf("As texturas devem ter extensão .xpm.\n");
		return (false);
	}
	return (true);
}


