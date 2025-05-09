/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:58:48 by isousa-s          #+#    #+#             */
/*   Updated: 2025/05/09 19:33:42 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_server_data	g_server;

void	handle_signal(int signal)
{
	g_server.current_char = g_server.current_char << 1;
	if (signal == SIGUSR2)
		g_server.current_char = g_server.current_char | 1;
	g_server.bit_count++;
	if (g_server.bit_count == 8)
	{
		write(1, &g_server.current_char, 1);
		if (g_server.current_char == '\0')
			write(1, "\n", 1);
		g_server.current_char = 0;
		g_server.bit_count = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	g_server.current_char = 0;
	g_server.bit_count = 0;
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
