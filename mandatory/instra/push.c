/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:32:59 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/04 11:21:52 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*top;

	if (!src || !*src)
		return ;
	top = *src;
	*src = top->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	top->next = *dest;
	top->prev = NULL;
	if (*dest != NULL)
		(*dest)->prev = top;
	*dest = top;
}

void	pa(t_stack **a, t_stack **b, int nb)
{
	push(b, a);
	if (nb == 0)
		write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a, int nb)
{
	push(a, b);
	if (nb == 0)
		write(1, "pb\n", 3);
}
