/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:36:58 by jergonza          #+#    #+#             */
/*   Updated: 2023/09/11 13:36:59 by jergonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*str1_c;
	unsigned char	*str2_c;

	str1_c = (unsigned char *)str1;
	str2_c = (unsigned char *)str2;
	i = 0;
	while ((str1_c[i] != '\0' || str2_c[i] != '\0') && i < n)
	{
		if (str1_c[i] != str2_c[i])
			return (str1_c[i] - str2_c[i]);
		i++;
	}
	return (0);
}
