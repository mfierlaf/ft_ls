/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:34:56 by mfierlaf          #+#    #+#             */
/*   Updated: 2019/09/27 18:35:06 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void print(t_stock *stock)
{
if (stock->o_l == 1 && stock->actueln->max_nblink != 0)
	ft_printf("total %d\n", stock->actueln->total);
while (stock->actueln->actuelf->suivant != NULL)
{
	if (stock->o_l == 1)
		print_l(stock);
	else if (stock->o_a == 1 && stock->actueln->actuelf->options->file[0] != '\0')
		ft_printf("%s\n", stock->actueln->actuelf->options->file);
	else if (stock->actueln->actuelf->options->file[0] != '.' &&
			stock->actueln->actuelf->options->file[0] != '\0')
		ft_printf("%s\n", stock->actueln->actuelf->options->file);
	stock->actueln->actuelf = stock->actueln->actuelf->suivant;
}
if (stock->o_a == 1 && stock->o_t == 1 &&
	stock->o_r == 1 && stock->o_l == 0)
	ft_printf(".\n");
}
