# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguarien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 14:33:18 by sguarien          #+#    #+#              #
#    Updated: 2022/12/12 18:42:29 by sguarien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBFT		= ./libft/libft.a
LIBFTDIR	= ./libft

SRC			=./src

PRINTF_SRCS	= ft_printf.c ft_printf_hexadec.c ft_printf_pointer.c \
				ft_printf_unsigned.c ft_printf_utils.c

OBJS		= $(PRINTF_SRCS:.c=.o)

CC			= cc 
AR			= ar rcs
RM			= rm -rf 
CFLAGS		= -Wall -Wextra -Werror
CP			= cp

MSG1		= @echo "Compilation complete"
MSG2		= @echo "Cleaning complete"
MSG3		= @echo "ReCompilation complete"

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
				$(CP) $(LIBFT) $(NAME)
				@$(AR) $(NAME) $(OBJS)
				$(MSG1)

$(LIBFT):	$(LIBFTDIR)
				@$(MAKE) -C $(LIBFTDIR)

%.o: 		$(SRC)/%.c
				@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(MAKE) clean -C $(LIBFTDIR)
			@$(RM) $(OBJS)
			$(MSG2)

fclean:		clean
				@$(MAKE) fclean -C $(LIBFTDIR)
				@$(RM) $(NAME)
				$(MSG2)

re:			fclean all
				$(MSG3)

.PHONY:		all clean fclean re