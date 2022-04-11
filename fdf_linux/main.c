#include <fdf.h>

int	main(void)
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_inf	*info;


	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "Map Generator");
	img.height = 1000;
	img.width = 1000;
	img.img_ptr = mlx_new_image(mlx, img.width, img.height);
	img.buffer = mlx_get_data_addr(img.img_ptr, &img.pixel_bits, &img.line_bytes, &img.endian);
	ft_fill_img(mlx, &img, 0x3a3d42);
	ft_draw_diamond(mlx, &img, 0xFFFF);
	mlx_put_image_to_window(mlx, win, img.img_ptr, 0, 0);
	info = malloc(sizeof(t_inf));
	info->img = &img;
	info->mlx = mlx;
	info->win = win;
	ft_setup_hooks(info);
	free(info);
	mlx_loop(mlx);
	return (0);
}