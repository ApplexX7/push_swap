/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:39:57 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/11 15:53:30 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

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
void	ft_free_str(char **arr);
size_t	ft_strlen(const char *s);
/*building functions*/
void	append_to_list(t_stack **list, int *nb, int len);
t_stack	*ft_last(t_stack **lst);
int		s_lenlist(t_stack *stack);
int		list_is_sorted(t_stack *stack);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
int		ft_len(char **av);
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
/*bunos part*/
char	*get_next_line(int fd);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
