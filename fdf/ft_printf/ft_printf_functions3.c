/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:21:21 by amaria-m          #+#    #+#             */
/*   Updated: 2021/12/04 14:53:47 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_digits(unsigned long i)
{
	int	x;

	x = 1;
	while (i > 9)
	{
		i = i / 10;
		x++;
	}
	return (x);
}

char	*ft_putnbr_base(char *str, unsigned long nbr, char *base)
{
	unsigned long	base_size;
	unsigned long	x;

	base_size = ft_pf_strlen(base);
	if (nbr < base_size)
	{
		*str = base[nbr];
		str++;
	}
	else
	{
		x = nbr / base_size;
		str = ft_putnbr_base(str, x, base);
		x = nbr % base_size;
		*str = base[x];
		str++;
	}
	return (str);
}

char	*long_to_string(unsigned long i)
{
	char	*str;
	char	*mem;

	if (i != 0)
		str = malloc(ft_count_digits(i) + 3);
	else
		return (ft_nil("(nil)"));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	mem = str;
	mem += 2;
	mem = ft_putnbr_base(mem, i, "0123456789abcdef");
	*mem = '\0';
	return (str);
}

void	ft_print_p_zero_pad(t_settings *tab, char *str)
{
	char	*ptr;
	int		i;
	char	*mem;

	if (tab->width <= ft_pf_strlen(str))
		tab->t_length += write(1, str, ft_pf_strlen(str));
	else
	{
		i = 0;
		ptr = malloc(tab->width + 1);
		if (!ptr)
			return ;
		mem = ptr;
		*mem++ = '0';
		*mem++ = 'x';
		while (i++ < (tab->width - ft_pf_strlen(str)))
			*mem++ = '0';
		str += 2;
		while (*str)
			*mem++ = *str++;
		*mem = '\0';
		tab->t_length += write(1, ptr, ft_pf_strlen(ptr));
		free(ptr);
	}
}

void	ft_print_void(t_settings *tab)
{
	unsigned long	nbr;
	char			*str;

	nbr = (unsigned long)va_arg(tab->args, void *);
	str = long_to_string(nbr);
	if (tab->width && tab->dash)
	{
		tab->t_length += write(1, str, ft_pf_strlen(str));
		ft_print_padding(tab, ' ', (tab->width - ft_pf_strlen(str)));
	}
	else if (tab->width && tab->zero)
		ft_print_p_zero_pad(tab, str);
	else if (tab->width > ft_pf_strlen(str))
	{
		tab->t_length += write(1, " ", (tab->width - ft_pf_strlen(str)));
		tab->t_length += write(1, str, ft_pf_strlen(str));
	}
	else
		tab->t_length += write(1, str, ft_pf_strlen(str));
	free(str);
	set_tab(tab);
}
