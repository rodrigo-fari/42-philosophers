/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:29:30 by rde-fari          #+#    #+#             */
/*   Updated: 2024/11/17 16:55:36 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	p;

	p = ft_strlen(s);
	while (p >= 0)
	{
		if (s[p] == (unsigned char)c)
			return ((char *)s + p);
		p--;
	}
	return (NULL);
}
