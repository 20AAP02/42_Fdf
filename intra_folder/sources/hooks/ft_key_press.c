/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:28:26 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/03 16:14:57 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	ft_zx(int keycode, t_inf *info)
{
	if (keycode == KEY_Z)
		info->map_inf->scale += 1;
	else
		info->map_inf->scale -= 1;
	ft_draw_map(info->map_inf, info->mlx, info->win, info->img);
	return (0);
}

int	ft_move(int keycode, t_inf *info)
{
	if (keycode == KEY_LEFT)
		info->map_inf->move_x -= 10;
	else if (keycode == KEY_RIGHT)
		info->map_inf->move_x += 10;
	else if (keycode == KEY_DOWN)
		info->map_inf->move_y += 10;
	else if (keycode == KEY_UP)
		info->map_inf->move_y -= 10;
	ft_draw_map(info->map_inf, info->mlx, info->win, info->img);
	return (0);
}

int	ft_space(t_inf *info)
{
	if (info->map_inf->color_check)
		info->map_inf->color_check = 0;
	else
		info->map_inf->color_check = 1;
	ft_color_map(info->map_inf);
	ft_draw_map(info->map_inf, info->mlx, info->win, info->img);
	return (0);
}

int	ft_b_and_w(t_inf *info)
{
	if (info->map_inf->color_check)
	{
		info->map_inf->color_check = 0;
	}
	else if (info->map_inf->colors[0] != BLACK)
	{
		info->map_inf->colors[0] = BLACK;
		info->map_inf->colors[1] = WHITE;
	}
	else
	{
		info->map_inf->colors[0] = GREEN;
		info->map_inf->colors[1] = BROWN;
	}
	ft_color_map(info->map_inf);
	ft_draw_map(info->map_inf, info->mlx, info->win, info->img);
	return (0);
}

int	ft_key_press(int keycode, t_inf *info)
{
	if (keycode == ESC)
		ft_esc(info);
	if (keycode == KEY_Z || keycode == KEY_X)
		return (ft_zx(keycode, info));
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		return (ft_zoom(keycode, info));
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		return (ft_move(keycode, info));
	if (keycode == KEY_DOWN || keycode == KEY_UP)
		return (ft_move(keycode, info));
	if (keycode == KEY_SPACE)
		return (ft_space(info));
	if (keycode == KEY_B)
		return (ft_b_and_w(info));
	return (0);
}
