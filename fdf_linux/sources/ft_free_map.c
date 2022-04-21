#include <fdf.h>

void	ft_free_map(t_map *map_inf)
{
	int	i;

	i = 0;
	while (map_inf->map[i])
		free(map_inf->map[i++]);
	free(map_inf->map);
	free(map_inf);
}