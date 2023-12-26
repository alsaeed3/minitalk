# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 20:26:37 by alsaeed           #+#    #+#              #
#    Updated: 2023/06/23 20:45:21 by alsaeed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=		server.c client.c
OBJ 	=		$(SRC:.c=.o)

CC		=		cc
CFLAGS	=		-Wall -Wextra -Werror

NAME	=		server client

LIBFT = 		libft/libft.a

all:			$(NAME)

server:			$(OBJ) $(LIBFT)
				@$(CC) $(CFLAGS) $(LIBFT) -o $@ server.o

client:			$(OBJ) $(LIBFT)
				@$(CC) $(CFLAGS) $(LIBFT) -o $@ client.o

$(LIBFT):
				make -C libft

clean:
				rm -f $(OBJ)
				make -C libft clean

fclean:			clean
				make -C libft fclean
				rm -f $(NAME)

re: 			fclean all

.PHONY: 		all clean fclean re