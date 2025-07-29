/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:00:00 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/21 12:56:35 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *stack)
{
	int		i;
	int		num;

	i = argc - 1;
	while (i >= 1)
	{
		if (!is_number(argv[i]))
			return (0);
		num = ft_atoi(argv[i]);
		if (is_overflow(argv[i], num))
			return (0);
		if (stack_contains(stack, num))
			return (0);
		if (!stack_push(stack, num))
			return (0);
		i--;
	}
	return (1);
}
