#include <fdf.h>

int	main(int argc, char **argv)
{
	t_map	*map_inf;
	void	*mlx;
	void	*win;
	t_img	img;

	// read map.fdf file
	if ((argc != 2) || (ft_strnstr(argv[1] + (ft_strlen(argv[1]) - 4), ".fdf", 5) == NULL))
		return (0);
	map_inf = ft_read_fdf_file(argv[1]);
	if (!map_inf || !map_inf->map)
		return (0);
	// Create window and such
	mlx = mlx_init();
	img.height = 1000;
	img.width = 1000;
	win = mlx_new_window(mlx, img.width, img.height, "Map Generator");
	img.img_ptr = mlx_new_image(mlx, img.width, img.height);
	img.buffer = mlx_get_data_addr(img.img_ptr, &img.pixel_bits, &img.line_bytes, &img.endian);
	ft_fill_img(mlx, &img, 0x3b3a39);
	ft_draw_map(map_inf);
	map_inf->comp_x = ft_pt_compensate_x(map_inf);
    map_inf->comp_y = ft_pt_compensate_y(map_inf);
	map_inf->pt_dist = ft_calc_pt_dist(&img, map_inf);
	ft_draw_H_lines(mlx, &img, map_inf);
	ft_draw_V_lines(mlx, &img, map_inf);
	//ft_draw_D_lines(mlx, &img, map_inf);
	//ft_draw_D2_lines(mlx, &img, map_inf);
	mlx_put_image_to_window(mlx, win, img.img_ptr, 0, 0);
	ft_setup_hooks(&img, mlx, win);
	ft_free_map(map_inf);
	mlx_loop(mlx);
	return (0);
}