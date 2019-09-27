/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:04:19 by mfierlaf          #+#    #+#             */
/*   Updated: 2019/09/16 17:29:30 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

static	void pading_int(int max, int current)
{
	int		cpt;
	int		tmp;
	char	*l;

	l = ft_itoa(max);
	tmp = ft_strlen(l);
	ft_strdel(&l);
	l = ft_itoa(current);
	cpt = ft_strlen(l);
	ft_strdel(&l);
	while (tmp > cpt)
	{
		ft_printf(" ");
		tmp--;
	}
	ft_printf("%d", current);
}
static	void pading_char(char *max, char *current)
{
	int		cpt;
	int		tmp;

	tmp = ft_strlen(max);
	cpt = ft_strlen(current);
	ft_printf("%s", current);
	while (tmp > cpt)
	{
		ft_printf(" ");
		tmp--;
	}
}

static	void	print_l2(t_stock *stock)
{
	ft_printf("%c", stock->actueln->actuelf->options->type);
	ft_printf("%s  ", stock->actueln->actuelf->options->right);
	pading_int(stock->actueln->max_nblink, stock->actueln->actuelf->options->nb_link);
	ft_printf(" ");
	pading_char(stock->actueln->max_owner, stock->actueln->actuelf->options->owner);
	ft_printf("  ");
	pading_char(stock->actueln->max_group, stock->actueln->actuelf->options->group);
	ft_printf("  ");
	if (stock->actueln->actuelf->options->type == 'c' ||
	stock->actueln->actuelf->options->type == 'b')
	{
		pading_int(stock->actueln->max_major, stock->actueln->actuelf->options->major);
		ft_printf(", ");
		pading_int(stock->actueln->max_minor, stock->actueln->actuelf->options->minor);
	}
	else
	{
		pading_int(stock->actueln->max_size, stock->actueln->actuelf->options->size);
	}
	ft_printf(" ");
	ft_printf("%s ", stock->actueln->actuelf->options->htime);
	ft_printf("%s", stock->actueln->actuelf->options->file);
	if (stock->actueln->actuelf->options->type == 'l')
		ft_printf(" -> %s", stock->actueln->actuelf->options->pathname);
	ft_printf("\n");
}

void			print_l(t_stock *stock)
{
	if (stock->o_a == 0 && stock->actueln->actuelf->options->file[0] != '.')
	{
		print_l2(stock);
	}
	else if (stock->o_a == 1)
	{
		print_l2(stock);
	}
}
