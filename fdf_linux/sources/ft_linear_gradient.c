#include <fdf.h>

int	ft_linear_gradient(int colors[2], int altitude, int range[2])
{
	float	slope;
	double	b;
	int		y;

	if (colors[1] - colors[0] == 0)
		return (colors[0]);
	slope = (colors[1] - colors[0]) / (range[1] - range[0]);
	b = colors[0] - (slope * range[0]);
	y = (slope * altitude) + b;

	return (y);
}