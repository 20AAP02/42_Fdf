/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:20:53 by amaria-m          #+#    #+#             */
/*   Updated: 2021/12/03 18:29:22 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_itoa(int n)
{
	char		*str;
	long long	nb;
	int			i;

	nb = n;
	i = number_of_digits(nb);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	str[i--] = 0;
	if (nb < 0)
		nb *= -1;
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	pass_int_to_str(&nb, str, &i);
	return (str);
}

char	*ft_printf_itoa_unsigned_int(unsigned int n)
{
	char		*str;
	long long	nb;
	int			i;

	nb = n;
	i = number_of_digits(nb);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	str[i--] = 0;
	if (nb < 0)
		nb *= -1;
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	pass_int_to_str(&nb, str, &i);
	return (str);
}

t_settings	*ft_initialise_tab(t_settings *tab)
{
	tab->hash = 0;
	tab->zero = 0;
	tab->dash = 0;
	tab->space = 0;
	tab->plus = 0;
	tab->width = 0;
	tab->prec = 0;
	tab->point = 0;
	tab->t_length = 0;
	return (tab);
}

t_settings	*set_tab(t_settings *tab)
{
	int	i;

	i = tab->t_length;
	ft_initialise_tab(tab);
	tab->t_length = i;
	return (tab);
}

void	ft_print_padding(t_settings *tab, char pad, int times)
{
	int	i;

	i = -1;
	while (++i < times)
		tab->t_length += write(1, &pad, 1);
}
