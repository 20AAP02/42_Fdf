/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:50:38 by antonio           #+#    #+#             */
/*   Updated: 2022/04/20 18:29:09 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

// Achar \n na static save(que guarda tudo o que n foi processado)
// Alocar memoria necessaria p todas as posicoes de chr da linha
// a ser retornarda mais \n e null 
char	*ft_get_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save || *save == 0)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	s = malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
// Processar conteudo da static var 
// Oq ja foi devolvido pela funcao principal desalocar
// o que falta ser devolvido = obter e alocar para nova conteudo de save
// menos oq ja foi devolvido mais o null 

char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (save[i])
		s[c++] = save[i++];
	s[c] = '\0';
	free(save);
	return (s);
}
// Processar conteudo q ainda nao foi lido no fd according BUFFER_SIZE
// E verificar se nao ha erros de leitura
// save = backup buffer, ou seja, oq ainda nao foi lido na chamada anterior
// nao ha erros no processo de leitura e ainda ha bytes a serem lidos no fd
// unir conteudo da variavel save ao buffer

char	*ft_read_and_save(int fd, char *save)
{
	char	*buff;
	int		read_bytes;
	char	*mem;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		mem = save;
		save = ft_strjoin(save, buff);
		free(mem);
	}
	free(buff);
	return (save);
}
// Retorna o que precisa ser lido ate \n
// save = backup buffer (oq ainda nao foi lido)

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
