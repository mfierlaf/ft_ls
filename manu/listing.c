/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:45:29 by tde-brit          #+#    #+#             */
/*   Updated: 2019/09/06 15:52:15 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"
void	print_name(t_stock *stock)
{
	if (stock->o_R == 1)
	{
			ft_printf("%s:\n", stock->actueln->name);
	}
}
void listing(t_stock *stock)
{
	stock->premierf = list_init('f', stock);
	stock->actuelf = stock->premierf;
	if ((stock->dirp = opendir(stock->actueln->name)) == NULL)
	{
		ft_printf("Error : %s Folder Doesn't exist\n", stock->actueln->name);
		if (stock->actueln->suivant != NULL)
		{
			stock->actueln = stock->actueln->suivant;
			listing(stock);
		}
		return ;
	}
	print_name(stock);
	while ((stock->dp = readdir(stock->dirp)) != NULL)
	{
		if (stock->o_R == 1 && stock->dp->d_type == DT_DIR &&
				((ft_strcmp(stock->dp->d_name, "..")) != 0 &&
				 (ft_strcmp(stock->dp->d_name, ".")) != 0))
		{
			stock->tmpn = stock->actueln;
			while (stock->actueln->suivant != NULL &&
				stock->actueln->suivant->nat != 1)
				stock->actueln = stock->actueln->suivant ;
			stock->actueln->suivant = list_init('o', stock);
			stock->actueln->suivant->name = ft_strjoin(stock->tmpn->name,
				ft_strjoin("/", stock->dp->d_name));
			stock->actueln = stock->tmpn;
		}
		stock->tmpf = stock->actuelf;
		stock->actuelf = stock->premierf;
		if (stock->o_r == 0)
		{
			while (stock->actuelf->suivant != NULL &&
			(ft_strcmp(stock->dp->d_name, stock->actuelf->suivant->file)) < 0)
			stock->actuelf = stock->actuelf->suivant;
		}
		else
		{
			while (stock->actuelf->suivant != NULL &&
			(ft_strcmp(stock->dp->d_name, stock->actuelf->suivant->file)) > 0)
			stock->actuelf = stock->actuelf->suivant;
		}
		stock->actuelf = stock->tmpf;
		stock->actuelf->suivant = list_init('g', stock);
		stock->actuelf->file = stock->dp->d_name;
		stock->actuelf = stock->actuelf->suivant;
	}
	stock->actuelf = stock->premierf;
	while (stock->actuelf->suivant != NULL)
	{
		if (stock->o_a == 1)
			ft_printf("%s\n", stock->actuelf->file);
		else if (stock->actuelf->file[0] != '.')
			ft_printf("%s\n", stock->actuelf->file);
		stock->actuelf = stock->actuelf->suivant;
	}
	closedir(stock->dirp);
	if (stock->actueln->suivant != NULL)
	{
		stock->actueln = stock->actueln->suivant;
		listing(stock);
	}
	return ;
}
