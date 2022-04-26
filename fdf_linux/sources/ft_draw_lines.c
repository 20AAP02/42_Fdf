#include <fdf.h>

void    ft_draw_H_lines(void *mlx, t_img *img, t_map *map_inf)
{
    int     y;
    int     x;
    int     z;
    t_ln    line;
    t_pt    a;
    t_pt    b;

    y = 0;
    while (y < map_inf->height)
    {
        x = 0;
        while (x < map_inf->width - 1)
        {
            z = map_inf->map[y][x].altitude;
            a.x = (iso(x, y, z, 0) + map_inf->comp_x) * map_inf->pt_dist;
            a.y = (iso(x, y, z, 1) + map_inf->comp_y) * map_inf->pt_dist;
            b.x = (iso(x + 1, y, z, 0) + map_inf->comp_x) * map_inf->pt_dist;
            line = ft_init_line(a.x, a.y, b.x, a.y);
            line.colors[0] = map_inf->map[y][x].color;
            line.colors[1] = map_inf->map[y][x + 1].color;
            if (a.x < img->width && b.x < img->width && a.y < img->height && a.x >= 0 && b.x >= 0 && a.y >= 0)
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
    int     z;
    t_ln    line;
    t_pt    a;
    t_pt    b;

    y = 0;
    while (y < map_inf->height - 1)
    {
        x = 0;
        while (x < map_inf->width)
        {
            z = map_inf->map[y][x].altitude;
            a.x = (iso(x, y, z, 0) + map_inf->comp_x) * map_inf->pt_dist;
            a.y = (iso(x, y, z, 1) + map_inf->comp_y) * map_inf->pt_dist;
            b.y = (iso(x, y + 1, z, 1) + map_inf->comp_y) * map_inf->pt_dist;
            line = ft_init_line(a.x, a.y, a.x, b.y);
            line.colors[0] = map_inf->map[y][x].color;
            line.colors[1] = map_inf->map[y + 1][x].color;
            if (a.x < img->width && a.y < img->height && b.y < img->height && a.x >= 0 && a.y >= 0 && b.y >= 0)
                ft_draw_line(mlx, img, line);
            x++;
        }
        y++;
    }
}