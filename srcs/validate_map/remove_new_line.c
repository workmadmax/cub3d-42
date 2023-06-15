/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_new_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:59:35 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/14 19:00:04 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*copy_without_newlines(const char *string, size_t length)
{
	size_t	i;
	size_t	j;
	char	*result;

	result = (char *)malloc((length + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < length)
	{
		if (string[i] != '\n')
		{
			result[j] = string[i];
			j++;
		}
		i++;
	}
	result[j] = '\0';
	return (result);
}

char	*remove_newlines(const char *string)
{
	size_t	length;

	if (string == NULL)
		return (NULL);
	length = ft_strlen(string);
	return (copy_without_newlines(string, length));
}
