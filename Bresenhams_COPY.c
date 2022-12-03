
#include"fdf.h"
# include<math.h>

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

void	ft_isometric(float *x0, float *y0, int altt)
{
// Xs = (coefficients repeat of X) cos (a) - (coefficients repeat of y) cos a
	*x0 = cos(0.523599) * (*x0 - *y0);
	*y0 = (*y0 + *x0 ) * sin(0.523599) - altt;
}

void	drawline(t_map_data *data, t_point *lines, t_data *img)
{
	double	pixelX;
	double	pixelY;
	int	    p;
	int		altt;
	int		altt1;
	int		color;

	lines = ft_convert(lines);
	altt = data->map[(int)lines->y0][(int)lines->x0];
	altt1 = data->map[(int)lines->y1][(int)lines->x1];
	color = get_color(altt, data);
//----------- zoom --------------
	lines->x1 *= data->zoom;
	lines->x0 *= data->zoom;
	lines->y1 *= data->zoom; 
	lines->y0 *= data->zoom;

	ft_isometric(&lines->x0, &lines->y0, altt);
	ft_isometric(&lines->x1, &lines->y1, altt1);

//---------- moove ---------------
	lines->x1 += 250;
	lines->x0 += 250;
	lines->y1 += 250; 
	lines->y0 += 250;

	lines->delta_x = lines->x1 - lines->x0;
	lines->delta_y = lines->y1 - lines->y0;
	p = sqrt((lines->delta_x * lines->delta_x) + (lines->delta_y * lines->delta_y));
	lines->delta_x /= p;
	lines->delta_y /= p;
	pixelX = lines->x0;
	pixelY = lines->y0;
	while (p)
	{
		my_mlx_pixel_put(img, pixelX, pixelY, color);
		pixelX += lines->delta_x;
		pixelY += lines->delta_y;
		--p;
	}
            mlx_put_image_to_window(data->mlx, data->mlx_win, img->img, 0, 0);
}
