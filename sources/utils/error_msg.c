/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:55:08 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/14 14:10:12 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_msg(const char *str, int code)
{
	printf("Error\n");
	if (code == ERROR_MSG)
		printf("\t%d: %s\n", code, str);
	if (code == ERROR_EXTENSION)
		printf("\t%d: error de extensão %s\n", code, str);
	if (code == ERROR_FOUND)
		printf("\t%d: error de arquivo not found %s\n", code, str);
	if (code == ERROR_LINE)
		printf("\t%d: error linha invalda  %s\n", code, str);
	if (code == ERROR_READ)
		printf("\t%d: error de leitura do mapa %s\n", code, str);
	if (code == ERROR_COUNT_FLAG)
		printf("\t%d: error de flags de textura %s\n", code, str);
	if (code == ERROR_LINE_WRONG_POSITION)
		printf("\t%d: error linha longa %s\n", code, str);
	if (code == ERROR_RGB)
		printf("\t%d: error de rgb %s\n", code, str);
	if (code == ERROR_RGB_2)
		printf("\t%d: error de rgb2 %s\n", code, str);
	if (code == ERROR_MALLOC)
		printf("\t%d: error ao mallocar %s\n", code, str);
	if (code == ERROR_WIN)
		printf("\t%d: error na janela %s\n", code, str);
	return (FAILURE);
}
