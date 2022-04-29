#include <fdf.h>

void    ft_draw_map(t_map *map_inf, void *mlx, void *win, t_img *img)
{
    ft_fill_img(mlx, img, 0x3b3a39);
	map_inf->color_check = ft_map_color_check(map_inf);
	ft_reset_altitude(map_inf);
	ft_scale_altitude(map_inf);
	ft_color_map(map_inf);
	map_inf->comp_x = ft_pt_compensate_x(map_inf);
	map_inf->comp_x += map_inf->move_x;
    map_inf->comp_y = ft_pt_compensate_y(map_inf);
	map_inf->comp_y += map_inf->move_y;
	map_inf->pt_dist = ft_calc_pt_dist(img, map_inf);
	map_inf->pt_dist += map_inf->zoom;
	ft_draw_H_lines(mlx, img, map_inf);
	ft_draw_V_lines(mlx, img, map_inf);
	if (map_inf->height > 50)
	{
		ft_draw_D_lines(mlx, img, map_inf);
		ft_draw_D2_lines(mlx, img, map_inf);
	}
	mlx_put_image_to_window(mlx, win, img->img_ptr, 0, 0);
}