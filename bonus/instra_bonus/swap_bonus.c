/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:34:18 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/03 18:06:36 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	if (first->next)
		first->next->prev = first;
	second->prev = first->prev;
	first->prev = second;
	if (second->prev == NULL)
		*stack = second;
}

void	sa(t_stack **a, int nb)
{
	swap(a);
	if (nb == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int nb)
{
	swap(b);
	if (nb == 0)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int nb)
{
	swap(a);
	swap(b);
	if (nb == 0)
		write(1, "ss\n", 3);
}
