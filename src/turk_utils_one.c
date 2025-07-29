/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:01:20 by asemykin          #+#    #+#             */
/*   Updated: 2025/03/03 22:37:56 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotatemoves(t_stack **stack, long moves, bool rotate, char *str)
{
	if (rotate)
	{
		while (moves--)
			ft_rotate(stack, str);
	}
	else
		while (moves--)
			ft_revrotate(stack, str);
}

void	ft_rotatemoves_a(t_stack **stack, long moves, int value_a, int size)
{
	int	i;

	i = counttoindex(stack, value_a);
	if (i < ((size + 1) / 2))
	{
		while (moves--)
			ft_rotate(stack, "a");
	}
	else
		while (moves--)
			ft_revrotate(stack, "a");
}

t_closest	ft_rotatetogether(t_stack **stack_a, t_stack **stack_b,
		t_closest best)
{
	int	size;
	int	i;

	i = counttoindex(stack_a, (&best)->value_a);
	size = ft_getsize(*stack_a);
	if (i <= ((size + 1) / 2) && (&best)->rb)
	{
		while ((&best)->moves_a > 0 && (&best)->moves_b > 0)
		{
			ft_rr(stack_a, stack_b);
			(&best)->moves_a--;
			(&best)->moves_b--;
		}
	}
	else if (i > ((size + 1) / 2) && !(&best)->rb)
	{
		while ((&best)->moves_a > 0 && (&best)->moves_b > 0)
		{
			ft_rrr(stack_a, stack_b);
			(&best)->moves_a--;
			(&best)->moves_b--;
		}
	}
	return (best);
}

t_closest	ft_getbestmoves(t_stack current, t_stack **stack_a,
		t_stack **stack_b, long index)
{
	t_closest	n;
	t_index		closest;

	closest = ft_getclosest(stack_b, (&current)->value);
	index = ft_cheapestmoves(stack_a, index);
	if ((&closest)->value < (&current)->value)
	{
		if ((&closest)->index <= ((ft_getsize(*stack_b) + 1) / 2))
			n = ft_initclosest(index, ft_diff(1, (&closest)->index),
					(&current)->value, true);
		else
			n = ft_initclosest(index, ft_diff(ft_getsize(*stack_b) + 1,
						(&closest)->index), (&current)->value, false);
	}
	else
	{
		if ((&closest)->index <= ((ft_getsize(*stack_b) + 1) / 2))
			n = ft_initclosest(index, ft_diff(1, (&closest)->index) + 1,
					(&current)->value, true);
		else
			n = ft_initclosest(index, ft_diff(ft_getsize(*stack_b),
						(&closest)->index), (&current)->value, false);
	}
	return (n);
}

long	ft_cheapestmoves(t_stack **stack_a, long index)
{
	int	size;

	size = ft_getsize(*stack_a);
	if (index <= ((size + 1) / 2))
		index = ft_diff(1, index);
	else
		index = ft_diff(size + 1, index);
	return (index);
}
