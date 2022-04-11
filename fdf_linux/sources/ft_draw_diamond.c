#include <fdf.h>

void	ft_draw_diamond(void *mlx_ptr, t_img *img, int color)
{
	int	pixel;
	int	x;
	int	y;
	int c1 = (img->width / 2) - 1;
	int c2 = (img->width / 2) + 1;

	if (img->pixel_bits != 32)
		color = mlx_get_color_value(mlx_ptr, color);
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			pixel = (y * img->line_bytes) + (x * 4);
			if (x > c1 && x < c2 && y > (img->height / 4) && y < ((img->height / 4) * 3))
				if ((pixel % 5 == 0) && (pixel % 3 == 0))
					ft_color_img_pixel(img, pixel, color);
			x++;
		}

		if (y > (img->height / 4) && y < (img->height / 2) && c1 > (img->width / 4))
		{
			c1--;
			c2++;
		}
		if (y > (img->height / 2) && y < ((img->height / 4) * 3) && c1 >= (img->width / 4))
		{
			c1++;
			c2--;
		}
		y++;
	}
}