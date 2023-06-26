/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguarien <sguarien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:12:23 by sguarien          #+#    #+#             */
/*   Updated: 2023/04/12 15:46:37 by sguarien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_handlesignal(int signal)
{
	static int				bitsreceived = 0;
	static unsigned char	currentbit;
	static unsigned char	futurebyte;

	if (signal == SIGUSR1)
	{
		currentbit = 1;
		futurebyte = futurebyte | (currentbit << bitsreceived);
		bitsreceived++;
	}
	else if (signal == SIGUSR2)
	{
		currentbit = 0;
		futurebyte = futurebyte | (currentbit << bitsreceived);
		bitsreceived++;
	}
	if (bitsreceived == 8)
	{
		ft_printf("%c", (char)futurebyte);
		futurebyte = 0;
		bitsreceived = 0;
	}
}

void	ft_recivesignal(void)
{
	signal(SIGUSR1, ft_handlesignal);
	signal(SIGUSR2, ft_handlesignal);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Your Process ID is: %d\n", pid);
	ft_recivesignal();
	while (1)
		pause();
}
