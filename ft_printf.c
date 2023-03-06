/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 07:17:50 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/06 08:39:15 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrbase(unsigned long long int nbr, char *base, char format)
{
	unsigned int	base_len;
	int				count;

	base_len = ft_strlen(base);
	count = 0;
	if (nbr < 10)
		count += ft_putchar(nbr + '0');
	else if (nbr < base_len)
	{
		if (format == 'x' || format == 'p')
			count += ft_putchar(nbr - 10 + 'a');
		else if (format == 'X')
			count += ft_putchar(nbr - 10 + 'A');
	}
	else
	{
		count += ft_putnbrbase(nbr / base_len, base, format);
		count += ft_putnbrbase(nbr % base_len, base, format);
	}
	return (count);
}

int	parameter_gps_d_i(int num, char format)
{
	int				count;
	long long int	long_num;

	count = 0;
	if (num < 0)
	{
		count += ft_putchar('-');
		long_num = -(long long int)num;
	}
	else
		long_num = num;
	return (count + ft_putnbrbase((unsigned long long int)long_num,
			"0123456789", format));
}

int	parameter_gps_p(unsigned long long int ull_num, char format)
{
	if (ull_num == 0)
		return (ft_putstr("(nil)"));
	write(1, "0x", 2);
	return (ft_putnbrbase(ull_num, "0123456789ABCDEF", format) + 2);
}

int	parameter_gps(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (parameter_gps_d_i(va_arg(args, int), format));
	else if (format == 'u')
		return (ft_putnbrbase(va_arg(args, unsigned int),
				"0123456789", format));
	else if (format == 'x' || format == 'X')
		return (ft_putnbrbase(va_arg(args, unsigned int),
				"0123456789ABCDEF", format));
	else if (format == 'p')
		return (parameter_gps_p(va_arg(args, unsigned long long int), format));
	else
		return (ft_putchar(format));
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			count += parameter_gps(*(++str), args);
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (count);
}
