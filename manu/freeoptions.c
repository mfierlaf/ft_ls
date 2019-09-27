/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeoptions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:06:12 by tde-brit          #+#    #+#             */
/*   Updated: 2019/09/26 13:06:33 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void freeoptions(t_stock	*stock, int l)
{
	if (l == 1)
	{
		ft_strdel(&(stock->actueln->actuelf->options->right));
		ft_strdel(&(stock->actueln->actuelf->options->owner));
		ft_strdel(&(stock->actueln->actuelf->options->group));
		ft_strdel(&(stock->actueln->actuelf->options->htime));
		ft_strdel(&(stock->actueln->actuelf->options->pathname));
		ft_strdel(&(stock->actueln->actuelf->options->path));
		ft_strdel(&(stock->actueln->actuelf->options->file));
		free(stock->actueln->actuelf->options);
	}
	else
	{
		ft_strdel(&(stock->actueln->actuelf->options->file));
		free(stock->actueln->actuelf->options);
	}
}
