/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:01:30 by mlopez-i          #+#    #+#             */
/*   Updated: 2023/09/26 21:05:22 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Chooses what type to print after a % and calls the function
void	ft_printspecial(char c, int *counter, va_list args)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), counter);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), counter);
	else if (c == 'p')
		ft_putpointer(va_arg(args, unsigned long), counter);
	else if (c == 'd' || c == 'i')
		ft_putnbrdec(va_arg(args, int), counter);
	else if (c == 'u')
		ft_putnbrunsigned(va_arg(args, unsigned int), counter);
	else if (c == 'x' || c == 'X')
		ft_putnbrhex(va_arg(args, unsigned int), c, counter);
	else if (c == '%')
		ft_putchar('%', counter);
}

// Main function for ft_printf()
int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i], &counter);
		else if (str[i] == '%' && str[i + 1])
		{
			ft_printspecial(str[i + 1], &counter, args);
			i++;
		}
		i++;
		if (counter == -1)
			return (-1);
	}
	va_end(args);
	return (counter);
}
