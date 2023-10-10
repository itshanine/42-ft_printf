/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjebou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:23:15 by hanjebou          #+#    #+#             */
/*   Updated: 2023/10/10 18:11:04 by hanjebou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int		print_length;
	size_t	j;
	char	rev[10];

	print_length = 0;
	j = 0;
	if (nb == INT_MIN)
		return ((void)write(1, "-2147483648", 11), 11);
	if (nb < 0)
	{
		print_length += ft_putchar('-');
		nb *= -1;
	}
	while (nb != 0 || j == 0)
	{
		rev[j++] = nb % 10 + '0';
		nb /= 10;
	}
	while (j > 0)
		print_length += ft_putchar(rev[--j]);
	return (print_length);
}

int	ft_putunbr(unsigned int nb)
{
	int		print_length;
	size_t	j;
	char	rev[10];

	print_length = 0;
	j = 0;
	if (nb < 0)
	{
		print_length += ft_putchar('-');
		nb *= -1;
	}
	while (nb != 0 || j == 0)
	{
		rev[j++] = nb % 10 + '0';
		nb /= 10;
	}
	while (j > 0)
		print_length += ft_putchar(rev[--j]);
	return (print_length);
}

int	ft_putadress(void *ptr)
{
	int				print_length;
	size_t			j;
	unsigned long	adress;
	char			*hex;
	char			rev[16];

	if (!ptr)
		return (ft_putstr("0x0"), 3);
	print_length = 0;
	j = 0;
	adress = (unsigned long)ptr;
	hex = "0123456789abcdef";
	while (adress != 0 || j == 0)
	{
		rev[j++] = hex[adress % 16];
		adress /= 16;
	}
	print_length += ft_putstr("0x");
	while (j > 0)
		print_length += ft_putchar(rev[--j]);
	return (print_length);
}

int	ft_puthexa(unsigned int nb, char *base)
{
	int		print_length;
	size_t	j;
	char	rev[8];

	print_length = 0;
	j = 0;
	while (nb != 0 || j == 0)
	{
		rev[j++] = base[nb % 16];
		nb /= 16;
	}
	while (j > 0)
		print_length += ft_putchar(rev[--j]);
	return (print_length);
}
