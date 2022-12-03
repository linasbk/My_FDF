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

# include "mlx.h"
# include<fcntl.h>
# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>
# include<math.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct point {
	float	x0;
	float	y0;
	float	x1;
	float	y1;
	double	delta_x;
	double	delta_y;
}				t_point;

typedef struct map {
	void		*mlx;
	void		*mlx_win;

	int			height;
	int			width;
	int			zoom;
	int			color;
	int			**map;
	char		**line;
}				t_map_data;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
void	read_map(char *file, t_map_data *data, int i, int j);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(char *s);
int		ft_strchr(char *s, char c);
int		get_num_word(char *s, char sep);
int		ft_atoi(const char *str);
int		get_color(int color, t_map_data *data);
char	**ft_split(char const *s, char c);
void	drawline(t_map_data *data, t_point *lines, t_data *img);

#endif
