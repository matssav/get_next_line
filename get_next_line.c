#include "get_next_line.h"

char	*ft_read_to_silo(int fd, char *silo)
{
	char	*buff;
	int		bytes_r;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes_r = 1;
	while (!ft_strchr(silo, '\n') && bytes_r != 0)
	{
		bytes_r = read(fd, buff, BUFFER_SIZE);
		if (bytes_r == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_r] = '\0';
		silo = ft_strjoin(silo, buff);
	}
	free(buff);
	return (silo);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*silo;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	silo = ft_read_to_silo(fd, silo);
	if (!silo)
		return (NULL);
	line = ft_getline(silo);
	silo = ft_new_silo(silo);
	return (line);
}
