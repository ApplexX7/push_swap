/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_one.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:02:20 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/07 13:01:48 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	char	*s;
	int		sign;
	long	nbr;

	sign = 1;
	s = (char *) str;
	while (*s == ' ' || *s == '\n' || *s == '\v' || *s == '\f'
		|| *s == '\t' || *s == '\r')
		s++;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		sign = -1;
		s++;
	}
	nbr = 0;
	while (*s >= '0' && *s <= '9' && nbr <= (long) INT_MAX + 1)
	{
		nbr = nbr * 10 + (*s - '0');
		s++;
	}
	return (nbr * sign);
}

void	ft_free(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*tmp;

	curr = *stack;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*stack = NULL;
}

int	check_syntax(char *s)
{
	int	i;

	i = 0;
	if (!(s[i] == '+' || s[i] == '-') && !(s[i] >= '0' && s[i] <= '9'))
		return (1);
	if ((s[i] == '+' || s[i] == '-') && !(s[1] >= '0' && s[1] <= '9'))
		return (1);
	else
		i++;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	duplicate_number(int *arr, int nb, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	*indexing(int *s, int len)
{
	int		*ind;
	int		j;
	int		i;

	i = 0;
	ind = (int *)ft_calloc(len, 4);
	if (!ind)
		return (0);
	while (i < len)
	{
		j = len;
		while (j--)
		{
			if (s[i] > s[j])
				ind[i]++;
		}
		i++;
	}
	return (ind);
}
