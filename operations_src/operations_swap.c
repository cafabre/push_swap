/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:15:00 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/23 21:21:14 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_top_two(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}

void	op_sa(t_stack *stack_a)
{
	swap_top_two(stack_a);
	write(1, "sa\n", 3);
}

void	op_sb(t_stack *stack_b)
{
	swap_top_two(stack_b);
	write(1, "sb\n", 3);
}

void	op_ss(t_stack *stack_a, t_stack *stack_b)
{
	swap_top_two(stack_a);
	swap_top_two(stack_b);
	write(1, "ss\n", 3);
}
