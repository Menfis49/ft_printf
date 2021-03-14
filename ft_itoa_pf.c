/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <vazra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:00:06 by vazra             #+#    #+#             */
/*   Updated: 2021/02/01 13:28:38 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intlen(long int nbr)
{
	int i;

	i = 1;
	nbr /= 10;
	while (nbr > 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

void	ft_itoa_fill(char *str, long nbr, int i)
{
	int temp;

	temp = nbr % 10;
	str[i - 1] = temp + '0';
	nbr /= 10;
	if (nbr > 0)
		ft_itoa_fill(str, nbr, i - 1);
}

char	*ft_itoa_pf(int n, t_struct *tab)
{
	char		*str;
	int			i;
	int			sign;
	long int	nbr;

	(void)tab;
	i = 0;
	sign = 0;
	if (n < 0)
	{
		nbr = n;
		nbr *= -1;
		sign = 1;
		i++;
	}
	else
		nbr = n;
	if (!(str = malloc(sizeof(char) * (ft_intlen(nbr) + sign + 1))))
		return (NULL);
	if (sign == 1)
		str[0] = '-';
	ft_itoa_fill(str + sign, nbr, ft_intlen(nbr));
	str[ft_intlen(nbr) + sign] = '\0';
	return (str);
}

void	ft_itoa_unsigned_fill(char *str, unsigned long nbr, unsigned int i)
{
	unsigned int temp;

	temp = nbr % 10;
	str[i - 1] = temp + '0';
	nbr /= 10;
	if (nbr > 0)
		ft_itoa_unsigned_fill(str, nbr, i - 1);
}

char	*ft_itoa_unsigned(unsigned int n, t_struct *tab)
{
	char				*str;
	unsigned int		i;
	unsigned int		sign;
	unsigned long int	nb;

	(void)tab;
	sign = 0;
	i = 0;
	if (n < 0)
	{
		nb = n;
		nb *= -1;
		sign = 1;
		i++;
	}
	else
		nb = n;
	if (!(str = malloc(sizeof(*str) * (ft_intlen(nb) + sign + 1))))
		return (NULL);
	if (sign == 1)
		str[0] = '-';
	ft_itoa_unsigned_fill(str + sign, nb, ft_intlen(nb));
	str[ft_intlen(nb) + sign] = '\0';
	return (str);
}
