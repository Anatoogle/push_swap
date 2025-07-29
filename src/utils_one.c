/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:09:56 by asemykin          #+#    #+#             */
/*   Updated: 2025/03/03 21:27:29 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_index	ft_getmin(t_stack **stack_a)
{
	t_stack	*tmp;
	t_index	min;
	int		i;

	tmp = *stack_a;
	(&min)->value = (*stack_a)->value;
	(&min)->index = 1;
	i = 1;
	while (tmp)
	{
		if (tmp->value < (&min)->value)
		{
			(&min)->index = i;
			(&min)->value = tmp->value;
		}
		i++;
		tmp = tmp->next;
	}
	return (min);
}

t_stack	*ft_newlst(int value)
{
	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	if (!newnode)
		return (NULL);
	newnode->value = value;
	newnode->next = NULL;
	return (newnode);
}

t_stack	*ft_getlast(t_stack *lst)
{
	t_stack	*tlast;

	tlast = (t_stack *)lst;
	if (!lst)
		return (NULL);
	while (tlast)
	{
		if (!tlast->next)
			return (tlast);
		else
			tlast = tlast->next;
	}
	return (tlast);
}

void	ft_free(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	ft_getsize(t_stack *lst)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = (t_stack *)lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
