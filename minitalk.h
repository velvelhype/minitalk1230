#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_counts
{
	int	char_stock;
	int	strlen_stock;
	int	count;
}	t_counts;

#endif