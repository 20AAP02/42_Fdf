/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:48:32 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/02 15:55:09 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

typedef struct s_line_variables
{
	int		pixel;
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	int		color;
	int		dist;
	int		dist2;
	t_pt	c_point;
}		t_line_vars;

void	ft_dl_block1(t_line_vars *vars, t_ln line)
{
	vars->dx = abs(line.b.x - line.a.x);
	vars->dy = abs(line.b.y - line.a.y) * (-1);
	vars->err = vars->dx + vars->dy;
	vars->sx = ft_x_direction(line.a, line.b);
	vars->sy = ft_y_direction(line.a, line.b);
	vars->x = line.a.x;
	vars->y = line.a.y;
	vars->dist2 = ft_calc_2Pt_dist(line.a, line.b);
}

void	ft_draw_line(void *mlx_ptr, t_img *img, t_ln line)
{
	t_line_vars	vars;

	ft_dl_block1(&vars, line);
	while (vars.x != line.b.x || vars.y != line.b.y)
	{
		vars.pixel = (vars.y * img->line_bytes) + (vars.x * 4);
		vars.c_point.x = vars.x;
		vars.c_point.y = vars.y;
		vars.dist = ft_calc_2Pt_dist(line.a, vars.c_point) * 100;
		vars.color = ft_linear_gradient(line.colors, vars.dist / vars.dist2);
		if (vars.y >= 0 && vars.y < img->height)
			if (vars.x >= 0 && vars.x < img->width)
				ft_color_img_pixel(img, vars.pixel, vars.color, mlx_ptr);
		vars.e2 = 2 * vars.err;
		if (vars.e2 >= vars.dy)
		{
			vars.err += vars.dy;
			vars.x += vars.sx;
		}
		if (vars.e2 <= vars.dx)
		{
			vars.err += vars.dx;
			vars.y += vars.sy;
		}
	}
}
