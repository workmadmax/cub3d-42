/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:46:34 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/12 14:56:51 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_string(char *string)
{
	free(string);
	string = NULL;
}

void	free_string_array(char **string)
{
	int	i;

	i = 0;
	while (string[i])
		free(string[i++]);
	free(string);
	string = NULL;
}
