/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <vazra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:53:37 by vazra             #+#    #+#             */
/*   Updated: 2021/02/01 13:04:45 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_adr_put(unsigned long nb, t_struct *tab)
{
	char *base;

	base = "0123456789abcdef";
	if (nb >= 16)
		ft_adr_put(nb / 16, tab);
	ft_putchar_pf(base[nb % 16], tab);
}

void	ft_adr_len(unsigned long nb, t_struct *tab)
{
	if (nb >= 16)
		ft_adr_len(nb / 16, tab);
	tab->len++;
}

void	ft_convert_pointer(t_struct *tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	tab->p = va_arg(tab->va, unsigned long);
	ft_adr_len(tab->p, tab);
	tab->len += 2;
	if (tab->p == 0 && tab->point == 1 && (tab->dash_star == 1 || tab->point_len == 0))
		tab->len--;
	while (!tab->dash && i < tab->width_len - tab->len)
	{
		ft_putchar_pf(' ', tab);
		i++;
	}
	ft_putstr_pf("0x", tab);
	while (tab->point && j < tab->point_len - tab->len + 2)
	{
		ft_putchar_pf('0', tab);
		j++;
	}
	if (tab->p == 0 && tab->point == 1 && (tab->dash_star == 1 || tab->point_len == 0))
		;
	else
		ft_adr_put(tab->p, tab);
	while (tab->dash && i < tab->width_len - tab->len)
	{
		ft_putchar_pf(' ', tab);
		i++;
	}
}
