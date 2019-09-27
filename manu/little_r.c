/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:55:07 by tde-brit          #+#    #+#             */
/*   Updated: 2019/09/23 13:55:37 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

t_stock	*little_r(t_stock *stock)
{
	if (stock->o_r == 0)
	{
		while (stock->actueln->actuelf->suivant != NULL &&
				(ft_strcmp(stock->dp->d_name, stock->actueln->actuelf->options->file)) > 0)
			stock->actueln->actuelf = stock->actueln->actuelf->suivant;
	}
	else if (stock->o_t == 0 && stock->o_r == 1)
	{
		while (stock->actueln->actuelf->suivant != NULL &&
				(ft_strcmp(stock->dp->d_name, stock->actueln->actuelf->options->file)) < 0)
			stock->actueln->actuelf = stock->actueln->actuelf->suivant;
	}
	return (stock);
}
