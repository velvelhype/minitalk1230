#include "minitalk.h"

void	error_case()
{
	write(2, "Error\n", 6);
	exit(1);
}

int	custom_atoi(const char *str)
{
	unsigned long	i;
	int				j;
	unsigned long	sum;

	sum = 0;
	i = 0;
	j = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			j = j * -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		sum = (sum * 10) + str[i] - '0';
		i++;
	}
	if (ft_isalpha(str[i]))
		error_case();
	return ((int)j * sum);
}


void	send_char(int pid, char a)
{
	// printf("c: send %c\n", a);
	// printf("pid %d\n", pid);
	int i;

	i = 7;
	if(pid == -1 || pid == 0)
		error_case();
	if (kill(pid, 0) == -1)
		error_case();
	while (i >= 0)
	{
		if (a >> i & 1)
			kill(pid, SIGUSR1);	
		else
			kill(pid, SIGUSR2);	
		usleep(100);
		i--;
	}
}

void	send_str(char **argv)
{
	int	pid;

	pid = custom_atoi(argv[1]);
	printf("s: send %s\n", argv[2]);
	while (*argv[2])
	{
		send_char(pid, *argv[2]);
		++(argv[2]);
	}
	send_char(pid, '\n');
}

int main(int argc, char **argv)
{
	int pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	if (argc != 3)
		exit(1);
	send_str(argv);
}