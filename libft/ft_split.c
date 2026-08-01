#include <stdlib.h>
#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*next_word(const char *s, char c, size_t *start)
{
	char	*word;
	size_t	len;
	size_t	i;

	while (s[*start] == c)
		(*start)++;
	len = 0;
	while (s[*start + len] && s[*start + len] != c)
		len++;
	word = (char *)malloc(len + 1);
	if (!word)
		return (0);
	i = 0;
	while (i < len)
	{
		word[i] = s[*start + i];
		i++;
	}
	word[i] = '\0';
	*start += len;
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	count;
	size_t	i;
	size_t	start;

	if (!s)
		return (0);
	count = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (0);
	start = 0;
	i = 0;
	while (i < count)
	{
		result[i] = next_word(s, c, &start);
		if (!result[i])
			return (0);
		i++;
	}
	result[i] = 0;
	return (result);
}
