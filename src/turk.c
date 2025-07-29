/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:19:39 by asemykin          #+#    #+#             */
/*   Updated: 2025/03/03 22:36:45 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_turk(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b, "b");
	ft_push(stack_a, stack_b, "b");
	ft_turk_pb(stack_a, stack_b);
	ft_sort_three(stack_a, "a");
	while (*stack_b)
		ft_turk_pa(stack_a, stack_b);
	ft_mintotop(stack_a);
}

void	ft_mintotop(t_stack **stack_a)
{
	t_index	min;
	long	moves;
	int		size;

	min = ft_getmin(stack_a);
	size = ft_getsize(*stack_a);
	moves = ft_cheapestmoves(stack_a, (&min)->index);
	if ((&min)->index <= ((size + 1) / 2))
		ft_rotatemoves(stack_a, moves, true, "a");
	else
		ft_rotatemoves(stack_a, moves, false, "a");
}

void	ft_turk_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_closest	n;
	t_closest	best;
	t_stack		*tmp;
	long		index;

	while (ft_getsize(*stack_a) > 3)
	{
		index = 1;
		tmp = *stack_a;
		best = ft_getbestmoves(*tmp, stack_a, stack_b, index);
		while (tmp)
		{
			n = ft_getbestmoves(*tmp, stack_a, stack_b, index);
			if (((&n)->moves_a + (&n)->moves_b) < ((&best)->moves_a
					+ (&best)->moves_b))
				best = ft_getbestmoves(*tmp, stack_a, stack_b, index);
			tmp = tmp->next;
			index++;
		}
		best = ft_rotatetogether(stack_a, stack_b, best);
		ft_rotatemoves_a(stack_a, (&best)->moves_a, (&best)->value_a,
			ft_getsize(*stack_a));
		ft_rotatemoves(stack_b, (&best)->moves_b, (&best)->rb, "b");
		ft_push(stack_a, stack_b, "b");
	}
}

void	ft_turk_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_index	closest;
	int		size;
	t_stack	*tmp;
	long	i;

	size = ft_getsize(*stack_a);
	closest = ft_getclosest(stack_a, (*stack_b)->value);
	tmp = *stack_a;
	i = ft_cheapestmoves(stack_a, (&closest)->index);
	if ((&closest)->value < (*stack_b)->value)
	{
		if ((&closest)->index <= ((size + 1) / 2))
			ft_rotatemoves(stack_a, i + 1, true, "a");
		else
			ft_rotatemoves(stack_a, i - 1, false, "a");
	}
	else
	{
		if ((&closest)->index <= ((size + 1) / 2))
			ft_rotatemoves(stack_a, i, true, "a");
		else
			ft_rotatemoves(stack_a, i, false, "a");
	}
	ft_push(stack_b, stack_a, "a");
}
