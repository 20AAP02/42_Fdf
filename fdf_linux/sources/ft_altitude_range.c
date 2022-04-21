#include <fdf.h>

void	ft_altitude_range(t_map *map_inf)
{
	int	x;
	int	y;
	int	min;
	int	max;

	y = 0;
	min = 0;
	max = 0;
	while (map_inf->map[y])
	{
		x = 0;
		while (x < map_inf->width)
		{
			if (x == 0 && y == 0)
			{
				min = map_inf->map[y][x].altitude;
				max = map_inf->map[y][x].altitude;
			}
			else if (map_inf->map[y][x].altitude < min)
				min = map_inf->map[y][x].altitude;
			else if (map_inf->map[y][x].altitude > max)
				max = map_inf->map[y][x].altitude;
			x++;
		}
		y++;
	}
	map_inf->range[0] = min;
	map_inf->range[1] = max;
}