/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <vazra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:54:00 by vazra             #+#    #+#             */
/*   Updated: 2021/02/04 17:03:47 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct		s_struct
{
	va_list			va;
	int				ret;
	int				k;
	char			*str;
	char			*s;
	int				len;
	int				num;
	unsigned long	p;
	char			zero;
	int				dash;
	int				dash_star;
	int				width;
	int				width_len;
	int				point;
	int				point_len;
}					t_struct;

int					ft_printf(const char *str, ...);
void				ft_categorie(t_struct *tab);
void				ft_flags(t_struct *tab);
void				ft_width(t_struct *tab);
void				ft_convert_int(t_struct *tab);
void				ft_convert_char(t_struct *tab);
void				ft_convert_hexa(t_struct *tab);
void				ft_convert_pointer(t_struct *tab);
char				*ft_itoa_pf(int n, t_struct *tab);
void				ft_itoa_fill(char *str, long nbr, int i);
char				*ft_itoa_unsigned(unsigned int n, t_struct *tab);
void				ft_itoa_unsigned_fill(char *str,
		unsigned long nbr, unsigned int i);
void				ft_put_hexa(int nb, t_struct *tab);
void				ft_len_hexa(int nb, t_struct *tab);
void				ft_init_struct(t_struct *tab);
void				ft_putchar_pf(char c, t_struct *tab);
void				ft_putstr_pf(char *str, t_struct *tab);
int					ft_strlen_pf(const char *str);
int					ft_atoi_pf(const char *str);

#endif
