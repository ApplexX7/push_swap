/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:34:09 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/03 18:06:33 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	rrotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*null;
	t_stack	*begin;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	begin = *stack;
	last = ft_last(stack);
	null = last->prev;
	null->next = NULL;
	last->next = begin;
	last->prev = begin->prev;
	begin->prev = last;
	if (last->prev == NULL)
		*stack = last;
}

void	rra(t_stack **a, int nb)
{
	rrotate(a);
	if (nb == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int nb)
{
	rrotate(b);
	if (nb == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int nb)
{
	rrotate(a);
	rrotate(b);
	if (nb == 0)
		write(1, "rrr\n", 4);
}
