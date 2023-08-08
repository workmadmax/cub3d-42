/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:26:46 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/08 14:52:02 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* static int	check_space(char c)
{
	if (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}
 */
int	get_flag_code(char *str)
{
	if (str[0] == '1')
		return (WALL);
	if (str[0] == '\0')
		return (END);
	if (str[0] == '\n')
		return (NEW_LINE);
	if (ft_strncmp(str, "C", ft_strlen(str)) == 0)
		return (C);
	if (ft_strncmp(str, "F", ft_strlen(str)) == 0)
		return (F);
	if (ft_strncmp(str, "NO", ft_strlen(str)) == 0)
		return (NO);
	if (ft_strncmp(str, "SO", ft_strlen(str)) == 0)
		return (SO);
	if (ft_strncmp(str, "WE", ft_strlen(str)) == 0)
		return (WE);
	if (ft_strncmp(str, "EA", ft_strlen(str)) == 0)
		return (EA);
	return (FAILURE);
}


int	get_line_code(char *line)
{
	int		status;
	char	**split;

	split = ft_split(line, ' ');
	status = get_flag_code(split[0]);
	free_string_array(split);
	return (status);
}
