/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:06:52 by lsabik            #+#    #+#             */
/*   Updated: 2022/11/25 15:06:55 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	my_mlx_pixel_put(t_fdf_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_convert(t_point *a, t_point *b)
{
	int	swap;

	if (a->x > b->x)
	{
			swap = a->x;
			a->x = b->x;
			b->x = swap;
	}
	if (a->y > b->y)
	{
			swap = a->y;
			a->y = b->y;
			b->y = swap;
	}
}

void	drawline(t_fdf_data *data, t_point *a, t_point *b)
{
	int	p;
	int	color;

	ft_convert(a, b);
	color = 0;
	a->z = data->map[(int)a->y][(int)a->x];
	b->z = data->map[(int)b->y][(int)b->x];
	color += get_color(a->z) + (data->color * 10);
	zoom_iso(a, b, data);
	a->delta_x = b->x - a->x;
	a->delta_y = b->y - a->y;
	p = sqrt((a->delta_x * a->delta_x) + (a->delta_y * a->delta_y));
	a->delta_x /= p;
	a->delta_y /= p;
	while (p)
	{
		if ((a->x > 0 && a->x < data->win_width) && (a->y > 0
				&& a->y < data->win_height))
			my_mlx_pixel_put(data, a->x, a->y, color);
			a->x += a->delta_x;
			a->y += a->delta_y;
			--p;
	}
	free(a);
	free(b);
}
