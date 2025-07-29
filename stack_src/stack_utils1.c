/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:15:00 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/21 12:57:11 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_is_empty(t_stack *stack)
{
	return (!stack || !stack->top);
}

int	stack_size(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack->size);
}

int	stack_peek(t_stack *stack, int *value)
{
	if (!stack || !stack->top)
		return (0);
	*value = stack->top->value;
	return (1);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top || !stack->top->next)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
