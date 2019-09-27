/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   high_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:34:45 by tde-brit          #+#    #+#             */
/*   Updated: 2019/09/23 13:35:54 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

t_stock	*high_r(t_stock *stock)
{
	stock->tmpn = stock->actueln;
	if (stock->lastn != NULL)
		stock->actueln = stock->lastn;
	stock->actueln->suivant = list_init('o', stock);
	stock->actueln->suivant->name = ft_strjoin_free(stock->tmpn->name,
			ft_strjoin("/", stock->tmpn->actuelf->options->file), 2);
	stock->lastn = stock->actueln->suivant;
	stock->actueln = stock->tmpn;
	return (stock);
}
