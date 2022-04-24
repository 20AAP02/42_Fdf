#include <fdf.h>

typedef struct
{
	int 	pixel;
	int 	x;
	int 	y;
	int 	dx;
	int 	dy;
	int 	sx;
	int 	sy;
	int 	err;
	int 	e2;
	int		color;
	int		colors[2];
	int		altitude;
	int		range[2];
	int		cur_x;
	int		cur_y;
	t_ln	line;
}		line_vars;


void	ft_draw_line(void *mlx_ptr, t_img *img, t_ln line, t_map *map_inf)
{
	line_vars	vars;

	vars.dx = abs(line.b.x - line.a.x);
	vars.dy = abs(line.b.y - line.a.y) * (-1);
	vars.err = vars.dx + vars.dy;
	vars.sx = ft_x_direction(line.a, line.b);
	vars.sy = ft_y_direction(line.a, line.b);
	vars.x = line.a.x;
	vars.y = line.a.y;
	while (vars.x != line.b.x || vars.y != line.b.y)
	{
		vars.line.a.y = (line.a.y - map_inf->img_Ycenter) / map_inf->pt_dist;
		vars.line.a.x = (line.a.x - map_inf->img_Xcenter) / map_inf->pt_dist;
		vars.line.b.y = (line.b.y - map_inf->img_Ycenter) / map_inf->pt_dist;
		vars.line.b.x = (line.b.x - map_inf->img_Xcenter) / map_inf->pt_dist;

		vars.cur_y = (vars.y - map_inf->img_Ycenter) / map_inf->pt_dist;
		vars.cur_x = (vars.x - map_inf->img_Xcenter) / map_inf->pt_dist;

		vars.pixel = (vars.y * img->line_bytes) + (vars.x * 4);
		
		vars.colors[0] = map_inf->map[vars.line.a.y][vars.line.a.x].color;
		vars.colors[1] = map_inf->map[vars.line.b.y][vars.line.b.x].color;

		vars.altitude = map_inf->map[vars.cur_y][vars.cur_x].altitude;

		vars.range[0] = map_inf->map[vars.line.a.y][vars.line.a.x].altitude;
		vars.range[1] = map_inf->map[vars.line.b.y][vars.line.b.x].altitude;
		vars.color = ft_linear_gradient(vars.colors, vars.altitude, vars.range);
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
