#include"fdf.h"

void	ft_error(void)
{
	ft_putstr("\033[1;31m fdf initialization error!!\n");
	exit(EXIT_FAILURE);
}

void	init_data(t_fdf_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		ft_error();
	data->mlx_win = mlx_new_window(data->mlx, data->win_width,
			data->win_height, "FDF");
	if (data->mlx_win == NULL)
		ft_error();
	data->img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	data->addr = mlx_get_data_addr(data->img, &(data->bpp), &(data->line_len),
			&(data->endian));
}

void	init_param(t_fdf_data *data)
{
	data->iso = 1;
	data->scale_z = 1;
	data->angle = 0.523599;
	data->win_width = 2500;
	data->win_height = 1500;
	data->color = 0;
	data->shift_x = (data->win_width - 50) / 2 ;
	data->shift_y = (data->win_height - 50) / 3;
	init_data(data);
	if (data->width < 29 || data->height < 29)
		data->zoom = 40;
	else if (data->width <= 50 || data->height <= 50)
		data->zoom = 20;
	else if (data->width <= 250 || data->height <= 250)
		data->zoom = 5;
	else
		data->zoom = 2;
}

/*
key 2 : 84
key 8 : 91
key 6 : 88
key 4 : 86
key 7 : 89
key 7 : 85
*/