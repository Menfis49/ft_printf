/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <vazra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:53:26 by vazra             #+#    #+#             */
/*   Updated: 2021/02/01 15:57:42 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_convert_int(t_struct *tab)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (tab->str[tab->k] == 'u')
		tab->s = ft_itoa_unsigned(va_arg(tab->va, unsigned int), tab);
	else
		tab->s = ft_itoa_pf(va_arg(tab->va, int), tab);
	if (tab->s == NULL)
		return ;
	if (tab->point && ft_strlen_pf(tab->s) < tab->point_len)
		tab->len = tab->point_len;
	else
		tab->len = ft_strlen_pf(tab->s);
	if (tab->point && tab->point_len == 0 && tab->s[0] == '0' && tab->s[1] == '\0')
	{
		tab->s[0] = '\0';
		if (tab->width_len > 0)
			i--;
	}
	if (tab->width && tab->point && tab->width_len > tab->point_len && ft_strlen_pf(tab->s) <= tab->point_len && tab->s[0] == '-')
		i++;
	while (tab->zero == ' ' && tab->width && i < tab->width_len - tab->len && !tab->dash)
	{
		ft_putchar_pf(tab->zero, tab);
		i++;
	}
	while (tab->zero == '0' && tab->point && tab->width && i < tab->width_len - tab->len && !tab->dash && tab->point_len < 0)
	{
		ft_putchar_pf('0', tab);
		i++;
	}
	while (tab->zero == '0' && tab->point && tab->width && i < tab->width_len - tab->len && !tab->dash)
	{
		ft_putchar_pf(' ', tab);
		i++;
	}
	if (tab->s[j] == '-')
	{
		ft_putchar_pf('-', tab);
		j++;
		k = -1;
	}
	while (tab->zero == '0' && tab->width && i < (tab->width_len - tab->len) && !tab->dash)
	{
		ft_putchar_pf(tab->zero, tab);
		i++;
	}
	while (tab->point && k < tab->point_len - ft_strlen_pf(tab->s))
	{
		ft_putchar_pf('0', tab);
		k++;
	}
	while (j < ft_strlen_pf(tab->s))
		ft_putchar_pf(tab->s[j++], tab);
	while (tab->width && i < tab->width_len - tab->len && tab->dash)
	{
		ft_putchar_pf(' ', tab);
		i++;
	}
	free(tab->s);
}
