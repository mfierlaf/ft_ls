/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 16:32:48 by mfierlaf          #+#    #+#             */
/*   Updated: 2018/10/17 15:05:58 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*res;
	unsigned char	*origin;
	size_t			i;

	res = (unsigned char*)dst;
	origin = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		res[i] = origin[i];
		i++;
	}
	return (res);
}
