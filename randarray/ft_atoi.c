/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:26:28 by jchapman          #+#    #+#             */
/*   Updated: 2022/09/21 15:39:42 by jchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"

int	ft_atoi(const char *str)
{
	long	out;
	int		posneg;
	int		i;

	out = 0;
	posneg = 1;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') || \
			(str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{	
		if (str[i] == '-')
			posneg = -1;
		i++;
		if ((str[i] == '+') || (str[i] == '-'))
			return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		out = out * 10;
		out = out + (str[i] - 48);
		i++;
	}
	return ((int) out * posneg);
}
