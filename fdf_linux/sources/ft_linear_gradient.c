#include <fdf.h>

int get_light(int start, int end, float percent)
{
	return ((float)(1.0 - (percent / 100.0)) * (float)start + (percent / 100.0) * (float)end);
}

int	ft_linear_gradient(int colors[2], int percent)
{
	int	red;
	int	green;
	int	blue;

	if (colors[0] == colors[1])
		return (colors[0]);
	red = get_light(ft_getRed(colors[0]), ft_getRed(colors[1]), (float)percent);
	green = get_light(ft_getGreen(colors[0]), ft_getGreen(colors[1]), (float)percent);
    blue = get_light(ft_getBlue(colors[0]), ft_getBlue(colors[1]), (float)percent);
	return ((red << 16) | (green << 8) | blue);
}