/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:59:51 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/02/19 13:52:40 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_infos
{
	int			resx;
	int			resy;
	int			fr;
	int			fg;
	int			fb;
	int			cr;
	int			cg;
	int			cb;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	char		**map;
	int			lines;
	int			columns;
	int			departx;
	int			departy;
	char		depart;
}				t_infos;

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *str, char c);
void		ft_bzero(void *s, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strdup(const char *s, char c);
char		*ft_strjoin(char *s1, char const *s2);
t_infos     infos_init(void);
void		parsing(char *file);
void		errors(char *message);
void		resolution(t_infos *infos, char *str);
void		colors(t_infos *infos, char *str);
int			size_map(t_infos *infos, char *str);
void		map_parse(t_infos *infos, char *file);
void		map_is_valid(t_infos infos);

#endif