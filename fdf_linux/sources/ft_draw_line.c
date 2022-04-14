#include <fdf.h>

void	ft_draw_line(void *mlx_ptr, t_img *img, t_ln line, int color)
{
	int pixel;
	int x;
	int y;
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;

	if (img->pixel_bits != 32)
		color = mlx_get_color_value(mlx_ptr, color);
	dx = abs(line.b.x - line.a.x);
	dy = abs(line.b.y - line.a.y) * (-1);
	err = dx + dy;
	sx = ft_x_direction(line.a, line.b);
	sy = ft_y_direction(line.a, line.b);
	x = line.a.x;
	y = line.a.y;
	while (x != line.b.x || y != line.b.y)
	{
		pixel = (y * img->line_bytes) + (x * 4);
		ft_color_img_pixel(img, pixel, color);
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y += sy;
		}
	}
}
