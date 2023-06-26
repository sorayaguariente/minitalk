/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguarien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:43:50 by sguarien          #+#    #+#             */
/*   Updated: 2023/04/19 12:43:53 by sguarien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	*g_strbits = NULL;

static void	ft_handle_signal(int sign, siginfo_t *signinfo, void *lastaction)
{
	static unsigned char	currentbit = 0;
	static unsigned char	futurebyte = 0;
	static int				bitsreceived = 0;

	(void)lastaction;
	futurebyte = (sign == SIGUSR1);
	currentbit = currentbit | (futurebyte << bitsreceived);
	bitsreceived++;
	if (bitsreceived == 8)
	{
		g_strbits = ft_joinstrbits(g_strbits, currentbit);
		if (currentbit == '\0')
		{
			ft_printf("%s", g_strbits);
			kill(signinfo->si_pid, SIGUSR1);
			free(g_strbits);
			g_strbits = NULL;
		}
		currentbit = 0;
		bitsreceived = 0;
	}
}

void	ft_recivesignal(void)
{
	struct sigaction	signal;

	signal.sa_sigaction = &ft_handle_signal;
	signal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
}

int	main(void)
{
	ft_printf("Your Process ID is: %d\n", getpid());
	ft_recivesignal();
	while (1)
		pause();
}
