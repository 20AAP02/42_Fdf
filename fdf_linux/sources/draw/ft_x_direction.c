#include <fdf.h>

int ft_x_direction(t_pt a, t_pt b)
{
	if (b.x > a.x)
		return (1);
	else
		return (-1);
}
