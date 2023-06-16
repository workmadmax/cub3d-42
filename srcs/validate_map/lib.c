/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:54:26 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/15 17:55:45 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_array_len(char	**array)
{
	int	len;

	len = -1;
	if (array == NULL || *array == NULL)
		return (len);
	while (array[++len])
		;
	return (len);
}

char	**ft_array_dup(char **array)
{
	char	**cpy;
	int		len;

	if (array == NULL || *array == NULL)
		return (NULL);
	len = ft_array_len(array) + 1;
	cpy = (char **)malloc(len * sizeof(char *));
	cpy[--len] = NULL;
	while (len--)
		cpy[len] = ft_strdup(array[len]);
	return (cpy);
}
