# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aheister <aheister@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/26 11:01:13 by aheister      #+#    #+#                  #
#    Updated: 2021/06/26 15:27:56 by aheister      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	miniRT

CFLAGS			=	-Wall -Werror -Wextra -Iincludes
CC				=	gcc

LIBFT			=	lib/libft/libft.a

MLX				=	libmlx.dylib

MAN_FILES		= 	srcs/initialize.o\
					srcs/intersect.o\
					srcs/light.o\

SHARED_FILES	=	srcs/calculate_point.o\
					srcs/cylinder.o\
					srcs/cylinder2.o\
					srcs/errors.o\
					srcs/ft_atof.o\
					srcs/get_next_line/get_next_line.o\
					srcs/get_next_line/get_next_line_utils.o\
					srcs/initialize_checks.o\
					srcs/initialize_utils.o\
					srcs/image.o\
					srcs/image_utils.o\
					srcs/minirt.o\
					srcs/plane.o\
					srcs/sphere.o\
					srcs/vector_ops.o\
					srcs/vector_ops2.o\

BONUS_FILES		=	srcs/bonus/initialize_bonus.o\
					srcs/bonus/intersect_bonus.o\
					srcs/bonus/light_bonus.o\
					srcs/bonus/triangle.o\

ifdef WITH_BONUS
OBJ_FILES = $(BONUS_FILES) $(SHARED_FILES)
else
OBJ_FILES = $(MAN_FILES) $(SHARED_FILES)
endif

%.o:				%.c
					$(CC) -c $(CFLAGS) -o $@ $<

all:				$(NAME)

$(LIBFT):		
					$(MAKE) -C lib/libft

$(MLX):
					$(MAKE) -C lib/mlx
					cp lib/mlx/libmlx.dylib libmlx.dylib

$(NAME):			$(OBJ_FILES) $(LIBFT) $(MLX)
					$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) $(MLX) -L lib/mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
					rm -f $(MAN_FILES) $(BONUS_FILES) $(SHARED_FILES)
					$(MAKE) clean -C lib/libft
					$(MAKE) clean -C lib/mlx

bonus:
					$(MAKE) WITH_BONUS=1 all

fclean:				clean
					rm -f $(NAME)
					rm -f $(LIBFT)
					rm -f $(MLX)

re:
					$(MAKE) fclean
					$(MAKE) all

.PHONY:				all clean fclean re bonus
