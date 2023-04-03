#include "ft_memcpy.c"
#include "ft_bzero.c"
#include "ft_calloc.c"
#include "ft_itoa.c"
#include "ft_strlen.c"
#include "ft_substr.c"
#include "ft_atoi.c"
#include "ft_split.cc"
#include "ft_isdigit.cc"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#define _POSIX_SOURCE
#include <unistd.h>
#include <limits.h>

static int make_positive(int a)
{
	if(a < 0)
		a = a * -1;
	return (a);
}

static int is_repeat(int tmp, int **array, int i)
{
	int j = 0;

	while(j < i)
	{
		if(*array[j] == tmp)
			return (1);
		j++;
	}
	return (0);
}

static void fill_array(int **array, int size, int digits)
{
	int	i = 0;
	int j = 0;
	int	posneg = 0;
	int	mint = 0;
	int *tmp;
	int isdouble = 1;
	time_t currenttime;
	static time_t oldtime;
	static int rs = 7;

	currenttime = time(0);
	if(oldtime != currenttime)
	{
		oldtime = currenttime;
		srand(oldtime);
//		printf("time:%ld, ", ((long)oldtime) % 1000);
	}
	else
	{
		oldtime = currenttime;
		srand(oldtime + rs);
		rs = rs + 7877;
	}
	if(digits < 0)
	{
		if(digits == -10)
			mint = 1;
		posneg = 1;
		digits *= -1;
	}
	while(i < size)
	{	
		tmp = malloc(1 * sizeof (int));
		while(isdouble == 1)
		{
			*tmp = rand();
			if(posneg && (rand() & 1) == 1)
				*tmp = *tmp * -1;
			if(digits < 10)
				*tmp = (*tmp % ((int) pow(10, digits)));
			else if(mint && posneg)
				if((*tmp & 15) == 15)
				{
					*tmp = INT_MIN;				
					mint = 0;
				}
			if(i > 0)
				isdouble = is_repeat(*tmp, array, i);
			else 
				isdouble = 0;
		}
		free(array[i]);
		array[i] = tmp;
		isdouble = 1;
//		printf("%d ", *array[i]);
		i++;
	}
//	printf("\n");ß
}

static char **split_args(int argc, char **args)
{
	char	**validargs;
	int 	i = 1;
	int		j = 0;

	if(argc == 2)
		validargs = ft_split(args[1], ' ');
	else
	{
		validargs = malloc((argc) * sizeof(char *));
		while(args[i])
		{
			validargs[i - 1] = args[i];
			i++;
		}	
	}	
	if(argc == 1 || !validargs[1])
	{
		printf("\t\t<<< No Repeat Random Number Array Generator >>>\n\
\tadd 2 to 4 arguments: ./a.out (-)<num_of_digits> <size of array>  <sets of arrays> <name of file>\n\
\tplacing a (-) before <numb of digits> will include negative numbers in the array. -10 will include MIN_INT\n\
eg:\n\
\t./aout -1 3\n\
\t-9 3 -4\n\
or:\n\
\t./aout 2 2 3 log.txt\n\
\tcat log.txt\n\
\t64 75\n\
\t13 71\n\
\t44 68\n"); 
		return (NULL);
	}
	while(j < 3 && validargs[j])
	{
		i = 0;
		while(validargs[j][i])
		{
			if(ft_isdigit(validargs[j][i] || validargs[j][i] == '-' || validargs[j][i] == ' '))
				printf("first 3 args must be numbers\n");
			if(j > 0 && (validargs[j][i] == '-'))
				printf("<size of array> cannot be < 1, <sets of arrays> cannot be < 1\n");
			i++;
		}
		j++;
	}
	return (validargs);	
}

int main (int argc, char **argv)
{
	char	**args;
	int		**randomarray;
	char	*tmp;
	int		arraysize;
	int		checksize;
	int		digits = 11;
	int		fd = 1;
	int		fdset = 0;
	int		i = 0;
	int		numofarray = 1;
//	int 	p = 0;

	args = split_args(argc, argv);
	if (!args)
		return (0);
//	while(args[++p])
//		printf("%s ", args[p]);
//	printf("are your args in main\n");
	arraysize = ft_atoi(args[1]);
	randomarray = malloc((arraysize + 1) * sizeof (int *));
	if(!randomarray)
	{
		free(args);
		return(0);
	}
//	while(i++ < (arraysize + 1))
//		randomarray[i - 1] = NULL;
	if(args[2])
	{
		numofarray = ft_atoi(args[2]);
		if(numofarray == 0 || arraysize == 0)
		{
			free(args);
			printf("<size of array> cannot be < 1, <sets of arrays> cannot be < 1\n");
			return(0);
		}
	}
	digits = ft_atoi(args[0]);
	if(digits == 0 || digits > 10 || digits < -10)
	{
		printf("<no_of_digits>111 must be between -10 and 10, and cannot be 0");
		free(args);
		return (0);
	}
	checksize = (int) pow(10,make_positive(digits));
	if(digits < 0)
		checksize = ((checksize * 2) - 1);
	if(arraysize > checksize)
	{
		printf("not enough unique %d digit numbers for that sized array\n", make_positive(digits));
		free(args);
		return (0);
	}
	if(args[3] && !fdset)
		{
			fdset = 1;
			unlink(args[3]);
			fd = open(args[3], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		}	
	while(numofarray > 0)
	{
		fill_array(randomarray, arraysize, digits);
		while(randomarray[i])
		{
			tmp = ft_itoa(*randomarray[i]);
			write(fd, tmp, ft_strlen(tmp));
			free(tmp);
			write(fd, " ", 1);
			i++;
		}
	write(fd, "\n", 1);
	i = 0;
	numofarray--;
	}
	free(args);
	free(randomarray);
	close(fd);
	return (0);
}
