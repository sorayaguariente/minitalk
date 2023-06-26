/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguarien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:43:34 by sguarien          #+#    #+#             */
/*   Updated: 2023/04/19 12:43:39 by sguarien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sendmessage(int server_pid, char *str)
{
	int		bitindex;
	char	currentchar;
	int		lenght;
	int		i;

	bitindex = 0;
	i = 0;
	lenght = ft_strlen(str);
	while (i <= lenght)
	{
		currentchar = str[i];
		while (bitindex < 8)
		{
			if (currentchar & 0b00000001)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			currentchar >>= 1;
			bitindex++;
			usleep(160);
		}
		i++;
		bitindex = 0;
	}
}

static void	ft_handlesignal(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message received\n");
}

void	ft_recivesignal(void)
{
	signal(SIGUSR1, ft_handlesignal);
	signal(SIGUSR2, ft_handlesignal);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (ft_printf("Invalid number of arguments, try again!\n"));
	pid = ft_atoi(argv[1]);
	ft_recivesignal();
	ft_sendmessage(pid, argv[2]);
	return (0);
}
