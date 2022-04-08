#include <fdf.h>

int	ft_close(int keycode, t_inf info)
{
	if (keycode)
		mlx_destroy_window(info.mlx, info.win);
	else
		mlx_destroy_window(info.mlx, info.win);
	return (0);
}
