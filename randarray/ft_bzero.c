/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:29:12 by jchapman          #+#    #+#             */
/*   Updated: 2022/09/16 14:39:04 by jchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdlib.h>

void	ft_bzero(void *s, size_t a)
{
	unsigned char	*ch;

	ch = (unsigned char *) s;
	while (a > 0)
	{
		ch[a - 1] = 0;
		a--;
	}
	s = ch;
}
