/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:17:08 by amaria-m          #+#    #+#             */
/*   Updated: 2021/11/05 11:17:08 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "../ft_printf/ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int	index;

	if (!s)
		return (NULL);
	index = 0;
	if (s[index] == (char)c)
		return ((char *)s);
	while (s[index++] != '\0')
		if (s[index] == (char)c)
			return ((char *)s + index);
	return (NULL);
}
