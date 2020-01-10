#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char * dst, const char * src);
int		ft_strcmp(const char *s1, const char *s2);

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
	else
		printf("Error\nFunction unknow");
	return(EXIT_SUCCESS);
}