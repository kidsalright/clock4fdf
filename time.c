/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 18:58:12 by yberries          #+#    #+#             */
/*   Updated: 2020/09/25 16:04:56 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "libft/libft.h"
#include <curses.h>

#define	CYN	"\x1B[36m"
#define MAG	"\x1B[35m"


void print_char(char c)
{
		c = ft_toupper(c);
		if (c == 'A')
				ft_printf("..######..\n..#....#..\n..######..\n..#....#..\n..#....#..\n\n");
		else if (c == 'B')
				ft_printf("..######..\n..#....#..\n..#####...\n..#....#..\n..######..\n\n");
		else if (c == 'C')
				ft_printf("..######..\n..#.......\n..#.......\n..#.......\n..######..\n\n");
		else if (c == 'D')
				ft_printf("..#####...\n..#....#..\n..#....#..\n..#....#..\n..#####...\n\n");
		else if (c == 'E')
				ft_printf("..######..\n..#.......\n..#####...\n..#.......\n..######..\n\n");
		else if (c == 'F')
				ft_printf("..######..\n..#.......\n..#####...\n..#.......\n..#.......\n\n");
		else if (c == 'G')
				ft_printf("..######..\n..#.......\n..#####...\n..#....#..\n..#####...\n\n");
		else if (c == 'H')
				ft_printf("..#....#..\n..#....#..\n..######..\n..#....#..\n..#....#..\n\n");
		else if (c == 'I')
				ft_printf("..######..\n....##....\n....##....\n....##....\n..######..\n\n");
		else if (c == 'J')
				ft_printf("..######..\n....##....\n....##....\n..#.##....\n..####....\n\n");
		else if (c == 'K')
				ft_printf("..#...#...\n..#..#....\n..##......\n..#..#....\n..#...#...\n\n");
		else if (c == 'L')
				ft_printf("..#.......\n..#.......\n..#.......\n..#.......\n..######..\n\n");
		else if (c == 'M')
				ft_printf("..#....#..\n..##..##..\n..#.##.#..\n..#....#..\n..#....#..\n\n");
		else if (c == 'N')
				ft_printf("..#....#..\n..##...#..\n..#.#..#..\n..#..#.#..\n..#...##..\n\n");
		else if (c == 'O')
				ft_printf("..######..\n..#....#..\n..#....#..\n..#....#..\n..######..\n\n");
		else if (c == 'P')
				ft_printf("..######..\n..#....#..\n..######..\n..#.......\n..#.......\n\n");
		else if (c == 'Q')
				ft_printf("..######..\n..#....#..\n..#.#..#..\n..#..#.#..\n..######..\n\n");
		else if (c == 'R')
				ft_printf("..######..\n..#....#..\n..#.##...\n..#...#...\n..#....#..\n\n");
		else if (c == 'S')
				ft_printf("..######..\n..#.......\n..######..\n.......#..\n..######..\n\n");
		else if (c == 'T')
				ft_printf("..######..\n....##....\n....##....\n....##....\n....##....\n\n");
		else if (c == 'U')
				ft_printf("..#....#..\n..#....#..\n..#....#..\n..#....#..\n..######..\n\n");
		else if (c == 'V')
				ft_printf("..#....#..\n..#....#..\n..#....#..\n...#..#...\n....##....\n\n");
		else if (c == 'W')
				ft_printf("..#....#..\n..#....#..\n..#.##.#..\n..##..##..\n..#....#..\n\n");
		else if (c == 'X')
				ft_printf("..#....#..\n...#..#...\n....##....\n...#..#...\n..#....#..\n\n");
		else if (c == 'Y')
				ft_printf("..#....#..\n...#..#...\n....##....\n....##....\n....##....\n\n");
		else if (c == 'Z')
				ft_printf("..######..\n......#...\n.....#....\n....#.....\n..######..\n\n");
		else if (c == ' ')
				ft_printf("..........\n..........\n..........\n..........\n\n");
		else if (c == '.')
				ft_printf("----..----\n\n");
}

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
		int		j;

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
		ft_putstr(CYN);
		while (++i < 56)
				ft_putchar('0');
		ft_putchar('\n');
		i = -1;
		while (++i < 9)
		{
				j = -1;
				while (++j < 57)
				{
						if (clock[i][j] == '0')
								ft_putstr(CYN);
						else
								ft_putstr(MAG);
						ft_putchar(clock[i][j]);
				}
				free(clock[i]);
				ft_putstr("\n");
		}
		i = -1;
		ft_putstr(CYN);
		while (++i < 56)
				ft_putchar('0');
		ft_putchar('\n');
		free(clock);
}

int		main(int ac, char **av)
{
		long int	i;
		long int	j;
		char		*str;
		char		***digits;

		if (ac == 2 && av[1][0] == 't')
		{
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
		}
		else
		{
				while (1)
				{
						while (get_next_line(0, &str))
						{
								i = 0;
								while(str[i])
									print_char(str[i++]);
								ft_strdel(&str);
						}
				}
		}
		return (0);
}
