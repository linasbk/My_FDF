/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:46:13 by lsabik            #+#    #+#             */
/*   Updated: 2022/11/25 15:07:48 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	free_all(char **str, int size, char *string)
{
	if (string)
		free(string);
	while (size--)
		free(str[size]);
	free(str);
}

int	map_height(char *file)
{
	int		fd;
	int		line;
	char	*str;

	line = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	str = get_next_line(fd);
	while (str)
	{
		line++;
		free(str);
		str = get_next_line(fd);
	}
	close (fd);
	return (line);
}

void	read_map(char *file, t_map_data *data, int i, int j)
{
	int		fd;
	char	*str;

	data->height = map_height(file);
	data->map = malloc(data->height * sizeof(int *));
	if (!data->map)
		return ;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	str = get_next_line(fd);
	while (++i < data->height)
	{
		data->line = ft_split(str, ' ');
		data->width = get_num_word(str, ' ');
		data->map[i] = malloc(sizeof(int) * data->width);
		if (!data->map[i])
			return ;
		j = -1;
		while (++j < data->width)
			data->map[i][j] = ft_atoi(data->line[j]);
		free_all(data->line, j, str);
		str = get_next_line(fd);
	}
	close(fd);
}
