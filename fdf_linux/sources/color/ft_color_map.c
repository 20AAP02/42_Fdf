#include <fdf.h>

void	ft_color_map(t_map *map_inf)
{
	int	x;
	int	y;

	ft_altitude_range(map_inf);
	y = 0;
	while (y < map_inf->height)
	{
		x = 0;
		while (x < map_inf->width)
		{
			if (map_inf->color_check)
				map_inf->map[y][x].color = ft_color_mixer(map_inf->range, map_inf->map[y][x].altitude, map_inf);
			x++;
		}
		y++;
	}
}