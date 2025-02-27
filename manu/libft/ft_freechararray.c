/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 13:51:33 by tde-brit          #+#    #+#             */
/*   Updated: 2018/10/28 20:02:11 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_freechararray(char **dst, int j)
{
	while (j >= 0)
	{
		free(dst[j]);
		j--;
	}
	free(dst);
	return (NULL);
}
