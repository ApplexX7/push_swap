/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus_utils_two.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:53:27 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/04 11:40:27 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	append_to_list(t_stack **list, int *nb, int len)
{
	t_stack	*new;
	t_stack	*last;
	int		i;

	i = 0;
	while (i < len)
	{
		new = malloc(sizeof(t_stack) + 1);
		if (!new)
			return ;
		new->data = nb[i];
		new->next = NULL;
		new->prev = NULL;
		if (!list)
			return ;
		if (!*list)
			*list = new;
		else
		{
			last = ft_last(list);
			last->next = new;
			new->prev = last;
		}
		i++;
	}
}

int	list_is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	s_lenlist(t_stack *stack)
{
	int		count;
	t_stack	*curr;

	curr = stack;
	count = 0;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0')
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

t_stack	*ft_last(t_stack **lst)
{
	t_stack	*last;

	if (!lst)
		return (NULL);
	last = *lst;
	while (last->next)
		last = last->next;
	return (last);
}
