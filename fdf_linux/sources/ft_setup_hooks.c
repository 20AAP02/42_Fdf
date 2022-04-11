#include <fdf.h>

void	ft_setup_hooks(t_inf *info)
{
	mlx_hook(info->win, 17, 0, ft_close, info);
}