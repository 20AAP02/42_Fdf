#include <fdf.h>

int	ft_close(t_inf *info)
{
	ft_free_map(info->map_inf);
	free(info);
	exit(0);
	return (0);
}
