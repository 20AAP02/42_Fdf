/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:17:43 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/03 16:30:23 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
//system("leaks -- fdf");
int	ft_close(t_inf *info)
{
	ft_free_map(info->map_inf);
	free(info);
	exit(0);
}
