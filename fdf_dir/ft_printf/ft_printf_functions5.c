/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions5.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:21:42 by amaria-m          #+#    #+#             */
/*   Updated: 2021/12/04 22:50:48 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned_dec_block(t_settings *tab, char *str)
{
	tab->t_length += write(1, str, ft_pf_strlen(str));
	free(str);
	set_tab(tab);
}

void	ft_print_unsigned_dec(t_settings *tab)
{
	unsigned int	nbr;
	char			*str;

	nbr = va_arg(tab->args, unsigned int);
	if (!nbr && !tab->prec && tab->point)
	{
		str = malloc(1);
		*str = '\0';
	}
	else
		str = ft_printf_itoa_unsigned_int(nbr);
	ft_print_dec_update_tab(tab);
	if (tab->prec > ft_pf_strlen(str))
		str = ft_add_beg_str(str, tab->prec - ft_pf_strlen(str), '0', 0);
	if (tab->width > ft_pf_strlen(str) && tab->dash)
		str = ft_add_char_to_end_str(str, tab->width - ft_pf_strlen(str), ' ');
	else if (tab->width > ft_pf_strlen(str) && tab->zero)
		str = ft_add_beg_str(str, tab->width - ft_pf_strlen(str), '0', 0);
	else if (tab->width > ft_pf_strlen(str))
		str = ft_add_beg_str(str, tab->width - ft_pf_strlen(str), ' ', 0);
	print_unsigned_dec_block(tab, str);
}

char	*ft_uns_int_dec_to_hex(unsigned int i, char a)
{
	char	*str;
	char	*mem;

	str = malloc(ft_count_digits(i) + 1);
	if (!str)
		return (NULL);
	mem = str;
	if (a == 'x')
		mem = ft_putnbr_base(mem, i, "0123456789abcdef");
	else
		mem = ft_putnbr_base(mem, i, "0123456789ABCDEF");
	*mem = '\0';
	return (str);
}

void	print_num_hex_block(t_settings *tab, char *str, char l, int nbr)
{
	if (tab->hash && l == 'x' && nbr)
		str = ft_add_beg_str(str, 1, 'x', 0);
	else if (tab->hash && l == 'X' && nbr)
		str = ft_add_beg_str(str, 1, 'X', 0);
	if (tab->hash && nbr)
		str = ft_add_beg_str(str, 1, '0', 0);
	if (tab->width > ft_pf_strlen(str) && tab->dash)
		str = ft_add_char_to_end_str(str, tab->width - ft_pf_strlen(str), ' ');
	else if (tab->width > ft_pf_strlen(str) && !tab->zero)
		str = ft_add_beg_str(str, tab->width - ft_pf_strlen(str), ' ', 0);
	tab->t_length += write(1, str, ft_pf_strlen(str));
	free(str);
	set_tab(tab);
}

void	ft_print_num_hex(t_settings *tab, char l)
{
	unsigned int	nbr;
	char			*str;

	nbr = va_arg(tab->args, unsigned int);
	if (!nbr && !tab->prec && tab->point)
	{
		str = malloc(1);
		*str = '\0';
	}
	else
		str = ft_uns_int_dec_to_hex(nbr, l);
	ft_print_dec_update_tab(tab);
	if (tab->prec > ft_pf_strlen(str))
		str = ft_add_beg_str(str, tab->prec - ft_pf_strlen(str), '0', 0);
	if (tab->width > ft_pf_strlen(str) && tab->zero && !tab->hash)
		str = ft_add_beg_str(str, tab->width - ft_pf_strlen(str), '0', 0);
	else if (tab->width > (ft_pf_strlen(str) + 2) && tab->zero && tab->hash)
		str = ft_add_beg_str(str, tab->width - ft_pf_strlen(str) - 2, '0', 0);
	print_num_hex_block(tab, str, l, nbr);
}
