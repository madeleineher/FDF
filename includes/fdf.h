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
# include <stdio.h> // REMOVE ME
# include <unistd.h>
# include <assert.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>

# define ESC	53 
# define A		0
# define D		2
# define W		13
# define S		1
# define C		8
# define Q		12	
# define E		14
# define KEY_1	18
# define KEY_2	19
# define M		46
# define L		37
# define K		40
# define N		45

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
	int				lx; //len lines
	int				ly; //len down
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
	void			*img;
	char			*data;
	int				bpp;
	int				ed;
	int				s_li;	
}					t_img;

typedef struct		s_env
{
	char			**map; // for the x, and y coordinantes
	char			*line; // line for GNL
	char			**lin; // ** for str_split
	char			**tmp;
	int				ks[300]; //keys
	int				ret; // return for GNL
	int				spax;
	int				iso;
	int				spay;
	int				ml;
	int				mx;
	int				my;
	int				zo;
	int				rr;
	int				rl;
	int				hi;
	int				tp;

	int				iso_check;
	t_win			w; // my window and mlx variables
	t_img			i; // for my images !
	t_ll			*lines; // linked list of strings 
	t_cor			**co; // ALL OF MY INFO 'POINTS' !! 
	t_bre			b; // bresenham algo
	t_pl			pla;
}					t_env;

int					reader(int fd, t_env *e);
void				delevr(t_env *e, int w);
void				free_link(t_ll *link);
int					visualize(t_env *e);
int					points(t_env *e);
void				texting(t_env *e);
void				draw_me(t_env *e);
int					touch(t_env *e);
void				projection(t_env *e);
int					tmp(t_env *e);
int					main(int argc, char **argv);

#endif
