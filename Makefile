# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 14:36:18 by mohimi            #+#    #+#              #
#    Updated: 2024/03/11 15:49:59 by mohimi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror -Imlx -g

NAME = so_long

NAME_BONUS = so_long_bonus

SRCS = ./mandatory/ft_split.c \
		./mandatory/draw_map.c \
		./mandatory/get_next_line.c \
		./mandatory/get_next_line_utils.c \
		./mandatory/read_map.c \
		./mandatory/set_hei_wid.c \
		./mandatory/set_parameter.c \
		./mandatory/main.c \
		./mandatory/set_positon.c \
		./mandatory/movemont.c \
		./mandatory/you_win.c \
		./mandatory/ft_putnbr.c \
		./mandatory/ft_check_validefile.c

OBJS = $(SRCS:.c=.o)

BONUS = ./bonus/ft_split_bonus.c \
		./bonus/draw_map_bonus.c \
		./bonus/get_next_line_bonus.c \
		./bonus/get_next_line_utils_bonus.c \
		./bonus/read_map_bonus.c \
		./bonus/set_hei_wid_bonus.c \
		./bonus/set_parameter_bonus.c \
		./bonus/main_bonus.c \
		./bonus/set_positon_bonus.c \
		./bonus/movemont_bonus.c \
		./bonus/you_win_bonus.c \
		./bonus/ft_itoa_bonus.c \
		./bonus/ft_check_validefile_bonus.c \
		./bonus/ft_enemy_bonus.c \
		./bonus/ft_collec_bonus.c

OBJB = $(BONUS:.c=.o)

GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

bonus : $(NAME_BONUS)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(NAME_BONUS) : $(OBJB)
	$(CC) $(FLAGS) $(OBJB) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
	@echo "$(GREEN)$(NAME_BONUS) created$(RESET)"

mandatory/%.o: mandatory/%.c mandatory/so_long.h
	$(CC) $(FLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/so_long_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJB)
	@echo "$(GREEN)$(NAME)$(NAME_BONUS) objects cleaned$(RESET)"

re: fclean all

fclean: clean

	rm -f $(NAME) $(NAME_BONUS)
	@echo "$(GREEN)$(NAME)$(NAME_BONUS) fcleaned$(RESET)"

.PHONY: clean

char *x = NULL;