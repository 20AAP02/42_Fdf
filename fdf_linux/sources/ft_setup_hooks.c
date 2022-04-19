#include <fdf.h>

void	ft_setup_hooks(t_img *img, void *mlx, void *win)
{
	t_inf	*info;

	info = malloc(sizeof(t_inf));
	info->img = img;
	info->mlx = mlx;
	info->win = win;
	mlx_hook(win, 17, 0, ft_close, info);
	mlx_hook(win, 8, 0, ft_key_press, info);
	free(info);
}