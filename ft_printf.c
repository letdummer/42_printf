/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:45:46 by ldummer-          #+#    #+#             */
/*   Updated: 2024/11/25 12:41:41 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_p_specifier(va_list args)
{
	void				*ptr;
	int					length;
	unsigned long long	address;

	length = 0;
	ptr = va_arg(args, void *);
	address = (unsigned long long)ptr;
	if (ptr == NULL)
		length += ft_putstr("(nil)");
	else
	{
		length += ft_putchar('0');
		length += ft_putchar('x');
		length += ft_puthex(address, 'x');
	}
	return (length);
}

int	ft_format_arg(const char *specifier, va_list args, int i)
{
	int	counter;

	counter = 0;
	if (specifier[i] == '%')
		counter += ft_putchar('%');
	else if (specifier[i] == 'c')
		counter += ft_putchar((char)va_arg(args, int));
	else if (specifier[i] == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (specifier[i] == 'x' || specifier[i] == 'X')
		counter += ft_puthex((long)va_arg(args, unsigned int), specifier[i]);
	else if (specifier[i] == 'i' || specifier[i] == 'd')
		counter += ft_putnbr((long)va_arg(args, int));
	else if (specifier[i] == 'u')
		counter += ft_putunsigned(va_arg(args, unsigned int));
	else if (specifier[i] == 'p')
		counter += ft_p_specifier(args);
	else
		counter += ft_putchar(specifier[i]);
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count_printed;
	int		i;

	va_start(args, format);
	count_printed = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			count_printed += ft_format_arg(format, args, ++i);
		else if (format[i] != '%')
			count_printed += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count_printed);
}
