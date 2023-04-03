/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 08:55:42 by jchapman          #+#    #+#             */
/*   Updated: 2022/09/26 12:08:09 by jchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*out;
	unsigned int	i;
	unsigned int	maxlength;

	maxlength = 0;
	if (start >= ft_strlen(s))
		len = 0;
	else
		maxlength = ft_strlen(&s[start]);
	if (len > maxlength)
		len = maxlength;
	out = malloc((len + 1) * sizeof(char));
	if (out == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = s[start + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
