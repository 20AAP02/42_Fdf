#include <fdf.h>

int iso(int x, int y, int z, int check)
{
    int previous_x;
    int previous_y;

    previous_x = x;
    previous_y = y;
    x = (previous_x - previous_y) * cos(0.523599);
    y = -z + (previous_x + previous_y) * sin(0.523599);
    if (check)
        return (y);
    return (x);
}



void    ft_draw_H_lines(void *mlx, t_img *img, t_map *map_inf)
{
    int     y;
    int     x;
    t_ln    line;
    t_pt    a;
    t_pt    b;
    int     z;
    int     range;

    map_inf->pt_dist = ft_calculate_pt_dist(map_inf->width, img->width, map_inf->height, img->height);
    map_inf->pt_dist = 1;
    y = 0;
    while (y < map_inf->height)
    {
        x = 0;
        while (x < map_inf->width - 1)
        {
            z = map_inf->map[y][x].altitude;
            range = map_inf->range[1] - map_inf->range[0];
            a.x = (iso(x, y, z, 0) * map_inf->pt_dist) + (map_inf->pt_dist * range);
            a.y = (iso(x, y, z, 1) * map_inf->pt_dist) + (map_inf->pt_dist * range);
            b.x = (iso(x + 1, y, z, 0) * map_inf->pt_dist) + (map_inf->pt_dist * range);
            line = ft_init_line(a.x, a.y, b.x, a.y);
            line.colors[0] = map_inf->map[y][x].color;
            line.colors[1] = map_inf->map[y][x + 1].color;
            if (a.x < img->width && b.x < img->width && a.y < img->height)
                ft_draw_line(mlx, img, line);
            x++;
        }
        y++;
    }
}

void    ft_draw_V_lines(void *mlx, t_img *img, t_map *map_inf)
{
    int     y;
    int     x;
    t_ln    line;
    t_pt    a;
    t_pt    b;
    int     z;
    int     range;

    map_inf->pt_dist = ft_calculate_pt_dist(map_inf->width, img->width, map_inf->height, img->height);
    map_inf->pt_dist = 1;
    y = 0;
    while (y < map_inf->height - 1)
    {
        x = 0;
        while (x < map_inf->width)
        {
            z = map_inf->map[y][x].altitude;
            range = map_inf->range[1] - map_inf->range[0];
            a.x = (iso(x, y, z, 0) * map_inf->pt_dist) + (map_inf->pt_dist * range);
            a.y = (iso(x, y, z, 1) * map_inf->pt_dist) + (map_inf->pt_dist * range);
            b.y = (iso(x, y + 1, z, 1) * map_inf->pt_dist) + (map_inf->pt_dist * range);
            line = ft_init_line(a.x, a.y, a.x, b.y);
            line.colors[0] = map_inf->map[y][x].color;
            line.colors[1] = map_inf->map[y + 1][x].color;
            if (a.x < img->width && a.y < img->height && b.y < img->height)
                ft_draw_line(mlx, img, line);
            x++;
        }
        y++;
    }
}