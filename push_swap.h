/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:52:45 by ybenchel          #+#    #+#             */
/*   Updated: 2025/01/24 15:36:07 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char				*get_next_line(int fd);
char				*ft_strchr(char *s, int c);
char				*ft_strjoin(char *s1, char *s2);
void				ft_error(char **numbers, t_list **head);
void				ft_e_error(t_list **stack_a);
void				free_numbers(char **numbers);
t_list				*ft_lstnew(int value);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					is_duplicate(t_list *lst, int value);
long				ft_atoi(const char *str);
char				*ft_substr(const char *s, unsigned int start, int len);
int					ft_strlen(const char *s);
void				*ft_memcpy(void *dst, const void *src, int n);
char				*ft_strdup(const char *str);
char				**ft_split(char const *s, char c);
void				ft_lstclear(t_list **lst);
void				sa(t_list **a, int write_flag);
void				pb(t_list **a, t_list **b, int write_flag);
void				pa(t_list **a, t_list **b, int write_flag);
void				ra(t_list **a, int write_flag);
void				rb(t_list **b, int write_flag);
void				rra(t_list **a, int write_flag);
void				rrb(t_list **b, int write_flag);
void				sb(t_list **b, int write_flag);
void				ss(t_list **a, t_list **b, int write_flag);
void				rrr(t_list **a, t_list **b, int write_flag);
void				rr(t_list **a, t_list **b, int write_flag);
int					ft_max(t_list *head);
void				push_to_a(t_list **stack_a, t_list **stack_b);
void				ft_sort(t_list **a, t_list **b);
void				ft_sort_3(t_list **a);
void				ft_sort_5(t_list **a, t_list **b);
int					ft_lstsize(t_list *lst);
void				indexing(t_list **a);
int					max_index(t_list *stack);
int					find_distance(t_list **stack, int pos);
int					find_first_index(t_list *head, int i, int p);
int					ft_is_sorted(t_list *head);
int					ft_strcmp(const char *s1, const char *s2);
void				push_to_b(t_list **s_a, t_list **s_b, int p);
int					is_number(const char *str);
void				process_numbers(char **numbers, t_list **stack_a);

#endif