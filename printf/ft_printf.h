/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 07:17:43 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/06 08:39:17 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	parameter_gps_p(unsigned long long int ull_num, char format);
int	parameter_gps_d_i(int num, char format);
int	parameter_gps(char format, va_list args);
int	ft_putnbrbase(unsigned long long int nbr, char *base, char format);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_strlen(char *str);

#endif
