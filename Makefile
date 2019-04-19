# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/17 16:55:29 by mhernand          #+#    #+#              #
#    Updated: 2019/04/19 20:23:48 by mhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Werror -Wextra # DON'T FORGET TO ADD MEEEEEEEEEE!

SRCS = main.c\
	   reader.c\
	   deltab.c\
	   visualize.c\
	   texting.c\
	   touch.c\
	   points.c
		#line.c
	   #set_to_zero.c\

OBJECTS = $(SRCS:.c=.o)

LIB_FOLDER = libft/

LIB_TARG = libft

LIBMLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

all:$(NAME)

### REMOVE -g3 FLAGGGGGGGGGGG!

DUMB = -fsanitize=address  -fno-omit-frame-pointer -fsanitize-address-use-after-scope 

$(NAME):$(OBJECTS) | $(LIB_TARG)
	$(CC) -g3 $(CFLAGS) $(SRCS) libft/libft.a $(LIBMLX) -o $(NAME)

$(LIB_TARG):
	@make -C $(LIB_FOLDER) 

clean:
	@make -C $(LIB_FOLDER) clean
	rm -rf $(OBJECTS)

fclean:
	@make -C $(LIB_FOLDER) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean all libft
