/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:00:12 by roalvare          #+#    #+#             */
/*   Updated: 2020/01/29 18:47:58 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"


int	test_atoi_base(int argc, char *argv[])
{
	if (argc <= 3)
	{
		printf("Error\nNeed argument\n");
		return (EXIT_SUCCESS);
	}
	printf("atoi_base :\t%d\n", atoi_base(argv[2], argv[3]));
	printf("ft_atoi_base :\t%d\n", ft_atoi_base(argv[2], argv[3]));
	return (EXIT_SUCCESS);
}

int	test_strstr(int argc, char *argv[])
{
	if (argc <= 3)
	{
		printf("Error\nNeed argument\n");
		return (EXIT_SUCCESS);
	}
	printf("strstr :\t%d\n", ft_strstr(argv[2], argv[3][0]));
	return (EXIT_SUCCESS);
}

int	test_list_push_front(int argc, char *argv[])
{
	t_list *elmt1 = NULL;
	t_list *elmt2 = NULL;

	if (argc <= 2)
	{
		printf("Error\nNeed argument\n");
		return (EXIT_SUCCESS);
	}
	int i = 1;
	while (++i < argc)
	{
		list_push_front(&elmt1 , argv[i]);
		ft_list_push_front(&elmt2, argv[i]);
	}
	print_list(elmt1);
	print_list(elmt2);
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
	else if (strcmp(argv[1], "list_push_front") == 0)
		test_list_push_front(argc, argv);
	else
		printf("Error\nFunction unknow");
	return(EXIT_SUCCESS);
}