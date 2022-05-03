/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:12:43 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/03 16:12:44 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	ft_zoom(int keycode, t_inf *info)
{
	if (keycode == KEY_PLUS)
		info->map_inf->zoom += 1;
	else
		info->map_inf->zoom -= 1;
	ft_draw_map(info->map_inf, info->mlx, info->win, info->img);
	return (0);
}
