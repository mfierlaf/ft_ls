/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freelstnames.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:58:47 by tde-brit          #+#    #+#             */
/*   Updated: 2019/09/26 13:04:30 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void	freelstnames(t_stock *stock)
{
		t_names *tmp;

		stock->actueln = stock->premiern;
		while(stock->actueln != NULL)
		{
			ft_printf("name = %s\n", stock->actueln->name);
			tmp = stock->actueln->suivant;
			ft_strdel(&(stock->actueln->max_owner));
			ft_strdel(&(stock->actueln->max_group));
			ft_strdel(&(stock->actueln->name));
			freelstfiles(stock, stock->o_l);
			free(stock->actueln);
			stock->actueln = tmp;
		}
}
