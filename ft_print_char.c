/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:53:53 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/13 16:53:56 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_char(char c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.left == 1)
		count += ft_print_c(c);
	count += ft_pad_width(flags.width, 1, flags.zero);
	if (flags.left == 0)
		count += ft_print_c(c);
	return (count);
}
