/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjebou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:00:58 by hanjebou          #+#    #+#             */
/*   Updated: 2023/10/10 19:59:12 by hanjebou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list *args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (format == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (format == 'p')
		return (ft_putadress(va_arg(*args, void *)));
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (format == 'u')
		return (ft_putunbr(va_arg(*args, unsigned int)));
	if (format == 'x')
		return (ft_puthexa(va_arg(*args, unsigned int), "0123456789abcdef"));
	if (format == 'X')
		return (ft_puthexa(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	if (format == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	int		print_length;
	va_list	args;

	i = 0;
	print_length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] != '\0')
			{
				print_length += ft_format(&args, format[i]);
			}
		}
		else
			print_length += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
