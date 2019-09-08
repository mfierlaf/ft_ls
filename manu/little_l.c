/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:11:13 by mfierlaf          #+#    #+#             */
/*   Updated: 2019/09/08 14:49:14 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

int	permision(t_stock *stock)
{
	char *tmp;

	stock->i == 3;
	if ((tmp = malloc(sizeof(char)*6)) == NULL)
		return(-1);
	if (stock->actuelf->options->right = ft_strnew(0);
	tmp = ft_itoa(stock->buf->st_mode);
	while (stock->i < 6)
	{
		if (tmp[i] == '0')
			ft_strjoin(stock->actuelf->options->right, "---");
		else if (tmp[i] == '1')
			ft_strjoin(stock->actuelf->options->right, "--x");
		else if (tmp[i] == '2')
			ft_strjoin(stock->actuelf->options->right, "-w-");
		else if (tmp[i] == '3')
			ft_strjoin(stock->actuelf->options->right, "-wx");
		else if (tmp[i] == '4')
			ft_strjoin(stock->actuelf->options->right, "r--");
		else if (tmp[i] == '5')
			ft_strjoin(stock->actuelf->options->right, "r-x");
		else if (tmp[i] == '6')
			ft_strjoin(stock->actuelf->options->right, "rw-");
		else if (tmp[i] == '7')
			ft_strjoin(stock->actuelf->options->right, "rwx");
	}
	free(tmp);
	return (0);
}

void size(t_stock	*stock)
{
	stock->actuelf->options->nblink = stock->buf->st_nlink;
	stock->actuelf->options->size = stock->buf->st_size;
	stock->actuelf->options->owner = stock->pwd->pw_name;


}
