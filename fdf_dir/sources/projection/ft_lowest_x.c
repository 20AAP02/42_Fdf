/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowest_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:16:36 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/03 16:20:06 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	ft_lowest_x(t_map *map_inf, int comp)
{
	int	y;
	int	x;
	int	z;
	int	x1;
	int	x2;

	y = 0;
	x2 = 0;
	while (y < map_inf->height)
	{
		x = 0;
		while (x < map_inf->width)
		{
			z = map_inf->map[y][x].altitude;
			x1 = iso(x, y, z, 0) + comp;
			if ((y == 0 && x == 0) || x2 > x1)
				x2 = x1;
			x++;
		}
		y++;
	}
	return (x2);
}
