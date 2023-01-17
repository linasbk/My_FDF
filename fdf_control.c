
#include"fdf.h"

void	clear_window(t_fdf_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	data->addr = mlx_get_data_addr(data->img, &(data->bpp), &(data->line_len),
			&(data->endian));
	draw(data);
}

int	ft_keyboard(int keynum, t_fdf_data *data)
{
	if (keynum == 53)
		exit(EXIT_FAILURE);
	if (keynum == KEY_UP)
		data->shift_y -= 20;
	if (keynum == KEY_DOWN)
		data->shift_y += 20;
	if (keynum == KEY_LEFT)
		data->shift_x -= 20;
	if (keynum == KEY_RIGHT)
		data->shift_x += 20;
	if (keynum == 6)
		data->scale_z += 0.5;
	if (keynum == 8)
		data->color += 5;
	if (keynum == 13)
		data->scale_z -= 0.5;
	if (keynum == 86)
		data->angle += 0.05;
	if (keynum == 88)
		data->angle -= 0.05;
	clear_window(data);
	return (0);
}

int	ft_mouse(int keynum, int x, int y, t_fdf_data *data)
{
	(void)x;
	(void)y;
	if (keynum == SCROLL_CLICK)
	{
		if (data->iso == 0)
			data->iso = 1;
		else
			data->iso = 0;
	}
	if (keynum == SCROLL_UP)
		data->zoom -= 0.5;
	if (keynum == SCROLL_DOWN)
		data->zoom += 0.5;
	clear_window(data);
	return (0);
}
