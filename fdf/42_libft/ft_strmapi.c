/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:20:52 by amaria-m          #+#    #+#             */
/*   Updated: 2021/11/05 11:20:52 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "../ft_printf/ft_printf.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mod_s;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	mod_s = malloc(i + 1);
	if (!mod_s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mod_s[i] = f(i, s[i]);
		i++;
	}
	mod_s[i] = 0;
	return (mod_s);
}
