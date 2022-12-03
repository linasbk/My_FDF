/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:06:34 by lsabik            #+#    #+#             */
/*   Updated: 2022/11/25 15:06:40 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


t_point	*get_points(int x, int y, int x1, int y1)
{
	t_point		*lines;
	lines = malloc(sizeof(t_point));
	if (!lines)
		return (0);
	lines->x0 = x;
	lines->y0 = y;
	lines->x1 = x1;
	lines->y1 = y1;
			printf("\nx:%d,y:%d\n",lines->y0,lines->y1);

	return (lines);
}

int	main(void)
{
	t_map_data	*data;
	t_data	img;
    int	x;
	int	y;

	data = malloc(sizeof(t_map_data));
	if (!data)
		return (0);
	data->zoom = 20;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 800, 800, "Hello lina!");
	img.img = mlx_new_image(data->mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	read_map("42.fdf", data, -1, 0);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while(x < data->width)
		{
			// printf("\nx:%d,y:%d\n",x,y);
			drawline(data, get_points(x, y, x + 1, y), &img);
			drawline(data, get_points(0, 2, 10, 80), &img);
			x++;
		}
		y++;
	}
	mlx_loop(data->mlx);
}