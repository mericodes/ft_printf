# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 15:57:28 by mlopez-i          #+#    #+#              #
#    Updated: 2023/09/26 21:06:56 by mlopez-i         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS	=	ft_printf.c			\
			ft_printfnums.c		\
			ft_printfutils.c	\

OBJS	= ${SRCS:.c=.o}
CC		= cc
CFLAGS 	= -Wall -Werror -Wextra
RM		= rm -rf
AR		= ar rcs
HEADER = ft_printf.h

all	:	$(NAME)
		@echo Compiling mandatory part of "libftprintf.a": $@ ...

$(NAME)	:	$(OBJS)
		@echo Compiling library file: $@ ...
		$(AR) $(NAME) $(OBJS)

%.o:	%.c $(HEADER) Makefile
		@echo Compiling files: $@ ...
		$(CC) $(CFLAGS) -c $< -o $@ 

clean	:	
		@echo Cleaning object files: $@ ...
		$(RM) ${OBJS}


fclean	:	clean
		@echo Cleaning object files and libftprintf.a:
		$(RM) $(NAME)

re	:	fclean all
		@echo Cleaning object files and libftprintf.a and remake everything:

	.PHONY: all clean fclean re