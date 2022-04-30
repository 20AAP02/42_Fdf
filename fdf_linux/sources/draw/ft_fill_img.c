#include <fdf.h>

void	ft_fill_img(void *mlx_ptr, t_img *img, int color)
{
	int	pixel;
	int	x;
	int	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			pixel = (y * img->line_bytes) + (x * 4);
			ft_color_img_pixel(img, pixel, color, mlx_ptr);
			x++;
		}
		y++;
	}
}