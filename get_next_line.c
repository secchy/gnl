/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheloaho <jheloaho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:51:03 by jheloaho          #+#    #+#             */
/*   Updated: 2022/11/28 17:50:22 by jheloaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char    *get_next_line(int fd)
{
	char		*line;
	static char	*prev;
	char		*temp;
	int			len;
	ssize_t		result;
	
	if (!fd)
		return (NULL);
	line = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	result = read(fd, line, BUFFER_SIZE);
	line[result] = '\0';
	len = 0;
	if (!prev)
		prev = "";
	temp = ft_strjoin(prev, line);
	while (result != -1)
	{
		temp = ft_strjoin(temp, line);
		while (result-- > 0)
		{
			if (temp[len] == '\n' || temp[len] == '\0')
			{
				prev = ft_substr(temp, len + 1, ft_strlen(temp) - len);
				line = ft_substr(temp, 0, len);
				return (line);
			}
			len++;
		}
		result = read(fd, line, BUFFER_SIZE);
		line[result] = '\0';
		if (result == 0)
		{
			if (prev[result] != '\0')
				temp = prev;
			else
			{
				if (*prev)
					free (prev);
				free (line);
				free (temp);
				return (NULL);
			}
		}
	}
	free (line);
	free (temp);
	return (NULL);
}