#include "mlx.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(void)
{
	void	  *mlx;
	void	  *mlx_win;
	int			i;
	int			j;


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 400, "luna");
 	for (i=300+1;i>1;i--)
    {
        for (j=200;j<i-1;j++)
        {
					printf("%d, %d\n", i, j);
					if (j == (i - 2) ||  j == 200 || i == 300)
          mlx_pixel_put(mlx, mlx_win, i, j,  0x0000FF00);
        }
    }
	mlx_loop(mlx);
	return (0);
}
