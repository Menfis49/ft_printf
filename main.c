/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:22:02 by vazra             #+#    #+#             */
/*   Updated: 2021/02/01 15:52:44 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("=========== PRINTF ========= \n");
	printf("Char : %c\nString s = %s\nPourcent = %%\nInt d = %d\nInt i = %d\nUnsigned int = %u\nhexa = %x\nHEXA = %X\nPointeur p = %p\n", 'v',"coucou", 5, 6, 65355, 999, 999, "hello");
	printf("=========== FT_PRINTF ========= \n");
	ft_printf("Char : %c\nString s = %s\nPourcent = %%\nInt d = %d\nInt i = %d\nUnsigned int = %u\nhexa = %x\nHEXA = %X\nPointeur p = %p\n", 'v', "coucou", 5, 6, 65355, 999, 999, "hello");
	printf("=========== AUTRE TEST ========== \n");
	printf("TEST =%0dok %s\n", 5, "ola");
	ft_printf("TEST =%0dok %s\n", 5, "ola");
	printf("c-tiret-12 =%-12cok %s\n", 'c', "ola");
	ft_printf("c-tiret-12 =%-12cok %s\n", 'c', "ola");
	printf("s-tiret-12 =%-12sok %s\n", "amis", "ola");
	ft_printf("s-tiret-12 =%-12sok %s\n", "amis", "ola");
	printf("d-tiret-12 =%-12dok %s\n", 33, "ola");
	ft_printf("d-tiret-12 =%-12dok %s\n", 33, "ola");
	printf("p-tiret-12 =%-12pok %s\n", "cc", "ola");
	ft_printf("p-tiret-12 =%-12pok %s\n", "cc", "ola");
	printf("i-tiret-12 =%-12iok %s\n", 33, "ola");
	ft_printf("i-tiret-12 =%-12iok %s\n", 33, "ola");
	printf("u-tiret-12 =%-12uok %s\n", 65355, "ola");
	ft_printf("u-tiret-12 =%-12uok %s\n", 65355, "ola");
	printf("x-tiret-12 =%-12xok %s\n", 999, "ola");
	ft_printf("x-tiret-12 =%-12xok %s\n", 999, "ola");
	printf("X-tiret-12 =%-12Xok %s\n", 999, "ola");
	ft_printf("X-tiret-12 =%-12Xok %s\n", 999, "ola");
	printf("printf1 :%.c\n", 'a');
	ft_printf("printf2 :%.c\n", 'a');
	printf("{%05.*d}\n", -15, 42);
	ft_printf("{%05.*d}\n", -15, 42);

	return (0);
}
