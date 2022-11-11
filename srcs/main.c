/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:24:40 by sfathima          #+#    #+#             */
/*   Updated: 2022/04/25 13:24:40 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_num_arg(t_stack *stack, int argc, char **argv, int i)
{
	int	j;
	int	flag;

	j = i;
	flag = i;
	while (j < argc)
	{
		ft_check_num(argv[j], stack, flag, &argv[0]);
		j++;
	}
	j = i;
	i = 0;
	while (j < argc)
	{
		stack->a[i] = ft_atoi(argv[j], stack, flag);
		j++;
		i++;
	}
}

void	ft_init(t_stack *stack, int n)
{
	stack->a = malloc(sizeof(int) * (n + 1));
	stack->b = malloc(sizeof(int) * (n + 1));
	stack->a_size = n;
	stack->b_size = 0;
}

void	get_data(int *argc, char **argv, t_stack *stack)
{
	*argc = ft_word_count(argv[1], ' ');
	argv = ft_split(argv[1], ' ');
	ft_init(stack, *argc);
	get_num_arg(stack, *argc, argv, 0);
	ft_free_str(argv, *argc);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (argc < 2)
	{
		free (stack);
		exit (1);
	}
	else if (argc == 2)
		get_data(&argc, argv, stack);
	else
	{
		ft_init(stack, --argc);
		get_num_arg(stack, argc + 1, argv, 1);
	}
	check_repti(stack, argc);
	ft_sort(stack);
	ft_free_stack(stack);
	return (0);
}
