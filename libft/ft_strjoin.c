#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = (char *)malloc(len1 + len2 + 1);
	if (!join)
		return (0);
	ft_memcpy(join, s1, len1);
	ft_memcpy(join + len1, s2, len2 + 1);
	return (join);
}
