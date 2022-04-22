#include <fdf.h>

void    ft_draw_H_lines(void *mlx, t_img *img, t_map *map_inf)
{
    int     y;
    int     x;
    t_ln    line;
    int     pt_dist;
    int     img_Ycenter;
    int     img_Xcenter;
    t_pt    a;
    t_pt    b;

    pt_dist = ft_calculate_pt_dist(map_inf->width, img->width, map_inf->height, img->height);
	//pt_dist = 1;
	img_Ycenter = (img->height - (map_inf->height * pt_dist)) / 2;
	img_Xcenter = (img->width - (map_inf->width * pt_dist)) / 2;

    y = 0;
    while (y < map_inf->height)
    {
        x = 0;
        while (x < map_inf->width - 1)
        {
            a.x = (x * pt_dist) + img_Xcenter;
            a.y = (y * pt_dist) + img_Ycenter;
            b.x = ((x + 1) * pt_dist) + img_Xcenter;
            line = ft_init_line(a.x, a.y, b.x, a.y);
            ft_draw_line(mlx, img, line, 0);
            x++;
        }
        y++;
    }
    
}