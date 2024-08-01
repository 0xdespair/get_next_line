#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*dup;
	int		i;

	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s_join;
	int		i;
	int		j;

	s_join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s_join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s_join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s_join[i + j] = s2[j];
		j++;
	}
	s_join[i + j] = '\0';
	return (s_join);
}

char	*extract_line(char *s)
{
	int		i;
	char	*line;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clean_stock(char **stock)
{
	int		i;
	int		j;
	char	*new_stock;

	i = 0;
	j = 0;
	while ((*stock)[i] && (*stock)[i] != '\n')
		i++;
	if ((*stock)[i] == '\n')
		i++;
	new_stock = malloc(ft_strlen(*stock) - i + 1);
	if (!new_stock)
		return (NULL);
	while ((*stock)[i + j])
	{
		new_stock[j] = (*stock)[i + j];
		j++;
	}
	new_stock[j] = '\0';
	free(*stock);
	return (new_stock);
}
