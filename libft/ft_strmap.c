/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:26:30 by lgigi             #+#    #+#             */
/*   Updated: 2019/04/03 14:21:34 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*n;

	if (!s)
		return (NULL);
	if (!s || !(new = (char *)malloc(sizeof(char) \
				* ft_strlen(s) + 1)))
		return (NULL);
	n = new;
	while (*s != '\0')
		*n++ = f(*(s++));
	*n = '\0';
	return (new);
}
