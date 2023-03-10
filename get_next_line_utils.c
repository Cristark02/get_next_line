/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:23:51 by mmita             #+#    #+#             */
/*   Updated: 2023/03/11 13:47:22 by mmita            ###   ########.fr       */
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
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	counter;

	counter = 0;
	while (n != 0 && counter++ <= (n - 1))
	{
		*(char *)s = '\0';
		s++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}

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
