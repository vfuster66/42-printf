/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:45:54 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/08 13:48:21 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/****************************************************************************
 *
 * 
 * 
*****************************************************************************/

/****************************************************************************
 *
 * 
 * 
*****************************************************************************/
int	ft_print_i(char *nbstr, int n, t_flag flag)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		if (flag.zero == 0 || flag.precision >= 0)
			count += ft_print_c('-');
	}
	else if (flag.plus == 1 && flag.zero == 0)
		count += ft_print_c('+');
	else if (flag.space == 1 && flag.zero == 0)
		count += ft_print_c(' ');
	if (flag.precision >= 0)
		count += ft_width(flag.precision - 1,
				ft_strlen(nbstr) - 1, 1);
	count += ft_print_s(nbstr);
	return (count);
}

/****************************************************************************
 *
 * 
 * 
*****************************************************************************/
int	ft_print_sign_precision(int n, t_flag *flag)
{
	int	count;

	count = 0;
	if (n < 0 && flag->precision == -1)
	{
		count += ft_print_c('-');
		flag->width--;
	}
	else if (flag->plus == 1)
		count += ft_print_c('+');
	else if (flag->space == 1)
	{
		count += ft_print_c(' ');
		flag->width--;
	}
	return (count);
}

/****************************************************************************
 *
 * 
 * 
*****************************************************************************/
int	ft_print_integer(char *nbstr, int n, t_flag flag)
{
	int	count;

	count = 0;
	if (flag.zero == 1)
		count += ft_print_sign_precision(n, &flag);
	if (flag.left == 1)
		count += ft_print_i(nbstr, n, flag);
	if (flag.precision >= 0 && (size_t)flag.precision < ft_strlen(nbstr))
		flag.precision = ft_strlen(nbstr);
	if (flag.precision >= 0)
	{
		flag.width -= flag.precision;
		if (n < 0 && flag.left == 0)
			flag.width -= 1;
		count += ft_width(flag.width, 0, 0);
	}
	else
		count += ft_width(flag.width - flag.plus - flag.space,
				ft_strlen(nbstr), flag.zero);
	if (flag.left == 0)
		count += ft_print_i(nbstr, n, flag);
	return (count);
}

/****************************************************************************
 *
 * 
 * 
*****************************************************************************/
int	ft_print_int(int n, t_flag flag)
{
	char	*nbstr;
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		if (flag.zero == 0)
			flag.width--;
	}
	if (flag.precision == 0 && n == 0)
	{
		count += ft_width(flag.width, 0, 0);
		return (count);
	}
	nbstr = ft_print_itoa(nb);
	if (!nbstr)
		return (0);
	count += ft_print_integer(nbstr, n, flag);
	free(nbstr);
	return (count);
}
