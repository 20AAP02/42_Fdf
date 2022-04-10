#include <fdf.h>

void	setup_controls(t_inf info)
{
	mlx_hook(info.win, 2, 0, ft_key_press, &info);
	mlx_hook(info.win, 17, 0, ft_close, &info);
	mlx_hook(info.win, 4, 0, ft_mouse_press, &info);
	mlx_hook(info.win, 5, 0, ft_mouse_release, &info);
	mlx_hook(info.win, 6, 0, ft_mouse_move, &info);
}