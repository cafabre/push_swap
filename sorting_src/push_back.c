/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:15:00 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/21 14:52:10 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_max_pos(t_stack *stack_b)
{
	t_node	*current;
	int		max_val;
	int		max_pos;
	int		pos;

	current = stack_b->top;
	max_val = current->value;
	max_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->value > max_val)
		{
			max_val = current->value;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

static void	rotate_max_to_top(t_stack *stack_b, int max_pos)
{
	while (max_pos > 0 && max_pos <= stack_size(stack_b) / 2)
	{
		op_rb(stack_b);
		max_pos--;
	}
	while (max_pos > stack_size(stack_b) / 2)
	{
		op_rrb(stack_b);
		max_pos++;
		if (max_pos >= stack_size(stack_b))
			max_pos = 0;
	}
}

static void	push_back_max(t_stack *stack_a, t_stack *stack_b)
{
	int	max_pos;

	if (stack_size(stack_b) == 0)
		return ;
	max_pos = find_max_pos(stack_b);
	rotate_max_to_top(stack_b, max_pos);
	op_pa(stack_a, stack_b);
}

void	optimized_push_back(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_size(stack_b) > 0)
		push_back_max(stack_a, stack_b);
}
