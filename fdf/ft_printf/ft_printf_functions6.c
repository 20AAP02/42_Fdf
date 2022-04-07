/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions6.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:21:56 by amaria-m          #+#    #+#             */
/*   Updated: 2021/12/03 18:29:22 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_format(char letter, char *conversions)
{
	int	i;

	i = -1;
	while (conversions[++i])
		if (letter == conversions[i])
			return (1);
	return (0);
}

int	ft_convert(t_settings *tab, const char *format, int i)
{
	while (format[i] && !ft_is_format(format[i], "%cspdiuxX"))
		i++;
	if (format[i] == '%')
		ft_print_percent(tab, format[i]);
	else if (format[i] == 'c')
		ft_print_char(tab);
	else if (format[i] == 's')
		ft_print_string(tab);
	else if (format[i] == 'p')
		ft_print_void(tab);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_print_dec_num(tab);
	else if (format[i] == 'u')
		ft_print_unsigned_dec(tab);
	else if (format[i] == 'x')
		ft_print_num_hex(tab, 'x');
	else if (format[i] == 'X')
		ft_print_num_hex(tab, 'X');
	return (i);
}

int	ft_analise_prec(t_settings *tab, const char *format, int i)
{
	int		j;
	char	*prec;

	tab->point = 1;
	j = i;
	if (format[i] > 48 && format[i] < 58)
		while (format[i] > 47 && format[i] < 58)
			i++;
	if (j != i)
	{
		prec = ft_printf_substr(format, j, i - j);
		tab->prec = ft_printf_atoi(prec);
		free(prec);
	}
	i = ft_convert(tab, format, i);
	return (i);
}

int	ft_analise_width(t_settings *tab, const char *format, int i)
{
	int		j;
	char	*width;

	j = i;
	if (format[i] > 48 && format[i] < 58)
		while (format[i] > 47 && format[i] < 58)
			i++;
	if (j != i)
	{
		width = ft_printf_substr(format, j, i - j);
		tab->width = ft_printf_atoi(width);
		free(width);
	}
	if (format[i] == '.')
		i = ft_analise_prec(tab, format, i + 1);
	else
		i = ft_convert(tab, format, i);
	return (i);
}

int	is_flag(char letter, char *flags)
{
	int	i;

	i = -1;
	while (flags[++i])
		if (flags[i] == letter)
			return (1);
	return (0);
}
