/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:00:00 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/21 12:45:01 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	if (!stack_a || !stack_b)
		return ;
	if (is_sorted(stack_a))
		return ;
	size = stack_size(stack_a);
	if (size == 2)
	{
		if (stack_a->top->value > stack_a->top->next->value)
			op_sa(stack_a);
	}
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else
		sort_large(stack_a, stack_b);
}
