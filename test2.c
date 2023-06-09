/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:59:57 by madmax42          #+#    #+#             */
/*   Updated: 2023/06/09 15:02:02 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx-linux/mlx.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WALL_COLOR  0x808080

void draw_wall(void *mlx_ptr, void *win_ptr, int x, int y)
{
	mlx_pixel_put(mlx_ptr, win_ptr, x, y, WALL_COLOR);
}

int main()
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Maze");

	int maze[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	int x, y;
	for (y = 0; y < 10; y++)
	{
		for (x = 0; x < 10; x++)
		{
			if (maze[y][x] == 1)
				draw_wall(mlx_ptr, win_ptr, x * 50, y * 50);
		}
	}
	mlx_loop(mlx_ptr);
	return 0;
}
