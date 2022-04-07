#include <fdf.h>

void	ft_color_img_pixel(t_img img, int pixel, int color)
{
	if (img.endian)
	{
		img.buffer[pixel + 0] = (color >> 24);
		img.buffer[pixel + 1] = (color >> 16) & 0xFF;
		img.buffer[pixel + 2] = (color >> 8) & 0xFF;
		img.buffer[pixel + 3] = (color) & 0xFF;
	}
	else
	{
		img.buffer[pixel + 0] = (color) & 0xFF;
		img.buffer[pixel + 1] = (color >> 8) & 0xFF;
		img.buffer[pixel + 2] = (color >> 16) & 0xFF;
		img.buffer[pixel + 3] = (color >> 24);
	}
}