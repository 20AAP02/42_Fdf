#include <fdf.h>

void	ft_free_map(t_map *map_inf)
{
	int	i;

	i = 0;
	if (map_inf)
		if (map_inf->map)
			while (i < map_inf->height)
				free(map_inf->map[i++]);
	if (map_inf)
		if (map_inf->map)
			free(map_inf->map);
	if (map_inf)
		free(map_inf);
}