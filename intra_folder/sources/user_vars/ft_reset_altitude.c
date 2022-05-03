/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_altitude.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:22:29 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/03 16:22:38 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_reset_altitude(t_map *map_inf)
{
	int	y;
	int	x;

	y = 0;
	while (y < map_inf->height)
	{
		x = 0;
		while (x < map_inf->width)
		{
			map_inf->map[y][x].altitude = map_inf->map[y][x].alt2;
			x++;
		}
		y++;
	}
}
