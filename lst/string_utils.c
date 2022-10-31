#include "utils.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*ret;
	int		len;
	int		i;

	if (str == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	ret = malloc(len + 1);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int	ft_strcmp(char *str, char *str2)
{
	int	i;

	if (str == NULL || str2 == NULL)
		return (1);
	i = 0;
	while (str[i] && str2[i])
	{
		if (str[i] != str2[i])
			return (1);
		i++;
	}
	if (str[i] || str2[i])
		return (1);
	return (0);
}
