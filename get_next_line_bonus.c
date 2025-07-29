/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:40:04 by ybutkov           #+#    #+#             */
/*   Updated: 2025/07/29 18:48:02 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static char	*fill_str_from_buffer(char *cur_str, int *total_len, char *buffer)
{
	int		len;
	char	*res;

	len = 0;
	res = NULL;
	while (len < BUFFER_SIZE && buffer[len] && buffer[len] != '\n')
		len++;
	if (len < BUFFER_SIZE && buffer[len] == '\n')
		len += 1;
	if (len == 0)
		return (cur_str);
	res = malloc((*total_len + len + 1) * sizeof(char));
	if (res == NULL)
		return (free(cur_str), NULL);
	if (cur_str)
	{
		ft_memmove(res, cur_str, *total_len);
		free(cur_str);
	}
	ft_memmove(res + *total_len, buffer, len);
	ft_memmove(buffer, buffer + len, BUFFER_SIZE - len);
	ft_memset(buffer + BUFFER_SIZE - len, '\0', len);
	*total_len += len;
	return (res);
}

static char	*read_from_fd(int fd, char *res, int total_len, char *buffer)
{
	ssize_t		read_bytes;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			if (res)
				free(res);
			return (NULL);
		}
		else if (read_bytes == 0)
			break ;
		res = fill_str_from_buffer(res, &total_len, buffer);
		if (!res)
			return (NULL);
		if (res[total_len - 1] == '\n')
			break ;
	}
	if (res)
		res[total_len] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buffer[FD_MAX_SIZE][BUFFER_SIZE];
	int			total_len;
	char		*res;

	if (fd < 0 || fd >= FD_MAX_SIZE)
		return (NULL);
	res = NULL;
	total_len = 0;
	if (buffer[fd][0])
		res = fill_str_from_buffer(NULL, &total_len, buffer[fd]);
	if (buffer[fd][0] != '\0' && res == NULL)
		return (NULL);
	if (res && res[total_len - 1] == '\n')
		return (res[total_len] = '\0', res);
	res = read_from_fd(fd, res, total_len, buffer[fd]);
	return (res);
}
