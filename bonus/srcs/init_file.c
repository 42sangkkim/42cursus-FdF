/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 23:00:41 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/06 23:23:59 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "libft.h"
#include "utils.h"

char	*get_next_line(int fd);

void	parse_next_line(char ****words_ptr, char *line, size_t line_cnt);
int		is_valid_format(char *word);

char	***get_file_data(char *filename)
{
	int		fd;
	size_t	line_cnt;
	char	*line;
	char	***words;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_msg("file open error\n");
	line_cnt = 0;
	words = ft_calloc(1, sizeof(char **));
	if (!words)
		exit_msg("malloc error\n");
	line = get_next_line(fd);
	while (line)
	{
		parse_next_line(&words, line, line_cnt++);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (words);
}

void	parse_next_line(char ****words_ptr, char *line, size_t line_cnt)
{
	*words_ptr = (char ***)ft_realloc(*words_ptr,
			(line_cnt + 1) * sizeof(char **),
			(line_cnt + 2) * sizeof(char **));
	if (!*words_ptr)
		exit_msg("malloc error\n");
	if (ft_strchr(line, '\n'))
		*(ft_strchr(line, '\n')) = '\0';
	(*words_ptr)[line_cnt] = ft_split(line, ' ');
	if (!(*words_ptr)[line_cnt])
		exit_msg("malloc error\n");
	(*words_ptr)[line_cnt + 1] = NULL;
}

int	check_file_data(char ***words)
{
	size_t	width;
	size_t	i;
	size_t	j;

	width = ft_arrlen((void **)words[0]);
	i = 0;
	while (words[i])
	{
		if (ft_arrlen((void **)words[i]) != width)
		{
			write(1, "[Invalid format] FdF is not rectangle\n", 38);
			return (0);
		}
		j = 0;
		while (j < width)
		{
			if (!is_valid_format(words[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_format(char *word)
{
	if (*word == '+' || *word == '-')
		word++;
	while (ft_isdigit(*word))
		word++;
	if (*word == ',')
	{
		if (ft_strncmp(++word, "0x", 2))
		{
			write(1, "[Invalid format] Color is not valid format\n", 55);
			return (0);
		}
		word += 2;
		while (ft_isdigit(*word)
			|| ('A' <= *word && *word <= 'F')
			|| ('a' <= *word && *word <= 'f'))
			word++;
	}
	if (*word)
	{
		write(1, "[Invalid format] Altitude is not valid format\n", 55);
		return (0);
	}
	else
		return (1);
}
