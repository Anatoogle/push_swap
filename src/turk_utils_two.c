/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:01:39 by asemykin          #+#    #+#             */
/*   Updated: 2025/03/03 22:37:21 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_closest	ft_initclosest(long moves_a, long moves_b, int value_a, bool rb)
{
	t_closest	closest;

	(&closest)->moves_a = moves_a;
	(&closest)->moves_b = moves_b;
	(&closest)->value_a = value_a;
	(&closest)->rb = rb;
	return (closest);
}

t_index	ft_getclosest(t_stack **stack, int value)
{
	t_stack	*tmp;
	t_index	closest;
	long	diff;
	int		i;

	diff = 9223372036854775807;
	tmp = *stack;
	(&closest)->value = (*stack)->value;
	(&closest)->index = 1;
	i = 1;
	while (tmp)
	{
		if (ft_diff(value, tmp->value) < diff)
		{
			diff = ft_diff(value, tmp->value);
			(&closest)->index = i;
			(&closest)->value = tmp->value;
		}
		i++;
		tmp = tmp->next;
	}
	return (closest);
}

int	counttoindex(t_stack **stack, int value)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (value == tmp->value)
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

long	ft_diff(long a, long b)
{
	if (a > b)
		return (a - (b));
	else
		return (b - (a));
}
