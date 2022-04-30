/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:55:26 by amaria-m          #+#    #+#             */
/*   Updated: 2022/04/30 18:00:14 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int argc, char **argv)
{
	t_winInf	info;

	if (argc != 2)
		return (0);
	if (ft_strnstr(argv[1] + (ft_strlen(argv[1]) - 4), ".fdf", 5) == NULL)
		return (0);
	info.map_inf = ft_read_fdf_file(argv[1]);
	if (!info.map_inf || !info.map_inf->map)
		return (0);
	ft_win_init(&info);
	info.map_inf->scale = 0;
	info.map_inf->zoom = 0;
	info.map_inf->move_x = 0;
	info.map_inf->move_y = 0;
	info.map_inf->colors[0] = GREEN;
	info.map_inf->colors[1] = BROWN;
	info.map_inf->color_check = ft_map_color_check(info.map_inf);
	info.map_inf->comp_x = ft_pt_compensate_x(info.map_inf);
	info.map_inf->comp_y = ft_pt_compensate_y(info.map_inf);
	ft_color_map(info.map_inf);
	ft_draw_map(info.map_inf, info.mlx, info.win, &info.img);
	ft_setup_hooks(&info.img, info.mlx, info.win, info.map_inf);
	mlx_loop(info.mlx);
	return (0);
}
