/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:20:32 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/03 16:07:28 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_pos(t_stack *b, int a)
{
	int	i;

	i = 0;
	while (b)
	{
		if (b->data == a)
			break ;
		i++;
		b = b->next;
	}
	return (i);
}

static void	ft_complet_sorting(t_stack **a, t_stack **b)
{
	int	pos;

	pos = check_pos(*b, (*a)->data - 1);
	if (pos <= s_lenlist(*b) / 2)
		rb(b, 0);
	else
		rrb(b, 0);
}

static void	ft_do_the_work(t_stack **a, int *traker)
{
	rra(a, 0);
	(*traker)--;
}

static void	push_form_a_to_b(t_stack **a, t_stack **b, int *traker)
{
	if ((*a)->data - 1 == (*b)->data)
		pa(a, b, 0);
	else if ((*a)->data - 1 == ft_last(b)->data)
		(rrb(b, 0), pa(a, b, 0));
	else if (!(*traker))
	{
		(pa(a, b, 0), ra(a, 0));
		(*traker)++;
	}
	else if ((*a)->data -1 == ft_last(a)->data)
		ft_do_the_work(a, traker);
	else if ((*b)->data > ft_last(a)->data)
	{
		(pa(a, b, 0), ra(a, 0));
		(*traker)++;
	}
	else if (ft_last(a)->data < ft_last(b)->data)
	{
		(rrb(b, 0), pa(a, b, 0), ra(a, 0));
		(*traker)++;
	}
	else
		ft_complet_sorting(a, b);
}

void	algo_b_to_a(t_stack **a, t_stack **b)
{
	int	traker;

	traker = 0;
	while (s_lenlist(*b) > 0)
		push_form_a_to_b(a, b, &traker);
	while ((*a)->data - 1 == ft_last(a)->data)
		rra(a, 0);
}
