/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:13:52 by roalvare          #+#    #+#             */
/*   Updated: 2020/01/31 13:59:54 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(char c)
{
	return (c == '\t'
			|| c == '\n'
			|| c == '\v'
			|| c == '\f'
			|| c == '\r'
			|| c == ' ');
}

int	is_valid_char(char c)
{
	return (!(c == '-' || c == '+' || is_space(c)));
}

int	check_base(char *base)
{
	int				i;
	unsigned int	j;

	i = -1;
	while (base[++i])
	{
		if (!is_valid_char(base[i]))
			return (0);
		j = i;
		while (base[++j])
			if (base[j] == base[i])
				return (0);
	}
	return (i <= 1 ? 0 : i);
}

int	find_idx_base(char c, char *base)
{
	int i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (i);
	return (-1);
}

int	atoi_base(char *str, char *base)
{
	unsigned int	i;
	int				count;
	unsigned int	sign;
	unsigned int	base_size;
	int				idx;

	if (!(base_size = check_base(base)))
		return (0);
	i = 0;
	count = 0;
	sign = 0;
	while (is_space(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign++;
	while (str[i])
	{
		if ((idx = find_idx_base(str[i++], base)) == -1 && count > 0)
			break ;
		if (idx == -1 && count == 0)
			return (0);
		count = count * base_size + idx;
	}
	return (sign % 2 ? -count : count);
}
