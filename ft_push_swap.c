/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:33:29 by fakouyat          #+#    #+#             */
/*   Updated: 2022/06/24 19:33:29 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_headers.h"

int	check_redondance(t_stack **tab_stack_a, int lenght)
{
	int	*arr;
	int	i;
	int	j;

	i = 0;
	arr = stack_to_array(*tab_stack_a, lenght);
	while (i < lenght - 1)
	{
		j = i + 1;
		while (j < lenght)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	**tab_stack_a;
	int		lenght;

	lenght = argc - 1;
	tab_stack_a = ft_initialise(argv, lenght + 1);
	if (!tab_stack_a || check_redondance(tab_stack_a, lenght) == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_sort(tab_stack_a, lenght);
	free(tab_stack_a);
	return (0);
}