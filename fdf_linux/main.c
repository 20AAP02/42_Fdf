#include <fdf.h>

// "wasd" for changing camera view point
// "arrows" to change center of img
// "zx" change altitude scale
// "+ -" to zoom
int	main(int argc, char **argv)
{
	t_winInf	info;

	// read map.fdf file
	if ((argc != 2) || (ft_strnstr(argv[1] + (ft_strlen(argv[1]) - 4), ".fdf", 5) == NULL))
		return (0);
	info.map_inf = ft_read_fdf_file(argv[1]);
	if (!info.map_inf || !info.map_inf->map)
		return (0);
	// Create window and image
	ft_win_init(&info);

	// create map
	info.map_inf->scale = 0;
	info.map_inf->zoom = 0;
	info.map_inf->move_x = 0;
	info.map_inf->move_y = 0;
	info.map_inf->color_check = ft_map_color_check(info.map_inf);
	info.map_inf->comp_x = ft_pt_compensate_x(info.map_inf);
	info.map_inf->comp_y = ft_pt_compensate_y(info.map_inf);
	ft_color_map(info.map_inf);
	ft_draw_map(info.map_inf, info.mlx, info.win, &info.img);

	ft_setup_hooks(&info.img, info.mlx, info.win, info.map_inf);
	mlx_loop(info.mlx);
	return (0);
}