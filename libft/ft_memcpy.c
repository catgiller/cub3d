#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src_ptr;

	dst = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	while (n--)
		*dst++ = *src_ptr++;
	return (dest);
}
