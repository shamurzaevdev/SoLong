/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashamurz <ashamurz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:51:28 by ashamurz          #+#    #+#             */
/*   Updated: 2022/10/15 00:11:12 by ashamurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	len;
	char	*dest;

	len = ft_strlen((char *)src);
	if (src == NULL)
		return (NULL);
	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// char	*ft_substr(char *s, unsigned int start, size_t len)
// {
// 	char	*dest;
// 	size_t	i;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	if (ft_strlen(s) < start)
// 		len = 0;
// 	dest = malloc(sizeof(char) * (len + 1));
// 	if (dest == NULL)
// 		return (NULL);
// 	while (s[i] && i < len)
// 	{
// 		dest[i] = s[start + i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	return (NULL);
}
