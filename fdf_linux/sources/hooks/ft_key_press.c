#include <fdf.h>

// xev | awk -F'[ )]+' '/^KeyPress/ { a[NR+2] } NR in a { printf "%-3s %s\n", $5, $8 }'

int	ft_key_press(int keycode, t_inf *info)
{
	if (keycode == ESC)
	{
		ft_free_map(info->map_inf);
		free(info);
		exit(0);
	}
	if (keycode == KEY_Z || keycode == KEY_X)
	{
		if (keycode == KEY_Z)
			info->map_inf->scale += 1;
		else
			info->map_inf->scale -= 1;
		ft_draw_map(info->map_inf, info->mlx, info->win, info->img);
		return (0);
	}
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
	{
		if (keycode == KEY_PLUS)
			info->map_inf->zoom += 1;
		else
			info->map_inf->zoom -= 1;
		ft_draw_map(info->map_inf, info->mlx, info->win, info->img);
		return (0);
	}
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT || keycode == KEY_DOWN || keycode == KEY_UP)
	{
		if (keycode == KEY_LEFT)
			info->map_inf->move_x -= 10;
		else if (keycode == KEY_RIGHT)
			info->map_inf->move_x += 10;
		else if (keycode == KEY_DOWN)
			info->map_inf->move_y += 10;
		else if (keycode == KEY_UP)
			info->map_inf->move_y -= 10;
		ft_draw_map(info->map_inf, info->mlx, info->win, info->img);
		return (0);
	}
	if (keycode == KEY_SPACE)
	{
		if (info->map_inf->color_check)
			info->map_inf->color_check = 0;
		else
			info->map_inf->color_check = 1;
		ft_color_map(info->map_inf);
		ft_draw_map(info->map_inf, info->mlx, info->win, info->img);
	}
	if (keycode == KEY_B)
	{
		if (info->map_inf->color_check)
		{
			info->map_inf->color_check = 0;
		}
		else if (info->map_inf->colors[0] != BLACK)
		{
			info->map_inf->colors[0] = BLACK;
			info->map_inf->colors[1] = WHITE;
		}
		else
		{
			info->map_inf->colors[0] = GREEN;
			info->map_inf->colors[1] = BROWN;
		}
		ft_color_map(info->map_inf);
		ft_draw_map(info->map_inf, info->mlx, info->win, info->img);
	}
	return (0);
}
