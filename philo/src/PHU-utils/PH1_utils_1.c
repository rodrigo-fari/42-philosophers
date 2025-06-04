/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PH1_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:56:46 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/04 12:52:32 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PH2.h"

bool	array_content(char **array)
{
	int	i;

	i = 1;
	while (array[i])
	{
		if (!array[i][0] || !is_digit(array[i]))
			return (PARSE_ERROR);
		i++;
	}
	return (PARSE_SUCCESS);
}

bool	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && (str[i] < '0' || str[i] > '9'))
			return (PARSE_ERROR);
		i++;
	}
	return (PARSE_SUCCESS);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signal;
	int	result;

	signal = 1;
	result = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			signal = signal * (-1);
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * signal);
}

long	ft_atol(const char *s)
{
	int		i;
	long	res;
	long	coeff;

	i = 0;
	res = 0;
	coeff = 1;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (!s[i])
		return (0);
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
	{
		coeff = -1;
		i++;
	}
	while (s[i] && ft_isdigit(s[i]))
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res * coeff);
}

bool	number_of_dishes(char **array)
{
	if (array[array_len(array) - 1])
	{
		if (ft_atoi(array[array_len(array) - 1]) <= 0)
			return (PARSE_ERROR);
	}
	return (PARSE_SUCCESS);
}
