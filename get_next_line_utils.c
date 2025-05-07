/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:57:48 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/07 18:29:55 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;

	if ((dest == NULL) && (src == NULL))
		return (NULL);
	ptr_dest = (unsigned char *) dest;
	ptr_src = (const unsigned char *) src;
	while (n--)
		*ptr_dest++ = *ptr_src++;
	return (dest);
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
	ft_memcpy(result, s1, len_s1);
	ft_memcpy(result + len_s1, s2, len_s2);
	result[len_result] = '\0';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*str;
	char	cc;

	str = (char *) s;
	cc = (char) c;
	len = ft_strlen(str);
	if (cc == '\0')
		return (&str[len]);
	while (len > 0)
	{
		if (str[len - 1] == cc)
			return (&str[len - 1]);
		len--;
	}
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
