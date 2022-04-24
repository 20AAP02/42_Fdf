#include <fdf.h>

int	ft_linear_gradient(int colors[2], int altitude, int range[2])
{
	float	slope;
	float	b;
	int		y;

	slope = ((float)colors[1] - (float)colors[0]) / ((float)range[1] - (float)range[0]);
	b = (float)colors[0] - (slope * (float)range[0]);
	y = (int)((slope * (float)altitude) + b);

	return (y);
}