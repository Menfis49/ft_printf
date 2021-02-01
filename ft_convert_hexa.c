/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <vazra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:53:48 by vazra             #+#    #+#             */
/*   Updated: 2021/02/01 13:51:24 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_len_hexa(int nb, t_struct *tab)
{
	long n;

	n = (long)nb;
	if (n < 0)
		n = 4294967296 + n;
	if (n >= 16)
		ft_len_hexa(n / 16, tab);
	tab->len++;
}

void	ft_put_hexa(int nb, t_struct *tab)
{
	char *base;
	long n;

	n = (long)nb;
	if (tab->str[tab->k] == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n < 0)
		n = 4294967296 + n;
	if (n >= 16)
		ft_put_hexa(n / 16, tab);
	ft_putchar_pf(base[n % 16], tab);
}

void	ft_convert_hexa(t_struct *tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	tab->num = va_arg(tab->va, int);
	ft_len_hexa(tab->num, tab);
	while (!tab->dash && j < tab->width_len - tab->point_len && j < tab->width_len - tab->len)
	{
		if (tab->zero != '0' || tab->point)
			ft_putchar_pf(' ', tab);
		else
			ft_putchar_pf('0', tab);
		j++;
	}
	while (i < tab->point_len - tab->len)
	{
		ft_putchar_pf('0', tab);
		i++;
	}
	if (tab->num == 0 && tab->point && tab->point_len == 0)
	{
		if (tab->width_len > 0)
			ft_putchar_pf(' ', tab);
	}
	else
		ft_put_hexa(tab->num, tab);
	while (tab->dash && j < tab->width_len - tab->point_len && j < tab->width_len - tab->len)
	{
		ft_putchar_pf(' ', tab);
		j++;
	}
}
