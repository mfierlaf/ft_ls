/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:34:52 by tde-brit          #+#    #+#             */
/*   Updated: 2019/09/23 13:40:35 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

static void	*list_init2(char c, t_stock *stock)
{
	t_names		*nouveaun;
	t_files		*nouveauf;

	if (c == 'o')
	{
		nouveaun = list_init('n', stock);
		if (!(stock->actueln) && stock->actueln->suivant != NULL)
		{
			nouveaun->suivant = stock->actueln->suivant;
		}
		return (nouveaun);
	}
	if (c == 'g')
	{
		nouveauf = list_init('f', stock);
		if (stock->actueln->actuelf->suivant != NULL)
			nouveauf->suivant = stock->actueln->actuelf->suivant;
		return (nouveauf);
	}
	return (NULL);
}

void		*list_init(char c, t_stock *stock)
{
	t_names		*names;
	t_files		*files;

	if (c == 'o' || c == 'g')
		return (list_init2(c, stock));
	if (c == 'n')
	{
		names = (t_names *)malloc(sizeof(t_names));
		names->name = NULL;
		names->max_size = 0;
		names->max_nblink = 0;
		names->max_major = 0;
		names->max_minor = 0;
		names->total = 0;
		names->max_owner = ft_strnew(0);
		names->max_group = ft_strnew(0);
		names->nat = 0;
		names->suivant = NULL;
		return (names);
	}
	if (c == 'f')
	{
		files = (t_files *)malloc(sizeof(t_files));
		files->options = (t_option *)malloc(sizeof(t_option));
		files->suivant = NULL;
		return (files);
	}
	return (NULL);
}
