#include <fdf.h>

#define WHITE 0xffffff;
#define BLACK 0x000000;
#define GREEN 0x275e00;
#define BROWN 0x7a500b;
#define GREEN 0x275e00;

int	ft_color_mixer(int range[2], int altitude)
{
	int	percent;
	int	dist;
	int	color[2];

	color[0] = BLACK;
	color[1] = WHITE;
	if (altitude == range[0])
		return (color[0]);
	if (altitude == range[1])
		return (color[1]);
	dist = abs(altitude - range[0]);
	percent = (dist * 100) / (range[1] - range[0]);
	return (ft_linear_gradient(color, percent));
}