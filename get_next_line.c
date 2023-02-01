/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheloaho <jheloaho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:51:03 by jheloaho          #+#    #+#             */
/*   Updated: 2023/02/01 08:45:19 by jheloaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

char	*ft_read_file(int fd, char *stash)
{
	char	*line;
	ssize_t bytes;

	if (!stash)
		stash = "";
	line = (char *) malloc((BUFFER_SIZE + 1) * sizeof(size_t));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, line, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(stash);
			return (NULL);
		}
		line[bytes] = '\0';
		stash = ft_strjoin(stash, line);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free (line);
	return (stash);
}

char    *get_next_line(int fd)
{
	char		*line;
	static char	*stash;
	int			len;

	if (!fd || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	stash = ft_read_file(fd, stash);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	line = ft_substr(stash, 0, len);
	stash = ft_substr(stash, len + 1, ft_strlen(stash) - len - 1);
	return (line);
}
