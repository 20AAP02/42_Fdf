#include <fdf.h>

int	ft_calculate_pt_dist(int map_width, int img_width, int map_height, int img_height)
{
	int pt_dist;

	pt_dist = img_width;
	while ((map_width * pt_dist) >= img_width)
		pt_dist--;
	while ((map_height * pt_dist) >= img_height)
		pt_dist--;
	return (pt_dist);
}

void	ft_draw_map(void *mlx, t_img *img, int color, t_map *map_inf)
{
	int	pt_dist;
	int	pixel;
	int	img_Ycenter;
	int	img_Xcenter;
	int	x;
	int	y;

	if (img->pixel_bits != 32)
		color = mlx_get_color_value(mlx, color);
	pt_dist = ft_calculate_pt_dist(map_inf->width, img->width, map_inf->height, img->height);
	img_Ycenter = (img->height - (map_inf->height * pt_dist)) / 2;
	img_Xcenter = (img->width - (map_inf->width * pt_dist));
	y = 0;
	while (map_inf->map[y])
	{
		x = 0;
		while (x < map_inf->width)
		{
			pixel = (((y * pt_dist) + img_Ycenter) * img->line_bytes) + (((x * pt_dist) + img_Xcenter) * 4);
			ft_color_img_pixel(img, pixel, color * map_inf->map[y][x]);
			x++;
		}
		y++;
	}
}