/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjebou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:47:56 by hanjebou          #+#    #+#             */
/*   Updated: 2023/10/09 16:02:40 by hanjebou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

int	ft_putchar(int c);
int	ft_putpercent(void);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_putunbr(int nb);
int	ft_putadress(void *ptr);
int	ft_puthexa(unsigned int nb, char *base);
int	ft_format(va_list args, const char format);
int	ft_printf(const char *str, ...);

#endif //FT_PRINTF_H 
