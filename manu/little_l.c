/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:11:13 by mfierlaf          #+#    #+#             */
/*   Updated: 2019/09/16 15:15:48 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"
static char	type(t_stock *stock)
{
	if (stock->actueln->actuelf->options->d_type == DT_BLK)
		return ('b');
	else if (stock->actueln->actuelf->options->d_type == DT_CHR)
		return ('c');
	else if (stock->actueln->actuelf->options->d_type == DT_DIR)
		return ('d');
	else if (stock->actueln->actuelf->options->d_type == DT_SOCK)
		return ('s');
	else if (stock->actueln->actuelf->options->d_type == DT_FIFO)
		return ('p');
	else if (stock->actueln->actuelf->options->d_type == DT_REG)
		return ('-');
	else if (stock->actueln->actuelf->options->d_type == DT_LNK)
		return ('l');
	return (0);
}
static t_stock	*permision(t_stock *stock)
{
	int cpt;

	cpt = 6;
	stock->i = 2;
	if ((stock->actueln->actuelf->options->right = ft_strnew(10)) == NULL)
		return (NULL);
	stock->actueln->actuelf->options->right[9] = '\0';
	while (stock->i < 5)
	{
		if (stock->buf.st_mode % 8 == 1 || stock->buf.st_mode % 8 == 3 ||
			stock->buf.st_mode % 8 == 5 || stock->buf.st_mode % 8 == 7)
			stock->actueln->actuelf->options->right[cpt + 2] = 'x';
		if (stock->buf.st_mode % 8 == 2 || stock->buf.st_mode % 8 == 3
			|| stock->buf.st_mode % 8 == 6 || stock->buf.st_mode % 8 == 7)
			stock->actueln->actuelf->options->right[cpt + 1] = 'w';
		if (stock->buf.st_mode % 8 == 4 || stock->buf.st_mode % 8 == 5
			|| stock->buf.st_mode % 8 == 6 || stock->buf.st_mode % 8 == 7)
			stock->actueln->actuelf->options->right[cpt] = 'r';
		if (stock->actueln->actuelf->options->right[cpt] != 'r')
			stock->actueln->actuelf->options->right[cpt] = '-';
		if (stock->actueln->actuelf->options->right[cpt + 1] != 'w')
			stock->actueln->actuelf->options->right[cpt + 1] = '-';
		if (stock->actueln->actuelf->options->right[cpt + 2] != 'x')
			stock->actueln->actuelf->options->right[cpt + 2] = '-';
		stock->buf.st_mode /= 8;
		cpt -= 3;
		stock->i++;
	}
	return (stock);
}

static t_stock *size(t_stock	*stock)
{
	struct	passwd	*pwd;
	struct	group		*grp;
	char						*tmp;
	char						*tmp2;
	time_t					today;

	time(&today);
	stock->actueln->actuelf->options->pathname = ft_strnew(stock->buf.st_size + 1);
	if ((pwd = getpwuid(stock->buf.st_uid)) == NULL)
		stock->actueln->actuelf->options->owner = ft_itoa(stock->buf.st_uid);
	else
		stock->actueln->actuelf->options->owner = ft_strdup(pwd->pw_name);
	if ((grp = getgrgid(stock->buf.st_gid)) == NULL)
		stock->actueln->actuelf->options->group = ft_itoa(stock->buf.st_gid);
	else
		stock->actueln->actuelf->options->group = ft_strdup(grp->gr_name);
	if (stock->o_a == 0 && stock->actueln->actuelf->options->file[0] != '.')
		stock->actueln->total += stock->buf.st_blocks;
	else if (stock->o_a == 1)
		stock->actueln->total += stock->buf.st_blocks;
	stock->actueln->actuelf->options->nb_link = stock->buf.st_nlink;
	if (stock->actueln->actuelf->options->nb_link > stock->actueln->max_nblink)
		stock->actueln->max_nblink = stock->actueln->actuelf->options->nb_link;

	if (ft_strlen(stock->actueln->actuelf->options->owner) >
	ft_strlen(stock->actueln->max_owner))
		{
			ft_strdel(&stock->actueln->max_owner);
			stock->actueln->max_owner = ft_strdup(stock->actueln->actuelf->options->owner);
		}

	if (ft_strlen(stock->actueln->actuelf->options->group) >
	ft_strlen(stock->actueln->max_group))
		{
			ft_strdel(&stock->actueln->max_group);
			stock->actueln->max_group = ft_strdup(stock->actueln->actuelf->options->group);
		}
	stock->actueln->actuelf->options->time = stock->buf.st_mtime;
	tmp = ctime(&stock->actueln->actuelf->options->time);
	if (ft_strlen(tmp) == 30)
	{
		stock->actueln->actuelf->options->htime = ft_strnew(12);
		if ((tmp2 = malloc(sizeof(char) * 7)) == NULL)
			return (NULL);
		tmp2[6] = '\0';
		stock->actueln->actuelf->options->htime = ft_strncpy(stock->actueln->actuelf->options->htime,
		&tmp[4], 6);
		tmp2 = ft_strncpy(tmp2, &tmp[23], 6);
		stock->actueln->actuelf->options->htime = ft_strjoin_free(
			stock->actueln->actuelf->options->htime, " ", 1);
		stock->actueln->actuelf->options->htime = ft_strjoin_free(
			stock->actueln->actuelf->options->htime, tmp2, 3);
	}
	else if (today - stock->actueln->actuelf->options->time >= 15724800 ||
		today - stock->actueln->actuelf->options->time < 0)
	{
		stock->actueln->actuelf->options->htime = ft_strnew(12);
		if ((tmp2 = malloc(sizeof(char) * 6)) == NULL)
			return (NULL);
		tmp2[5] = '\0';
		stock->actueln->actuelf->options->htime = ft_strncpy(stock->actueln->actuelf->options->htime,
		&tmp[4], 6);
		tmp2 = ft_strncpy(tmp2, &tmp[19], 5);
		stock->actueln->actuelf->options->htime = ft_strjoin_free(
			stock->actueln->actuelf->options->htime, " ", 1);
		stock->actueln->actuelf->options->htime = ft_strjoin_free(
			stock->actueln->actuelf->options->htime, tmp2, 3);
	}
	else
			{
				stock->actueln->actuelf->options->htime = ft_strnew(13);
				stock->actueln->actuelf->options->htime = ft_strncpy(stock->actueln->actuelf->options->htime,
				&tmp[4], 12);
		}
	ft_printf("htime = %s\n", stock->actueln->actuelf->options->htime);
	stock->actueln->actuelf->options->size = stock->buf.st_size;
	if (stock->actueln->actuelf->options->type == 'l')
		readlink(stock->actueln->actuelf->options->path, stock->actueln->actuelf->options->pathname, stock->buf.st_size + 1);
	if (stock->actueln->actuelf->options->size > stock->actueln->max_size)
		stock->actueln->max_size = stock->actueln->actuelf->options->size;
	if (stock->actueln->actuelf->options->type == 'c' ||
	stock->actueln->actuelf->options->type == 'b')
	{
		stock->actueln->actuelf->options->major = major(stock->buf.st_rdev);
		if (stock->actueln->actuelf->options->major > stock->actueln->max_major)
			stock->actueln->max_major = stock->actueln->actuelf->options->major;
		stock->actueln->actuelf->options->minor = minor(stock->buf.st_rdev);
		if (stock->actueln->actuelf->options->minor > stock->actueln->max_minor)
			stock->actueln->max_minor = stock->actueln->actuelf->options->minor;
	}
	return (stock);
}

t_stock	*little_l(t_stock	*stock)
{
	if (stock->o_a == 0 && stock->actueln->actuelf->options->file[0] == '.')
		return (stock);
	lstat(stock->actueln->actuelf->options->path, &stock->buf);
	stock->actueln->actuelf->options->type = type(stock);
	if ((stock = permision(stock)) == NULL)
		return (NULL);
	if ((stock = size(stock)) == NULL)
		return (NULL);
	return (stock);
}
