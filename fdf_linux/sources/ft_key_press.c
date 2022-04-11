#include <fdf.h>

int	ft_key_press(int keycode, t_inf info)
{
	printf("key_press\n");
	if (keycode)
		return (ft_close(keycode, info));
	else
		return (printf("click\n"));
}