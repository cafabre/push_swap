/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:15:00 by cafabre           #+#    #+#             */
/*   Updated: 2025/03/07 15:59:19 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate_stack(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	last = stack->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	op_rra(t_stack *stack_a)
{
	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	reverse_rotate_stack(stack_a);
	write(1, "rra\n", 4);
}

void	op_rrb(t_stack *stack_b)
{
	if (!stack_b || !stack_b->top || !stack_b->top->next)
		return ;
	reverse_rotate_stack(stack_b);
	write(1, "rrb\n", 4);
}

void	op_rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
	write(1, "rrr\n", 4);
}
