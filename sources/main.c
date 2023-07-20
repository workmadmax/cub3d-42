/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:45:04 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/20 11:46:15 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	char	**text;

	check_arguments(argc, argv);
	text = read_file_lines(argv[1]);
	check_cub_map_file(text);
    // Impressão das linhas do arquivo
	for (int i = 0; text[i]; i++)
		printf("%s\n", text[i]);
	free_string_array(text);
	return (0);
}
