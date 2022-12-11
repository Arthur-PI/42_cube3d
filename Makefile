# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apigeon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 16:08:04 by apigeon           #+#    #+#              #
#    Updated: 2022/12/11 20:33:11 by apigeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


### COMPILATION ###
CC		= cc
CFLAGS	= -Wall -Wextra
CFLAGS	+= -Wshadow -Wpedantic -Wuninitialized -Wmissing-include-dirs -Wundef -Winvalid-pch
CFLAGS	+= -Winit-self -Wswitch-enum -Wswitch-default -Wformat=2 -Wformat-nonliteral -Wformat-security -Wformat-y2k
CFLAGS	+= -Wdouble-promotion -Wfloat-equal -Wpointer-arith
CFLAGS	+= -Wconditional-uninitialized
CFLAGS	+= -MMD -MP
INCLUDE	= -I$(H_DIR) -I$(LIBFT_DIR)/$(H_DIR) -I$(MLX_DIR)
LFLAGS	= -L$(LIBFT_DIR) -L$(MLX_DIR)
LINKS	= -lm -lft -lmlx

### ENV VARIABLES ###
-include .env
FDEBUG		?= false
FTEST		?= false
FNOERROR	?= false

ifeq ($(FDEBUG),true)
	CFLAGS += -g3 -Os
endif

ifeq ($(FNOERROR),false)
	CFLAGS += -Werror
endif

ifeq ($(FTEST),true)
	SRCS	= test_main.c
else
	SRCS	= main.c
endif

### EXECUTABLE ###
NAME	= cube3d
ARGS	= ""

### INCLUDES ###
OBJ_DIR		= bin
SRC_DIR		= src
H_DIR		= incl
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
MLX_DIR		= mlx
MLX			= $(MLX_DIR)/libmlx.a

### SOURCE FILES ###
SRCS	= 	main.c \
			parse/parser.c \

### OBJECTS ###
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS	= $(OBJS:.o=.d)

### COLORS ###
RESET	= \033[0m
BLACK	= \034[1;30m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
PURPLE	= \033[1;35m
CYAN	= \033[1;36m
WHITE	= \033[1;37m

### OTHERS ###
UNAME_S = $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	VALGRIND	= leaks --list --groupByType --atExit --
else
	VALGRIND	= valgrind --track-origins=yes --leak-check=full
	CFLAGS		+= -X11 -Xext
endif

### RULES ###
all:	$(NAME)

$(LIBFT):
	@echo "$(NAME): $(GREEN)Compiling $(LIBFT_DIR)$(RESET)"
	@$(MAKE) addon -C $(LIBFT_DIR)

$(MLX):
	@echo "$(NAME): $(GREEN)Compiling $(MLX_DIR)$(RESET)"
	@$(MAKE) -C $(MLX_DIR)

$(NAME):	$(LIBFT) $(MLX) $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) $(LINKS) -o $(NAME)
	@echo "$(NAME): $(BLUE)Creating program file -> $(WHITE)$(notdir $@)... $(GREEN)[Done]$(RESET)"
	@echo "$(NAME): $(GREEN)Project successfully compiled$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(NAME): $(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(GREEN)[Done]$(RESET)"

run: $(NAME)
	@./$(NAME) $(ARGS)

val: $(NAME)
	@$(VALGRIND) ./$(NAME) $(ARGS)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@echo "$(NAME): $(RED)Supressing object files$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(NAME): $(RED)Supressing program file$(RESET)"
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

-include $(DEPS)
