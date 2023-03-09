/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:44:27 by vfuster-          #+#    #+#             */
/*   Updated: 2023/03/08 13:48:29 by vfuster-         ###   ########.fr       */
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
 * Utilisée pour imprimer le préfixe "0x" ou "0X" pour les nombres 
 * hexadécimaux. Elle prend un argument is_upper qui indique si la lettre "X"
 * doit être en majuscule ou en minuscule. En fonction de la valeur de 
 * is_upper, la fonction imprime soit "0x" soit "0X" en utilisant la fonction 
 * ft_print_s qui imprime une chaîne de caractères.
 * 
*****************************************************************************/
int	ft_print_x_prefix(int is_upper)
{
	if (is_upper == 1)
		ft_print_s("0X");
	else
		ft_print_s("0x");
	return (2);
}

/****************************************************************************
 *
 * Utilisée pour imprimer un nombre hexadécimal sous forme de chaîne de 
 * caractères. Elle prend en entrée la chaîne de caractères représentant le 
 * nombre hexadécimal, la longueur de cette chaîne, un drapeau is_upper qui 
 * indique si les lettres doivent être en majuscule ou en minuscule, et un 
 * drapeau flag qui contient les informations de formatage. La fonction 
 * commence par vérifier si le drapeau flag indique que le préfixe "0x" ou 
 * "0X" doit être imprimé en utilisant la fonction ft_print_x_prefix si 
 * nécessaire. Ensuite, si le drapeau flag indique une précision (nombre 
 * de chiffres à imprimer), la fonction utilise la fonction ft_width pour 
 * imprimer les espaces nécessaires pour aligner la chaîne de caractères. 
 * Enfin, la fonction imprime la chaîne de caractères elle-même en utilisant 
 * la fonction ft_print_s.
 * 
*****************************************************************************/
int	ft_print_x(char *nbstr, int n, int is_upper, t_flag flag)
{
	int	count;

	count = 0;
	if (flag.zero == 0 && flag.hash == 1 && n != 0)
		count += ft_print_x_prefix(is_upper);
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
int	ft_print_hexadec(char *nbstr, int n, int is_upper, t_flag flag)
{
	int	count;

	count = 0;
	if (flag.zero == 1 && flag.hash == 1 && n != 0)
		count += ft_print_x_prefix(is_upper);
	if (flag.left == 1)
		count += ft_print_x(nbstr, n, is_upper, flag);
	if (flag.precision >= 0 && (size_t)flag.precision < ft_strlen(nbstr))
		flag.precision = ft_strlen(nbstr);
	if (flag.precision >= 0)
	{
		flag.width -= flag.precision;
		count += ft_width(flag.width, 0, 0);
	}
	else
		count += ft_width(flag.width,
				ft_strlen(nbstr) + (flag.hash * 2), flag.zero);
	if (flag.left == 0)
		count += ft_print_x(nbstr, n, is_upper, flag);
	return (count);
}

/****************************************************************************
 *
 * 
 * 
*****************************************************************************/
int	ft_print_hexa(unsigned int n, int is_upper, t_flag flag)
{
	char	*nbstr;
	int		count;

	count = 0;
	if (flag.precision == 0 && n == 0)
	{
		count += ft_width(flag.width, 0, 0);
		return (count);
	}
	nbstr = ft_print_xtoa(n, is_upper);
	if (!nbstr)
		return (0);
	count += ft_print_hexadec(nbstr, n, is_upper, flag);
	free(nbstr);
	return (count);
}
