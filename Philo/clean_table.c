/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:59:39 by lbatista          #+#    #+#             */
/*   Updated: 2023/05/02 12:59:48 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_forks(t_table *table);
static void	destroy_philos(t_table *table);

void	*clean_table(t_table **table)
{
	if (*table)
	{
		pthread_mutex_destroy(&(*table)->print_zone);
		pthread_mutex_destroy(&(*table)->is_over_lock);
		if ((*table)->forks)
			destroy_forks(*table);
		if ((*table)->philos)
			destroy_philos(*table);
		free(*table);
	}
	return (NULL);
}

static void	destroy_forks(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->args.nb_philo)
		pthread_mutex_destroy(&table->forks[i]);
	free(table->forks);
}

static void	destroy_philos(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->args.nb_philo)
	{
		pthread_mutex_destroy(&table->philos[i]->is_done_lock);
		free(table->philos[i]);
	}
	free(table->philos);
}
