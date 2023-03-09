/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:34:19 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/08 13:52:21 by vfuster-         ###   ########.fr       */
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
static size_t	ft_ulen(long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num >= 1)
	{
		len++;
		num /= 10;
	}
	return (len);
}

/****************************************************************************
 *
 * 
 * 
*****************************************************************************/
static char	*ft_utostr(unsigned int num, char *str, size_t len)
{
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	len--;
	while (len)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	str[0] = (num % 10) + '0';
	return (str);
}

/****************************************************************************
 *
 * 
 * 
*****************************************************************************/
char	*ft_print_utoa(unsigned int num)
{
	size_t	len;
	char	*str;

	len = ft_ulen(num);
	str = 0;
	str = ft_utostr(num, str, len);
	if (!str)
		return (NULL);
	return (str);
}