/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:04:33 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/08 13:49:18 by vfuster-         ###   ########.fr       */
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
static int	ft_print_string(const char *str, t_flag flag)
{
	int	count;

	count = 0;
	if (flag.precision >= 0)
	{
		count += ft_width(flag.precision, ft_strlen(str), 0);
		count += ft_print_s_precision(str, flag.precision);
	}
	else
		count += ft_print_s_precision(str, ft_strlen(str));
	return (count);
}

/****************************************************************************
 *
 * 
 * 
*****************************************************************************/
int	ft_print_str(const char *str, t_flag flag)
{
	int	count;

	count = 0;
	if (str == NULL)
		str = "(null)";
	if (flag.precision >= 0 && (size_t)flag.precision > ft_strlen(str))
		flag.precision = ft_strlen(str);
	if (flag.left == 1)
		count += ft_print_string(str, flag);
	if (flag.precision >= 0)
		count += ft_width(flag.width, flag.precision, 0);
	else
		count += ft_width(flag.width, ft_strlen(str), 0);
	if (flag.left == 0)
		count += ft_print_string(str, flag);
	return (count);
}

/****************************************************************************
 *
 * 
 * 
*****************************************************************************/
int	ft_print_s_precision(const char *str, int precision)
{
	int	count;

	count = 0;
	while (str[count] && count < precision)
		write(1, &str[count++], 1);
	return (count);
}

/****************************************************************************
 *
 * 
 * 
*****************************************************************************/
int	ft_print_s(const char *str)
{
	int	len;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}
