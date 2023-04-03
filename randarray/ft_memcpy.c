/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:44:27 by jchapman          #+#    #+#             */
/*   Updated: 2022/09/19 15:38:07 by jchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *source, size_t len)
{
	char	*sourcestr;
	char	*returnstr;
	size_t	i;

	if (dest == NULL && source == NULL)
		return (dest);
	sourcestr = (char *) source;
	returnstr = (char *) dest;
	i = 0;
	while (i < len)
	{	
		returnstr[i] = sourcestr[i];
		i++;
	}
	dest = returnstr;
	return (returnstr);
}
