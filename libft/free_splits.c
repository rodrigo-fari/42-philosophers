/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_splits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:29:08 by rde-fari          #+#    #+#             */
/*   Updated: 2024/11/26 11:29:12 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	free_splits(char **line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
		free(line[i++]);
	free(line);
	return (0);
}
