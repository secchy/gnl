/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheloaho <jheloaho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:33:14 by jheloaho          #+#    #+#             */
/*   Updated: 2022/11/10 13:24:46 by jheloaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char    *get_next_line(int fd)
{
	char		*line;
	char		*ret;
	static char	*temp;
	int			len;
	size_t		result;
	
	if (!fd)
		return (NULL);
	line = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	len = 0;
	result = read(fd, line, BUFFER_SIZE);
	ret = line;
	if (result == -1 || result == 0)
		return (NULL);
	while (line[len] != '\n' && line[len] != '\0')
	{
		len++;
		if (len == BUFFER_SIZE)
			ft_strjoin(ret, line);
	}
	if (line[len] == '\n')
	{
		ret = ft_substr(line, 0, len);
		if (ret)
			return(ret);
	}
	else if (line[len] == '\0')
		return (ft_strdup(line));
}	
