/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_out.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:40:18 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/08 18:28:32 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

//No ordena bien la pila de 5, no chequea la entrada del segundo elemento de B
// para eso tendría que mover forzosamente los menores de A siempre.

void	ft_sort5(t_stack **stack_a, t_stack **stack_b)
{
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack_b)
		return ;
	*stack_b = NULL;
	ft_3tower (stack_a, stack_b);
	ft_print_list(*stack_a);
	ft_print_list(*stack_b);
	ft_sort3(stack_a);
	while (*stack_b)
	{
		if ((*stack_b)->data > (*stack_a)->data)
		{
			move_to_last(stack_a, stack_b, "ra");
			push(stack_b, stack_a);
			write(1, "pa\n", 3);
			move_rotate(stack_a, NULL, "rra");
		}
		else
		{
			push(stack_b, stack_a);
			write(1, "pa\n", 3);
		}
	}
}

void	ft_big_sort(t_stack **a, t_stack **b)
{
	ft_up_or_down(a, b);
	ft_sort3(a);
	//ft_print_list(*a);
	//ft_print_list(*b);
	ft_sort(a, b);
}

void	ft_sort_out(t_stack **stack_a, int nums)
{
	t_stack	**stack_b;

	nums--;
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack_b)
		return ;
	*stack_b = NULL;
	if (nums == 2)
		ft_sort_2(stack_a);
	else if (nums == 3)
		ft_sort3(stack_a);
	else if (nums <= 5)
		ft_sort5(stack_a, stack_b);
	else
		ft_big_sort(stack_a, stack_b);
	ft_free(stack_b);
}

void	ft_sort(t_stack **a, t_stack **b)
{
	ft_cost_b(b);
	ft_print_list(*b);
	ft_print_list(*a);
}
