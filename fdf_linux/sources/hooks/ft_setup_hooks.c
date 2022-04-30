#include <fdf.h>

void	ft_setup_hooks(t_img *img, void *mlx, void *win, t_map *map_inf)
{
	t_inf	*info;

	info = malloc(sizeof(t_inf));
	info->img = img;
	info->mlx = mlx;
	info->win = win;
	info->map_inf = map_inf;
	mlx_hook(win, 17, 1L<<17, ft_close, info);
	mlx_hook(win, 2, 1L<<0, ft_key_press, info);
}