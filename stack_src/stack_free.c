/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:45:00 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/21 12:57:20 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	free_node(t_node *node)
{
	if (node)
		free(node);
}

static int	free_all_nodes(t_stack *stack)
{
	t_node	*current;
	t_node	*next;
	int		count;

	count = 0;
	if (!stack)
		return (count);
	current = stack->top;
	while (current)
	{
		next = current->next;
		free_node(current);
		current = next;
		count++;
	}
	stack->top = NULL;
	stack->size = 0;
	return (count);
}

void	stack_free(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	free_all_nodes(*stack);
	free(*stack);
	*stack = NULL;
}

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a)
		stack_free(stack_a);
	if (stack_b)
		stack_free(stack_b);
}
