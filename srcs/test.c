/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:32:12 by madmax42          #+#    #+#             */
/*   Updated: 2023/07/03 15:50:44 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdbool.h>
#include <string.h>

#define MAX_MAP_LINES 10000

void	init_cub3d(t_cub3d *cub3d)
{
	cub3d->mlx = NULL;
	cub3d->mlx_win = NULL;
	cub3d->map_file_content = NULL;
	cub3d->map_file_copy = NULL;
	cub3d->map.width = 0;
	cub3d->map.height = 0;
	cub3d->map.lines = 0;
	cub3d->player = malloc(sizeof(t_player));
	if (cub3d->player == NULL)
	{
		printf("Erro ao alocar memória para o jogador.\n");
		exit(1);
	}
	else
	{
		cub3d->player->x = -1;
		cub3d->player->y = -1;
		cub3d->player->dir_x = 0;
		cub3d->player->dir_y = 0;
	}
}

t_bool	process_map_data(t_cub3d *cub3d, char *line)
{

	if (!update_map_dimensions(line, cub3d))
	{
		printf("Erro ao atualizar as dimensões do mapa.\n");
		free(line);
		return (FALSE);
	}
	return (TRUE);
}


int	main(int arg, char **argv)
{
	int		fd;
	t_cub3d	cub3d;

	init_cub3d(&cub3d);
	cub3d.map_file_content = malloc(MAX_MAP_LINES * sizeof(char *));
	if (cub3d.map_file_content == NULL)
	{
		printf("Falha ao alocar memória para o mapa no começo do main.\n");
		return (1);
	}
	if (arg != 2)
	{
		printf("Uso: ./cub3d <arquivo.cub>\n");
		return (1);
	}
	if (!open_map_file(argv[1], &fd))
	{
		printf("Falha ao abrir o arquivo em open_file.\n");
		return (1);
	}
	if (!read_map_file_data(&cub3d, fd))
	{
		printf("Falha ao ler o arquivo em read_map_file.\n");
		if (cub3d.map_file_content != NULL)
			free(cub3d.map_file_content);
		close(fd);
		return (1);
	}
	if (!validate_map_characters(&cub3d))
	{
		printf("Falha ao validar os caracteres do mapa.\n");
		if (cub3d.map_file_content != NULL)
			free(cub3d.map_file_content);
		close(fd);
		return (1);
	}
	apply_flood_fill(&cub3d);
	find_player_position(&cub3d);
	printf("\n");
	printf("========= map dimensions =========\n\n");
	printf("lines = %d\n", cub3d.map.lines);
	printf("width = %d\n", cub3d.map.width);
	printf("height = %d\n", cub3d.map.height);
	printf("\n");
	printf("========= map_file_content =========\n\n");
	// print content of map_file_content
    for (int i = 0; i < cub3d.map.lines; i++)
    {
 		printf("%s\n", cub3d.map_file_content[i]);
    }
	printf("\n");
	printf("========= map_file_copy =========\n\n");
	for (int i = 0; i < cub3d.map.lines; i++)
		printf("%s\n", cub3d.map_file_copy[i]);
	printf("\n");
	printf("========= player inicializado =========\n\n");
	printf("x = %d\n", cub3d.player->x);
	printf("y = %d\n", cub3d.player->y);
	printf("dir_x = %d\n", cub3d.player->dir_x);
	printf("dir_y = %d\n", cub3d.player->dir_y);
	printf("\n");
	return (0);
}
