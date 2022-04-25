#include <fdf.h>

void    ft_draw_H_lines(void *mlx, t_img *img, t_map *map_inf)
{
    int     y;
    int     x;
    t_ln    line;
    t_pt    a;
    t_pt    b;

    map_inf->pt_dist = ft_calculate_pt_dist(map_inf->width, img->width, map_inf->height, img->height);
    y = 0;
    while (y < map_inf->height)
    {
        x = 0;
        while (x < map_inf->width - 1)
        {
            a.x = (x * map_inf->pt_dist);
            a.y = (y * map_inf->pt_dist);
            b.x = ((x + 1) * map_inf->pt_dist);
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

    map_inf->pt_dist = ft_calculate_pt_dist(map_inf->width, img->width, map_inf->height, img->height);
    y = 0;
    while (y < map_inf->height - 1)
    {
        x = 0;
        while (x < map_inf->width)
        {
            a.x = (x * map_inf->pt_dist);
            a.y = (y * map_inf->pt_dist);
            b.y = ((y + 1) * map_inf->pt_dist);
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