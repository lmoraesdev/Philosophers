/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:03:51 by lbatista          #+#    #+#             */
/*   Updated: 2023/05/02 13:03:58 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	ft_isnumeric(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	long	total;
	long	prev;

	i = 0;
	sign = 1;
	total = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		prev = total;
		total = total * 10 + (str[i] - '0');
		if (total < prev)
			return (0);
		i++;
	}
	return (total * sign);
}

long	gettimems(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}
