/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:32:12 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/15 17:40:29 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <nome_do_arquivo>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    char **map = NULL;
    int num_lines = 0;
    t_map dimensions;

    printf("Contando as linhas do mapa...\n");
    num_lines = count_map_lines(filename);
    printf("Número de linhas do mapa: %d\n", num_lines);

    printf("Lendo as linhas do mapa...\n");
    read_map_lines(&map, filename, num_lines);
    printf("Mapa lido:\n");

    // Imprimir o mapa
    for (int i = 0; map[i] != NULL; i++) {
        printf("%s\n", map[i]);
    }

    // Obter as dimensões do mapa
    get_map_dimensions(map, &dimensions);

	int flag_wall = check_wall(map, &dimensions);
	if (!flag_wall)
		printf("Mapa inválido.\n");
	else
		printf("Mapa válido.\n");

    // Imprimir as dimensões do mapa
    printf("Dimensões do mapa:\n");
    printf("Largura: %d\n", dimensions.width);
    printf("Altura: %d\n", dimensions.height);

    // Validar as paredes do mapa
	/* if (!validate_map_walls(map, dimensions)) {
		printf("Mapa inválido.\n");
		return 1;
	} */
	
    // Liberar a memória alocada para o mapa
    for (int i = 0; map[i] != NULL; i++) {
        free(map[i]);
    }
    free(map);
    return 0;
}