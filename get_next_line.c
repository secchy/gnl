/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheloaho <jheloaho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:51:03 by jheloaho          #+#    #+#             */
/*   Updated: 2023/02/18 21:06:33 by jheloaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

char	*ft_join_and_free(char *stash, char *line)
{
	char	*temp;

	temp = ft_strjoin(stash, line);
	free(stash);
	return (temp);
}

char	*ft_read_file(int fd, char *stash)
{
	char	*line;
	ssize_t	bytes;

	if (!stash)
		stash = ft_calloc(1, 1);
	if (ft_strchr(stash, '\n'))
		return (stash);
	line = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, line, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(line);
			return (NULL);
		}
		line[bytes] = '\0';
		stash = ft_join_and_free(stash, line);
	}
	free (line);
	return (stash);
}

char	*get_line(char *stash)
{
	int		len;
	char	*line;

	len = 0;
	if (!stash[len])
		return (NULL);
	while (stash[len] && stash[len] != '\n')
		len++;
	line = ft_calloc((len + 2), sizeof(char));
	len = 0;
	while (stash[len] && stash[len] != '\n')
	{
		line[len] = stash[len];
		len++;
	}
	if (stash[len] == '\n')
		line[len] = '\n';
	return (line);
}

char	*ft_stash(char *stash)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(stash) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (stash[i])
		str[j++] = stash[i++];
	free(stash);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	stash = ft_read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = ft_stash(stash);
	return (line);
}
