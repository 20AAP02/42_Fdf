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
	int	color_check;
	int	pixel;
	int	img_Ycenter;
	int	img_Xcenter;
	int	x;
	int	y;

	ft_altitude_range(map_inf);
	color_check = ft_map_color_check(map_inf);
	pt_dist = ft_calculate_pt_dist(map_inf->width, img->width, map_inf->height, img->height);
	//pt_dist = 2;
	img_Ycenter = (img->height - (map_inf->height * pt_dist)) / 2;
	img_Xcenter = (img->width - (map_inf->width * pt_dist)) / 2;
	y = 0;
	while (map_inf->map[y])
	{
		x = 0;
		while (x < map_inf->width)
		{
			pixel = (((y * pt_dist) + img_Ycenter) * img->line_bytes) + (((x * pt_dist) + img_Xcenter) * 4);
			if (color_check)
				color = ft_color_mixer(map_inf->range, map_inf->map[y][x].altitude);
			else
				color = map_inf->map[y][x].color;
			ft_color_img_pixel(img, pixel, color, mlx);
			x++;
		}
		y++;
	}
}