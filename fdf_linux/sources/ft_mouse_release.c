#include <fdf.h>

int	ft_mouse_release(int keycode, t_inf info)
{
	printf("mouse_release\n");
	if (keycode)
		return (ft_close(keycode, info));
	else
		return (printf("disclick\n"));
}
