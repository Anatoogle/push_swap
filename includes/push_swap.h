/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 00:01:33 by asemykin          #+#    #+#             */
/*   Updated: 2025/03/03 22:55:03 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct s_index
{
	int				value;
	int				index;
}					t_index;

typedef struct s_closest
{
	long			moves_a;
	long			moves_b;
	int				value_a;
	bool			rb;
}					t_closest;

void				ft_listprint(t_stack **stack_a, t_stack **stack_b);

int					ft_isnumber(char *str);
int					ft_isvalid(int argc, char **argv);
int					ft_issorted(t_stack **stack);
int					ft_checkdup(t_stack **stack);

void				ft_insert(int argc, char **argv, t_stack **stack);
void				ft_free(t_stack **stack);

void				ft_sorting(t_stack **stack_a, t_stack **stack_b, int argc);
void				ft_sort_two(t_stack **stack, char *c);
void				ft_sort_three(t_stack **stack, char *c);
void				ft_pushsmallest(t_stack **stack_a, t_stack **stack_b);
t_index				ft_getmin(t_stack **stack_a);
void				ft_movelstmin(t_stack **stack_a, t_stack **stack_b,
						t_index *min);

t_stack				*ft_newlst(int value);
t_stack				*ft_getlast(t_stack *lst);
int					ft_getsize(t_stack *lst);
long				ft_atol(const char *nptr);

void				ft_swap(t_stack **stack, char *str);
void				ft_push(t_stack **stack_take, t_stack **stack_put,
						char *str);
void				ft_rotate(t_stack **stack, char *str);
void				ft_revrotate(t_stack **stack, char *str);
void				ft_rrr(t_stack **stack_a, t_stack **stack_b);
void				ft_rr(t_stack **stack_a, t_stack **stack_b);

int					ft_getbits(t_stack *stack);
void				ft_radix(t_stack **stack_a, t_stack **stack_b);

void				ft_turk(t_stack **stack_a, t_stack **stack_b);
void				ft_turk_pb(t_stack **stack_a, t_stack **stack_b);
void				ft_turk_pa(t_stack **stack_a, t_stack **stack_b);
void				ft_mintotop(t_stack **stack_a);

void				ft_rotatemoves(t_stack **stack, long moves, bool rotate,
						char *str);
void				ft_rotatemoves_a(t_stack **stack, long moves, int value_a,
						int size);

t_closest			ft_rotatetogether(t_stack **stack_a, t_stack **stack_b,
						t_closest best);
t_closest			ft_getbestmoves(t_stack tmp, t_stack **stack_a,
						t_stack **stack_b, long index);
t_closest			ft_initclosest(long moves_a, long moves_b, int value_a,
						bool rb);
t_index				ft_getclosest(t_stack **stack_b, int value);
long				ft_cheapestmoves(t_stack **stack_a, long index);
int					counttoindex(t_stack **stack, int value);
long				ft_diff(long a, long b);

#endif
