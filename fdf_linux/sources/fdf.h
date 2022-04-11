#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <math.h>
#include <libft.h>
#include <stdio.h> // printf
#include <stdlib.h> // abs

typedef struct t_image
{
	void 	*img_ptr;
	int	pixel_bits;
	int	line_bytes;
	int	endian;
	char	*buffer;
	int	width;
	int	height;
}		t_img;

typedef struct t_info
{
	void	*win;
	void	*mlx;
	t_img	*img;
}			t_inf;

typedef struct t_point
{
	int	x;
	int	y;
}		t_pt;

typedef struct t_line
{
	t_pt	a;
	t_pt	b;
}			t_ln;


void	ft_color_img_pixel(t_img *img, int pixel, int color);
void	ft_fill_img(void *mlx_ptr, t_img *img, int color);
void	ft_draw_line(void *mlx_ptr, t_img *img, t_ln line, int color);
void	ft_draw_diamond(void *mlx_ptr, t_img *img, int color);
int		ft_close(int keycode, t_inf info);
int		ft_key_press(int keycode, t_inf info);
void	setup_controls(t_inf info);
int		ft_mouse_move(int keycode, t_inf info);
int		ft_mouse_press(int keycode, t_inf info);
int		ft_mouse_release(int keycode, t_inf info);
t_ln	ft_init_line(int x0, int y0, int x1, int y1);

#endif