/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 08:41:35 by mhernand          #+#    #+#             */
/*   Updated: 2019/05/08 19:13:20 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <unistd.h>
# include <unistd.h>
# include <assert.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>

# define ESC			53
# define A				0
# define D				2
# define W				13
# define S				1
# define C				8
# define Q				12
# define E				14
# define KEY_1			18
# define KEY_2			19
# define M				46
# define L				37
# define K				40
# define N				45
# define R				15

# define GRASS	0x32CD32
# define SAND	0xF4A460
# define ROCK	0x999999
# define SNOW	0xFFF5EE
# define WATER	0x1E90FF

typedef struct		s_ll
{
	size_t			content_size;
	char			**content;
	struct s_ll		*next;
}					t_ll;

typedef struct		s_cor
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				z;
}					t_cor;

typedef struct		s_pl
{
	int				px;
	int				py;
	int				hx;
	int				hy;
	int				lx;
	int				ly;
}					t_pl;

typedef struct		s_bre
{
	int				dx;
	int				dy;
	int				tdx;
	int				tdy;
	int				t_y;
	int				t_x;
	int				er2;
	int				ix;
	int				iy;
}					t_bre;

typedef struct		s_win
{
	void			*mp;
	void			*wp;
	int				wx;
	int				wy;
}					t_win;

typedef struct		s_img
{
	void			*ig;
	char			*dt;
	int				bp;
	int				ed;
	int				sl;
}					t_img;

typedef struct		s_env
{
	char			**map;
	char			*line;
	char			**lin;
	char			**tmp;
	int				k[300];
	int				ret;
	int				spax;
	int				iso;
	int				spay;
	int				mx;
	int				my;
	int				zo;
	int				hi;
	int				tp;
	int				c;
	double			r;
	int				iso_check;
	int				r_check;
	t_win			w;
	t_img			i;
	t_ll			*lines;
	t_cor			**co;
	t_bre			b;
	t_pl			pla;
}					t_env;

int					reader(int fd, t_env *e);
void				delevr(t_env *e, int w);
void				free_link(t_ll *link);
int					visualize(t_env *e);
int					points(t_env *e);
void				texting(t_env *e);
void				draw_lines(t_env *e);
void				reset(t_env *e);
int					color_me(t_cor co, t_cor nx, t_env *e, int w);
int					touch(t_env *e);
void				projection(t_env *e);
int					redraw(t_env *e);
int					main(int argc, char **argv);

#endif
