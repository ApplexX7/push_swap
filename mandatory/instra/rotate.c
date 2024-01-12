/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:33:18 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/04 11:22:10 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*begin;
	t_stack	*last;
	t_stack	*new_head;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	begin = *stack;
	last = ft_last(stack);
	new_head = begin->next;
	new_head->prev = begin->prev;
	last->next = begin;
	begin->next = NULL;
	begin->prev = last;
	if (new_head->prev == NULL)
		*stack = new_head;
}

void	ra(t_stack **a, int nb)
{
	rotate(a);
	if (nb == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int nb)
{
	rotate(b);
	if (nb == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int nb)
{
	rotate(a);
	rotate(b);
	if (nb == 0)
		write(1, "rr\n", 3);
}
