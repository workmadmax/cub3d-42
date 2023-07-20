/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:45:07 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/20 11:45:27 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_numeric_string(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (FAILURE);
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (FAILURE);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
