#include "libft.h"

long	ft_atol(const char *nptr)
{
	long	n;
	int		i;
	long	sign;

	i = 0;
	sign = 1;
	n = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		n = (n * 10) + (nptr[i] - '0');
		i++;
	}
	return (n * sign);
}