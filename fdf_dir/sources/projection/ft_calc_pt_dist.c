/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_pt_dist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:16:20 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/03 16:19:10 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	ft_check_pt_dist(t_img *img, t_map *map_inf, int pt_dist)
{
	int	y;
	int	x;
	int	z;
	int	y1;
	int	x1;

	y = 0;
	while (y < map_inf->height)
	{
		x = 0;
		while (x < map_inf->width)
		{
			z = map_inf->map[y][x].altitude;
			x1 = (iso(x, y, z, 0) + map_inf->comp_x) * pt_dist;
			y1 = (iso(x, y, z, 1) + map_inf->comp_y) * pt_dist;
			if (x1 >= img->width || y1 >= img->height)
				return (0);
			if (y1 < 0 || x1 < 0)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_calc_pt_dist(t_img *img, t_map *map_inf)
{
	int	pt_dist;

	pt_dist = 1;
	while (ft_check_pt_dist(img, map_inf, pt_dist))
		pt_dist++;
	return (pt_dist - 1);
}
