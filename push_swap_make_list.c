/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_make_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:15:35 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/08 20:14:51 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ft_new_nodo con el contenido del str y el siguiente-> NULL

void	ft_new_nodo(t_stack **stack, int valor)
{
	t_stack	*new_nodo;
	t_stack	*aux;

	new_nodo = (t_stack *)malloc (sizeof (t_stack));
	if (!new_nodo)
		return ;
	new_nodo->data = valor;
	new_nodo->next = NULL;
	new_nodo->cost_a = 0;
	new_nodo->cost_b = 0;
	new_nodo->cost = 0;
	aux = NULL;
	if (*stack == NULL)
		*stack = new_nodo;
	else
	{
		aux = *stack;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new_nodo;
	}
}

t_stack	**ft_make_list(char **str)
{
	t_stack	**stack;
	int		i;
	int		valor;

	i = 0;
	stack = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack)
		return (NULL);
	*stack = NULL;
	while (str[i] != NULL)
	{
		valor = ft_atoi(str[i]);
		ft_new_nodo(stack, valor);
		i++;
	}
	return (stack);
}

char	**ft_read_arg(int argc, char **argv)
{
	int		i;
	char	*str;
	char	**readed;

	i = 1;
	while (i <= argc -1)
	{
		str = malloc (sizeof (char *) * argc + 1);
		if (!str)
			return (0);
		i++;
	}
	i = 1;
	while (i <= argc - 1)
	{
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	readed = ft_split (str, ' ');
	return (readed);
}

// Almaceno la posicion final de cada nodo

void	ft_get_pos(t_stack **s, char **str)
{
	int		i;
	t_stack	*aux;

	i = 0;
	aux = *s;
	ft_bubble_sort(str);
	while (aux != NULL)
	{
		while (str[i] && aux)
		{
			if (aux->data == ft_atoi(str[i]))
			{
				aux->pos = i;
				i++;
				aux = aux->next;
			}
			else
				i++;
		}
		i = 0;
	}
}
