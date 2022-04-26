#include <fdf.h>

int ft_pt_compensate_x(t_map *map_inf)
{
    int comp;

    comp = 0;
    while (ft_lowest_x(map_inf, comp) < 0)
        comp++;

    return (comp);
}
