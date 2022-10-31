#include "utils.h"

void	*ft_malloc(size_t size)
{
	void	*ret;

	if (size < 0)
		return (NULL);
	ret = malloc(size);
	return (ret);
}

void	*ft_calloc(size_t size)
{
	char	*ret;
	size_t	i;

	ret = (char *)ft_malloc(size);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ret[i] = 0;
		i++;
	}
	return ((void *)ret);
}
