/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:45:22 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/11 15:32:49 by madmax42         ###   ########.fr       */
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

t_bool	ft_array_dup(char **array, char ***cpy)
{
	int	len;

	if (array == NULL || *array == NULL)
		return (FALSE);
	len = ft_array_len(array) + 1;
	*cpy = (char **)malloc(len * sizeof(char *));
	(*cpy)[--len] = NULL;
	while (len--)
		(*cpy)[len] = ft_strdup(array[len]);
	return (TRUE);
}

void	flood_fill(t_cub3d *cub3d, int x, int y)
{
	char	*p;

	if (x < 0 || x >= cub3d->map.width || y < 0 || y >= cub3d->map.lines)
		return ;
	p = &cub3d->map_file_copy[y][x];
	if (*p != '1' && *p != '.')
	{
		*p = '.';
		if (x + 1 < cub3d->map.width && cub3d->map_file_copy[y][x + 1] != '1'
			&& cub3d->map_file_copy[y][x + 1] != '.')
			flood_fill(cub3d, x + 1, y);
		if (x - 1 >= 0 && cub3d->map_file_copy[y][x - 1] != '1'
			&& cub3d->map_file_copy[y][x - 1] != '.')
			flood_fill(cub3d, x - 1, y);
		if (y + 1 < cub3d->map.lines
			&& x < (int)strlen(cub3d->map_file_copy[y + 1])
			&& cub3d->map_file_copy[y + 1][x] != '1'
			&& cub3d->map_file_copy[y + 1][x] != '.')
			flood_fill(cub3d, x, y + 1);
		if (y - 1 >= 0 && x < (int)strlen(cub3d->map_file_copy[y - 1])
			&& cub3d->map_file_copy[y - 1][x] != '1'
			&& cub3d->map_file_copy[y - 1][x] != '.')
			flood_fill(cub3d, x, y - 1);
	}
}

/* 
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
 */