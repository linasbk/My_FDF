#include "mlx.h"
#include<stdlib.h>
#include<math.h>
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	double	deltaX;
	double	deltaY;
	double	pixelX;
	double	pixelY;
	int			pixels;

	deltaY = endY - beginY;
	deltaX = endX - beginX;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	pixelX = beginX;
	pixelY = beginY;
	while (pixels)
	{
		printf("%f,%f\n",pixelX,pixelY);
			mlx_pixel_put(mlx, win, pixelX, pixelY, color);
			pixelX += deltaX;
			pixelY += deltaY;
			--pixels;
	}
	return (0);
}

int	main(void)
{
	void	  *mlx;
	void	  *mlx_win;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 400, "luna");
	draw_line(mlx, mlx_win, 0, 2, 0,300, 0xFFFFFF); 
	mlx_loop(mlx);
	return (0);
}
