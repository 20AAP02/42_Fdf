#include <fdf.h>

void    ft_draw_H_lines(void *mlx, t_img *img, t_map *map_inf)
{
	int     y;
	int     x;
	int     z;
	int		z2;
	t_ln    line;
	t_pt    a;
	t_pt    b;

	y = 0;
	while (y < map_inf->height)
	{
		x = 0;
		while (x < map_inf->width - 1)
		{
			z = map_inf->map[y][x].altitude;
			z2 = map_inf->map[y][x + 1].altitude;
			a.x = (iso(x * map_inf->pt_dist, y * map_inf->pt_dist, z * map_inf->pt_dist, 0)) + ((map_inf->comp_x + 1) * map_inf->pt_dist);
			a.y = (iso(x * map_inf->pt_dist, y * map_inf->pt_dist, z * map_inf->pt_dist, 1)) + ((map_inf->comp_y + 1) * map_inf->pt_dist);
			b.x = (iso((x + 1) * map_inf->pt_dist, y * map_inf->pt_dist, z2 * map_inf->pt_dist, 0)) + ((map_inf->comp_x + 1) * map_inf->pt_dist);
			b.y = (iso((x + 1) * map_inf->pt_dist, y * map_inf->pt_dist, z2 * map_inf->pt_dist, 1)) + ((map_inf->comp_y + 1) * map_inf->pt_dist);
			line = ft_init_line(a.x, a.y, b.x, b.y);
			line.colors[0] = map_inf->map[y][x].color;
			line.colors[1] = map_inf->map[y][x + 1].color;
			if (a.x < img->width && a.y < img->height && b.x < img->width && b.y < img->height)
				if (a.x >= 0 && a.y >= 0 && b.x >= 0 && b.y >= 0)
					ft_draw_line(mlx, img, line);
			x++;
		}
		y++;
	}
}

void    ft_draw_V_lines(void *mlx, t_img *img, t_map *map_inf)
{
	int     y;
	int     x;
	int     z;
	int		z2;
	t_ln    line;
	t_pt    a;
	t_pt    b;

	y = 0;
	while (y < map_inf->height - 1)
	{
		x = 0;
		while (x < map_inf->width)
		{
			z = map_inf->map[y][x].altitude;
			z2 = map_inf->map[y + 1][x].altitude;
			a.x = (iso(x * map_inf->pt_dist, y * map_inf->pt_dist, z * map_inf->pt_dist, 0)) + ((map_inf->comp_x + 1) * map_inf->pt_dist);
			a.y = (iso(x * map_inf->pt_dist, y * map_inf->pt_dist, z * map_inf->pt_dist, 1)) + ((map_inf->comp_y + 1) * map_inf->pt_dist);
			b.x = (iso(x * map_inf->pt_dist, (y + 1) * map_inf->pt_dist, z2 * map_inf->pt_dist, 0)) + ((map_inf->comp_x + 1) * map_inf->pt_dist);
			b.y = (iso(x * map_inf->pt_dist, (y + 1) * map_inf->pt_dist, z2 * map_inf->pt_dist, 1)) + ((map_inf->comp_y + 1) * map_inf->pt_dist);
			line = ft_init_line(a.x, a.y, b.x, b.y);
			line.colors[0] = map_inf->map[y][x].color;
			line.colors[1] = map_inf->map[y + 1][x].color;
			if (a.x < img->width && a.y < img->height && b.x < img->width && b.y < img->height)
				if (a.x >= 0 && a.y >= 0 && b.x >= 0 && b.y >= 0)
					ft_draw_line(mlx, img, line);
			x++;
		}
		y++;
	}
}

/*
void    ft_draw_D_lines(void *mlx, t_img *img, t_map *map_inf)
{
	int     y;
	int     x;
	int     z;
	t_ln    line;
	t_pt    a;
	t_pt    b;

	y = 0;
	while (y < map_inf->height - 1)
	{
		x = 0;
		while (x < map_inf->width - 1)
		{
			z = map_inf->map[y][x].altitude;
			a.x = (iso(x, y, z, 0) + map_inf->comp_x) * map_inf->pt_dist;
			a.y = (iso(x, y, z, 1) + map_inf->comp_y) * map_inf->pt_dist;
			b.x = (iso(x + 1, y, z, 0) + map_inf->comp_x) * map_inf->pt_dist;
			b.y = (iso(x, y + 1, z, 1) + map_inf->comp_y) * map_inf->pt_dist;
			line = ft_init_line(a.x * 6, a.y * 6, b.x * 6, b.y * 6);
			line.colors[0] = map_inf->map[y][x].color;
			line.colors[1] = map_inf->map[y + 1][x + 1].color;
			if (a.x < img->width && a.y < img->height && b.x < img->width && b.y < img->height)
				if (a.x >= 0 && a.y >= 0 && b.x >= 0 && b.y >= 0)
					ft_draw_line(mlx, img, line);
			x++;
		}
		y++;
	}
}

void    ft_draw_D2_lines(void *mlx, t_img *img, t_map *map_inf)
{
	int     y;
	int     x;
	int     z;
	t_ln    line;
	t_pt    a;
	t_pt    b;

	y = 0;
	while (y < map_inf->height - 1)
	{
		x = 1;
		while (x < map_inf->width)
		{
			z = map_inf->map[y][x].altitude;
			a.x = (iso(x, y, z, 0) + map_inf->comp_x) * map_inf->pt_dist;
			a.y = (iso(x, y, z, 1) + map_inf->comp_y) * map_inf->pt_dist;
			b.x = (iso(x - 1, y, z, 0) + map_inf->comp_y) * map_inf->pt_dist;
			b.y = (iso(x, y + 1, z, 1) + map_inf->comp_y) * map_inf->pt_dist;
			line = ft_init_line(a.x, a.y, b.x, b.y);
			line.colors[0] = map_inf->map[y][x].color;
			line.colors[1] = map_inf->map[y + 1][x + 1].color;
			if (a.x < img->width && a.y < img->height && b.x < img->width && b.y < img->height)
				if (a.x >= 0 && a.y >= 0 && b.x >= 0 && b.y >= 0)
					ft_draw_line(mlx, img, line);
			x++;
		}
		y++;
	}
}
*/