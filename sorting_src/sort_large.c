/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:00:00 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/21 13:30:17 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	radix_sort_binary(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	pass;
	int	max_bits;
	int	operations;

	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	pass = 0;
	while (pass < max_bits)
	{
		operations = size;
		while (operations-- > 0)
		{
			if ((stack_a->top->value >> pass) & 1)
				op_ra(stack_a);
			else
				op_pb(stack_a, stack_b);
		}
		while (stack_size(stack_b) > 0)
			op_pa(stack_a, stack_b);
		pass++;
	}
}

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	if (is_sorted(stack_a))
		return ;
	normalize_stack(stack_a);
	size = stack_size(stack_a);
	if (size > 50)
	{
		pre_sort_chunks(stack_a, stack_b);
		if (stack_size(stack_a) == 3)
			sort_three(stack_a);
		else if (stack_size(stack_a) == 2
			&& stack_a->top->value > stack_a->top->next->value)
			op_sa(stack_a);
		optimized_push_back(stack_a, stack_b);
	}
	else
		radix_sort_binary(stack_a, stack_b, size);
}
