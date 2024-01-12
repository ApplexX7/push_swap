/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:10:44 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/11 17:08:30 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	complet_building(t_stack **a, int *arr, int len)
{
	int	*index;

	index = indexing(arr, len);
	if (!index)
	{
		free(arr);
		arr = NULL;
		return ;
	}
	append_to_list(a, index, len);
	free(index);
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
	complet_building(a, arr, len);
	free(arr);
	return (1);
}

void	ft_sort_stack(t_stack **a, t_stack **b)
{
	if (s_lenlist(*a) == 2)
		sa(a, 0);
	if (s_lenlist(*a) == 3)
		sort_tree(a);
	else if (s_lenlist(*a) == 4)
		sorted_four(a, b);
	else if (s_lenlist(*a) == 5)
		sorted_five(a, b);
	else if (s_lenlist(*a) > 5)
	{
		algo_sort(a, b);
		sort_tree(a);
		algo_b_to_a(a, b);
	}
}

int	main(int ac, char *av[])
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
	free (str);
	if (!build_stack(&a, arr))
		return (ft_free(&a), ft_free_str(arr), 0);
	ft_free_str(arr);
	if (!list_is_sorted(a))
		ft_sort_stack(&a, &b);
	ft_free(&a);
	ft_free(&b);
}
