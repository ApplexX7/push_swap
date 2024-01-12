# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 15:10:02 by mohilali          #+#    #+#              #
#    Updated: 2024/01/07 13:20:45 by mohilali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = mandatory/push_swap.c mandatory/push_swap_utils.c mandatory/push_swap_utils_one.c mandatory/push_swap_utils_two.c \
	mandatory/simple_sort.c mandatory/push_swap_utils_tree.c mandatory/build_stack.c mandatory/instra/push.c  \
	mandatory/instra/rotate.c mandatory/instra/rrotate.c mandatory/instra/swap.c mandatory/algo_a_to_b.c mandatory/algo_b_to_a.c \

SRCB = bonus/checker_bonus.c bonus/checker_bonus_utils_one.c bonus/checker_bonus_utils_two.c bonus/checker_bonus_utils.c \
	bonus/checker_helper_bonus.c bonus/checker_helper_one_bonus.c bonus/checker_split_bonus.c bonus/instra_bonus/push_bonus.c \
	bonus/instra_bonus/rotate_bonus.c bonus/instra_bonus/rrotate_bonus.c bonus/instra_bonus/swap_bonus.c

OBJCT = ${SRC:.c=.o}
OBJCTB = ${SRCB:.c=.o}
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
NAME = push_swap
HEADER_NAME = mandatory/push_swap.h
HEADER_BONUS = bonus/push_swap_bonus.h
NAME_BONUS = checker

all : $(NAME)

$(NAME) : $(OBJCT)
	$(CC) $(OBJCT) -o $(NAME)

bonus: $(OBJCTB)
	$(CC) $(OBJCTB) -o $(NAME_BONUS)

mandatory/%.o : mandatory/%.c $(HEADER_NAME)
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o : bonus/%.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJCT) $(OBJCTB)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)
re : fclean all