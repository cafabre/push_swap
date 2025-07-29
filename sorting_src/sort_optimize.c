/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_optimize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:00:00 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/21 14:52:25 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_range(t_stack *stack_a, t_stack *stack_b, int min, int max)
{
	int	size;
	int	i;

	size = stack_size(stack_a);
	i = 0;
	while (i < size)
	{
		if (stack_a->top->value >= min && stack_a->top->value <= max)
		{
			op_pb(stack_a, stack_b);
			if (stack_size(stack_b) > 1
				&& stack_b->top->value < min + (max - min) / 2)
				op_rb(stack_b);
		}
		else
			op_ra(stack_a);
		i++;
	}
}

void	pre_sort_chunks(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	chunk_size;
	int	chunks;
	int	i;

	size = stack_size(stack_a);
	if (size <= 100)
		chunk_size = size / 4;
	else
		chunk_size = size / 15;
	chunks = (size + chunk_size - 1) / chunk_size;
	i = 0;
	while (i < chunks && stack_size(stack_a) > 3)
	{
		push_range(stack_a, stack_b, i * chunk_size, (i + 1) * chunk_size - 1);
		i++;
	}
}
