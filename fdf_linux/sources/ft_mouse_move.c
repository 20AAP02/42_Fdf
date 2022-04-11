#include <fdf.h>

int	ft_mouse_move(int keycode, t_inf info)
{
	printf("mouse_move\n");
	if (keycode)
		return (ft_close(keycode, info));
	else
		return (printf("move\n"));
}