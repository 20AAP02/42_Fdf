/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:54:19 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/02 16:54:22 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_fill_img(void *mlx_ptr, t_img *img, int color)
{
	int	pixel;
	int	x;
	int	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			pixel = (y * img->line_bytes) + (x * 4);
			ft_color_img_pixel(img, pixel, color, mlx_ptr);
			x++;
		}
		y++;
	}
}
