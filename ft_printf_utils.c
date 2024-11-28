/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:22:51 by ldummer-          #+#    #+#             */
/*   Updated: 2024/11/23 11:45:26 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	count;

	count = -1;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[++count])
	{
		write(1, &str[count], 1);
	}
	return (count);
}

int	ft_puthex(unsigned long long n, char specifier)
{
	int		count;
	char	*nb_hex;

	count = 0;
	if (specifier == 'x')
		nb_hex = "0123456789abcdef";
	else if (specifier == 'X')
		nb_hex = "0123456789ABCDEF";
	if (n == 0)
		return (ft_putchar('0'));
	if (n >= 16)
		count += ft_puthex(n / 16, specifier);
	count += ft_putchar(nb_hex[n % 16]);
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		return (write (1, "-2147483648", 11));
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_putunsigned(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunsigned(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}
