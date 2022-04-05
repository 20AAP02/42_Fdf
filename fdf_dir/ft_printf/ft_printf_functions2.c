/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:21:09 by amaria-m          #+#    #+#             */
/*   Updated: 2021/12/04 14:58:28 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_percent(t_settings *tab, char percent)
{
	tab->t_length += write(1, &percent, 1);
	set_tab(tab);
}

void	ft_print_char(t_settings *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	if (tab->width && !tab->dash)
		ft_print_padding(tab, ' ', (tab->width - 1));
	tab->t_length += write(1, &a, 1);
	if (tab->width && tab->dash)
		ft_print_padding(tab, ' ', (tab->width - 1));
	set_tab(tab);
}

void	ft_print_s_dash(t_settings *tab, const char *str)
{
	if (tab->point && tab->prec <= ft_pf_strlen(str))
	{
		tab->t_length += write(1, str, tab->prec);
		ft_print_padding(tab, ' ', (tab->width - tab->prec));
	}
	else
	{
		tab->t_length += write(1, str, ft_pf_strlen(str));
		ft_print_padding(tab, ' ', (tab->width - ft_pf_strlen(str)));
	}
}

void	ft_print_s_no_dash(t_settings *tab, const char *str)
{
	if (tab->point && tab->prec <= ft_pf_strlen(str))
	{
		ft_print_padding(tab, ' ', (tab->width - tab->prec));
		tab->t_length += write(1, str, tab->prec);
	}
	else
	{
		ft_print_padding(tab, ' ', (tab->width - ft_pf_strlen(str)));
		tab->t_length += write(1, str, ft_pf_strlen(str));
	}
}

void	ft_print_string(t_settings *tab)
{
	char	*str;

	str = va_arg(tab->args, char *);
	if (str == NULL)
	{
		tab->t_length = write(1, "(null)", 6);
	}
	else if (tab->width)
	{
		if (tab->dash)
			ft_print_s_dash(tab, str);
		else
			ft_print_s_no_dash(tab, str);
	}
	else
	{
		if (tab->point && tab->prec <= ft_pf_strlen(str))
			tab->t_length += write(1, str, tab->prec);
		else
			tab->t_length += write(1, str, ft_pf_strlen(str));
	}
	set_tab(tab);
}
