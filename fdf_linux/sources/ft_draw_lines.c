#include <fdf.h>

void    ft_draw_H_lines(void *mlx, t_img *img, t_map *map_inf)
{
    int     y;
    int     x;
    t_ln    line;
    t_pt    a;
    t_pt    b;

    map_inf->pt_dist = ft_calculate_pt_dist(map_inf->width, img->width, map_inf->height, img->height);
	//pt_dist = 1;
	map_inf->img_Ycenter = (img->height - (map_inf->height * map_inf->pt_dist)) / 2;
	map_inf->img_Xcenter = (img->width - (map_inf->width * map_inf->pt_dist)) / 2;

    y = 0;
    while (y < map_inf->height)
    {
        x = 0;
        while (x < map_inf->width - 1)
        {
            a.x = (x * map_inf->pt_dist) + map_inf->img_Xcenter;
            a.y = (y * map_inf->pt_dist) + map_inf->img_Ycenter;
            b.x = ((x + 1) * map_inf->pt_dist) + map_inf->img_Xcenter;
            line = ft_init_line(a.x, a.y, b.x, a.y);
            ft_draw_line(mlx, img, line, map_inf);
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
	//pt_dist = 1;
	map_inf->img_Ycenter = (img->height - (map_inf->height * map_inf->pt_dist)) / 2;
	map_inf->img_Xcenter = (img->width - (map_inf->width * map_inf->pt_dist)) / 2;

    y = 0;
    while (y < map_inf->height - 1)
    {
        x = 0;
        while (x < map_inf->width)
        {
            a.x = (x * map_inf->pt_dist) + map_inf->img_Xcenter;
            a.y = (y * map_inf->pt_dist) + map_inf->img_Ycenter;
            b.y = ((y + 1) * map_inf->pt_dist) + map_inf->img_Ycenter;
            line = ft_init_line(a.x, a.y, a.x, b.y);
            ft_draw_line(mlx, img, line, map_inf);
            x++;
        }
        y++;
    }
    printf("h: %i, w: %i\n", map_inf->height, map_inf->width);
}