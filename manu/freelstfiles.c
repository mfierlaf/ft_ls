/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freelst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:33:14 by mfierlaf          #+#    #+#             */
/*   Updated: 2019/09/25 17:35:54 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void freelstfiles(t_stock *stock, int l)
{
	t_files	*tmp;

	stock->actueln->actuelf = stock->actueln->premierf;
	while (stock->actueln->actuelf != NULL)
	{
		tmp = stock->actueln->actuelf->suivant;
		if (stock != NULL)
			freeoptions(stock, l);
		free(stock->actueln->actuelf);
		stock->actueln->actuelf = tmp;
	}
}
