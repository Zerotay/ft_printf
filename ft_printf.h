/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:44:08 by dongguki          #+#    #+#             */
/*   Updated: 2021/02/02 16:22:33 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_condition_for_conversion
{
	int			sort1zero2;
	int			width;
	int			precision;
	int			onlyfors;
	char		spec;
}				t_cfc;

int				ft_printf(const char *s, ...);
t_cfc			makecfc(const char *s, int *i, t_cfc cfc, va_list ap);
int				print(t_cfc cfc, va_list ap);

int				godi(t_cfc cfc, va_list ap);
int				gox(t_cfc cfc, va_list ap);
int				goxx(t_cfc cfc, va_list ap);
int				gou(t_cfc cfc, va_list ap);
int				goc(t_cfc cfc, va_list ap);
int				gos(t_cfc cfc, va_list ap);
int				gop(t_cfc cfc, va_list ap);
int				gol(t_cfc cfc);

char			*itop(unsigned long n);
char			*itoplus(t_cfc cfc, unsigned int n);
char			*checkito(t_cfc cfc, int val);

int				lengthplus(t_cfc cfc, unsigned long val);
int				length(int val);

int				justwrite(t_cfc cfc, unsigned long val);
int				onlyfornull(t_cfc cfc);
int				precisionlong(t_cfc cfc, int val, int len);
int				sort(t_cfc cfc, int val, int len);
int				basic(t_cfc cfc, int val, int len);
int				zero(t_cfc cfc, int val, int len);

int				onlyfornul(t_cfc cfc);
int				onlyfornil(t_cfc cfc);

#endif
