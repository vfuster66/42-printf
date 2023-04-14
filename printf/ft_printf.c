/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 07:17:50 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/09 16:43:05 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*****************************************************************************
 * 
 * Prend un nombre non signé et une base (chaîne de caractères) et affiche le 
 * nombre dans la base donnée. La fonction commence par déterminer la longueur
 * de la base, puis effectue une division entière récursive pour convertir le
 * nombre en base. Si le nombre est inférieur à 10, il est simplement affiché
 * en tant que caractère en ajoutant le code ASCII '0'. Si le nombre est 
 * supérieur à 10, le caractère correspondant est déterminé en ajoutant ou en 
 * soustrayant la valeur 'a' ou 'A' selon que le format est 'x'/'p' ou 'X' 
 * respectivement. La fonction retourne le nombre de caractères affichés.
 * 
*****************************************************************************/
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

/*****************************************************************************
 * 
 * Prend un entier signé et un format et retourne le nombre de caractères 
 * affichés. Si le nombre est négatif, le signe moins est d'abord affiché et 
 * le nombre est converti en un entier long non signé. La fonction appelle 
 * ensuite la fonction "ft_putnbrbase" pour afficher le nombre en utilisant 
 * la base "0123456789". Le nombre de caractères affichés est renvoyé.
 * 
*****************************************************************************/
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

/*****************************************************************************
 * 
 * prend un nombre non signé et un format et affiche le nombre dans la base 
 * hexadécimale, précédé de "0x". Si le nombre est nul, la chaîne "(nil)" est 
 * affichée. La fonction appelle la fonction "ft_putnbrbase" en utilisant la 
 * base "0123456789ABCDEF" et retourne le nombre de caractères affichés.
 * 
*****************************************************************************/
int	parameter_gps_p(unsigned long long int ull_num, char format)
{
	if (ull_num == 0)
		return (ft_putstr("(nil)"));
	write(1, "0x", 2);
	return (ft_putnbrbase(ull_num, "0123456789ABCDEF", format) + 2);
}

/*****************************************************************************
 * 
 * prend un format et une liste d'arguments et affiche les arguments en 
 * fonction du format. Si le format est 'c', elle affiche un caractère. Si 
 * le format est 's', elle affiche une chaîne de caractères. Si le format 
 * est 'd' ou 'i', elle appelle la fonction "parameter_gps_d_i" pour afficher 
 * un entier signé. Si le format est 'u', elle appelle la fonction 
 * "ft_putnbrbase" pour afficher un entier non signé en utilisant la base 
 * "0123456789". Si le format est 'x' ou 'X', elle appelle la fonction 
 * "ft_putnbrbase" pour afficher un entier non signé en utilisant la base 
 * "0123456789ABCDEF". Si le format est 'p', elle appelle la fonction 
 * "parameter_gps_p" pour afficher un pointeur. Sinon, elle affiche 
 * simplement le caractère spécifié. La fonction retourne le nombre de 
 * caractères affichés.
 * 
*****************************************************************************/
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

/*****************************************************************************
 * 
 * fonction principale qui prend en charge l'impression de chaînes de 
 * caractères formatées. Elle parcourt chaque caractère de la chaîne de 
 * formatage et appelle la fonction parameter_gps pour chaque spécificateur 
 * de conversion qu'elle rencontre. Si elle ne rencontre pas un spécificateur 
 * de conversion, elle utilise la fonction ft_putchar pour afficher le 
 * caractère courant.
 * 
*****************************************************************************/
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
