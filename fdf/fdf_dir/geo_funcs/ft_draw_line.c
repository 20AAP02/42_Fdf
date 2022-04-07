#include <fdf.h>

void	ft_draw_line(void *mlx_ptr, t_img img, t_ln line, int color)
{
	int	pixel;
	int	x;
	int	y;

	if (img.pixel_bits != 32)
		color = mlx_get_color_value(mlx_ptr, color);
	y = line.a.y;
	x = line.a.x;
	pixel = (y * img.line_bytes) + (x * 4);
	ft_color_img_pixel(img, pixel, color);
}