# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/17 16:55:29 by mhernand          #+#    #+#              #
#    Updated: 2019/04/29 09:57:11 by mhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g # DON'T FORGET TO ADD MEEEEEEEEEE!

SRCS = main.c\
	   reader.c\
	   deltab.c\
	   visualize.c\
	   texting.c\
	   touch.c\
	   points.c\
	   projection.c\
	   lines.c

OBJECTS = $(SRCS:.c=.o)

LIB_FOLDER = libft/

LIB_TARG = libft

MINI_F = minilibx_macos/

LIBMLX = -L ./minilibx_macos/ -lmlx -framework OpenGL -framework Appkit

all:$(NAME)

### REMOVE -g3 FLAGGGGGGGGGGG!

DUMB = -fsanitize=address  -fno-omit-frame-pointer -fsanitize-address-use-after-scope 

$(NAME):$(OBJECTS) | $(LIB_TARG) 
	$(CC) -g3 $(CFLAGS) $(OBJECTS) libft/libft.a $(LIBMLX) -o $(NAME)
	@touch .gitignore
	@echo "*.o" > .gitignore
	@echo "*.a" >> .gitignore

$(LIB_TARG):
	@make -C $(LIB_FOLDER) 
	@make -C $(MINI_F)

clean:
	@make -C $(LIB_FOLDER) clean
	@make -C $(MINI_F) clean
	rm -rf $(OBJECTS)

fclean: clean
	@make -C $(LIB_FOLDER) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean all libft
