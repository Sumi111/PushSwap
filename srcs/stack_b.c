/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:38:26 by sfathima          #+#    #+#             */
/*   Updated: 2022/04/26 13:06:22 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sb(t_stack *stack, int print)
{
	int	tmp;

	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	if (print == 1)
		printf("sb\n");
}

void	pb(t_stack *stack)
{
	int	i;

	i = stack->b_size - 1;
	stack->b_size++;
	while (i >= 0)
	{
		stack->b[i + 1] = stack->b[i];
		i--;
	}
	stack->b[0] = stack->a[0];
	i = 0;
	while (i < stack->a_size - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a_size--;
	printf("pb\n");
}

void	rb(t_stack *stack, int print)
{
	int	tmp;
	int	i;

	tmp = stack->b[0];
	i = 0;
	while (i < stack->b_size - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = tmp;
	if (print == 1)
		printf("rb\n");
}

void	rrb(t_stack *stack, int print)
{
	int	tmp;
	int	i;

	i = stack->b_size - 1;
	tmp = stack->b[i];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = tmp;
	if (print == 1)
		printf("rrb\n");
}
