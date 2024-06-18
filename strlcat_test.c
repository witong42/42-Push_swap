#include <stdio.h>
#include <bsd/string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle[0] && len == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && i + j < len)
		{
			if (haystack[i + j] != needle[j])
				break ;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

int main()
{
    char    *dest;
    char    *src;

    dest = "Hello World Next";
    src = "";
printf("%s", strnstr(dest, src, -1));
printf("%s", ft_strnstr(dest, src, -1));

}
