/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:39:16 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/21 10:06:44 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


t_bool	validate_map(const t_cub3d *cub3d)
{
	if (!validate_required_fields(&(cub3d->map))
		|| !validate_texture(cub3d))
	{
		return (FALSE);
	}
	// Adicione outras validações necessárias aqui 
	return (TRUE);
}
