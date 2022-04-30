#include <fdf.h>

int ft_calc_2Pt_dist(t_pt pt1, t_pt pt2)
{
    int dx;
    int dy;

    dx = pt2.x - pt1.x;
    dy = pt2.y - pt1.y;
    dx = ft_recursive_power(dx, 2);
    dy = ft_recursive_power(dy, 2);
    dx = sqrt(dx + dy);
    return (dx);
}