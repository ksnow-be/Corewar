/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:39:52 by lgigi             #+#    #+#             */
/*   Updated: 2019/07/24 14:29:49 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define MAX(a, b) (((a) > (b)) ? (a) : (b))

# define BUF_S 128

# define F_ZR (1 << 0)
# define F_PL (1 << 1)
# define F_SP (1 << 2)
# define F_MS (1 << 3)
# define F_DSH (1 << 4)
# define F_STR (1 << 5)

# define M_H (1 << 6)
# define M_HH (1 << 7)
# define M_L (1 << 8)
# define M_Z (1 << 9)
# define M_J (1 << 10)
# define M_FL (1 << 11)

# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <inttypes.h>

typedef struct		s_pr
{
	int		prec;
	int		field;
	short	m_f;
	int		index;
	size_t	print;
	char	b[BUF_S];
}					t_pr;

int					ft_printf(const char *format, ...);
char				*ft_ultoa_base(unsigned long n, int base, int flag);
char				*ft_ltoa(long long n);
char				*ft_utoa(unsigned int n);
char				*ft_ultoa(unsigned long n);

void				ft_print_ptr(va_list ag, t_pr *vals, long i);
void				ft_print_str(va_list ag, t_pr *vals);
void				ft_print_c(va_list ag, t_pr *vals, int perc);
void				ft_print_i(va_list ag, t_pr *v, long i, char conv);
void				print_float(va_list ag, t_pr *v, long i, char conv);
void				ft_print_ox(va_list ag, t_pr *v, long i, char conv);

char				*parse_val(t_pr **val, char *fmt, va_list ag);
void				manage_fl_prec(t_pr *v, char *num, long n, char conv);
char				*init_num_string(long n, unsigned long l,
										t_pr *v, char conv);
long				find_add_field_size(t_pr *v, long n, char *num, char conv);
void				manage_flags(long i, t_pr *v, long double n);
char				*rounder(int size, unsigned int sz, char *s, int round);

int					check_multipy_mods(char *f);
int					ft_isconv(char c);
int					ft_isflag(char c);
int					mods_checker(char *fmt);

void				ft_fill_buff(long i, char c, t_pr *v);
void				ft_add_c(int c, t_pr *v);

#endif
