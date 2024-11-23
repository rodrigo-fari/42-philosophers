/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:29:10 by rde-fari          #+#    #+#             */
/*   Updated: 2024/11/17 16:29:11 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	p;

	srcsize = ft_strlen(src);
	p = 0;
	if (!dst || !src)
		return (0);
	if (dstsize != 0)
	{
		while (src[p] != '\0' && p < (dstsize - 1))
		{
			dst[p] = src[p];
			p++;
		}
		dst[p] = '\0';
	}
	return (srcsize);
}
