/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:32:12 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/18 15:56:48 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
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

