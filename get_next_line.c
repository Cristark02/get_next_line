/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:09:12 by mmita             #+#    #+#             */
/*   Updated: 2023/02/19 17:16:55 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_memory(int fd, char *memo)
{
	char	*store;
	int		byte_nbr;

	byte_nbr = 1;
	store = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!store && !ft_strchr(memo, '\n'))
		return (0);
	while (byte_nbr > 0)
	{
		byte_nbr = read(fd, store, BUFFER_SIZE);
		if (byte_nbr == -1)
		{
			free(memo);
			free(store);
			return (0);
		}
		else if (byte_nbr == 0)
			break ;
		store[byte_nbr] = '\0';
		memo = ft_strjoin(memo, store);
	}
	free(store);
	return (memo);
}

char	*ft_return_line(char *memo)
{
	int		i;
	char	*str;

	i = 0;
	if (!memo && *memo == '\0')
		return (NULL);
	while (memo[i] != '\0' && memo[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (memo[i] && memo[i] != '\n')
	{
		str[i] = memo[i];
		i++;
	}
	if (memo[i] == '\n')
		str[i] = '\n';
	return (str);
}

char	*ft_update_memo(char *memo)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (memo[i] != '\0' && memo[i] != '\n')
		i++;
	if (!memo[i])
	{
		free(memo);
		return (0);
	}
	str = ft_calloc(ft_strlen(memo) - i + 1, sizeof(char));
	if (!str)
	{
		return (0);
	}
	i++;
	while (memo[i] != '\0')
		str[j++] = memo[i++];
	free(memo);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*return_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	memory = ft_read_memory (fd, memory);
	if (!memory)
		return (0);
	return_line = ft_return_line (memory);
	memory = ft_update_memo (memory);
	return (return_line);
}
