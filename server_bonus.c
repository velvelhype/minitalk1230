#include "minitalk.h"

t_counts	g_counts;

void    handler(int signum)
{
	if(signum == SIGUSR1)
		g_counts.char_stock += 1;
	g_counts.count++;
	if (g_counts.count != 8)
		g_counts.char_stock <<= 1;
	else
	{
		write(1, &(g_counts.char_stock), 1);
	    g_counts.count = 0;
	    g_counts.char_stock = 0;
	}
}

int main()
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1) 
		pause();
}