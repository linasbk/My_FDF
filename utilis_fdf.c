#include"fdf.h"

// Xs = (coefficients repeat of X) cos (a) - (coefficients repeat of y) cos a
void	ft_isometric(t_point *point, t_fdf_data *data)
{
	point->x = cos(data->angle) * (point->x - point->y);
	point->y = (point->y + point->x ) * sin(data->angle) - point->z;
}

void	zoom(t_point *a, t_point *b, t_fdf_data *data)
{
	a->x *= data->zoom;
	a->y *= data->zoom;
	b->x *= data->zoom;
	b->y *= data->zoom;
	a->z *= data->scale_z;
	b->z *= data->scale_z;
}


void	zoom_iso(t_point *a, t_point *b, t_fdf_data *data)
{
	zoom(a, b, data);
	if (data->iso)
	{
		ft_isometric(a, data);
		ft_isometric(b, data);
	}
	a->x += data->shift_x;
	a->y += data->shift_y;
	b->x += data->shift_x;
	b->y += data->shift_y;
}
