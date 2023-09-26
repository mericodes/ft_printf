/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:27:02 by mlopez-i          #+#    #+#             */
/*   Updated: 2023/07/18 14:19:15 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Writes a char and sums the counter (%c)
void	ft_putchar(int c, int *counter)
{
	if (write(1, &c, 1) == -1)
		*counter = -1;
	else
		*counter += 1;
}

// Writes a string (%s)
void	ft_putstr(char *str, int *counter)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", counter);
		return ;
	}
	while (str[i])
	{
		ft_putchar(str[i], counter);
		if (*counter == -1)
			return ;
		i++;
	}
}
