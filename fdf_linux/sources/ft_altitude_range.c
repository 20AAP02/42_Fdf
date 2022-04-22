#include <fdf.h>

void	ft_altitude_range(t_map *map_inf)
{
	int	x;
	int	y;
	int	min;
	int	max;

	y = 0;
	min = map_inf->map[0][0].altitude;
	max = map_inf->map[0][0].altitude;
	while (y < map_inf->height)
	{
		x = 0;
		while (x < map_inf->width)
		{
			if (map_inf->map[y][x].altitude < min)
				min = map_inf->map[y][x].altitude;
			if (map_inf->map[y][x].altitude > max)
				max = map_inf->map[y][x].altitude;
			x++;
		}
		y++;
	}
	map_inf->range[0] = min;
	map_inf->range[1] = max;
}