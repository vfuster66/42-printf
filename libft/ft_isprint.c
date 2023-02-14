/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:13:51 by vfuster-          #+#    #+#             */
/*   Updated: 2023/02/08 08:04:53 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* booleen indiquant si le caractere passe en argument est un
 * caractere imprimable. Renvoie 1 si vrai, 0 si faux 
 *
 * */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
