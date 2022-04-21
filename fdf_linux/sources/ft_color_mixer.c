#include <fdf.h>

#define COLOR_0 0x275e00
#define COLOR_1 0x3a5e00
#define COLOR_2 0x4d5e00
#define COLOR_3 0x615f01
#define COLOR_4 0x745f01
#define COLOR_5 0x875f01

int	ft_color_mixer(int range[2], int altitude)
{
	float	slope;
	float	b;
	int		y;

	slope = (float)6 / ((float)range[1] - (float)range[0]);
	b = (float)1 - (slope * (float)range[0]);
	y = (int)((slope * (float)altitude) + b);

	if (y == 1)
		return (COLOR_5);
	else if (y == 2)
		return (COLOR_4);
	else if (y == 3)
		return (COLOR_3);
	else if (y == 4)
		return (COLOR_2);
	else if (y == 5)
		return (COLOR_1);
	else if (y == 6)
		return (COLOR_0);
	else
		return (COLOR_0);
}