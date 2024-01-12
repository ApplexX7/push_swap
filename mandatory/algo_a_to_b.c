/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:16:37 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/08 12:26:28 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initial_pivots(t_stack **a, int *pv1, int *pv2, int *lpv1)
{
	*lpv1 = *pv1;
	*pv2 = *pv1 + s_lenlist(*a) / 6;
	*pv1 = s_lenlist(*a) / 3 + *pv1;
}

void	algo_sort(t_stack **a, t_stack **b)
{
	int	pv1;
	int	pv2;
	int	lpv1;

	lpv1 = -1;
	pv1 = 0;
	pv2 = s_lenlist(*a) / 6 + pv1;
	pv1 = s_lenlist(*a) / 3 + pv1;
	while (s_lenlist(*a) > 3)
	{
		if (s_lenlist(*b) > 1 && (*a)->data >= pv1
			&& (*b)->data < pv2 && (*b)->data > lpv1)
			rr(a, b, 0);
		else if (s_lenlist(*b) > 1 && (*b)->data < pv2 && (*b)->data > lpv1)
			rb(b, 0);
		if ((*a)->data >= pv1)
			ra(a, 0);
		else
			pb(b, a, 0);
		if (s_lenlist(*b) >= pv1)
			initial_pivots(a, &pv1, &pv2, &lpv1);
	}
}
