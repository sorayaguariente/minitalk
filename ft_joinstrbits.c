/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinstrbits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguarien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:57:59 by sguarien          #+#    #+#             */
/*   Updated: 2023/04/20 15:58:07 by sguarien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	*ft_joinstrbits(unsigned char *str, unsigned char c)
{
	int				lenght;
	int				counter;
	unsigned char	*result;

	lenght = 0;
	counter = 0;
	if (str)
		lenght = ft_strlen((char *)str);
	result = malloc(sizeof(char) * (lenght + 2));
	if (str)
	{
		while (str[counter])
		{
			result[counter] = str[counter];
			counter++;
		}
	}
	result[counter] = c;
	result[counter + 1] = '\0';
	if (str)
		free(str);
	return (result);
}
