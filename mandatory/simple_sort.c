/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:10:58 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/03 16:05:18 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorted_four(t_stack **a, t_stack **b)
{
	t_stack	*curr;
	int		med;
	int		pos;

	curr = *a;
	pos = 0;
	med = s_lenlist(*a) / 2;
	while (curr->data != 0 && curr)
	{
		curr = curr->next;
		pos++;
	}
	while ((*a)->data != 0)
	{
		if (pos > med)
			rra(a, 0);
		else if (pos <= med)
			ra(a, 0);
	}
	pb(b, a, 0);
	sort_tree(a);
	pa(a, b, 0);
}

static void	complet_sorting(t_stack **a, t_stack **b, int med)
{
	t_stack	*curr;
	int		pos;

	curr = *a;
	pos = 0;
	while (curr->data != 1 && curr)
	{
		curr = curr->next;
		pos++;
	}
	while ((*a)->data != 1)
	{
		if (pos > med)
			rra(a, 0);
		else if (pos <= med)
			ra(a, 0);
	}
	pb(b, a, 0);
	sort_tree(a);
	pa(a, b, 0);
	pa(a, b, 0);
}

void	sorted_five(t_stack **a, t_stack **b)
{
	t_stack	*curr;
	int		med;
	int		pos;

	pos = 0;
	curr = *a;
	med = s_lenlist(*a) / 2;
	while (curr->data != 0 && curr)
	{
		curr = curr->next;
		pos++;
	}
	while ((*a)->data != 0)
	{
		if (pos > med)
			rra(a, 0);
		else if (pos <= med)
			ra(a, 0);
	}
	pb(b, a, 0);
	complet_sorting(a, b, med);
}

void	sort_tree(t_stack **a)
{
	t_stack	*top;
	t_stack	*bottom;

	top = *a;
	bottom = top->next->next;
	if (bottom->data < top->data && top->data > top->next->data)
	{
		ra(a, 0);
		top = *a;
	}
	else if (top->data < top->next->data && top->next->data > bottom->data)
	{
		rra(a, 0);
		top = *a;
	}
	if (top->data > top->next->data)
		sa(a, 0);
}
