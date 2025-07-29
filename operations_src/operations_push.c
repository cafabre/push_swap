/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:15:00 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/29 10:02:14 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_node(t_stack *from, t_stack *to)
{
	t_node	*temp;

	if (!from || !to || !from->top)
		return ;
	temp = from->top;
	from->top = temp->next;
	from->size--;
	temp->next = to->top;
	to->top = temp;
	to->size++;
}

void	op_pa(t_stack *stack_a, t_stack *stack_b)
{
	push_node(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	op_pb(t_stack *stack_a, t_stack *stack_b)
{
	push_node(stack_a, stack_b);
	write(1, "pb\n", 3);
}
