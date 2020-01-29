#ifndef BONUS_H
# define BONUS_H

# include "header.h"

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

int		atoi_base(char *str, char *base);
int		ft_atoi_base(char *str, char *base);
t_list	*ft_list_push_front(t_list **begin_list, void *data);

int		ft_strstr(char	*str, char c);

t_list	*ft_create_elem(void *data);
void	print_list(t_list *list);
int		list_size(t_list *begin_list);
void	list_push_front(t_list **begin_list, void *data);

#endif