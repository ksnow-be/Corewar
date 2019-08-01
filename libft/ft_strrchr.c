/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:42:16 by lgigi             #+#    #+#             */
/*   Updated: 2019/04/03 13:43:13 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int size;

	size = ft_strlen(str);
	if (!str)
		return (NULL);
	while (size--)
		if (str[size] == (char)c)
			return ((char *)&str[size]);
	size = ft_strlen(str);
	return ((!c) ? (char *)(str + size) : NULL);
}
