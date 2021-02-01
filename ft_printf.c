/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <vazra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:50:04 by vazra             #+#    #+#             */
/*   Updated: 2021/02/01 14:56:40 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width(t_struct *tab)
{
	tab->width = 1;
	if (tab->str[tab->k] == '*')
	{
		tab->width_len = va_arg(tab->va, int);
		tab->k++;
		if (tab->width_len < 0)
		{
			tab->width_len = -tab->width_len;
			tab->dash = 1;
			tab->dash_star = 1;
		}
	}
	else
	{
		tab->width_len = ft_atoi_pf(tab->str + tab->k);
		while (tab->str[tab->k] >= '0' && tab->str[tab->k] <= '9')
			tab->k++;
	}
}

void	ft_point(t_struct *tab)
{
	tab->point = 1;
	tab->k++;
	if (tab->str[tab->k] == '*')
	{
		tab->point_len = va_arg(tab->va, int);
		tab->k++;
	}
	else if (tab->str[tab->k] == 'c')
		tab->point_len = 1;
	else
	{
		tab->point_len = ft_atoi_pf(tab->str + tab->k);
		while (tab->str[tab->k] >= '0' && tab->str[tab->k] <= '9')
			tab->k++;
	}
}

void	ft_flags(t_struct *tab)
{
	while (tab->str[tab->k] == '0' || tab->str[tab->k] == '-')
	{
		if (tab->str[tab->k] == '0')
			tab->zero = '0';
		else
			tab->dash = 1;
		tab->k++;
	}
}

void	ft_categorie(t_struct *tab)
{
	ft_init_struct(tab);
	tab->k++;
	ft_flags(tab);
	if ((tab->str[tab->k] >= '1' && tab->str[tab->k] <= '9') || tab->str[tab->k] == '*')
		ft_width(tab);
	if (tab->str[tab->k] == '.')
		ft_point(tab);
	if (tab->str[tab->k] == 'd' || tab->str[tab->k] == 'i' || tab->str[tab->k] == 'u')
		ft_convert_int(tab);
	else if (tab->str[tab->k] == 'c' || tab->str[tab->k] == 's' || tab->str[tab->k] == '%')
		ft_convert_char(tab);
	else if (tab->str[tab->k] == 'x' || tab->str[tab->k] == 'X')
		ft_convert_hexa(tab);
	else if (tab->str[tab->k] == 'p')
		ft_convert_pointer(tab);
	else if (tab->str[tab->k] == '\0')
		tab->k--;
	tab->k++;
}

int		ft_printf(const char *str, ...)
{
	t_struct tab;

	tab.k = 0;
	tab.ret = 0;
	tab.str = (char *)str;
	va_start(tab.va, str);
	while (str[tab.k])
	{
		if (str[tab.k] == '%')
			ft_categorie(&tab);
		else
		{
			write(1, &str[tab.k], 1);
			tab.ret++;
			tab.k++;
		}
	}
	va_end(tab.va);
	return (tab.ret);
}
