/* ************************************************************************** */
/*                                                                          */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguarien <sguarien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:11:47 by sguarien          #+#    #+#             */
/*   Updated: 2023/04/12 15:46:38 by sguarien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sendsignals(int pid, char *str)
{
	int			bitindex;
	char		currentchar;
	int			i;

	i = 0;
	bitindex = 0;
	while (str[i])
	{
		currentchar = str[i];
		while (bitindex < 8)
		{
			if (currentchar & 0b00000001)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			currentchar = currentchar >> 1;
			bitindex++;
			usleep(100);
		}
		i++;
		bitindex = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (ft_printf("Invalid number of arguments, try again!\n"));
	pid = ft_atoi(argv[1]);
	ft_sendsignals(pid, argv[2]);
	return (0);
}
