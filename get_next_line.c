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
	char	*line;
	char	*temp;
	char	*ret;
	int		len;
	int		ret;
	
	line = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	len = 0;
	ret = read(fd, line, BUFFER_SIZE);
	if (ret == -1 || ret == 0)
		return (NULL);
	while (line[len] != '\n' && line[len] != '\0)
		len++;
	if (line[len] == '\n')
	{
		ret = ft_strsub(line, 0, len;
	}
}	
//return (*line) if correct behavior    
//return (NULL); if EOF or error
