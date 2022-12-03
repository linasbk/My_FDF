/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bresenhams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:06:52 by lsabik            #+#    #+#             */
/*   Updated: 2022/11/25 15:06:55 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


t_point	*ft_convert(t_point *lines)
{
	int	swap;

	if (lines->x0 > lines->x1)
	{
			swap = lines->x0;
			lines->x0 = lines->x1;
			lines->x1 = swap;
	}
	if (lines->y0 > lines->y1)
	{
			swap = lines->y0;
			lines->y0 = lines->y1;
			lines->y1 = swap;
	}
	return (lines);
}

void	drawline(t_map_data *data, t_point *lines, t_data *img)
{
	double	pixelX;
	double	pixelY;
	int	    p;
	// int		alt;

	lines = ft_convert(lines);

	lines->x1 *= data->zoom;
	lines->x0 *= data->zoom;
	lines->y1 *= data->zoom; 
	lines->y0 *= data->zoom;


	data->color = 0x00FF9005;
	lines->delta_x = lines->x1 - lines->x0;
	lines->delta_y = lines->y1 - lines->y0;
	p = sqrt((lines->delta_x * lines->delta_x) + (lines->delta_y * lines->delta_y));
	lines->delta_x /= p;
	lines->delta_y /= p;
	pixelX = lines->x0;
	pixelY = lines->y0;
	while (p)
	{
		my_mlx_pixel_put(img, pixelX, pixelY, data->color);
		pixelX += lines->delta_x;
		pixelY += lines->delta_y;
		--p;
	}
            mlx_put_image_to_window(data->mlx, data->mlx_win, img->img, 0, 0);
}
