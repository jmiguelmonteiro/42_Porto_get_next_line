/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:57:48 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/10 13:06:11 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_null(char *str)
{
	if (str)
		free(str);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_result;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_result = len_s1 + len_s2;
	result = malloc((len_result + 1) * sizeof (*result));
	if (!result)
		return (NULL);
	ft_memmove(result, s1, len_s1);
	ft_memmove(result + len_s1, s2, len_s2);
	result[len_result] = '\0';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	cc;

	str = (char *) s;
	cc = (char) c;
	i = 0;
	while (str[i])
	{
		if (str[i] == cc)
			return (&str[i]);
		i++;
	}
	if (cc == '\0')
		return (&str[i]);
	return (NULL);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;
	size_t				i;

	if ((dest == NULL) && (src == NULL))
		return (NULL);
	ptr_dest = (unsigned char *) dest;
	ptr_src = (const unsigned char *) src;
	i = 0;
	if (ptr_dest > ptr_src)
		while (n--)
			ptr_dest[n] = ptr_src[n];
	else
	{
		while (i < n)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
	}
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	while (n--)
		*ptr++ = (unsigned char) c;
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb && size && nmemb > (INT_MAX / size))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, '\0', nmemb * size);
	return (ptr);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr_s;

	i = 0;
	ptr_s = (unsigned char *) s;
	while (i < n)
	{
		if (ptr_s[i] == (unsigned char) c)
			return (&ptr_s[i]);
		i++;
	}
	return ((void *) NULL);
}
