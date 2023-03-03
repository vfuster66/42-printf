/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 07:17:43 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/03 15:23:15 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# if defined (__APPLE__)
#  define PTR_NULL "0x0"
# else
#  define PTR_NULL "(nil)"
# endif

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	parameter_gps(char fmt, va_list args);
int	ft_putnbrbase(long long int nbr, char *base, char format);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_strlen(char *str);

#endif