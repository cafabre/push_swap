/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:00:00 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/28 21:22:41 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_min_pos(t_stack *stack)
{
	t_node	*current;
	int		min_val;
	int		min_pos;
	int		pos;

	if (!stack || !stack->top)
		return (-1);
	min_val = stack->top->value;
	min_pos = 0;
	pos = 0;
	current = stack->top;
	while (current)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

static void	move_min_to_top(t_stack *stack_a)
{
	int	min_pos;
	int	size;
	int	i;

	min_pos = find_min_pos(stack_a);
	size = stack_size(stack_a);
	if (min_pos <= size / 2)
	{
		i = 0;
		while (i < min_pos)
		{
			op_ra(stack_a);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size - min_pos)
		{
			op_rra(stack_a);
			i++;
		}
	}
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_size(stack_a);
	if (size < 4 || is_sorted(stack_a))
		return ;
	while (stack_size(stack_a) > 3)
	{
		move_min_to_top(stack_a);
		op_pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_size(stack_b) > 0)
		op_pa(stack_a, stack_b);
}
