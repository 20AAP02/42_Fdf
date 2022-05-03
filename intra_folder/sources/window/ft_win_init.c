/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:23:33 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/03 16:32:32 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_win_init(t_winInf *info)
{
	t_img	img;
	int		*ptr;
	int		*mem;

	img = info->img;
	ptr = &img.pixel_bits;
	mem = &img.line_bytes;
	info->mlx = mlx_init();
	img.height = 1000;
	img.width = 1000;
	info->win = mlx_new_window(info->mlx, 1000, 1000, "Map Generator");
	img.img_ptr = mlx_new_image(info->mlx, img.width, img.height);
	img.buffer = mlx_get_data_addr(img.img_ptr, ptr, mem, &img.endian);
	info->img = img;
}
