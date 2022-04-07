/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:08:02 by amaria-m          #+#    #+#             */
/*   Updated: 2021/11/05 11:08:02 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "../ft_printf/ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	ft_memset(temp, '\0', count * size);
	return (temp);
}
