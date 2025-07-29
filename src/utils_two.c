/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:10:04 by asemykin          #+#    #+#             */
/*   Updated: 2025/03/03 22:35:54 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atol(const char *nptr)
{
	int		i;
	long	num;
	int		plusminus;

	num = 0;
	plusminus = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			plusminus = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	num = num * (plusminus);
	return (num);
}

// void	ft_listprint(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	a = *stack_a;
// 	b = *stack_b;
// 	while (a || b)
// 	{
// 		ft_printf("value: ");
// 		if (a)
// 		{
// 			ft_printf("%i", a->value);
// 			a = a->next;
// 		}
// 		if (b)
// 		{
// 			ft_printf("                       %i", b->value);
// 			b = b->next;
// 		}
// 		ft_printf("\n");
// 	}
// }
