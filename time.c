/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 18:58:12 by yberries          #+#    #+#             */
/*   Updated: 2020/09/14 06:41:45 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "libft/libft.h"

char	***get_d(void)
{
		char	*line;
		int		fd;
		int		i;
		int		j;
		char	***arr;

		i = -1;
		fd = open("digits.txt", O_RDONLY);
		arr = (char ***)malloc(sizeof(char **) * 11);
		while (++i < 11)
		{
				arr[i] = (char **)malloc(sizeof(char *) * 9);
				j = -1;
				while (++j < 9 && get_next_line(fd, &line))
				{
						arr[i][j] = ft_strdup(line);
						free(line);
				}
		}
		close(fd);
		return (arr);
}

void	time2fdf(char *str, char ***digits)
{
		int		i;
		int		n;
		char	**clock;
		char	*tmp;
		int		flag;

		flag = -1;
		clock = (char **)malloc(sizeof(char *) * 9);
		while (*str != ' ')
		{
				i = -1;
				n = *str - '0';
				if (*str != ':')
				{
						while (++i < 9)
						{
								if (++flag < 9)
										clock[i] = ft_strnew(57);
								tmp = ft_strdup(digits[n][i]);
								clock[i] = ft_strcat(clock[i], tmp);
								free(tmp);
						}
				}
				else 
				{
						while (++i < 9)
						{
								tmp = ft_strdup(digits[10][i]);
								clock[i] = ft_strcat(clock[i], tmp);
								free(tmp);
						}
				}
				*++str;
		}
		i = -1;
		while (++i < 9)
		{
				ft_putstr(clock[i]);
				free(clock[i]);
				ft_putstr("\n");
		}
		free(clock);
}

int		main()
{
		long int	i;
		long int	j;
		char		*str;
		char		***digits;

		j = 0;
		digits = get_d();
		while (1)
		{
				i = time(NULL);
				if (j < i)
				{
						system("clear");
						j = i;
						str = ctime(&i);
						while (*str != ':')
								++str;
						str -= 2;
						time2fdf(str, digits);
				}
		}
		return (0);
}
