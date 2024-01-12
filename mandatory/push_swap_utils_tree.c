/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_tree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:38:46 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/07 13:00:22 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = malloc((count) * size);
	if (s)
	{
		ft_bzero(s, size * count);
		return (s);
	}
	return (NULL);
}

void	ft_bzero(void *dst, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) dst;
	while (n)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
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
