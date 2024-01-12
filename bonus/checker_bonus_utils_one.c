/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus_utils_one.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:16:01 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/04 11:40:56 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			x;

	if (!s)
		return (NULL);
	x = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == x)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == x)
		return ((char *) &s[i]);
	return (NULL);
}
