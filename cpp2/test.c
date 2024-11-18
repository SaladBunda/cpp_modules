#include <string.h>
#include <stdlib.h>
#include <stdio.h>



size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	count;

	count = strlen(src);
	if (dstsize == 0)
		return (count);
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
}

int main()
{
    char dest[5];
    char src[] = "nada";
    printf("%lu\n",sizeof(src));
    printf("%lu\n", ft_strlcpy(dest, src,4));
    printf("%s\n", dest);
}