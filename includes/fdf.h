/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 08:41:35 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/23 19:19:07 by mhernand         ###   ########.fr       */
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
# define I		34
# define O		31
# define KEY_1	18
# define KEY_2	19
# define M		46
# define L		37

typedef struct		s_ll
{
	size_t			content_size;
	char			**content;
	struct s_ll		*next;
}					t_ll;

typedef struct		s_rgb
{
	float			r;
	float			g;
	float			b;
}					t_rgb;

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
	float			px;
	float			py;
	float			hx;
	float			hy;
	int				lx; //len lines
	int				ly; //len down
}					t_pl;

typedef struct		s_bre
{
	float			dx;
	float			dy;
	float			dec;
	float			dydx;
	float			tdydx;
	float			tdxdy;
	float			m;
}					t_bre;

typedef struct		s_win
{
	void			*m_p;
	void			*w_p;
	float			wx;
	float			wy;
}					t_win;

typedef struct		s_env
{
	char			**map; // for the x, and y coordinantes
	char			*line; // line for GNL
	char			**lin; // ** for str_split
	char			**tmp;
	int				ks[300]; //keys
	float			ret; // return for GNL
	float			spa;
	int				prx;
	int				pry;
	t_win			w; // my window and mlx variables
	t_ll			*lines; // linked list of strings 
	t_rgb			rgb; // colours
	t_cor			**co; // ALL OF MY INFO 'POINTS' !! 
	t_bre			be; // bresenham algo
	t_pl			pla;
}					t_env;

int					reader(int fd, t_env *ev);
void				delevr(t_env *ev);
void				free_link(t_ll *link);
int					visualize(t_env *ev);
int					points(t_env *ev);
void				texting(t_env *ev);
void				lines(t_env *ev);
int					touch(t_env *ev);
int					main(int argc, char **argv);

#endif
