/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:53:35 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/02 16:54:03 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_draw_map(t_map *map_inf, void *mlx, void *win, t_img *img)
{
	ft_fill_img(mlx, img, 0x3b3a39);
	ft_reset_altitude(map_inf);
	ft_scale_altitude(map_inf);
	map_inf->pt_dist = ft_calc_pt_dist(img, map_inf);
	map_inf->pt_dist += map_inf->zoom;
	ft_draw_h_lines(mlx, img, map_inf);
	ft_draw_v_lines(mlx, img, map_inf);
	if (map_inf->height > 50)
	{
		ft_draw_d_lines(mlx, img, map_inf);
		ft_draw_d2_lines(mlx, img, map_inf);
	}
	mlx_put_image_to_window(mlx, win, img->img_ptr, 0, 0);
}
