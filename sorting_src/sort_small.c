/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:00:00 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/21 12:46:21 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	if (stack_size(stack_a) != 3 || is_sorted(stack_a))
		return ;
	a = stack_a->top->value;
	b = stack_a->top->next->value;
	c = stack_a->top->next->next->value;
	if (a > b && b < c && a < c)
		op_sa(stack_a);
	else if (a > b && b > c)
	{
		op_sa(stack_a);
		op_rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		op_ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		op_sa(stack_a);
		op_ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		op_rra(stack_a);
}
