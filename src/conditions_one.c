/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:45:57 by asemykin          #+#    #+#             */
/*   Updated: 2025/03/03 13:46:06 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// swap (sa / sb)
// swap the first 2 elements at the top of the stack.
void	ft_swap(t_stack **stack, char *str)
{
	t_stack	*first_node;
	t_stack	*second_node;

	if (!stack || !(*stack)->next)
		return ;
	first_node = *stack;
	second_node = first_node->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*stack = second_node;
	if (ft_strncmp(str, "a", 1) == 0)
		ft_printf("sa\n");
	if (ft_strncmp(str, "b", 1) == 0)
		ft_printf("sb\n");
}

// push (pa / pb)
// take the first element at the top of stack_take and
// put it at the top of stack_put
void	ft_push(t_stack **stack_take, t_stack **stack_put, char *str)
{
	t_stack	*first_put;
	t_stack	*first_take;

	if (!*stack_take)
		return ;
	first_put = ft_newlst((*stack_take)->value);
	if ((*stack_put))
		first_put->next = *stack_put;
	if ((*stack_take)->next)
		first_take = (*stack_take)->next;
	else
		first_take = NULL;
	free(*stack_take);
	*stack_put = first_put;
	*stack_take = first_take;
	if (ft_strncmp(str, "a", 1) == 0)
		ft_printf("pa\n");
	if (ft_strncmp(str, "b", 1) == 0)
		ft_printf("pb\n");
}

// rotate (ra / rb)
// shift up all elements of stack by 1.
// the first element becomes the last.
void	ft_rotate(t_stack **stack, char *str)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	first = ft_newlst((*stack)->value);
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	last = ft_getlast(*stack);
	last->next = first;
	if (ft_strncmp(str, "a", 1) == 0)
		ft_printf("ra\n");
	if (ft_strncmp(str, "b", 1) == 0)
		ft_printf("rb\n");
}

// reverse rotate (rra / rrb)
// shift down all elements of stack by 1.
// the last element becomes the first.
void	ft_revrotate(t_stack **stack, char *str)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next->next)
		last = last->next;
	first = ft_newlst(last->next->value);
	first->next = *stack;
	*stack = first;
	free(last->next);
	last->next = NULL;
	if (ft_strncmp(str, "a", 1) == 0)
		ft_printf("rra\n");
	if (ft_strncmp(str, "b", 1) == 0)
		ft_printf("rrb\n");
}
