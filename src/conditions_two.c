/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:46:08 by asemykin          #+#    #+#             */
/*   Updated: 2025/03/03 13:55:38 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a, "0");
	ft_rotate(stack_b, "0");
	ft_printf("rr\n");
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_revrotate(stack_a, "0");
	ft_revrotate(stack_b, "0");
	ft_printf("rrr\n");
}

// void	ft_ss(t_stack **stack_a, t_stack **stack_b)
// {
// 	ft_swap(stack_a, "0");
// 	ft_swap(stack_b, "0");
// 	ft_printf("ss\n");
// }
