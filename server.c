#include "minitalk.h"

int     char_stock = 0;
int		count  = 0;


void    handler(int signum)
{
	if(signum == SIGUSR1)
		char_stock += 1;
	count++;
}

int main()
{
	printf("%d\n", getpid());
	struct sigaction sa_signal;
	sigset_t	mask;

	// sigemptyset(&mask);
	// sigaddset(&mask, SIGINT);
	// sigaddset(&mask, SIGQUIT);

	memset(&sa_signal, 0, sizeof(sa_signal));
	sa_signal.sa_handler = handler;
	sa_signal.sa_flags = SA_RESTART;
	// sa_signal.sa_mask = mask;
	if (sigaction(SIGUSR1, &sa_signal, NULL) < 0)
	{
		perror("sigaction");
		exit(1);
	}
	if (sigaction(SIGUSR2, &sa_signal, NULL) < 0)
	{
		perror("sigaction");
		exit(1);
	}
	while (1) 
	{
		pause();
		// printf("count is %d\n", count);
		if (count != 8)
			char_stock <<= 1;
		else
		{
			write(1, &char_stock, 1);
		    count = 0;
		    char_stock = 0;
		}
	}
}