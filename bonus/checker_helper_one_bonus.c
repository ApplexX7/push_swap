/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper_one_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:53:05 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/11 16:29:46 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char			*dest;
	unsigned int	i;

	if (!s1)
		return (NULL);
	dest = (char *)malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char				*res;
	unsigned int		i;
	unsigned int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = 0;
	j = 0;
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

static int	check_space(char *av)
{
	int	j;

	j = 0;
	while ((av[j] == ' ' || av[j] == '\t') && av[j])
		j++;
	if (av[j] == '\0')
		return (1);
	return (0);
}

char	*join_the_input(char **av)
{
	int		i;
	char	*str;
	char	*tmp;

	i = -1;
	while (av[++i])
	{
		if (!av[i] || !av[i][0])
			return (free(str), NULL);
		if (check_space(av[i]))
			return (free(str), NULL);
		tmp = ft_strjoin(str, av[i]);
		if (!tmp)
			return (0);
		free(str);
		str = ft_strjoin(tmp, " ");
		if (!str)
			return (free(tmp), NULL);
		free(tmp);
	}
	return (str);
}
