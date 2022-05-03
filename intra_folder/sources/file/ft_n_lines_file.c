/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_lines_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:08:51 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/02 18:08:52 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	ft_n_lines_file(char *file_name)
{
	int		fd;
	int		n;
	int		count;
	char	str[1];

	fd = open(file_name, O_RDONLY);
	count = 0;
	n = read(fd, str, sizeof(char));
	while (n != 0)
	{
		if (*str == '\n')
			count++;
		n = read(fd, str, sizeof(char));
	}
	close(fd);
	return (count);
}
