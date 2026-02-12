# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/12 10:22:44 by frocha-b          #+#    #+#              #
#    Updated: 2026/02/12 14:13:34 by frocha-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = global_banksters

# Compiler and flags
CC          = c++
# Added -std=c++98 for 42 compatibility
CFLAGS      = -Wall -Werror -Wextra -std=c++98 -g

# Directories
OBJ_DIR     = objects

# Explicitly list files (Recommended for 42)
SRC_FILES   =  Account.cpp tests.cpp
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

# Includes
INC         = -Iincludes

# Colors
C_GREEN     = \033[0;32m
C_YELLOW    = \033[1;33m
C_RESET     = \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(C_GREEN)✅ $(NAME) created!$(C_RESET)"

# Fixed pattern rule: uses .cpp and matches the OBJ_DIR structure
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "$(C_YELLOW)🛠️  Compiling $<$(C_RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@echo "$(C_YELLOW)🧹 Cleaning objects...$(C_RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "$(C_GREEN)🧽 Full clean complete!$(C_RESET)"

re: fclean all

.PHONY: all clean fclean re