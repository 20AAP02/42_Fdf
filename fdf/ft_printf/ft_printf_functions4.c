/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:21:32 by amaria-m          #+#    #+#             */
/*   Updated: 2021/12/04 22:40:24 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_beg_str(char *str, int times, char a, int t)
{
	char	*str_mem;
	char	*ptr;
	char	*mem;

	if (t && (str[0] == '0' || str[0] == ' ') && ft_pf_strlen(str) != 1)
		return (ft_exection_t(a, str));
	str_mem = str;
	ptr = malloc(times + ft_pf_strlen(str) + 1);
	if (!ptr)
		return (NULL);
	mem = ptr;
	while (times--)
		*mem++ = a;
	while (*str)
		*mem++ = *str++;
	*mem = '\0';
	free(str_mem);
	return (ptr);
}

char	*ft_add_char_to_end_str(char *str, int times, char a)
{
	char	*str_mem;
	char	*ptr;
	char	*mem;

	str_mem = str;
	ptr = malloc(times + ft_pf_strlen(str) + 1);
	if (!ptr)
		return (NULL);
	mem = ptr;
	while (*str)
		*mem++ = *str++;
	while (times--)
		*mem++ = a;
	*mem = '\0';
	free(str_mem);
	return (ptr);
}

void	ft_print_dec_update_tab(t_settings *tab)
{
	if (tab->plus && tab->space)
		tab->space = 0;
	if (tab->zero && tab->dash)
		tab->zero = 0;
	if (tab->point && tab->zero)
		tab->zero = 0;
}

void	print_dec_num_block(t_settings *tab, char *str, int nbr)
{
	int	i;

	i = tab->width - ft_pf_strlen(str);
	if (tab->width > ft_pf_strlen(str) && tab->zero && !tab->dash)
		str = ft_add_beg_str(str, i, '0', 0);
	if (nbr < 0)
		str = ft_add_beg_str(str, 1, '-', !tab->point);
	else if (tab->plus)
		str = ft_add_beg_str(str, 1, '+', !tab->point);
	else if (tab->space)
		str = ft_add_beg_str(str, 1, ' ', 0);
	i = tab->width - ft_pf_strlen(str);
	if (tab->width > ft_pf_strlen(str) && tab->dash)
		str = ft_add_char_to_end_str(str, i, ' ');
	else if (tab->width > ft_pf_strlen(str) && !tab->zero)
		str = ft_add_beg_str(str, i, ' ', 0);
	tab->t_length += write(1, str, ft_pf_strlen(str));
	free(str);
	set_tab(tab);
}

void	ft_print_dec_num(t_settings *tab)
{
	int		nbr;
	char	*str;
	int		i;

	nbr = va_arg(tab->args, int);
	if (!nbr && !tab->prec && tab->point)
	{
		str = malloc(1);
		*str = '\0';
	}
	else
		str = ft_printf_itoa(nbr);
	ft_print_dec_update_tab(tab);
	i = tab->prec - ft_pf_strlen(str);
	if (tab->prec > ft_pf_strlen(str))
		str = ft_add_beg_str(str, i, '0', 0);
	print_dec_num_block(tab, str, nbr);
}
