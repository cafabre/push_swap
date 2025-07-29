/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:15:00 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/29 10:02:55 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	last = stack->top;
	while (last->next)
		last = last->next;
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	op_ra(t_stack *stack_a)
{
	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	rotate_stack(stack_a);
	write(1, "ra\n", 3);
}

void	op_rb(t_stack *stack_b)
{
	if (!stack_b || !stack_b->top || !stack_b->top->next)
		return ;
	rotate_stack(stack_b);
	write(1, "rb\n", 3);
}

void	op_rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	write(1, "rr\n", 3);
}
