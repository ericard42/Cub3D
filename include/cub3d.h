/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:50:11 by ericard           #+#    #+#             */
/*   Updated: 2021/04/05 12:28:05 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*addr;
	int			img_width;
	int			img_height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			screenx;
	int			screeny;
}				t_mlx;

typedef struct	s_sprite
{
	double		*zbuffer;
	int			nbsprites;
	int			*order;
	double		*spritedist;
	double		spritex;
	double		spritey;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			spriteheight;
	int			drawstarty;
	int			drawendy;
	int			spritewidth;
	int			drawstartx;
	int			drawendx;
	int			stripe;
	int			texx;
}				t_sprite;

typedef struct	s_spritepos
{
	double		x;
	double		y;
}				t_spritepos;

typedef struct	s_colors
{
	int			r;
	int			g;
	int			b;
	int			value;
}				t_colors;

typedef struct	s_texture
{
	int			tex;
	double		wallx;
	int			texx;
	int			texy;
	double		step;
	double		texpos;
}				t_texture;

typedef struct	s_moves
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
}				t_move;

typedef struct	s_ray
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
	double		raydirx;
	double		raydiry;
	double		camerax;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			x;
}				t_ray;

typedef struct	s_infos
{
	int			resx;
	int			resy;
	t_colors	f;
	t_colors	c;
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
	int			save;
	int			inmap;
	t_mlx		mlx;
	t_mlx		textures[5];
	t_ray		ray;
	t_texture	tex;
	t_sprite	sp;
	t_spritepos	*spos;
	t_move		move;
}				t_infos;

int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *str, char c);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strdup(const char *s, char c);
char			*ft_strjoin(char *s1, char const *s2);
void			infos_init(t_infos *infos);
void			parsing(char *file, t_infos *infos);
void			errors(char *message, t_infos *infos);
void			resolution(t_infos *infos, char *str);
void			colors(t_infos *infos, char *str);
int				size_map(t_infos *infos, char *str);
void			map_parse(t_infos *infos, char *file);
void			map_is_valid(t_infos *infos);
void			textures(t_infos *infos, char *str);
int				verify_map(char *str);
int				ft_close(t_infos *infos);
void			mlx_start(t_infos *infos);
void			struct_mlx_init(t_infos *infos);
int				key_press(int keycode, t_infos *infos);
void			my_mlx_pixel_put(t_infos *infos, int x, int y, int color);
int				raycasting(t_infos *infos);
void			depart_init(t_infos *infos);
void			key_left(t_infos *infos);
void			key_right(t_infos *infos);
void			key_a_d(t_infos *infos, char key);
void			key_w_s(t_infos *infos, char key);
int				minimap(t_infos	*infos);
void			print_columns(t_infos *infos);
void			sprite(t_infos *infos);
void			init_sprite(t_infos *infos);
void			save(t_infos *infos);
int				key_release(int keycode, t_infos *infos);
int				key(t_infos *infos);

#endif
