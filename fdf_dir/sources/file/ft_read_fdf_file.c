/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fdf_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:09:16 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/02 18:17:02 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_map	*ft_read_fdf_file(char *file_name)
{
	t_map	*map_inf;
	int		file_lines;
	char	*str;
	int		fd;
	int		i;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_inf = malloc(sizeof(t_map));
	file_lines = ft_n_lines_file(file_name) + 1;
	map_inf->map = malloc(sizeof(t_3dPt *) * (file_lines + 1));
	i = 0;
	str = get_next_line(fd);
	map_inf->width = ft_map_width(str);
	while (str)
	{
		map_inf->map[i] = malloc(sizeof(t_3dPt) * map_inf->width);
		free(ft_cpy_ln_to_intarr(map_inf->map, str, i++));
		str = get_next_line(fd);
	}
	map_inf->height = i;
	free(str);
	close(fd);
	return (map_inf);
}
