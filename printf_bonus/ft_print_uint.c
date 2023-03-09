/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:09:44 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/08 13:51:49 by vfuster-         ###   ########.fr       */
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

int	ft_print_u(char *nbstr, t_flag flag)
{
	int	count;

	count = 0;
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
int	ft_print_uint(char *nbstr, t_flag flag)
{
	int	count;

	count = 0;
	if (flag.left == 1)
		count += ft_print_u(nbstr, flag);
	if (flag.precision >= 0 && (size_t)flag.precision < ft_strlen(nbstr))
		flag.precision = ft_strlen(nbstr);
	if (flag.precision >= 0)
	{
		flag.width -= flag.precision;
		count += ft_width(flag.width, 0, 0);
	}
	else
		count += ft_width(flag.width, ft_strlen(nbstr), flag.zero);
	if (flag.left == 0)
		count += ft_print_u(nbstr, flag);
	return (count);
}

/****************************************************************************
 *
 * 
 * 
*****************************************************************************/
int	ft_print_unsigned(unsigned n, t_flag flag)
{
	char	*nbstr;
	int		count;

	count = 0;
	if (flag.precision == 0 && n == 0)
	{
		count += ft_width(flag.width, 0, 0);
		return (count);
	}
	nbstr = ft_print_utoa(n);
	if (!nbstr)
		return (0);
	count += ft_print_uint(nbstr, flag);
	free(nbstr);
	return (count);
}
