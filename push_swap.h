/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:00:00 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/21 12:44:24 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

t_stack		*stack_init(void);
void		stack_free(t_stack **stack);
int			stack_is_empty(t_stack *stack);
int			stack_size(t_stack *stack);
int			stack_push(t_stack *stack, int value);
int			stack_pop(t_stack *stack, int *value);
int			stack_peek(t_stack *stack, int *value);
int			stack_contains(t_stack *stack, int value);
void		stack_print(t_stack *stack);

void		op_sa(t_stack *stack_a);
void		op_sb(t_stack *stack_b);
void		op_ss(t_stack *stack_a, t_stack *stack_b);
void		op_pa(t_stack *stack_a, t_stack *stack_b);
void		op_pb(t_stack *stack_a, t_stack *stack_b);
void		op_ra(t_stack *stack_a);
void		op_rb(t_stack *stack_b);
void		op_rr(t_stack *stack_a, t_stack *stack_b);
void		op_rra(t_stack *stack_a);
void		op_rrb(t_stack *stack_b);
void		op_rrr(t_stack *stack_a, t_stack *stack_b);

int			parse_args(int argc, char **argv, t_stack *stack);
int			check_duplicates(t_stack *stack);
int			is_number(char *str);
int			ft_atoi(const char *str);
int			is_overflow(char *str, int atoi_result);

void		sort_stack(t_stack *stack_a, t_stack *stack_b);
void		sort_three(t_stack *stack_a);
void		sort_five(t_stack *stack_a, t_stack *stack_b);
void		sort_large(t_stack *stack_a, t_stack *stack_b);

int			find_min(t_stack *stack);
int			find_max(t_stack *stack);
int			is_sorted(t_stack *stack);

void		pre_sort_chunks(t_stack *stack_a, t_stack *stack_b);
void		optimized_push_back(t_stack *stack_a, t_stack *stack_b);
void		normalize_stack(t_stack *stack_a);

#endif