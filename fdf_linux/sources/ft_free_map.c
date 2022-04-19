#include <fdf.h>

void	ft_free_map(int **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}