#include <fdf.h>

void    ft_reset_altitude(t_map *map_inf)
{
    int y;
    int x;

    y = 0;
    while (y < map_inf->height)
    {
        x = 0;
        while (x < map_inf->width)
        {
            map_inf->map[y][x].altitude = map_inf->map[y][x].alt2;
            x++;
        }
        y++;
    }
}
