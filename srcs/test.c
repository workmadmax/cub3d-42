/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:32:12 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/17 18:18:12 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!process_map_file(argv[1]))
		{
			printf("Erro ao processar o arquivo.\n");
			return (1);
		}
	}
	else
	{
		printf("Erro: argumentos inválidos.\n");
		return (1);
	}
	return (0);
}
