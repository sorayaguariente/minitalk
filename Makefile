# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguarien <sguarien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 17:13:16 by sguarien          #+#    #+#              #
#    Updated: 2023/04/12 15:42:21 by sguarien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= minitalk.a

CLIENT			= client
SERVER			= server

PRINTF			= ./printf/libftprintf.a
PRINTFDIR		= ./printf
CC				= cc
AR				= ar rcs
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror

MSG1			= @echo "Client Created"
MSG2			= @echo "Server Created"
MSG3			= @echo "Cleaning complete"
MSG4			= @echo "ReCompilation complete"
MSG5			= @echo "Bonus Created"

all: 			$(CLIENT) $(SERVER)

$(CLIENT):
				@$(MAKE) --no-print-directory -C $(PRINTFDIR)
				@$(CC) $(CFLAGS) client.c $(PRINTF) -o client
				$(MSG1)

$(SERVER):
				@$(MAKE) --no-print-directory -C $(PRINTFDIR)
				@$(CC) $(CFLAGS) server.c $(PRINTF) -o server
				$(MSG2)

bonus:
				@$(MAKE) -C $(PRINTFDIR)
				$(CC) $(CFLAGS) ft_joinstrbits.c client_bonus.c $(PRINTF) -o client_bonus
				$(CC) $(CFLAGS) ft_joinstrbits.c server_bonus.c $(PRINTF) -o server_bonus
				$(MSG5)

clean:			
				@$(MAKE) clean -C $(PRINTFDIR)
				$(RM) client server client_bonus server_bonus
				$(MSG3)	

fclean:			clean
					@$(MAKE) fclean -C $(PRINTFDIR)

re:				fclean all
					$(MSG4)

.PHONY:			all clean fclean re