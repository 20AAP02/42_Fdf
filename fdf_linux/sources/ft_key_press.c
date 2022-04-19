#include <fdf.h>

int	ft_key_press(int keycode, t_inf info)
{
	if (keycode == ESC)
		exit(0);
	if (info.img == 0)
		return (0);
	return (0);
}