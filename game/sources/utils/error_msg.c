/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:55:08 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/07 16:23:08 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_msg(const char *str, int code)
{
	printf("Error: \n");
	if (code == WALL_ERROR)
		printf("\t%d: map is not close %s\n", code, str);
	if (code == ERROR_MSG)
		printf("\t%d: %s\n", code, str);
	if (code == ERROR_EXTENSION)
		printf("\t%d: error in extension file %s\n", code, str);
	if (code == ERROR_FILE)
		printf("\t%d: error archive not found %s\n", code, str);
	if (code == ERROR_LINE)
		printf("\t%d: error invalid line  %s\n", code, str);
	if (code == ERROR_READ)
		printf("\t%d: error in reading the map %s\n", code, str);
	if (code == ERROR_COUNT_FLAG)
		printf("\t%d: error de flags de textura %s\n", code, str);
	if (code == ERROR_LINE_WRONG_POSITION)
		printf("\t%d: error wrong line %s\n", code, str);
	if (code == ERROR_RGB)
		printf("\t%d: error rgb %s\n", code, str);
	if (code == ERROR_MALLOC)
		printf("\t%d: error in malloc memory %s\n", code, str);
	if (code == ERROR_TEXTURE)
		printf("\t%d: error in texture %s\n", code, str);
	return (FAILURE);
}
