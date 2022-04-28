#include <fdf.h>

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
	ft_draw_map(info.map_inf, info.mlx, info.win, &info.img);

	ft_setup_hooks(&info.img, info.mlx, info.win);
	ft_free_map(info.map_inf);
	mlx_loop(info.mlx);
	return (0);
}