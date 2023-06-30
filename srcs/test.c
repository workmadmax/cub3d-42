/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:32:12 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/30 14:53:45 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdbool.h>
#include <string.h>

void	init_cub3d(t_cub3d *cub3d)
{
	cub3d->mlx = NULL;
	cub3d->mlx_win = NULL;
	cub3d->map_file_content = NULL;
	cub3d->map_file_copy = NULL;
	cub3d->map.width = 0;
	cub3d->map.height = 0;
	cub3d->map.lines = 0;
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

#define MAX_MAP_LINES 10000

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
	return (0);
}










/* #define MAX_MAP_LINES 10000

void	init_cub3d(t_cub3d *cub3d)
{
	cub3d->map.width = 0;
	cub3d->map.height = 0;
	cub3d->map.ea_texture = "../textures/colorstone.xpm";
	cub3d->map.we_texture = "../textures/greystone.xpm";
	cub3d->map.no_texture = "../textures/redbrick.xpm";
	cub3d->map.so_texture = "../textures/wood.xpm";
	cub3d->map.floor_color = "0,0,0";
	cub3d->map_file_content = NULL;
	cub3d->map_file_copy = NULL;
}

void	init_player(t_player *player)
{
		player->x = 0;
		player->y = 0;
		player->dir_x = -1;
		player->dir_y = 0;
}
 */



/*
int main(int argc, char **argv)
{
	int fd;
	t_cub3d cub3d;

	init_cub3d(&cub3d);

	cub3d.map_file_content = malloc(MAX_MAP_LINES * sizeof(char *));
	cub3d.map_file_copy = NULL;  // Inicializa map_file_copy como NULL

	if (argc != 2)
	{
		printf("Uso: ./cub3d <arquivo.cub>\n");
		return 1;
	}

	if (!open_map_file(argv[1], &fd))
	{
		printf("Falha ao abrir o arquivo.\n");
		return 1;
	}

	if (!read_map_file(fd, &cub3d))
	{
		printf("Falha ao ler o arquivo.\n");
		close(fd);
		return 1;
	}

	printf("---------------- conteudo do mapa cub3d map_file_content -----------------\n");
	for (int i = 0; i < cub3d.map.height; i++)
	{
		printf("%s\n", cub3d.map_file_content[i]);
	}
	printf("\n");
	printf("---------------- conteudo do mapa cub3d map_file_copy -----------------\n");
	if (!ft_array_dup(cub3d.map_file_content, &(cub3d.map_file_copy)))
	{
		printf("Erro ao duplicar o array de conteúdo do arquivo do mapa.\n");
		// Lidar com o erro de acordo com a necessidade
	}
	else
	{
		for (int i = 0; i < cub3d.map.height; i++)
		{
			printf("%s\n", cub3d.map_file_copy[i]);
		}
	}
	printf("\n");
	
	// Executa o flood fill (preenchimento de área) no mapa
	t_player player;
	init_player(&player);
	if (get_player_position(&cub3d))
	{
		printf("Posição do jogador: x = %d, y = %d\n", cub3d.map.player.x, cub3d.map.player.y);
	}
	else
	{
		printf("Jogador não encontrado.\n");
	}
	printf("\n");
	flood_fill(&cub3d, cub3d.map.player.x, cub3d.map.player.y);
	printf("Mapa após flood fill:\n");
	for (int i = 0; i < cub3d.map.height; i++)
	{
		printf("%s\n", cub3d.map_file_copy[i]);
	}
	// Libera as strings alocadas
	close(fd);
	// Chamando as funções de liberação de memória
	ft_free_array(&cub3d);
	return 0;
}

 */
/* int main(int argc, char **argv)
{
	t_cub3d cub3d;

	initialize_cub3d(&cub3d);
	printf("Largura: %d\n", cub3d.map.width);
	printf("Altura: %d\n", cub3d.map.height);
	printf("Textura norte: %s\n", cub3d.map.north_texture);
	printf("Textura sul: %s\n", cub3d.map.south_texture);
	printf("Textura oeste: %s\n", cub3d.map.west_texture);
	printf("Textura leste: %s\n", cub3d.map.east_texture);
	printf("Cor do chão: %s\n", cub3d.map.floor_color);
	printf("======== line separator ========\n");

	if (argc == 2)
	{
		if (!process_map_file(argv[1], &cub3d))
		{
			printf("Erro ao processar o arquivo.\n");
			return (1);
		}
		
		if (!validate_map(&cub3d))
		{
			printf("Erro: o mapa é inválido.\n");
			return (1);
		}
	}
	else
	{
		printf("Erro: argumentos inválidos.\n");
		return (1);
	}
	
	printf("Largura: %d\n", cub3d.map.width);
	printf("Altura: %d\n", cub3d.map.height);

	return (0);
}

 */


/* 
int main(int argc, char **argv)
{
	int fd;
	t_cub3d cub3d;

	init_cub3d(&cub3d);
	cub3d.map_file_content = malloc(MAX_MAP_LINES * sizeof(char *));
	cub3d.map_file_copy = NULL;  // Inicializa map_file_copy como NULL

	if (argc != 2)
	{
		printf("Uso: ./cub3d <arquivo.cub>\n");
		return 1;
	}

	if (!open_map_file(argv[1], &fd))
	{
		printf("Falha ao abrir o arquivo.\n");
		return 1;
	}

	if (!read_map_file(fd, &cub3d))
	{
		printf("Falha ao ler o arquivo.\n");
		close(fd);
		return 1;
	}

	printf("---------------- conteudo do mapa cub3d map_file_content -----------------\n");
	for (int i = 0; i < cub3d.map.height; i++)
	{
		printf("%s\n", cub3d.map_file_content[i]);
	}
	printf("\n");
	printf("---------------- conteudo do mapa cub3d map_file_copy -----------------\n");
	if (!ft_array_dup(cub3d.map_file_content, &(cub3d.map_file_copy)))
	{
		printf("Erro ao duplicar o array de conteúdo do arquivo do mapa.\n");
		// Lidar com o erro de acordo com a necessidade
	}
	else
	{
		for (int i = 0; i < cub3d.map.height; i++)
		{
			printf("%s\n", cub3d.map_file_copy[i]);
		}
	}
	printf("\n");
	t_player player;
	init_player(&player);
	if (get_player_position(&cub3d))
	{
		printf("Posição do jogador: x = %d, y = %d\n", cub3d.map.player.x, cub3d.map.player.y);
	}
	else
	{
		printf("Jogador não encontrado.\n");
	}
	printf("\n");

	// Executa o flood fill (preenchimento de área) no mapa
	if (get_player_position(&cub3d))
	{
		perform_flood_fill(cub3d.map_file_copy, cub3d.map.height, \
				cub3d.map.width. cub3d.map.player.y, cub3d.map.player.x);

	// Exibe o mapa após o preenchimento do flood fill
		printf("mapa copiado depois do flood fill \n");
		for (int i = 0; i < cub3d.map.height; i++)
		{
			printf("%s\n", cub3d.map_file_copy[i]);
		}
	}
	else
	{
		printf("Jogador não encontrado.\n");
	}
	printf("\n");
	// Libera as strings alocadas
	close(fd);
	// Chamando as funções de liberação de memória
	ft_free_array(&cub3d);
	return 0;
} */
