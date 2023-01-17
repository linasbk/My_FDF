/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:07:09 by lsabik            #+#    #+#             */
/*   Updated: 2022/11/25 15:07:13 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BACKGROUND 0x00222222
# define WHITE 0xFFFFFF

# define KEY_UP 126
# define KEY_DOWN 125 
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ISO 34

# define RIGHT_CLICK 2
# define LEFT_CLICK 1
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define SCROLL_CLICK 3
# define Z 13
# define W 6

# include "mlx.h"
# include<fcntl.h>
# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>
# include<math.h>

typedef struct point {
	float	x;
	float	y;
	float	z;
	double	delta_x;
	double	delta_y;
}				t_point;

typedef struct map {
	int			win_height;
	int			win_width;
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			mouse;
	int			height;
	int			width;
	int			iso;
	int			color;
	float		angle;
	int			**map;
	char		**line;
	float		zoom;
	float		shift_x;
	float		shift_y;
	float		scale_z;
}				t_fdf_data;

t_fdf_data	*ft_init(void);
char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s1);
int			read_map(char *file, t_fdf_data *data, int i, int j);
char		*ft_substr(char *s, unsigned int start, size_t len);
size_t		ft_strlen(char *s);
int			ft_strchr(char *s, char c);
int			get_num_word(char *s, char sep);
int			ft_atoi(const char *str);
int			ft_atoi_base(const char *str, int str_base);
int			get_color(int color);
char		**ft_split(char const *s, char c);
void		drawline(t_fdf_data *data, t_point *a, t_point *b);
void		ft_putstr(char *s);
void		ft_error(void);
void		draw(t_fdf_data	*data);
int			ft_keyboard(int keynum, t_fdf_data *data);
int			ft_mouse(int keynum, int x, int y, t_fdf_data *data);
void		init_param(t_fdf_data *data);
void		zoom_iso(t_point *a, t_point *b, t_fdf_data *data);
#endif
