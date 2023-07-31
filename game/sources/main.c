/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:45:04 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/31 10:40:51 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int	main(int argc, char **argv)
{
	char	**file;
	t_cub	game;

	ft_memset(&game, 0, sizeof(t_cub));
	check_arguments(argc, argv);
	file = read_file_lines(argv[1]);
	check_cub_map_file(file);
	set_value(&game, file);
	printf("\n======mapa setado do arquivo ======: \n");
	// Impressão das linhas depois do valor setado em set_value
	for (int i = 0; game.data.map[i]; i++)
		printf("%s\n", game.data.map[i]);
	free_string_array(file);
	return (0);
}
