/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:12:06 by amaria-m          #+#    #+#             */
/*   Updated: 2021/11/05 11:12:06 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "../ft_printf/ft_printf.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	index;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if (ptr[index] == (unsigned char)c)
			return (ptr + index);
		index++;
	}
	return (NULL);
}
