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

static t_stock	*flag_check(t_stock *stock, char **av)
{
	while (av[++stock->i] && av[stock->i][0] == '-' && av[stock->i][1] != '-')
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
	}
	while (av[stock->i])
	{
		stock->actueln->name = ft_strdup(av[stock->i]);
		stock->actueln->nat = 1;
		stock->actueln->types = 0;
		stock->checkp += 1;
		lstat(av[stock->i], &stock->buf);
		if (S_ISREG(stock->buf.st_mode))
			stock->actueln->types = 1;
		if (av[stock->i + 1])
		{
			stock->actueln->suivant = list_init('o', stock);
			stock->actueln = stock->actueln->suivant;
		}
		stock->i++;
	}
	return (stock);
}

int				main(int ac, char **av)
{
	t_stock		*stock;

	ac = 0;
	if ((stock = malloc(sizeof(t_stock))) == NULL)
		return (-1);
	stock = flag_init(stock);
	stock->premiern = list_init('n', stock);
	stock->actueln = stock->premiern;
	stock->i = 0;
	stock->j = 0;
	stock->checkp = 0;
	stock = flag_check(stock, av);
	stock->actueln = stock->premiern;
	if (stock->actueln->name == NULL)
	{
		stock->actueln->name = ft_strdup(".");
		stock->actueln->nat = 1;
		stock->actueln->types = 0;
	}
	if (stock->actueln->types == 0)
		listing(stock);
	else
		{
			if (stock->o_l == 1)
			{
				stock->actueln->premierf = list_init('f', stock);
				stock->actueln->actuelf = stock->actueln->premierf;
				stock->actueln->actuelf->options->path = ft_strdup(stock->actueln->name);
				stock->actueln->actuelf->options->file = ft_strdup(stock->actueln->name);
				stock = little_l(stock);
				print_l(stock);
			}
			else
				ft_printf("%s\n", stock->actueln->name);
		}
	freelstnames(stock);
	free(stock);
	return (0);
}
