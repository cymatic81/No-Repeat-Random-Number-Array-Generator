/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:35:07 by jchapman          #+#    #+#             */
/*   Updated: 2022/09/23 16:14:40 by jchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static char	**malloc_ptrs(const char *s, char c)
{
	char	**ptrarray;
	int		tf;
	int		count;
	int		n;

	tf = 0;
	count = 0;
	n = 0;
	while (s[n])
	{
		if (s[n] != c && tf == 0)
		{
			count++;
			tf = 1;
		}
		if (s[n] == c && tf == 1)
			tf = 0;
		n++;
	}
	ptrarray = malloc((count + 1) * (sizeof(char *)));
	if (!ptrarray)
		return (NULL);
	ptrarray[count] = NULL;
	return (ptrarray);
}

static char	*copystring(const char *oss, char c)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((oss[i] != '\0') && (oss[i] != c))
			i++;
	tmp = ft_substr(oss, 0, i);
	return (tmp);
}

char	**ft_split(const char *s, char c)
{
	char	**ptrarray;
	int		n;
	int		string;

	ptrarray = malloc_ptrs(s, c);
	if (ptrarray == (NULL))
		return (NULL);
	n = 0;
	string = 0;
	while (s[n])
	{
		while (s[n] == c)
			n++;
		if (!s[n])
			break ;
		ptrarray[string] = copystring(&s[n], c);
		string++;
		while ((s[n] != '\0') && (s[n] != c))
			n++;
	}
	return (ptrarray);
}
