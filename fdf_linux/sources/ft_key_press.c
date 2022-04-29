#include <fdf.h>

# define ESC 53 // -> click 5
# define KEY_Z 122 // -> mac(6) linux(122)
# define KEY_X 120 // -> mac(7) linux(122)
# define KEY_PLUS 69
# define KEY_MINUS 27

int	ft_key_press(int keycode, t_inf *info)
{
	if (keycode == ESC)
	{
		ft_free_map(info->map_inf);
		free(info);
		exit(0);
	}
	if (keycode == KEY_Z || keycode == KEY_X)
	{
		if (keycode == KEY_Z)
			info->map_inf->scale += 1;
		else
			info->map_inf->scale -= 1;
		ft_draw_map(info->map_inf, info->mlx, info->win, info->img);
		return (0);
	}
	return (0);
}
