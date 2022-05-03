/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:53:22 by amaria-m          #+#    #+#             */
/*   Updated: 2022/04/30 17:53:24 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int	ft_hex_ch_to_dec(char a)
{
	if (a == 'a' || a == 'A')
		return (10);
	else if (a == 'b' || a == 'B')
		return (11);
	else if (a == 'c' || a == 'C')
		return (12);
	else if (a == 'd' || a == 'D')
		return (13);
	else if (a == 'e' || a == 'E')
		return (14);
	else if (a == 'f' || a == 'F')
		return (15);
	else
		return (a - 48);
}

int	ft_hexstr_toint(char *str)
{
	int	n;
	int	i;

	while (*str && *str != 'x' && *str != 'X')
		str++;
	if (*str == 'x' || *str == 'X')
		str++;
	i = ft_strlen(str) - 1;
	n = 0;
	while (*str)
	{
		n += ft_hex_ch_to_dec(*str) * ft_recursive_power(16, i);
		i--;
		str++;
	}
	return (n);
}
