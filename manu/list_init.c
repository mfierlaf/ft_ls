/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:34:52 by tde-brit          #+#    #+#             */
/*   Updated: 2019/09/05 15:34:54 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"
void		*list_init(char c, t_stock *stock)
{
	if (c == 'n')
	{
		t_names		*names;

		names = malloc(sizeof(t_names));
		names->name = ft_strnew(0);
		names->nat = 0;
		names->suivant = NULL;
		return (names);
	}
	if (c == 'f')
	{
		t_files		*files;

		files = malloc(sizeof(t_files));
		files->file = ft_strnew(0);
		files->suivant = NULL;
		return (files);
	}
	if (c == 'o')
	{
		t_names *nouveau;

		nouveau = list_init('n', stock);
		if (stock->actueln->suivant != NULL)
			nouveau->suivant = stock->actueln->suivant;
		return (nouveau);
	}
	if (c == 'g')
	{
		t_files *nouveau;
		nouveau = list_init('f', stock);
		if (stock->actuelf->suivant != NULL)
			nouveau->suivant = stock->actuelf->suivant;
		return (nouveau);
	}
	return (NULL);
}
