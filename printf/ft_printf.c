/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:13:18 by isousa-s          #+#    #+#             */
/*   Updated: 2025/02/02 17:07:22 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int)));
	else if (format == 'X')
		return (ft_putnbr_hex_upper(va_arg(args, unsigned int)));
	else if (format == '%')
		return (write(1, "%", 1));
	return (0);
}

/**
 * @brief emulates the printf function
 * @arg 
 * Format specifiers:
 * 		c - single character
 * 		s - string
 * 		p - pointer (in hexadecimal format prefixed with 0x)
 * 		d - signed decimal integer
 * 		i - signed decimal integer (alternative for d)
 * 		u - unsigned decimal integer
 * 		x - unsigned hexadecimal numnber (lowercase letters)
 * 		X - unsigned hexadecimal numnber (capital letters)
 * 		% - literal % symbol
 * 
 */
int	ft_printf(char const *format, ...)
{
	int		len;
	int		pos;
	va_list	args;

	len = 0;
	pos = 0;
	va_start(args, format);
	while (format[pos])
	{
		if (format[pos] == '%')
		{
			pos++;
			len += handle_format(format[pos], args);
		}
		else
		{
			ft_putchar(format[pos]);
			len++;
		}
		pos++;
	}
	va_end(args);
	return (len);
}

