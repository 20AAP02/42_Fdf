/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:22:20 by amaria-m          #+#    #+#             */
/*   Updated: 2021/12/04 22:39:48 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_exection_t(char a, char *str)
{
	*str = a;
	return (str);
}

char	*ft_nil(char *a)
{
	char	*str;
	char	*ptr;

	str = malloc(ft_pf_strlen(a) + 1);
	if (!str)
		return (NULL);
	ptr = str;
	while (*a)
		*str++ = *a++;
	*str = '\0';
	return (ptr);
}

int	ft_analise_flags(t_settings *tab, const char *format, int i)
{
	while (is_flag(format[i], "-0# +"))
	{
		if (format[i] == '-')
			tab->dash = 1;
		else if (format[i] == '0')
			tab->zero = 1;
		else if (format[i] == '#')
			tab->hash = 1;
		else if (format[i] == ' ')
			tab->space = 1;
		else if (format[i] == '+')
			tab->plus = 1;
		i++;
	}
	i = ft_analise_width(tab, format, i);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	t_settings	*tab;
	int			i;
	int			t_printed;

	tab = malloc(sizeof(t_settings));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, format);
	i = -1;
	t_printed = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_analise_flags(tab, format, i + 1);
		else
			t_printed += write(1, &format[i], 1);
	}
	va_end(tab->args);
	t_printed += tab->t_length;
	free(tab);
	return (t_printed);
}
