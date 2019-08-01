/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:40:13 by lgigi             #+#    #+#             */
/*   Updated: 2019/04/03 14:18:15 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str1;
	char	*str2;

	str1 = (char *)haystack;
	str2 = (char *)needle;
	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (str1[i] != '\0' && i < len)
	{
		j = 0;
		while (str2[j] != '\0' && str1[j + i] == str2[j] && j < len \
				&& j + i < len)
			j++;
		if (str2[j] == '\0')
			return (str1 + i);
		i++;
	}
	return (NULL);
}
