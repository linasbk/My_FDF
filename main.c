/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:06:34 by lsabik            #+#    #+#             */
/*   Updated: 2022/11/25 15:06:40 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_file(char *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ".fdf";
	while (s[i])
	{
		if (s[i++] == str[j])
			j++;
		if (j == 3)
			return (0);
	}
	return (-1);
}

int	main(int ac, char **av)
{
	t_fdf_data	*data;

	if (ac != 2 || (fdf_file(av[1]) == -1))
	{
		ft_putstr("\033[1;31m Invalid arguments!!\n");
		ft_putstr("\033[0;34m The correct format is :<< ./fdf map_file.fdf>>");
		exit(EXIT_FAILURE);
	}
	data = (t_fdf_data *)malloc(sizeof(t_fdf_data) * 1);
	if (data == NULL)
		ft_error();
	if (read_map(av[1], data, -1, 0) == -1)
	{
		ft_putstr("\033[1;31m NON-Existing File!!\n");
		ft_putstr("\033[0;34m The correct format is :<< ./fdf map_file.fdf>>");
		exit(EXIT_FAILURE);
	}
	init_param(data);
	draw(data);
	mlx_hook(data->mlx_win, 2, 0, ft_keyboard, data);
	mlx_key_hook(data->mlx_win, ft_keyboard, data);
	mlx_hook(data->mlx_win, 4, 0, ft_mouse, data);
	mlx_loop(data->mlx);
	return (0);
}
