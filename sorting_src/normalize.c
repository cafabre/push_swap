/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:00:00 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/21 14:52:33 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	extract_values(t_stack *stack_a, int *values, int *sorted_values)
{
	t_node	*current;
	int		size;
	int		i;

	size = stack_size(stack_a);
	current = stack_a->top;
	i = 0;
	while (current && i < size)
	{
		values[i] = current->value;
		sorted_values[i] = current->value;
		current = current->next;
		i++;
	}
}

static void	sort_values(int *arr, int size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

static void	replace_with_ranks(t_stack *stack_a, int *values, int *sorted)
{
	t_node	*current;
	int		size;
	int		i;
	int		j;

	size = stack_size(stack_a);
	current = stack_a->top;
	i = 0;
	while (current && i < size)
	{
		j = 0;
		while (j < size)
		{
			if (values[i] == sorted[j])
			{
				current->value = j;
				break ;
			}
			j++;
		}
		current = current->next;
		i++;
	}
}

void	normalize_stack(t_stack *stack_a)
{
	int	*values;
	int	*sorted_values;
	int	size;

	size = stack_size(stack_a);
	values = malloc(sizeof(int) * size);
	sorted_values = malloc(sizeof(int) * size);
	if (!values || !sorted_values)
	{
		if (values)
			free(values);
		if (sorted_values)
			free(sorted_values);
		return ;
	}
	extract_values(stack_a, values, sorted_values);
	sort_values(sorted_values, size);
	replace_with_ranks(stack_a, values, sorted_values);
	free(values);
	free(sorted_values);
}
