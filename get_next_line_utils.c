/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheloaho <jheloaho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:33:39 by jheloaho          #+#    #+#             */
/*   Updated: 2022/11/10 13:19:55 by jheloaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return (&(str[i]));
		i--;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dupe;

	i = ft_strlen(s);
	dupe = (char *) malloc((i + 1) * sizeof(char));
	if (!dupe)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		dupe[i] = s[i];
		i++;
	}
	dupe[i] = '\0';
	return (dupe);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s)))
		len = ft_strlen(s);
	sub = (char *) malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	while (i <= len)
	{
		sub[i] = '\0';
		i++;
	}
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}
