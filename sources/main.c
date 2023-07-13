/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:45:04 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/13 16:19:35 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	char **tex;

	check_arguments(argc, argv);
	tex = read_file_lines(argv[1]);
	// print tex 
	for (int i = 0; tex[i]; i++)
		printf("%s\n", tex[i]);
	return (0);
}
