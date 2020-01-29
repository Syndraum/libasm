/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:13:52 by roalvare          #+#    #+#             */
/*   Updated: 2020/01/29 13:58:25 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long	ft_strlen(char *str)
{
	long i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int		ft_strstr(char *str, char to_find)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_return(char *str, char *base, int count)
{
	int result;
	int tmp;
	int i;
	int j;

	result = 0;
	i = 0;
	if (count == 0)
		return (0);
	while (i < count)
	{
		tmp = 1;
		j = 0;
		while (j < count - i - 1)
		{
			tmp *= ft_strlen(base);
			j++;
		}
		tmp *= ft_strstr(base, *(str + i));
		result += tmp;
		i++;
	}
	return (result);
}

int		verif_base(char *base)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] >= 9 && base[i] <= 14)
			return (0);
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		atoi_base(char *str, char *base)
{
	int i;
	int count;
	int signe;

	if (verif_base(base))
	{
		i = 0;
		count = 0;
		signe = 1;
		while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
			i++;
		while (str[i] && (str[i] == '-' || str[i] == '+'))
		{
			signe = (str[i] == '-') ? signe * -1 : signe * 1;
			i++;
		}
		while (str[i] != '\0' && ft_strstr(base, str[i] >= 0))
		{
			count++;
			i++;
		}
		return (ft_return(&str[i - count], base, count) * signe);
	}
	else
		return (0);
}
