/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:42:27 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/27 21:55:55 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_printf(const char *format, ...);
int	ft_format_arg(const char *specifier, va_list args, int i);
int	ft_puthex(unsigned long long n, char specifier);
int	ft_p_specifier(va_list args);
int	ft_putnbr(int n);
int	ft_putunsigned(unsigned long n);

#endif
