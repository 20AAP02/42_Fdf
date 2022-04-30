#include <fdf.h>

int ft_y_direction(t_pt a, t_pt b)
{
	if (b.y > a.y)
		return (1);
	else
		return (-1);
}
