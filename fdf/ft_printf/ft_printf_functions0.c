/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions0.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:20:03 by amaria-m          #+#    #+#             */
/*   Updated: 2021/12/03 18:29:22 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_printf_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	index;

	if (!s)
		return (NULL);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	index = 0;
	while (index < len && s[start + index])
	{
		ptr[index] = s[start + index];
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}

int	ft_printf_atoi(const char *str)
{
	int	number;
	int	sign;

	sign = 1;
	number = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		number = (number * 10) + (*str - 48);
		str++;
	}
	return (number * sign);
}

int	number_of_digits(long long nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		nb *= -1;
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void	pass_int_to_str(long long *nb, char *str, int *i)
{
	while (*nb > 0)
	{
		str[*i] = (*nb % 10) + 48;
		*nb /= 10;
		*i -= 1;
	}
}
