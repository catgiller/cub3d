#include <stdlib.h>
#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int	len;
	int	sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count_digits(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = '0' + (n % 10);
		n /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
