/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:00:12 by roalvare          #+#    #+#             */
/*   Updated: 2020/01/29 12:08:37 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	test_atoi_base(int argc, char *argv[])
{
	if (argc <= 3)
	{
		printf("Error\nNeed argument\n");
		return (EXIT_SUCCESS);
	}
	printf("atoi_base : %d\n", atoi_base(argv[2], argv[3]));
	return (EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		printf("Error\nNo function\n");
		return (EXIT_SUCCESS);
	}
	if (strcmp(argv[1], "ft_atoi_base") == 0)
		test_atoi_base(argc, argv);
	else
		printf("Error\nFunction unknow");
	return(EXIT_SUCCESS);
}