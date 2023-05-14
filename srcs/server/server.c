/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:28:10 by mnazarya          #+#    #+#             */
/*   Updated: 2023/05/13 21:30:31 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static void	err_mss(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	sig_identifier(int sig, siginfo_t *info, void *s)
{
	static int	bit;
	static int	i;

	(void)info;
	(void)s;
	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(i, 1);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 1)
		return (1);
	(void)argv;
	sa.sa_sigaction = &sig_identifier;
	sa.sa_flags = SA_SIGINFO;
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			err_mss();
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			err_mss();
	}
	return (0);
}
