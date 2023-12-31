# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanjebou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 17:45:52 by hanjebou          #+#    #+#              #
#    Updated: 2023/10/09 16:31:01 by hanjebou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#VARIABLES

NAME 		= libftprintf.a
CC 			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -I
LIBFT       = libft
INCLUDE		= include
SRC_DIR		= src/
OBJ_DIR		= obj/
AR			= ar rcs

#COLORS

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#SOURCE

SRC_FILES	= ft_printf_str ft_printf_utils ft_printf

SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJF		= .cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJ)
			@echo "$(GREEN)\n╭───────────────────────────────────╮$(DEF_COLOR)"
			@echo "$(GREEN)│       ft_printf compiled !        │$(DEF_COLOR)"
			@echo "$(GREEN)╰───────────────────────────────────╯\n$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
			@echo "$(GREEN) ✔ $< $(DEF_COLOR)"

$(OBJF):
			@mkdir -p $(OBJ_DIR)


clean:
			@$(RM) $(OBJ_DIR)
			@make clean -C $(LIBFT)
			@echo "$(YELLOW)\n╭───────────────────────────────────────────╮$(DEF_COLOR)"
			@echo "$(YELLOW)│           Cleaned object files.           │$(DEF_COLOR)"
			@echo "$(YELLOW)╰───────────────────────────────────────────╯\n$(DEF_COLOR)"

fclean:		
			@$(RM) $(OBJ_DIR) $(LIBFT)/libft.a $(NAME)
			@make clean -C $(LIBFT)
			@echo "$(YELLOW)\n╭───────────────────────────────────────────╮$(DEF_COLOR)"
			@echo "$(YELLOW)│  Cleaned object files and libftprintf.a.  │$(DEF_COLOR)"
			@echo "$(YELLOW)╰───────────────────────────────────────────╯\n$(DEF_COLOR)"


re:			fclean all
			@echo "$(CYAN)\n╭───────────────────────────────────╮$(DEF_COLOR)"
			@echo "$(CYAN)│  Cleaned and rebuilt ft_printf !  │$(DEF_COLOR)"
			@echo "$(CYAN)╰───────────────────────────────────╯\n$(DEF_COLOR)"

.PHONY:		all clean fclean re
