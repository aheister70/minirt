# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aheister <aheister@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/05 11:41:15 by aheister      #+#    #+#                  #
#    Updated: 2021/06/04 14:03:29 by aheister      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a
OBJ_FILES		= 	ft_atoi.o\
					ft_bzero.o\
					ft_calloc.o\
					ft_isalnum.o\
					ft_isalpha.o\
					ft_isascii.o\
					ft_isdigit.o\
					ft_isprint.o\
					ft_itoa.o\
					ft_memccpy.o\
					ft_memchr.o\
					ft_memcmp.o\
					ft_memcpy.o\
					ft_memmove.o\
					ft_memset.o\
					ft_putchar_fd.o\
					ft_putendl_fd.o\
					ft_putnbr_fd.o\
					ft_putstr_fd.o\
					ft_split.o\
					ft_strchr.o\
					ft_strdup.o\
					ft_strjoin.o\
					ft_strlcat.o\
					ft_strlcpy.o\
					ft_strlen.o\
					ft_strmapi.o\
					ft_strncmp.o\
					ft_strnstr.o\
					ft_strrchr.o\
					ft_strtrim.o\
					ft_substr.o\
					ft_tolower.o\
					ft_toupper.o\
					ft_lstadd_front.o\
					ft_lstadd_back.o\
					ft_lstclear.o\
					ft_lstdelone.o\
					ft_lstiter.o\
					ft_lstlast.o\
					ft_lstnew.o\
					ft_lstsize.o\

HEADER_FILES	=	libft.h
CFLAGS			=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ_FILES)
			ar -rcs $(NAME) $(OBJ_FILES)

%.o: 		%.c $(HEADER_FILES)
			gcc -c $(CFLAGS) -o $@ $<

clean:
			rm -f $(OBJ_FILES)

fclean: clean
			rm -f $(NAME)

re:
			$(MAKE) fclean
			$(MAKE) all

.PHONY: 	all clean fclean re
