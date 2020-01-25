#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char * dst, const char * src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);


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

	if (argc <= 4)
	{
		printf("Error\nNeed argument\n");
		return (EXIT_SUCCESS);
	}
	if ((fd = atoi(argv[2])) == 3)
		fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	printf("write\t : ");
	fflush(stdout);
	int ret_o = write(fd, argv[3], atoi(argv[4]));
	printf("\t| ret = %d\nft_write : ", ret_o);
	fflush(stdout);
	int ret_m = ft_write(fd, argv[3], atoi(argv[4]));
	printf("\t| ret = %d\n", ret_m);
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
	else
		printf("Error\nFunction unknow");
	return(EXIT_SUCCESS);
}