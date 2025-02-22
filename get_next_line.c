/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:48:12 by qcyril-a          #+#    #+#             */
/*   Updated: 2025/02/21 23:00:10 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	int		i;

	i = 0;
	str = 0;
	if (fd < 0)
		return (NULL);
	while (*buffer || read(fd, buffer, BUFFER_SIZE))
	{
		str = buffer;
	}
	return (str);
}
