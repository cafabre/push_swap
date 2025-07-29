/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:00:00 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/29 10:03:52 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_contains(t_stack *stack, int value)
{
	t_node	*current;

	if (!stack)
		return (0);
	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	stack_push(t_stack *stack, int value)
{
	t_node	*new_node;

	if (!stack)
		return (0);
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
	return (1);
}

int	stack_pop(t_stack *stack, int *value)
{
	t_node	*temp;

	if (!stack || !stack->top)
		return (0);
	*value = stack->top->value;
	temp = stack->top;
	stack->top = stack->top->next;
	free(temp);
	stack->size--;
	return (1);
}
