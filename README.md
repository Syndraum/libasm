# Libasm

Introduction to x64 assembly

## Overview

Rewrite function from C standar library and from previous project.

- [Mandatory]
- [Bonus]

## Mandatory

Function to reimplement.

- strlen
- strcpy
- strcmp
- write
- read
- strdup

## Bonus

List function use this structure

```c
typedef struct      s_list
{
    void            *data;
    struct s_list   *next;
}                   t_list;
```

Function to reimplement.

- atoi_base(char *str, char *base)
- list_push_front(t_list **lst, void *data)
- list_size(t_list *lst)
- list_sort(t_list **lst, void *cmp_fct)
- list_remove_if(t_list **lst, void *data, void *cmp_fct, void *cmp_free_fct)