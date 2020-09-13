/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 18:58:12 by yberries          #+#    #+#             */
/*   Updated: 2020/09/14 01:54:52 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"

char	*digit(char c)
{
		char	*line;
		int		fd;

		fd = open("digits.txt", O_RDONLY);
		while (get_next_line(fd, &line))
		{
				free(line);
		}
		close(fd);
}

void	time2fdf(char *str)
{
		int		i;
		int		j;
		char	**clock;

		i = 0;
		j = 0;
		while (str[i] != ' ')
		{
			
		}
}

int		main()
{
		long int	i;
		long int	j;
		char		*str;

		j = 0;
		while (1)
		{
				i = time(NULL);
				if (j < i)
				{
						j = i;
						str = ctime(&i);
						while (*str != ':')
								++str;
						str -= 2;
						//time2fdf(str);
				}
		}
		return (0);
}
