/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:30:11 by edouard           #+#    #+#             */
/*   Updated: 2024/02/24 16:54:26 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_first_line(char *line)
{
	int	i;
	int	length;

	i = 0;
	length = ft_strlen(line);
	if (line[length - 1] == '\n')
	{
		length--;
	}
	while (i < length)
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_mediums_lines(char *line)
{
	int	i;
	int	length;

	i = 1;
	length = ft_strlen(line);
	if (line[length - 1] == '\n')
		length--;
	if (line[0] != '1' || line[length - 1] != '1')
		return (0);
	while (i < length - 1)
	{
		if (line[i] != 'C' && line[i] != 'P' && line[i] != 'E' && line[i] != '0'
			&& line[i] != '1' && line[i] != 'N')
			return (0);
		i++;
	}
	return (1);
}

static int	check_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(char *line, int line_type)
{
	if (line_type == 1 && !check_first_line(line))
		print_errors("First line is not valid");
	else if (line_type == 3 && !check_last_line(line))
		print_errors("Last line is not valid");
	else if (line_type == 2 && !check_mediums_lines(line))
		print_errors("Medium line is not valid");
	return (1);
}
