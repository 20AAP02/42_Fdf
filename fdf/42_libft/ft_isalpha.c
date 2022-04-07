/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:08:27 by amaria-m          #+#    #+#             */
/*   Updated: 2022/04/05 12:25:08 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "../ft_printf/ft_printf.h"

int	ft_isalpha(int c)
{
	if (c > 64 && c < 91)
		return (1);
	else if (c > 96 && c < 123)
		return (1);
	else
		return (0);
}
