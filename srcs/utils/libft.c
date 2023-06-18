/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:45:22 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/18 15:45:30 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	int	index;

	index = 0;
	while (str1[index] == str2[index] && str1[index] != '\0')
		index++;
	if (str1[index] > str2[index])
		return (str1[index] - str2[index]);
	else if (str1[index] < str2[index])
		return (str1[index] - str2[index]);
	return (0);
}