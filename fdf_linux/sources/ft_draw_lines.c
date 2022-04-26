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

t_pt ft_lowest_pt(t_map *map_inf, int comp)
{
    int     y;
    int     x;
    int     z;
    t_pt    a;
    t_pt    low_pt;

    y = 0;
    while (y < map_inf->height)
    {
        x = 0;
        while (x < map_inf->width)
        {
            z = map_inf->map[y][x].altitude;
            a.x = iso(x, y, z, 0) + comp;
            a.y = iso(x, y, z, 1) + comp;
            if (x == 0 && y == 0)
                low_pt = a;
            else if ((low_pt.x > a.x && low_pt.y > a.x) || (low_pt.x > a.y && low_pt.y > a.y))
                low_pt = a;
            x++;
        }
        y++;
    }
    return (low_pt);
}

int ft_pt_compensation(t_map *map_inf)
{
    int comp;

    comp = 1;
    while (ft_lowest_pt(map_inf, comp).x < 0 || ft_lowest_pt(map_inf, comp).y < 0)
    {
        printf("comp - %i\n", comp);
        comp++;
    }

    return (comp);
}



void    ft_draw_H_lines(void *mlx, t_img *img, t_map *map_inf)
{
    int     y;
    int     x;
    t_ln    line;
    t_pt    a;
    t_pt    b;
    int     z;
    int     comp;

    comp = ft_pt_compensation(map_inf);
    y = 0;
    while (y < map_inf->height)
    {
        x = 0;
        while (x < map_inf->width - 1)
        {
            z = map_inf->map[y][x].altitude;
            a.x = iso(x, y, z, 0) + comp;
            a.y = iso(x, y, z, 1) + comp;
            b.x = iso(x + 1, y, z, 0) + comp;
            line = ft_init_line(a.x, a.y, b.x, a.y);
            line.colors[0] = map_inf->map[y][x].color;
            line.colors[1] = map_inf->map[y][x + 1].color;
            if (a.x < img->width && b.x < img->width && a.y < img->height)
                if (a.x >= 0 && b.x >= 0 && a.y >= 0)
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
    int     comp;

    comp = ft_pt_compensation(map_inf);
    y = 0;
    while (y < map_inf->height - 1)
    {
        x = 0;
        while (x < map_inf->width)
        {
            z = map_inf->map[y][x].altitude;
            a.x = iso(x, y, z, 0) + comp;
            a.y = iso(x, y, z, 1) + comp;
            b.y = iso(x, y + 1, z, 1) + comp;
            line = ft_init_line(a.x, a.y, a.x, b.y);
            line.colors[0] = map_inf->map[y][x].color;
            line.colors[1] = map_inf->map[y + 1][x].color;
            if (a.x < img->width && a.y < img->height && b.y < img->height)
                if (a.x >= 0 && a.y >= 0 && b.y >= 0)
                    ft_draw_line(mlx, img, line);
            x++;
        }
        y++;
    }
}