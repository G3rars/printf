/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:36:19 by jergonza          #+#    #+#             */
/*   Updated: 2023/09/12 10:36:21 by jergonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*src_cpy;
	char	*dest_cpy;
	size_t	i;

	if ((dest == NULL && src == NULL) || n == 0)
		return (dest);
	src_cpy = (char *)src;
	dest_cpy = dest;
	i = 0;
	while (i < n)
	{
		dest_cpy[i] = src_cpy[i];
		i++;
	}
	return ((void *)dest_cpy);
}
