#include "get_next_line.h"

int	check_newline(char *stock)
{
	int	i;

	i = 0;
	while (stock[i])
	{
		if (stock[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	add_to_stock(char **stock, char *buffer)
{
	char	*temp_stock;

	temp_stock = NULL;
	if (!*stock)
	{
		*stock = ft_strdup(buffer);
		if (!*stock)
			return ;
	}
	else
	{
		temp_stock = ft_strdup(*stock);
		if (!temp_stock)
			return ;
		free(*stock);
		*stock = ft_strjoin(temp_stock, buffer);
		if (!*stock)
			return ;
		free (temp_stock);
	}
}

void	read_next_line(int fd, char	**stock, int *bytes_read)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return ;
	while (*bytes_read > 0)
	{
		*bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (*bytes_read == 0 || *bytes_read == -1)
		{
			free(buffer);
			return ;
		}
		buffer[*bytes_read] = '\0';
		add_to_stock(stock, buffer);
		if (!*stock)
			return ;
		if (check_newline(*stock))
		{
			free(buffer);
			return ;
		}
	}
	free(buffer);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;
	int			bytes_read;

	bytes_read = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	read_next_line(fd, &stock, &bytes_read);
	if (!stock)
		return (NULL);
	line = extract_line(stock);
	if (!line)
		return (NULL);
	stock = clean_stock(&stock);
	if (!stock)
		return (NULL);
	if (line[0] == '\0')
	{
		free(stock);
		stock = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
