/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:13:28 by jergonza          #+#    #+#             */
/*   Updated: 2023/09/29 12:13:31 by jergonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

int	nbr(size_t n, char *src, unsigned int base, char letter)
{
	int	i;

	i = 0;
	if (n > base - 1)
	{
		i += nbr(n / base, src, base, letter);
	}
	else if (letter == 'p')
		i += write(1, "0x", 2);
	i += ft_putchar_fd(src[n % base], 1);
	return (i);
}

static int	ft_fuction(char s, va_list args)
{
	int		l;

	if (ft_strchr("cspdiuxX", s) || s == '%')
	{
		if (s == 'd' || s == 'i')
			return (l = ft_putnbr_fd(va_arg(args, int), 1));
		if (s == 'c')
			return (l = ft_putchar_fd(va_arg(args, int), 1));
		if (s == 's')
			return (l = ft_putstr_fd(va_arg(args, char *), 1));
		if (s == 'u')
			return (l = nbr(va_arg(args, unsigned), "0123456789", 10, s));
		if (s == 'p')
			return (l = nbr(va_arg(args, size_t), "0123456789abcdef", 16, s));
		if (s == 'x')
			return (l = nbr(va_arg(args, unsigned), "0123456789abcdef", 16, s));
		if (s == 'X')
			return (l = nbr(va_arg(args, unsigned), "0123456789ABCDEF", 16, s));
		if (s == '%')
			return (l = (ft_putchar_fd('%', 1)));
	}
	return (0);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		i;

	va_start(args, s);
	i = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '\0')
				break ;
			i = i + ft_fuction(*s, args);
		}
		else
		{
			i = i + ft_putchar_fd(*s, 1);
		}
		s++;
	}
	va_end(args);
	return (i);
}
