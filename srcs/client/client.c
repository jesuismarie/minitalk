/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:37:53 by mnazarya          #+#    #+#             */
/*   Updated: 2023/05/13 22:50:15 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void	yngerjan(int pid, char *str)
{
	int bit;
	int	i;

	i = -1;
	while (str[++i])
	{
		bit = 0;
		while (bit < 8)
		{
			if ((i & (0x01 << bit)))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			bit++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3 || ft_strlen(argv[2]) == 0)
		return (1);
	pid = ft_atoi(argv[1]);
	yngerjan(pid, argv[2]);
	return (0);
}
