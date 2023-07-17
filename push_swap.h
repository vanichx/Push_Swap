/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:33:21 by ipetruni          #+#    #+#             */
/*   Updated: 2023/07/15 18:00:11 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>//write
# include <stdlib.h>//malloc
# include <stdbool.h>//boolean
# include <limits.h>//int_max or int_min
# include <fcntl.h>//buffer size

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

//				(Linked-List Structure)
typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//				(Handle input -> ./push_swap "228 1337" <-)
int					count_words(char *str, char separator);
char				**ft_split(char *str, char separator);

//				(Handle  errors-free)
int					error_syntax(char *str_nbr);
int					error_duplicates(t_stack_node *a, int nbr);
void				free_matrix(char **argv);
void				free_stack(t_stack_node **stack);
void				error_free(t_stack_node **a, char **argv, bool flag_argc_2);

//				(Stack creation)
void				stack_init(t_stack_node **a, char **argv, bool flag_argc_2);
void				init_nodes(t_stack_node *a, t_stack_node *b);
void				set_current_position(t_stack_node *stack);
void				set_price(t_stack_node *a, t_stack_node *b);
void				set_cheapest(t_stack_node *b);

//				(Linked list utils)
int					stack_len(t_stack_node *stack);
void				append_node(t_stack_node **stack, int nbr);
t_stack_node		*find_last_node(t_stack_node *head);
t_stack_node		*find_smallest(t_stack_node *stack);
t_stack_node		*return_cheapest(t_stack_node *stack);
bool				stack_sorted(t_stack_node *stack);
void				check_for_sorting(t_stack_node **a, t_stack_node **b);
void				finish_rotation(t_stack_node **s, t_stack_node *n, char c);

//				(Algorithm Utils)
void				tiny_sort(t_stack_node **a);
void				handle_five(t_stack_node **a, t_stack_node **b);
void				push_swap(t_stack_node **a, t_stack_node **b);

//				(Swap Commands)
void				sa(t_stack_node **a, bool checker);
void				sb(t_stack_node **b, bool checker);
void				ss(t_stack_node **a, t_stack_node **b, bool checker);

//				(Push Commands)
void				pa(t_stack_node **a, t_stack_node **b, bool checker);
void				pb(t_stack_node **b, t_stack_node **a, bool checker);

//				(Rotate Commands)
void				ra(t_stack_node **a, bool checker);
void				rb(t_stack_node **b, bool checker);
void				rr(t_stack_node **a, t_stack_node **b, bool checker);

//				(Reverse Rotate Commands)
void				rra(t_stack_node **a, bool checker);
void				rrb(t_stack_node **b, bool checker);
void				rrr(t_stack_node **a, t_stack_node **b, bool checker);

// 				(Bonus-Part a.k.a Checker) 
char				*get_next_line(int fd);
size_t				ft_strlen(char *s);
char				*ft_strjoin(char *s1, char *s2);
int					ft_clean(char *str);

#endif