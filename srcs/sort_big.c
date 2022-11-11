/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:45:09 by sfathima          #+#    #+#             */
/*   Updated: 2022/09/12 14:17:06 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_mid(int rd, int *tmp, int size)
{
	int	mid;

	if (rd == 10)
		mid = tmp[size - 1];
	else
		mid = tmp[(size / 10) * rd];
	return (mid);
}

int	get_mid_2(int *tmp, int size, int rd, int ln)
{
	int	pos;

	if (ln <= 100)
		pos = tmp[(size / 10) * (rd - 1)];
	else
		pos = tmp[(int)((size / 10) * (float)(rd - 0.5))];
	return (pos);
}

void	sort_big(t_stack *stack, int *tmp, int size)
{
	int	ln;
	int	mid;
	int	rd;
	int	mid_2;

	mid = 0;
	mid_2 = 0;
	ln = stack->a_size - 1;
	if (stack->a_size <= 100)
		rd = 2;
	else
		rd = 1;
	while (stack->a_size > 0 && rd <= 10)
	{
		mid = get_mid(rd, tmp, size);
		mid_2 = get_mid_2(tmp, size, rd, ln);
		if (ln <= 100)
			rd += 2;
		else
			rd += 1;
		move_chunk(mid, stack, mid_2);
	}
	while (stack->b_size > 0)
		move_b(stack);
}

void	large_sort(t_stack *stack)
{
	int	*dup;
	int	size;

	size = stack->a_size - 1;
	dup = malloc(sizeof(int) * (size + 1));
	get_dup(dup, stack);
	quick_sort(dup, 0, size);
	sort_big(stack, dup, size + 1);
	free (dup);
}
