# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/25 16:14:42 by bvarea-k          #+#    #+#              #
#    Updated: 2025/12/05 16:55:49 by bvarea-k         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main ClapTrap ScavTrap FragTrap DiamondTrap

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = obj/

CFILES = $(addsuffix .cpp, $(SRC))
OFILES = $(addprefix $(OBJ), $(addsuffix .o, $(SRC)))

NAME = DiamondTrap

all: $(NAME)

$(NAME): $(OFILES)
	@c++ $(CFLAGS) $(OFILES) -o $(NAME)
	@echo "DiamondTrap compiled"

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