/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:29:26 by rde-fari          #+#    #+#             */
/*   Updated: 2024/11/17 16:55:07 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *) big);
	while (*big != '\0' && n-- >= little_len)
	{
		if (*big == *little && ft_strncmp(big, little, little_len) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
