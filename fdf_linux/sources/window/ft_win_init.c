#include <fdf.h>

void    ft_win_init(t_winInf *info)
{
    info->mlx = mlx_init();
	info->img.height = 1000;
	info->img.width = 1000;
	info->win = mlx_new_window(info->mlx, 1000, 1000, "Map Generator");
	info->img.img_ptr = mlx_new_image(info->mlx, info->img.width, info->img.height);
	info->img.buffer = mlx_get_data_addr(info->img.img_ptr, &info->img.pixel_bits, &info->img.line_bytes, &info->img.endian);
}