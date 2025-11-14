# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 09:56:36 by bvarea-k          #+#    #+#              #
#    Updated: 2025/11/14 12:36:22 by bvarea-k         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CNAMES = Megaphone

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = obj/

CFILES = $(addsuffix .cpp, $(CNAMES))
OFILES = $(addprefix $(OBJ), $(addsuffix .o, $(CNAMES)))

NAME = Megaphone

all: $(NAME)

$(NAME): $(OFILES)
	@c++ $(CFLAGS) $(OFILES) -o $(NAME)
	@echo "Megaphone compiled"

$(OFILES): $(CFILES)
	@mkdir -p $(OBJ)
	@c++ $(CFLAGS) -c $(CFILES)
	@mv *.o $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
