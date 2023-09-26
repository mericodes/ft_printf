/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:01:23 by mlopez-i          #+#    #+#             */
/*   Updated: 2023/09/26 21:05:30 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

// ft_printfutils.c
void			ft_putchar(int c, int *counter);
void			ft_putstr(char *str, int *counter);

// ft_printfnums.c
void			ft_putnbrdecrec(int num, int *counter);
void			ft_putnbrdec(int num, int *counter);
void			ft_putnbrunsigned(unsigned int num, int *counter);
void			ft_putnbrhex(unsigned long num, char c, int *counter);
void			ft_putpointer(unsigned long adr, int *counter);

// ft_printf.c
void			ft_printspecial(char c, int *counter, va_list args);
int				ft_printf(char const *str, ...);

#endif