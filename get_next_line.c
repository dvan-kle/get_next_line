/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 15:13:24 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/11/05 13:15:45 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

/*-------------------------------------------------*/

char	*leftover(char *str)
{
	int		i;
	int		j;
	char	*leftover;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0')
		return (free(str), NULL);
	i++;
	leftover = (char *)malloc(ft_strlen(str) - i + 1);
	if (!leftover)
		return (NULL);
	while (str[i] != '\0')
	{
		leftover[j] = str[i];
		j++;
		i++;
	}
	leftover[j] = '\0';
	return (free(str), leftover);
}

char	*new_line(char *str)
{
	char		*result;
	int			i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0')
		result = (char *)malloc(i + 1);
	else
		result = (char *)malloc(i + 2);
	if (!result)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		result[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		result[i++] = '\n';
	result[i] = '\0';
	return (result);
}

char	*get_str(int fd, char *str)
{
	char		buff[BUFFER_SIZE + 1];
	int			bytes_read;

	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(str, '\n'))
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(str), NULL);
		buff[bytes_read] = '\0';
		if (!str)
			str = ft_strdup(buff);
		else
			str = ft_strjoin(str, buff);
		if (!str)
			return (free(str), NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*result;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	str = get_str(fd, str);
	if (!str)
		return (NULL);
	result = new_line(str);
	str = leftover(str);
	if (result[0] == '\0')
		return (free(result), NULL);
	return (result);
}

// int	main()
// {
// 	int	fd;
// 	char	*s;

// 	// fd = open("test.txt", O_RDONLY);
// 	fd = (int)"testjes\n want moet ook\n";
// 	s = get_next_line(fd);
// 	printf("\ns = %s", s);
// 	s = get_next_line(fd);
// 	printf("\ns2 = %s", s);
// 	// s = get_next_line(fd);
// 	// printf("\ns3 = %s", s);
// 	// s = get_next_line(fd);
// 	// printf("\ns3 = %s", s);
// 	// s = get_next_line(fd);
// 	// printf("\ns3 = %s", s);
// 	// close(fd);
// 	return (0);
// }
