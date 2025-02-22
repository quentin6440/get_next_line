#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

size_t	linelen(char *str)
{
	size_t	i;
	
	i = 0;
	while (str[i] && str[i] != '\n');
	{
		i++;
	}
	return (i);
}

int	main(void)
{
	int	fd;
	char	*buf;
	size_t	BUFFER_SIZE = 999;
	ssize_t	bytesread;

	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (0);

	fd = open("./text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("error");
		return (1);
	}

	bytesread = read(fd, (void *)buf, linelen(buf));
	buf[bytesread] = 0;
	printf("%ld : '%s'\n", bytesread, buf);
/*
	bytesread = read(fd, (void *)buf, 12);
	buf[bytesread] = 0;
	printf("%ld : '%s'\n", bytesread, buf);
	bytesread = read(fd, (void *)buf, 25);
	buf[bytesread] = 0;
	printf("%ld : '%s'\n", bytesread, buf);
*/
	free(buf);
	close (fd);
	return (0);
}
