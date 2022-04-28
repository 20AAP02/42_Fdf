#include <fdf.h>

void	ft_draw_map(t_map *map_inf)
{
	int	color_check;
	int	x;
	int	y;

	ft_altitude_range(map_inf);
	color_check = ft_map_color_check(map_inf);
	y = 0;
	while (y < map_inf->height)
	{
		x = 0;
		while (x < map_inf->width)
		{
			if (map_inf->map[y][x].color == 0 && color_check)
				map_inf->map[y][x].color = ft_color_mixer(map_inf->range, map_inf->map[y][x].altitude);
			else if (map_inf->map[y][x].color == 0)
				map_inf->map[y][x].color = 0xFFFFFF;
			x++;
		}
		y++;
	}
}