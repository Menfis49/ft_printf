/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <vazra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:51:57 by vazra             #+#    #+#             */
/*   Updated: 2021/02/03 17:40:01 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_char2(t_struct *tab, int i, int j)
{
	if (tab->point_len < 0)
		tab->point_len = ft_strlen_pf(tab->s);
	if (tab->point && ft_strlen_pf(tab->s) > tab->point_len)
		tab->len = tab->point_len;
	else
		tab->len = ft_strlen_pf(tab->s);
	if (tab->str[tab->k] == 'c' && tab->s[0] == '\0')
		i++;
	while (tab->width && i < tab->width_len - tab->len && !tab->dash)
	{
		ft_putchar_pf(tab->zero, tab);
		i++;
	}
	while (j < tab->len)
		ft_putchar_pf(tab->s[j++], tab);
	if (tab->str[tab->k] == 'c' && tab->s[0] == '\0')
		ft_putchar_pf('\0', tab);
	while (tab->width && i < tab->width_len - tab->len && tab->dash)
	{
		ft_putchar_pf(tab->zero, tab);
		i++;
	}
}

void	ft_convert_char(t_struct *tab)
{
	char	c[2];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (tab->str[tab->k] == 's')
		tab->s = va_arg(tab->va, char *);
	if (tab->str[tab->k] == 'c')
	{
		c[0] = va_arg(tab->va, int);
		c[1] = '\0';
		tab->s = c;
	}
	if (tab->str[tab->k] == '%')
	{
		c[0] = '%';
		c[1] = '\0';
		tab->s = c;
	}
	if (tab->dash)
		tab->zero = ' ';
	if (tab->s == NULL && tab->str[tab->k] == 's')
		tab->s = "(null)";
	ft_convert_char2(tab, i, j);
}
