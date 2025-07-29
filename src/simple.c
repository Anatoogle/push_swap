/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:19:32 by asemykin          #+#    #+#             */
/*   Updated: 2025/03/01 18:10:26 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_two(t_stack **stack, char *c)
{
	if ((*stack)->value > (*stack)->next->value)
		ft_swap((stack), c);
}

// 3 2 1    ra sa
// 3 1 2    ra
// 1 3 2    rra sa
// 2 3 1    rra
// 2 1 3    sa
void	ft_sort_three(t_stack **stack, char *c)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (second > third && second < first)
	{
		ft_rotate(stack, c);
		ft_swap((stack), c);
	}
	else if (third > second && third < first)
		ft_rotate(stack, c);
	else if (third < second && third > first)
	{
		ft_revrotate(stack, c);
		ft_swap((stack), c);
	}
	else if (first < second && first > third)
		ft_revrotate(stack, c);
	else if (first > second && first < third)
		ft_swap((stack), c);
}

void	ft_pushsmallest(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	t_index	min;

	size = ft_getsize(*stack_a);
	min = ft_getmin(stack_a);
	while (size > 3)
	{
		ft_movelstmin(stack_a, stack_b, &min);
		min = ft_getmin(stack_a);
		size--;
	}
	ft_sort_three(stack_a, "a");
	while (*stack_b)
		ft_push(stack_b, stack_a, "a");
}

void	ft_movelstmin(t_stack **stack_a, t_stack **stack_b, t_index *min)
{
	int	size;

	size = ft_getsize(*stack_a);
	while ((*stack_a)->value != min->value)
	{
		if ((size % 2) != 0)
			size++;
		if ((min->index) <= (size / 2))
			ft_rotate(stack_a, "a");
		else
			ft_revrotate(stack_a, "a");
	}
	ft_push(stack_a, stack_b, "b");
}
