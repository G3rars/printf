/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:58:41 by jergonza          #+#    #+#             */
/*   Updated: 2023/09/12 16:58:43 by jergonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*str_copy;

	str_copy = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (str_copy[i] == (unsigned char)c)
			return ((void *)(str_copy + i));
		i++;
	}
	return (NULL);
}
