/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:17:21 by lgigi             #+#    #+#             */
/*   Updated: 2019/04/05 11:22:09 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupcase(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		str[i] -= (str[i] >= 'a' && str[i] <= 'z') ? 32 : 0;
		i++;
	}
	return (str);
}