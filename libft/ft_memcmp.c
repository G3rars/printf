/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:18:25 by jergonza          #+#    #+#             */
/*   Updated: 2023/09/12 17:18:27 by jergonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*str1_cpy;
	unsigned char	*str2_cpy;

	str1_cpy = (unsigned char *)str1;
	str2_cpy = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (str2_cpy[i] != str1_cpy[i])
			return (str1_cpy[i] - str2_cpy[i]);
		i++;
	}
	return (0);
}
