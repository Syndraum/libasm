/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:59:48 by roalvare          #+#    #+#             */
/*   Updated: 2020/01/29 12:00:02 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	test_strlen(int argc, char *argv[])
{
	char * str;
		if (argc <= 2)
		{
			printf("Error\nNeed argument\n");
			return (EXIT_SUCCESS);
		}
		if (strcmp(argv[2], "(null)") == 0)
			printf("ft_strlen\t%lu\nstrlen\t\t%lu\n", ft_strlen(str), strlen(str));
		else
			printf("ft_strlen\t%lu\nstrlen\t\t%lu\n", ft_strlen(argv[2]), strlen(argv[2]));
		return (EXIT_SUCCESS);
}

int	test_strcpy(int argc, char *argv[])
{
	char	*str1 = strdup(argv[2]);
	char	*str2 = strdup(argv[2]);

	if (argc <= 3)
	{
		printf("Error\nNeed argument\n");
		return (EXIT_SUCCESS);
	}
	printf("ft_strcpy\t|%s|\nstrcpy\t\t|%s|\n", ft_strcpy(str1, argv[3]), strcpy(str2,argv[3]));
	printf("src : %s\n", str1);
	free(str1);
	free(str2);
	return (EXIT_SUCCESS);
}

int	test_strcmp(int argc, char *argv[])
{
	if (argc <= 3)
	{
		printf("Error\nNeed argument\n");
		return (EXIT_SUCCESS);
	}
	printf("ft_strcmp\t|%d|\nstrcmp\t\t|%d|\n", ft_strcmp(argv[2], argv[3]), strcmp(argv[2],argv[3]));
	return (EXIT_SUCCESS);
}

int test_write(int argc, char *argv[])
{
	int fd;
	char * lol = NULL;

	if (argc <= 4)
	{
		printf("Error\nNeed argument\n");
		return (EXIT_SUCCESS);
	}
	if ((fd = atoi(argv[2])) == 3)
		fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	printf("write\t : ");
	fflush(stdout);
	int ret_o = write(fd, lol, atoi(argv[4]));
	printf("\t| ret = %d\nft_write : ", ret_o);
	fflush(stdout);
	int ret_m = ft_write(fd, lol, atoi(argv[4]));
	printf("\t| ret = %d\n", ret_m);
	return (EXIT_SUCCESS);
}

int test_read(int argc, char *argv[])
{
	int fd1;
	int	fd2;
	char *str1;
	char *str2;

	if (argc <= 4)
	{
		printf("Error\nNeed argument\n");
		return (EXIT_SUCCESS);
	}
	if ((fd1 = atoi(argv[2])) == 3 || (fd2 = atoi(argv[2])) == 3)
	{
		fd1 = open("test_read.txt", O_RDONLY);
		fd2 = open("test_read.txt", O_RDONLY);
	}
	else if (atoi(argv[2]) == 4)
	{
		fd1 = open("test_read.txt", O_WRONLY);
		fd2 = open("test_read.txt", O_WRONLY);
	}
	str1 = strdup(argv[3]);
	str2 = strdup(argv[3]);
	printf("read\t : %s\t| ret = %zd\n", str1, read(fd1, str1, atoi(argv[4])));
	printf("ft_read\t : %s\t| ret = %zd\n", str2, ft_read(fd2, str2, atoi(argv[4])));
	free(str1);
	free(str2);
	return (EXIT_SUCCESS);
}

int	test_strdup(int argc, char *argv[])
{
	char* str1;
	char* str2;

	if (argc <= 2)
	{
		printf("Error\nNeed argument\n");
		return (EXIT_SUCCESS);
	}
	str1 = strdup(argv[2]);
	str2 = strdup(argv[2]);
	printf("strdup\t\t: %s\n", strdup(str1));
	printf("ft_strdup\t: %s\n", ft_strdup(str2));
	*(argv[2]) = '8';
	printf("Modified arg\t: %s", str2);
	free(str1);
	free(str2);
	return (EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		printf("Error\nNo function\n");
		return (EXIT_SUCCESS);
	}
	if (strcmp(argv[1], "ft_strlen") == 0)
		test_strlen(argc, argv);
	else if (strcmp(argv[1], "ft_strcpy") == 0)
		test_strcpy(argc, argv);
	else if (strcmp(argv[1], "ft_strcmp") == 0)
		test_strcmp(argc, argv);
	else if (strcmp(argv[1], "ft_write") == 0)
		test_write(argc, argv);
	else if (strcmp(argv[1], "ft_read") == 0)
		test_read(argc, argv);
	else if (strcmp(argv[1], "ft_strdup") == 0)
		test_strdup(argc, argv);
	else
		printf("Error\nFunction unknow");
	return(EXIT_SUCCESS);
}