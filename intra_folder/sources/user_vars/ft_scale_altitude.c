/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_altitude.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:22:52 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/03 16:23:10 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_scale_altitude(t_map *map_inf)
{
	int	y;
	int	x;

	y = 0;
	while (y < map_inf->height)
	{
		x = 0;
		while (x < map_inf->width)
		{
			if (map_inf->map[y][x].alt2 > -map_inf->scale)
				map_inf->map[y][x].altitude += map_inf->scale;
			else if (map_inf->map[y][x].alt2)
				map_inf->map[y][x].altitude = 0;
			else if (map_inf->map[y][x].alt2 - map_inf->scale > 0)
				map_inf->map[y][x].altitude = 0;
			else if (map_inf->map[y][x].alt2 < 0)
				map_inf->map[y][x].altitude -= map_inf->scale;
			x++;
		}
		y++;
	}
}
