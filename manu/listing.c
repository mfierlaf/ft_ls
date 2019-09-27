/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:45:29 by tde-brit          #+#    #+#             */
/*   Updated: 2019/09/26 13:08:37 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

static void	swaptime(t_option **actuel, t_option **suivant)
{
	t_option		*tmp;

	tmp = *actuel;
	*actuel = *suivant;
	*suivant = tmp;
}

static t_stock	*timesort(t_stock *stock)
{
	if (stock->o_r == 0)
	{
		while (stock->actueln->actuelf->suivant->suivant != NULL)
		{
			if (stock->actueln->actuelf->options->time <
					stock->actueln->actuelf->suivant->options->time)
					{
						swaptime(&stock->actueln->actuelf->options,
							&stock->actueln->actuelf->suivant->options);
						stock->actueln->actuelf = stock->actueln->premierf;
					}
			else
				stock->actueln->actuelf = stock->actueln->actuelf->suivant;
		}
	}
	if (stock->o_r == 1)
	{
		while (stock->actueln->actuelf->suivant->suivant != NULL)
		{
			if (stock->actueln->actuelf->options->time >
					stock->actueln->actuelf->suivant->options->time)
				{
					swaptime(&stock->actueln->actuelf->options,
						&stock->actueln->actuelf->suivant->options);
					stock->actueln->actuelf = stock->actueln->premierf;
				}
			else
					stock->actueln->actuelf = stock->actueln->actuelf->suivant;
		}
	}
	return (stock);
}

static t_stock  *option_r(t_stock *stock)
{
	while (stock->actueln->actuelf->suivant != NULL)
	{
		if (stock->o_a == 1 && stock->o_R == 1 && stock->actueln->actuelf->options->d_type == DT_DIR	&&
			((ft_strcmp(stock->actueln->actuelf->options->file, "..")) != 0 &&
			(ft_strcmp(stock->actueln->actuelf->options->file, ".")) != 0))
			stock = high_r(stock);
		else if (stock->o_a == 0 && stock->o_R == 1 &&
			stock->actueln->actuelf->options->d_type == DT_DIR && stock->actueln->actuelf->options->file[0] != '.')
			stock = high_r(stock);
	stock->actueln->actuelf = stock->actueln->actuelf->suivant;}
	return (stock);
}

static t_stock	*getname(t_stock *stock)
{
	while ((stock->dp = readdir(stock->dirp)) != NULL)
	{
		stock->actueln->actuelf = stock->actueln->premierf;
		stock = little_r(stock);
		stock->actueln->actuelf->suivant = list_init('g', stock);
		stock->actueln->actuelf->suivant->options->file = stock->actueln->actuelf->options->file;
		stock->actueln->actuelf->options->file = ft_strdup(stock->dp->d_name);
		stock->actueln->actuelf->suivant->options->d_type = stock->actueln->actuelf->options->d_type;
		stock->actueln->actuelf->options->d_type = stock->dp->d_type;
		stock->actueln->actuelf->suivant->options->path = stock->actueln->actuelf->options->path;
		stock->actueln->actuelf->options->path = ft_strjoin_free(stock->actueln->name,
				ft_strjoin("/", stock->dp->d_name), 2);
		stock->actueln->actuelf = stock->actueln->actuelf->suivant;
	}
	stock->actueln->actuelf = stock->actueln->premierf;
	return (stock);
}

void			listing(t_stock *stock)
{
	stock->actueln->premierf = list_init('f', stock);
	stock->actueln->actuelf = stock->actueln->premierf;
	if (((stock->dirp = opendir(stock->actueln->name)) == NULL))
	{
		ft_printf("Error : %s Folder Doesn't exist\n", stock->actueln->name);
		if (stock->actueln->suivant != NULL)
		{
			stock->actueln = stock->actueln->suivant;
			listing(stock);
		}
		return ;
	}
	if ((stock->o_R == 1 && stock->actueln->nat == 0) || stock->checkp >= 2)
		ft_printf("%s:\n", stock->actueln->name);
	stock = getname(stock);
	stock->actueln->actuelf = stock->actueln->premierf;
	if (stock->o_l == 1 || stock->o_t == 1)
	{
		while (stock->actueln->actuelf->suivant != NULL)
		{
			stock = little_l(stock);
			stock->actueln->actuelf = stock->actueln->actuelf->suivant;
		}
	}
	stock->actueln->actuelf = stock->actueln->premierf;
	if (stock->o_t == 1)
		stock = timesort(stock);
	stock->actueln->actuelf = stock->actueln->premierf;
	stock = option_r(stock);
	stock->actueln->actuelf = stock->actueln->premierf;
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
	closedir(stock->dirp);
	if (stock->actueln->suivant != NULL)
	{
		stock->lastn = NULL;
		ft_printf("\n");
		stock->actueln = stock->actueln->suivant;
		listing(stock);
	}
	return ;
}
