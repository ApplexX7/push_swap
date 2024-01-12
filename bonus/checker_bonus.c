/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:48:19 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/11 17:03:48 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free_str(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	build_stack(t_stack **a, char **av)
{
	int		i;
	int		len;
	long	nb;
	int		*arr;

	i = 0;
	len = ft_len(av);
	arr = malloc(len * sizeof(int));
	if (!arr)
		return (0);
	while (av[i] != NULL)
	{
		if (check_syntax(av[i]))
			return (write(2, "Error\n", 6), ft_free(a), free(arr), 0);
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (write(2, "Error\n", 6), ft_free(a), free(arr), 0);
		if (!duplicate_number(arr, (int)nb, i))
			return (write(2, "Error\n", 6), ft_free(a), free(arr), 0);
		arr[i] = (int)nb;
		i++;
	}
	append_to_list(a, arr, len);
	free(arr);
	return (1);
}

int	ft_instraction(char *instraction, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(instraction, "sa\n"))
		sa(a, 1);
	else if (!ft_strcmp(instraction, "sb\n"))
		sb(a, 1);
	else if (!ft_strcmp(instraction, "rra\n"))
		rra(a, 1);
	else if (!ft_strcmp(instraction, "rrb\n"))
		rrb(b, 1);
	else if (!ft_strcmp(instraction, "ss\n"))
		ss(a, b, 1);
	else if (!ft_strcmp(instraction, "rrr\n"))
		rrr(a, b, 1);
	else if (!ft_strcmp(instraction, "ra\n"))
		ra(a, 1);
	else if (!ft_strcmp(instraction, "rb\n"))
		rb(b, 1);
	else if (!ft_strcmp(instraction, "rr\n"))
		rr(a, b, 1);
	else if (!ft_strcmp(instraction, "pa\n"))
		pa(a, b, 1);
	else if (!ft_strcmp(instraction, "pb\n"))
		pb(b, a, 1);
	else
		return (1);
	return (0);
}

void	check_sorted(t_stack **a, t_stack **b)
{
	char	*instractions;
	int		i;

	instractions = get_next_line(0);
	while (1)
	{
		if (instractions == NULL)
			break ;
		i = ft_instraction(instractions, a, b);
		if (i)
		{
			free(instractions);
			(ft_free(a), ft_free (b));
			a = NULL;
			b = NULL;
			write(2, "Error\n", 6);
			return ;
		}
		free(instractions);
		instractions = get_next_line(0);
	}
	if (!list_is_sorted(*a) || s_lenlist(*b) != 0)
		write (1, "KO\n", 3);
	else
		write (1, "OK\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*str;
	char	**arr;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if ((ac == 2 && !av[1][0]))
		return (write(2, "Error\n", 6), 0);
	str = join_the_input(av + 1);
	if (!str)
		return (write(2, "Error\n", 6), 0);
	arr = ft_split(str, ' ');
	if (!arr)
		return (free(str), 0);
	free(str);
	if (!build_stack(&a, arr))
		return (ft_free(&a), ft_free_str(arr), 0);
	ft_free_str(arr);
	check_sorted(&a, &b);
	ft_free(&a);
	ft_free(&b);
}
