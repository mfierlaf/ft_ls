/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:37:54 by tde-brit          #+#    #+#             */
/*   Updated: 2019/09/06 11:23:40 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"
static t_stock	*flag_init(t_stock *stock)
{
	stock->o_a = 0;
	stock->o_r = 0;
	stock->o_R = 0;
	stock->o_l = 0;
	stock->o_t = 0;
	return (stock);
}
int			main(int ac, char **av)
{
	t_stock		*stock;

	ac = 0;
	stock = malloc(sizeof(t_stock));
	stock = flag_init(stock);
	stock->premiern = list_init('n', stock);
	stock->actueln = stock->premiern;
	stock->i = 1;
	stock->j = 0;
	while (av[stock->i] && av[stock->i][0] == '-')
	{
		if (ft_strchr(av[stock->i], 'a'))
			stock->o_a = 1;
		if (ft_strchr(av[stock->i], 'r'))
			stock->o_r = 1;
		if (ft_strchr(av[stock->i], 'R'))
			stock->o_R = 1;
		if (ft_strchr(av[stock->i], 'l'))
			stock->o_l = 1;
		if (ft_strchr(av[stock->i], 't'))
			stock->o_t = 1;
		stock->i++;
	}
	while (av[stock->i])
	{
		stock->actueln->name = ft_strdup(av[stock->i]);
		stock->actueln->nat = 1;
		if (av[stock->i + 1])
		{
			stock->actueln->suivant = list_init('o', stock);
			stock->actueln = stock->actueln->suivant;
		}
		stock->i++;
		stock->j++;
	}
	stock->actueln = stock->premiern;
	if (stock->actueln->name[0] == '\0')
		{
			stock->actueln->name = ft_strdup(".");
			stock->actueln->nat = 1;
		}
	listing(stock);
	free(stock);
	return (0);
}
