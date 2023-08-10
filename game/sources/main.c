/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:45:04 by madmax42          #+#    #+#             */
/*   Updated: 2023/08/10 15:31:32 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_file_game(char **file)
{
	if (!check_first_word(file))
		free_and_close(file);
	if (!check_amount_flag(file))
		free_and_close(file);
	if (!check_value_flag(file))
		free_and_close(file);
	if (!check_maze_map(file))
		free_and_close(file);
}

int	main(int argc, char **argv)
{
	char		**file;
	t_check_p	check_p;
	t_cub		game;

	ft_memset(&game, 0, sizeof(t_cub));
	ft_memset(&check_p, 0, sizeof(t_check_p));
	check_arguments(argc, argv);
	file = read_file_lines(argv[1]);
	check_file_game(file);
	set_value(&game, file);
	free_string_array(game.data.map);
	free_string_array(file);
	return (0);
}
