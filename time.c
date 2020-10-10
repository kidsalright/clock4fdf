/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 18:58:12 by yberries          #+#    #+#             */
/*   Updated: 2020/10/10 22:56:22 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "libft/libft.h"
#include <curses.h>

#define	CYN	"\x1B[36m"
#define MAG	"\x1B[35m"

void	chars2fdf(char *str, char ***chars)
{
		int		i;
		int		j;
		int		l;
		int		flag;
		char	*tmp;
		char	**res;
		int		heh;

		flag = -1;
		j = 0;
		l = ft_strlen(str);
		res = (char **)malloc(sizeof(char *) * l * 5);
		while (l > 0)
		{
				i = -1;
				heh = str[j] - 'a';
				if (heh >= 0 && heh <= 25)
				{
						while (++i < 5)
						{
								if (++flag < 5)
										res[i] = ft_strnew(l * 10);
								tmp = ft_strdup(chars[heh][i]);
								res[i] = ft_strcat(res[i], tmp);
								free(tmp);
						}
				}
				else
				{
						while(++i < 5)
						{
								if (++flag < 5)
										res[i] = ft_strnew(l * 10);
								tmp = ft_strdup(chars[26][i]);
								res[i] = ft_strcat(res[i], tmp);
								free(tmp);
						}
				}
				++j;
				--l;
		}
		i = -1;
		l = ft_strlen(str);
		while (++i < 5)
		{
				j = -1;
				while (++j < (l * 10))
				{
						ft_putstr(MAG);
						ft_putchar(res[i][j]);
				}
				free(res[i]);
				ft_putstr("\n");
		}
}

char	***get_char(void)
{
		char	*line;
		int		fd;
		int		i;
		int		j;
		char	***arr;

		i = -1;
		fd = open("chars.txt", O_RDONLY);
		arr = (char ***)malloc(sizeof(char **) * 27);
		while (++i < 27)
		{
				arr[i] = (char **)malloc(sizeof(char *) * 5);
				j = -1;
				while (++j < 5 && get_next_line(fd, &line))
				{
						arr[i][j] = ft_strdup(line);
						free(line);
				}
		}
		close(fd);
		return (arr);
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
		while (++i < 57)
				ft_putchar('0');
		ft_putchar('\n');
		i = -1;
		while (++i < 9)
		{
				j = -1;
				while (++j < 57)
				{
						if (j == 56)
						{
								ft_putstr(CYN);
								ft_putchar('0');
								break;
						}
						if (clock[i][j] == '0')
								ft_putstr(CYN);
						else
								ft_putstr(MAG);
						if (clock[i][j] != '\n' || clock[i][j] != '\0')
								ft_putchar(clock[i][j]);
				}
				free(clock[i]);
				ft_putchar('\n');
		}
		i = -1;
		ft_putstr(CYN);
		while (++i < 57)
				ft_putchar('0');
		ft_putchar('\n');
		free(clock);
}

int		main(int ac, char **av)
{
		long int	i;
		long int	j;
		int			k;
		char		*str;
		char		***digits;
		char		***chars;
		int			fd;
		int			flag;

		if (ac == 2 && av[1][0] == 't')
		{
				j = 0;
				digits = get_d();
				while (1)
				{
						i = time(NULL);
						if (j < i)
						{
								k = 12;
								j = i;
								str = ctime(&i);
								while (*str != ':')
										++str;
								str -= 2;
								time2fdf(str, digits);
								system("sleep 1");
								while (--k)
										ft_printf("\033[A\33[2K\r");
						}
				}
		}
		else
		{
				chars = get_char();
				flag = 4;
				while (1)
				{
						fd = open("hello.c", O_WRONLY | O_APPEND | O_CREAT, 0644);
						while (get_next_line(0, &str))
						{
								if (str[0] == ':' && str[1] == 'q')
								{
										system("gcc hello.c -o hello");
										ft_strdel(&str);
										exit (0);
								}
								ft_putstr_fd(str, fd);
								ft_putstr_fd("\n", fd);
								chars2fdf(str, chars);
								--flag;
								ft_strdel(&str);
						}
				}
		}
		return (0);
}
