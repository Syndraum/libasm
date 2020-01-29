/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:41:01 by roalvare          #+#    #+#             */
/*   Updated: 2020/01/29 17:45:54 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

t_list		*ft_create_elem(void *data)
{
	t_list	*elemt;

	elemt = malloc(sizeof(t_list));
	elemt->next = NULL;
	elemt->data = data;
	return (elemt);
}

void	list_push_front(t_list **begin_list, void *data)
{
	t_list *elemt;
	elemt = ft_create_elem(data);
	if (*begin_list == NULL)
		*begin_list = elemt;
	else
	{
		elemt->next = *begin_list;
		*begin_list = elemt;
	}
}

int		list_size(t_list *begin_list)
{
	int size;

	size = 0;
	while (begin_list != NULL)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

void	print_list(t_list *list)
{
	while (list != NULL)
	{
		printf("%s => ", (char*)list->data);
		list = list->next;
	}
	printf("NULL\n");
}