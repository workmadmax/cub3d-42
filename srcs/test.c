/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:32:12 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/15 11:17:47 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Uso: %s <nome_do_arquivo>\n", argv[0]);
        return (1);
    }

    const char *filename = argv[1];
    char **map = NULL;

    printf("Contando as linhas do mapa...\n");
    int num_lines = count_map_lines(filename);
    printf("Número de linhas do mapa: %d\n", num_lines);

    printf("Lendo as linhas do mapa...\n");
    read_map_lines(&map, filename, num_lines);
    printf("Mapa lido:\n");
	
	// Imprimir o mapa
    for (int i = 0; map[i] != NULL; i++)
        printf("%s\n", map[i]);

    // Liberar a memória alocada para o mapa
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    return (0);
}