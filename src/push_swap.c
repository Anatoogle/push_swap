/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:19:18 by asemykin          #+#    #+#             */
/*   Updated: 2025/03/03 22:38:09 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!ft_isvalid(argc, argv))
		return (0);
	ft_insert(argc, argv, &stack_a);
	if (!ft_checkdup(&stack_a))
	{
		ft_printf("Error\n");
		ft_free(&stack_a);
		ft_free(&stack_b);
		return (1);
	}
	if (!ft_issorted(&stack_a))
		ft_sorting(&stack_a, &stack_b, argc);
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (1);
}

void	ft_sorting(t_stack **stack_a, t_stack **stack_b, int argc)
{
	if (argc == 3)
		ft_sort_two(stack_a, "a");
	else if (argc == 4)
		ft_sort_three(stack_a, "a");
	else if (argc >= 5 && argc <= 10)
		ft_pushsmallest(stack_a, stack_b);
	else
		ft_turk(stack_a, stack_b);
}

// sorting algorithm
//      radix sort
//      quicksort
//      chunk-based sorting
