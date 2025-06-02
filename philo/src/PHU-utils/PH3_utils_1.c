/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PH3_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:05:58 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/02 18:06:19 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*call;
	size_t			i;

	call = malloc(size * nmemb);
	if (!call)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
	{
		call[i] = 0;
		i++;
	}
	return (call);
}
