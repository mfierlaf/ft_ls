/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:32:35 by tde-brit          #+#    #+#             */
/*   Updated: 2019/09/05 11:33:46 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"
char	type(struct dirent	*dp)
{
	if (dp->d_type == DT_BLK)
		return ('b');
	if (dp->d_type == DT_CHR)
		return ('c');
	if (dp->d_type == DT_DIR)
		return ('d');
	if (dp->d_type == DT_LNK)
		return ('l');
	if (dp->d_type == DT_SOCK)
		return ('s');
	if (dp->d_type == DT_FIFO)
		return ('p');
	if (dp->d_type == DT_REG)
		return ('-');
	return (0);
}
void	option_l(t_stock *stock)
{
	stock->opt = malloc(sizeof(t_option));
	stock->buf = malloc(sizeof(struct stat));
	lstat(stock->dp->d_name, stock->buf);
	stock->opt->type = type(stock->dp);
//	ft_printf("%c %s %d %s %s %d %s %d %d:%d %s", opt->type, );
}
