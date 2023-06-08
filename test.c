/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:46:10 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/08 11:41:48 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx-linux/mlx.h"
#include "./libft/include/libft.h"


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct s_data
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_data;

// open window
/* int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	mlx_loop(mlx);
} */

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	int		i;
	int		j;
	void	*mlx;
	void	*win;
	t_data	img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);

	for (i = 100; i < 110; i++) {
		for (j = 100; j < 110; j++) {
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		}
	}

	mlx_put_image_to_window(mlx, win, img.img, 0, 0);

	int text_width = 120; // Largura estimada do texto
	int text_height = 200; // Altura estimada do texto
	int screen_width = WIDTH; // Largura da tela
	int screen_height = HEIGHT; // Altura da tela

	int text_x = (screen_width - text_width) / 2; // Posição x centralizada
	int text_y = (screen_height - text_height) / 2; // Posição y centralizada

	mlx_string_put(mlx, win, text_x, text_y, 0x00FFFFFF, "42");
	mlx_loop(mlx);
}

/* int	main(void)
{
	void	*mlx;
	void	*win;
	int		i;
	int		j;
	t_data	img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);

	for (i = 100; i < 110; i++) {
		for (j = 100; j < 110; j++) {
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		}
	}

	my_mlx_pixel_put(&img, 100, 100, 0x00FF0000);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
}
 */