/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:15:00 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/29 10:14:17 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_overflow(char *str, int atoi_result)
{
	long long	check;
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	check = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		check = check * 10 + (str[i] - '0');
		i++;
	}
	check *= sign;
	return (check != atoi_result);
}
