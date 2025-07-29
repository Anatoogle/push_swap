/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:12:17 by asemykin          #+#    #+#             */
/*   Updated: 2025/03/03 21:21:06 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_insert(int argc, char **argv, t_stack **stack)
{
	int		i;
	t_stack	*newnode;

	i = argc - 1;
	while (i > 0)
	{
		newnode = ft_newlst(ft_atoi(argv[i]));
		if (newnode == NULL)
			return ;
		newnode->next = *stack;
		*stack = newnode;
		i--;
	}
}

int	ft_isvalid(int argc, char **argv)
{
	while (argc > 1)
	{
		if (ft_isnumber(argv[argc - 1]) == 1)
			argc--;
		else
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	return (1);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (!*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	if (i > 12)
		return (0);
	if (ft_atol(str) > 2147483647 || ft_atol(str) < -2147483648)
		return (0);
	return (1);
}

int	ft_issorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

int	ft_checkdup(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = (*stack)->next;
	tmp2 = *stack;
	while (tmp2)
	{
		while (tmp)
		{
			if (tmp->value != tmp2->value)
				tmp = tmp->next;
			else
				return (0);
		}
		tmp2 = tmp2->next;
		if (tmp2)
			tmp = tmp2->next;
	}
	return (1);
}
