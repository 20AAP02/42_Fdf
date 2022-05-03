/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:00:59 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/02 17:10:06 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

typedef struct s_vars
{
	int		y;
	int		x;
	int		z;
	int		z2;
	t_ln	l;
	int		xn;
	int		yn;
	int		pd;
	int		x_p;
	int		y_p;
}			t_var;

void	ft_draw_h_lines(void *mlx, t_img *img, t_map *map_inf)
{
	t_var	x;

	x.pd = map_inf->pt_dist;
	x.xn = (map_inf->comp_x + 1) * x.pd + map_inf->move_x;
	x.yn = (map_inf->comp_y + 1) * x.pd + map_inf->move_y;
	x.y = 0;
	while (x.y < map_inf->height)
	{
		x.x = 0;
		while (x.x < map_inf->width - 1)
		{
			x.z = map_inf->map[x.y][x.x].altitude;
			x.z2 = map_inf->map[x.y][x.x + 1].altitude;
			x.l.a.x = iso(x.x * x.pd, x.y * x.pd, x.z * x.pd, 0) + x.xn;
			x.l.a.y = iso(x.x * x.pd, x.y * x.pd, x.z * x.pd, 1) + x.yn;
			x.l.b.x = iso((x.x + 1) * x.pd, x.y * x.pd, x.z2 * x.pd, 0) + x.xn;
			x.l.b.y = iso((x.x + 1) * x.pd, x.y * x.pd, x.z2 * x.pd, 1) + x.yn;
			x.l.colors[0] = map_inf->map[x.y][x.x].color;
			x.l.colors[1] = map_inf->map[x.y][x.x + 1].color;
			ft_draw_line(mlx, img, x.l);
			x.x++;
		}
		x.y++;
	}
}

void	ft_draw_v_lines(void *mlx, t_img *img, t_map *map_inf)
{
	t_var	x;

	x.pd = map_inf->pt_dist;
	x.xn = (map_inf->comp_x + 1) * x.pd + map_inf->move_x;
	x.yn = (map_inf->comp_y + 1) * x.pd + map_inf->move_y;
	x.y = 0;
	while (x.y < map_inf->height - 1)
	{
		x.x = 0;
		while (x.x < map_inf->width)
		{
			x.z = map_inf->map[x.y][x.x].altitude;
			x.z2 = map_inf->map[x.y + 1][x.x].altitude;
			x.l.a.x = iso(x.x * x.pd, x.y * x.pd, x.z * x.pd, 0) + x.xn;
			x.l.a.y = iso(x.x * x.pd, x.y * x.pd, x.z * x.pd, 1) + x.yn;
			x.l.b.x = iso(x.x * x.pd, (x.y + 1) * x.pd, x.z2 * x.pd, 0) + x.xn;
			x.l.b.y = iso(x.x * x.pd, (x.y + 1) * x.pd, x.z2 * x.pd, 1) + x.yn;
			x.l.colors[0] = map_inf->map[x.y][x.x].color;
			x.l.colors[1] = map_inf->map[x.y + 1][x.x].color;
			ft_draw_line(mlx, img, x.l);
			x.x++;
		}
		x.y++;
	}
}

void	ft_draw_d_lines(void *mlx, t_img *img, t_map *map_inf)
{
	t_var	x;

	x.pd = map_inf->pt_dist;
	x.xn = (map_inf->comp_x + 1) * x.pd + map_inf->move_x;
	x.yn = (map_inf->comp_y + 1) * x.pd + map_inf->move_y;
	x.y = -1;
	while (++x.y < map_inf->height - 1)
	{
		x.x = -1;
		while (++x.x < map_inf->width - 1)
		{
			x.x_p = x.x + 1;
			x.y_p = x.y + 1;
			x.z = map_inf->map[x.y][x.x].altitude;
			x.z2 = map_inf->map[x.y + 1][x.x + 1].altitude;
			x.l.a.x = iso(x.x * x.pd, x.y * x.pd, x.z * x.pd, 0) + x.xn;
			x.l.a.y = iso(x.x * x.pd, x.y * x.pd, x.z * x.pd, 1) + x.yn;
			x.l.b.x = iso(x.x_p * x.pd, x.y_p * x.pd, x.z2 * x.pd, 0) + x.xn;
			x.l.b.y = iso(x.x_p * x.pd, x.y_p * x.pd, x.z2 * x.pd, 1) + x.yn;
			x.l.colors[0] = map_inf->map[x.y][x.x].color;
			x.l.colors[1] = map_inf->map[x.y + 1][x.x + 1].color;
			ft_draw_line(mlx, img, x.l);
		}
	}
}

void	ft_draw_d2_lines(void *mlx, t_img *img, t_map *map_inf)
{
	t_var	x;

	x.pd = map_inf->pt_dist;
	x.xn = (map_inf->comp_x + 1) * x.pd + map_inf->move_x;
	x.yn = (map_inf->comp_y + 1) * x.pd + map_inf->move_y;
	x.y = -1;
	while (++x.y < map_inf->height - 1)
	{
		x.x = 0;
		while (++x.x < map_inf->width)
		{
			x.x_p = x.x - 1;
			x.y_p = x.y + 1;
			x.z = map_inf->map[x.y][x.x].altitude;
			x.z2 = map_inf->map[x.y + 1][x.x - 1].altitude;
			x.l.a.x = (iso(x.x * x.pd, x.y * x.pd, x.z * x.pd, 0)) + x.xn;
			x.l.a.y = (iso(x.x * x.pd, x.y * x.pd, x.z * x.pd, 1)) + x.yn;
			x.l.b.x = (iso(x.x_p * x.pd, x.y_p * x.pd, x.z2 * x.pd, 0)) + x.xn;
			x.l.b.y = (iso(x.x_p * x.pd, x.y_p * x.pd, x.z2 * x.pd, 1)) + x.yn;
			x.l.colors[0] = map_inf->map[x.y][x.x].color;
			x.l.colors[1] = map_inf->map[x.y + 1][x.x - 1].color;
			ft_draw_line(mlx, img, x.l);
		}
	}
}
