/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:00:00 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/23 13:41:57 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	cleanup(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		stack_free(&stack_a);
	if (stack_b)
		stack_free(&stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = stack_init();
	if (!stack_a)
		exit_error();
	stack_b = stack_init();
	if (!stack_b)
	{
		stack_free(&stack_a);
		exit_error();
	}
	if (!parse_args(argc, argv, stack_a))
	{
		cleanup(stack_a, stack_b);
		exit_error();
	}
	sort_stack(stack_a, stack_b);
	cleanup(stack_a, stack_b);
	return (0);
}
