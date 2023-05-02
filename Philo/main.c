/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:57:31 by lbatista          #+#    #+#             */
/*   Updated: 2023/05/02 12:57:45 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	table = set_table(argc, argv);
	if (!table)
		return (1);
	if (!start_dinner(table))
		return (1);
	clean_table(&table);
	return (0);
}
