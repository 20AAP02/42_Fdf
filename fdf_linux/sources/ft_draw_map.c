#include <fdf.h>

int	ft_calculate_pt_dist(int map_width, int img_width)
{
	int pt_dist;

	pt_dist = img_width;
}

void	ft_draw_map(void *mlx, t_img *img, int color, int **map)
{
	int map_width;
	int	pt_dist;
	int	pixel;
	int	x;
	int	y;

	if (img->pixel_bits != 32)
		color = mlx_get_color_value(mlx, color);
	map_width = 19;
	pt_dist = 50;
	map_width * pt_dist - pt_dist
	y = 0;
	while (map[y])
	{
		x = 0;
		while (x < map_width)
		{
			pixel = ((y * pt_dist) * img->line_bytes) + ((x * pt_dist) * 4);
			ft_color_img_pixel(img, pixel, color * map[y][x]);
			x++;
		}
		y++;
	}
}