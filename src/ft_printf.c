/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjebou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:00:58 by hanjebou          #+#    #+#             */
/*   Updated: 2023/10/09 16:03:21 by hanjebou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_putchar(va_arg(args, int));
	if (format == 's')
		length += ft_putstr(va_arg(args, char *));
	if (format == 'p')
		length += ft_putadress(va_arg(args, void *));
	if (format == 'd' || format == 'i')
		length += ft_putnbr(va_arg(args, int));
	if (format == 'u')
		length += ft_putunbr(va_arg(args, unsigned int));
	if (format == 'x')
		length += ft_puthexa(va_arg(args, unsigned int), "0123456789abcdef");
	if (format == 'X')
		length += ft_puthexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (format == '%')
		length += ft_putpercent();
	return (length);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	int		print_length;
	va_list	args;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_format(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
