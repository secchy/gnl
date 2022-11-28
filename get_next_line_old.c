/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheloaho <jheloaho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:33:14 by jheloaho          #+#    #+#             */
/*   Updated: 2022/11/28 15:50:15 by jheloaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
//#include <stdio.h>

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
	if (result == -1)
	{
		free(line);
		return (NULL);
	}
	if (result == 0)
	{
		if (prev != NULL)
		{
			
		}
	}
	line[result] = '\0';
	if (!prev)
		prev = "";
//	printf("%s\n", line);
	temp = ft_strjoin(prev, line);
	len = 0;
	while (temp[len] != '\n' && temp[len] != '\0')
	{
		len++;
		if ((len % BUFFER_SIZE) == 0 && temp[len] != '\n' && temp[len] != '\0')
		{
			read(fd, line, BUFFER_SIZE);
//check read result again?
			temp = ft_strjoin(temp, line);
		}
	}
	if (temp[len] == '\n')
	{
		prev = ft_substr(temp, len, (ft_strlen(temp) - len));
		return(ft_substr(temp, 0, len));
	}
	else if (temp[len] == '\0')
	{
		free(line);
		if (*prev)
			free(prev);
		return (temp);
	}
	else
		return(NULL);
}
