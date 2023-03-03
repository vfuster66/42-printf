/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 07:17:50 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/03 15:27:39 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parameter_gps(char fmt, va_list args)
{
	unsigned long long int	ptr;

	if (fmt == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (fmt == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (fmt == 'd' || fmt == 'i')
		return (ft_putnbrbase(va_arg(args, int), "0123456789", fmt));
	else if (fmt == 'u')
		return (ft_putnbrbase(va_arg(args, unsigned int),
				"0123456789", fmt));
	else if (fmt == 'x' || fmt == 'X')
		return (ft_putnbrbase(va_arg(args, unsigned int),
				"0123456789ABCDEF", fmt));
	else if (fmt == 'p')
	{
		ptr = (unsigned long long int)va_arg(args, void *);
		if (ptr == 0)
			return (ft_putstr(PTR_NULL));
		write(1, "0x", 2);
		return (ft_putnbrbase(ptr,"0123456789ABCDEF", fmt) + 2);
	}
	else
		return (ft_putchar(fmt));
}

int	ft_putnbrbase(long long int nbr, char *base, char format)
{
	unsigned long long int	n;
	int	base_len;
	int	count;

	base_len = ft_strlen(base);
	count = 0;
	if (nbr < 0 && format != 'u')
	{	
		count += write (1, "-", 1);
		nbr = -nbr;
	}
	else
		n = nbr;
		
	if (nbr < base_len)
	{
		if (format == 'x' || format == 'p')
			count += ft_putchar(n - 10 + 'a');
		else if (format == 'X')
			count += ft_putchar(n - 10 + 'A');
	}
	else
	{
		count += ft_putnbrbase(nbr / base_len, base, format);
		count += ft_putnbrbase(nbr % base_len, base, format);
	}
	return (count);
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
