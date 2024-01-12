/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:39:57 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/11 15:53:39 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list_stack
{
	int					data;
	struct s_list_stack	*next;
	struct s_list_stack	*prev;
}	t_stack;

/*helper functions*/
long	ft_atoi(const char *str);
void	ft_free(t_stack **stack);
int		check_syntax(char *s);
int		duplicate_number(int *a, int nb, int size);
void	printf_nodes(t_stack *a);
void	ft_free_str(char **arr);
size_t	ft_strlen(const char *s);
/*building functions*/
void	append_to_list(t_stack **list, int *nb, int len);
t_stack	*ft_last(t_stack **lst);
int		s_lenlist(t_stack *stack);
int		list_is_sorted(t_stack *stack);
char	**ft_split(char const *s, char c);
void	sort_tree(t_stack **a);
void	sorted_five(t_stack **a, t_stack **b);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
int		ft_len(char **av);
void	*ft_calloc(size_t count, size_t size);
int		*indexing(int *s, int len);
void	ft_bzero(void *dst, size_t n);
char	*join_the_input(char **av);
int		build_stack(t_stack **a, char **av);
/*intsractions*/
void	sa(t_stack **a, int nb);
void	sb(t_stack **b, int nb);
void	rra(t_stack **a, int nb);
void	rrb(t_stack **b, int nb);
void	ss(t_stack **a, t_stack **b, int nb);
void	rrr(t_stack **a, t_stack **b, int nb);
void	ra(t_stack **a, int nb);
void	rb(t_stack **b, int nb);
void	rr(t_stack **a, t_stack **b, int nb);
void	pa(t_stack **a, t_stack **b, int nb);
void	pb(t_stack **b, t_stack **a, int nb);
void	sorted_four(t_stack **a, t_stack **b);
void	algo_sort(t_stack **a, t_stack **b);
void	algo_b_to_a(t_stack **a, t_stack **b);

#endif
