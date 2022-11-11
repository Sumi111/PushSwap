/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:06:36 by sfathima          #+#    #+#             */
/*   Updated: 2022/04/27 13:06:58 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include <math.h>
# include<stdlib.h>
# include"../libft/libft.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	a_size;
	int	b_size;
}	t_stack;

void	ft_init(t_stack *stack, int n);
void	get_num_arg(t_stack *stack, int argc, char **argv, int i);
int		ft_atoi(const char *str, t_stack *stack, int flag);

void	ft_check_num(char *str, t_stack *stack, int flag, char **start);
void	check_repti(t_stack *stack, int argc);
void	ft_free_str(char **str, int ct);
void	ft_free_stack(t_stack *stack);
void	check_repti(t_stack *stack, int argc);

int		ft_max_pos(int *a, int a_size);
int		ft_min_pos(int *a, int a_size);
void	push_max_min(t_stack *stack, int pos);
int		get_max(int *a, int size);

void	ft_sort(t_stack *stack);
int		ft_sorted(t_stack *stack);
void	small_sort(t_stack *stack);
void	sort_3(t_stack *stack);
void	sort_5(t_stack *stack);
void	large_sort(t_stack *stack);
void	sort_big(t_stack *stack, int *tmp, int size);

void	sa(t_stack *stack, int print);
void	sb(t_stack *stack, int print);
void	ra(t_stack *stack, int print);
void	rb(t_stack *stack, int print);
void	rra(t_stack *stack, int print);
void	rrb(t_stack *stack, int print);
void	pa(t_stack *stack);
void	pb(t_stack *stack);

int		chunk_present(t_stack *stack, int chunk);
void	move_chunk(int mid, t_stack *stack, int s);
void	move_b(t_stack *stack);
int		make_way(int chunk, t_stack *stack);
void	get_dup(int *tmp, t_stack *stack);
void	quick_sort(int *tmp, int low, int high);

#endif