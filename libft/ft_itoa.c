/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:02:52 by jergonza          #+#    #+#             */
/*   Updated: 2023/09/19 13:02:59 by jergonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_digitcount(long *n)
{
	long	counter;
	long	cpy;

	counter = 0;
	if (*n <= 0)
	{
		*n = *n * -1;
		counter++;
	}
	cpy = *n;
	while (cpy > 0)
	{
		cpy = cpy / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(long n)
{
	long	i;
	long	num;
	char	*res;
	long	len;

	i = 1;
	num = n;
	len = ft_digitcount((long *)&num);
	res = ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	while (i <= len)
	{
		res[len - i] = (num % 10) + 48;
		num = num / 10;
		i++;
		if (num == 0 && n < 0)
			res[0] = '-';
	}
	free(res);
	return (res);
}
