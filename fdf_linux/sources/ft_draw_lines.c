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

int ft_lowest_y(t_map *map_inf, int comp)
{
    int     y;
    int     x;
    int     z;
    int     y_3d;
    int     low_y;

    y = 0;
    low_y = 0;
    while (y < map_inf->height)
    {
        x = 0;
        while (x < map_inf->width)
        {
            z = map_inf->map[y][x].altitude;
            y_3d = iso(x, y, z, 1) + comp;
            if (y == 0)
                low_y = y_3d;
            else if (low_y > y_3d)
                low_y = y_3d;
            x++;
        }
        y++;
    }
    return (low_y);
}

int ft_lowest_x(t_map *map_inf, int comp)
{
    int     y;
    int     x;
    int     z;
    int     x_3d;
    int     low_x;

    y = 0;
    low_x = 0;
    while (y < map_inf->height)
    {
        x = 0;
        while (x < map_inf->width)
        {
            z = map_inf->map[y][x].altitude;
            x_3d = iso(x, y, z, 0) + comp;
            if (y == 0)
                low_x = x_3d;
            else if (low_x > x_3d)
                low_x = x_3d;
            x++;
        }
        y++;
    }
    return (low_x);
}

int ft_pt_compensate_x(t_map *map_inf)
{
    int comp;

    comp = 0;
    while (ft_lowest_x(map_inf, comp) < 0)
    {
        printf("comp - %i\n", comp);
        comp++;
    }

    return (comp);
}

int ft_pt_compensate_y(t_map *map_inf)
{
    int comp;

    comp = 0;
    while (ft_lowest_y(map_inf, comp) < 0)
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
    int     comp_x;
    int     comp_y;

    comp_x = ft_pt_compensate_x(map_inf);
    comp_y = ft_pt_compensate_y(map_inf);
    y = 0;
    while (y < map_inf->height)
    {
        x = 0;
        while (x < map_inf->width - 1)
        {
            z = map_inf->map[y][x].altitude;
            a.x = iso(x, y, z, 0) + comp_x;
            a.y = iso(x, y, z, 1) + comp_y;
            b.x = iso(x + 1, y, z, 0) + comp_x;
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
    int     comp_x;
    int     comp_y;

    comp_x = ft_pt_compensate_x(map_inf);
    comp_y = ft_pt_compensate_y(map_inf);
    y = 0;
    while (y < map_inf->height - 1)
    {
        x = 0;
        while (x < map_inf->width)
        {
            z = map_inf->map[y][x].altitude;
            a.x = iso(x, y, z, 0) + comp_x;
            a.y = iso(x, y, z, 1) + comp_y;
            b.y = iso(x, y + 1, z, 1) + comp_y;
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