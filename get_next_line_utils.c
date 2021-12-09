#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen((char *)str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *silo, char *buf)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!silo)
	{
		silo = (char *)malloc(1 * sizeof(char));
		silo[0] = '\0';
	}
	if (!silo || !buf)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(silo) + ft_strlen(buf)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (silo)
		while (silo[++i] != '\0')
			str[i] = silo[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	str[ft_strlen(silo) + ft_strlen(buf)] = '\0';
	free(silo);
	return (str);
}

char	*ft_getline(char *silo)
{
	int		i;
	char	*str;

	i = 0;
	if (!silo[i])
		return (NULL);
	while (silo[i] && silo[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (silo[i] && silo[i] != '\n')
	{
		str[i] = silo[i];
		i++;
	}
	if (silo[i] == '\n')
	{
		str[i] = silo[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_silo(char *silo)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (silo[i] && silo[i] != '\n')
		i++;
	if (!silo[i])
	{
		free(silo);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(silo) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (silo[i])
		str[j++] = silo[i++];
	str[j] = '\0';
	free(silo);
	return (str);
}
