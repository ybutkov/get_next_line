/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:40:30 by ybutkov           #+#    #+#             */
/*   Updated: 2025/07/29 11:55:38 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*source;

	if (dst == NULL && src == NULL)
		return (NULL);
	dest = dst;
	source = src;
	if (src - dst > 0)
		while (len--)
			*dest++ = *source++;
	else
		while (len--)
			dest[len] = source[len];
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	value;
	unsigned char	*ch;

	value = (unsigned char)c;
	ch = b;
	while (len--)
		*ch++ = value;
	return (b);
}
