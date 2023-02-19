/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:23:51 by mmita             #+#    #+#             */
/*   Updated: 2023/02/19 17:59:31 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		i++;
	}
	return (i);
}

/**
 * @brief 
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	else
		return (NULL);
}

void	*ft_bzero(void *b, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (n-- > 0)
		*(ptr++) = '\0';
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (0);
	ft_bzero(ptr, (size * count));
	return (ptr);
}

/*
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	c1;
	size_t	c2;
	size_t	strlen_s1;
	size_t	strlen_s2;

	if (!s1 && !s2)
		return (NULL);
	strlen_s1 = ft_strlen(s1);
	strlen_s2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (strlen_s1 + strlen_s2 + 1));
	if (!str)
		return (0);
	c1 = 0;
	while (c1 < strlen_s1)
	{
		str[c1] = s1[c1];
		c1++;
	}
	c2 = 0;
	while (c2 < strlen_s2)
		str[c1++] = s2[c2++];
	str[c1] = '\0';
	free (s1);
	return (str);
}

*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = (char *)malloc (sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if ((!s1 && !s2) || !str)
	{
		return (NULL);
	}
	while (s1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
