/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjebou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:47:56 by hanjebou          #+#    #+#             */
/*   Updated: 2023/10/10 19:59:27 by hanjebou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FORMAT "int" 

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

int	ft_putchar(int c);
int	ft_putpercent(void);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_putunbr(unsigned int nb);
int	ft_putadress(void *ptr);
int	ft_puthexa(unsigned int nb, char *base);
int	ft_format(va_list *args, const char format);
int	ft_printf(const char *str, ...);

#endif //FT_PRINTF_H 
