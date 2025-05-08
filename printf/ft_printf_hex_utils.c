/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:28:24 by isousa-s          #+#    #+#             */
/*   Updated: 2025/02/02 17:04:27 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int n)
{
	char	*hex_str;
	int		len;

	len = 0;
	hex_str = "0123456789abcdef";
	if (n > 15)
		len += ft_putnbr_hex(n / 16);
	len += ft_putchar(hex_str[n % 16]);
	return (len);
}

int	ft_putnbr_hex_upper(unsigned int n)
{
	char	*hex_str;
	int		len;

	len = 0;
	hex_str = "0123456789ABCDEF";
	if (n > 15)
		len += ft_putnbr_hex_upper(n / 16);
	len += ft_putchar(hex_str[n % 16]);
	return (len);
}

void	ft_ptr_to_hex(unsigned long long address, int *len)
{
	char	*hex_str;
	char	buffer[16];
	int		pos;

	pos = 0;
	hex_str = "0123456789ABCDEF";
	if (address == 0)
		len += ft_putchar('0');
	else
	{
		while (address)
		{
			buffer[pos++] = hex_str[address % 16];
			address = address / 16;
		}
		while (pos--)
			len += ft_putchar(buffer[pos]);
	}
}

int	ft_putptr(void *ptr)
{
	unsigned long long	address;
	int					len;

	len = 0;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	address = (unsigned long long)ptr;
	len += ft_putstr("0x");
	ft_ptr_to_hex(address, &len);
	return (len);
}
