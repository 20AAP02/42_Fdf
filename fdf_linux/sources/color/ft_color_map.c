/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:22:55 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/02 15:25:59 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_color_map(t_map *map_inf)
{
	int	x;
	int	y;
	int	color;
	int	altitude;

	ft_altitude_range(map_inf);
	y = 0;
	while (y < map_inf->height)
	{
		x = 0;
		while (x < map_inf->width)
		{
			if (map_inf->color_check)
			{
				altitude = map_inf->map[y][x].altitude;
				color = ft_color_mixer(map_inf->range, altitude, map_inf);
				map_inf->map[y][x].color = color;
			}
			x++;
		}
		y++;
	}
}
