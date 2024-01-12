/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:02:20 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/07 12:49:58 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	while (*s >= '0' && *s <= '9' && nbr <= (long) INT_MAX)
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
	if ((s[i] == '+' || s[i] == '-') && !(s[1] >= '0' && s[i] <= '9'))
		return (1);
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

int	ft_len(char **av)
{
	int	i;

	i = 0;
	if (!av)
		return (0);
	while (av[i] != NULL)
		i++;
	return (i);
}
