#include <fdf.h>

int ft_sx(t_pt a, t_pt b)
{
	if (b.x > a.x)
		return (1);
	else
		return (-1);
}

int ft_sy(t_pt a, t_pt b)
{
	if (b.y > a.y)
		return (1);
	else
		return (-1);
}

void	ft_vertical_line()
{
	printf("VERTICAL LINE\n");
	return ;
}

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
	sx = ft_sx(line.a, line.b);
	sy = ft_sy(line.a, line.b);
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
