/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfnums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:43:17 by mlopez-i          #+#    #+#             */
/*   Updated: 2023/09/17 16:47:31 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Writes a number base 10 recursive (%d %i)
void	ft_putnbrdecrec(int num, int *counter)
{
	if (num > 9)
	{
		ft_putnbrdecrec(num / 10, counter);
		if (*counter == -1)
			return ;
		ft_putnbrdecrec(num % 10, counter);
	}
	else
		ft_putchar(num + 48, counter);
	if (*counter == -1)
		return ;
}

// Exception cases for put number base 10 (%d %i)
void	ft_putnbrdec(int num, int *counter)
{
	if (num == -2147483648)
		ft_putstr("-2147483648", counter);
	else if (num < 0)
	{
		ft_putchar('-', counter);
		if (*counter == -1)
			return ;
		ft_putnbrdecrec(-num, counter);
	}
	else
		ft_putnbrdecrec(num, counter);
}

// Writes an unsigned number base 10 (%u)
void	ft_putnbrunsigned(unsigned int num, int *counter)
{
	if (num > 9)
	{
		ft_putnbrunsigned(num / 10, counter);
		if (*counter == -1)
			return ;
		ft_putnbrunsigned(num % 10, counter);
	}
	else
		ft_putchar(num + 48, counter);
	if (*counter == -1)
		return ;
}

// Writes a hexadecimal number (%x %X)
void	ft_putnbrhex(unsigned long num, char c, int *counter)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (num > 15)
	{
		ft_putnbrhex(num / 16, c, counter);
		if (*counter == -1)
			return ;
		ft_putnbrhex(num % 16, c, counter);
	}
	else
	{
		if ((c == 'x' || c == 'p') || num < 10)
			ft_putchar(hexa[num], counter);
		else if (c == 'X')
			ft_putchar(hexa[num] - 32, counter);
		if (*counter == -1)
			return ;
	}
}

// Writes a pointer address (%p)
void	ft_putpointer(unsigned long adr, int *counter)
{
	ft_putstr("0x", counter);
	if (*counter == -1)
		return ;
	ft_putnbrhex(adr, 'p', counter);
}
