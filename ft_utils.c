/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <vazra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:54:53 by vazra             #+#    #+#             */
/*   Updated: 2021/02/04 17:03:26 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_struct(t_struct *tab)
{
	tab->len = 0;
	tab->zero = ' ';
	tab->dash = 0;
	tab->dash_star = 0;
	tab->width = 0;
	tab->width_len = 0;
	tab->point = 0;
	tab->point_len = 0;
}

void	ft_putchar_pf(char c, t_struct *tab)
{
	write(1, &c, 1);
	tab->ret++;
}

void	ft_putstr_pf(char *str, t_struct *tab)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		tab->ret++;
		i++;
	}
}

int		ft_strlen_pf(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_atoi_pf(const char *str)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
		nb = (nb * 10) + str[i++] - '0';
	return (nb * sign);
}
