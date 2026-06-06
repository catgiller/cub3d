# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/06 21:28:28 by ervsahin          #+#    #+#              #
#    Updated: 2026/06/06 21:41:51 by ervsahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================== VARIABLES ==================

NAME			= cub3D
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
BUFFER_SIZE		= 1024

# ================== DIRECTORIES ==================

SRC_DIR			= srcs
OBJ_DIR			= objs
PARSE_DIR		= $(SRC_DIR)/parsing
VALIDATION_DIR	= $(SRC_DIR)/validation
UTILS_DIR		= $(SRC_DIR)/utils.c
GNL_DIR			= $(UTILS_DIR)/get_next_line-main

# ================== SOURCE FILES ==================

# Main source
MAIN_SRC		= main.c

# Parsing sources
PARSE_SRC		= parse_file.c \
				  parse_elements.c \
				  parse_map.c \
				  parse_utils.c

# Validation sources
VALIDATION_SRC	= val_element.c \
				  val_map.c \
				  val_flood.c

# Utilities - get_next_line
GNL_SRC			= get_next_line.c \
				  get_next_line_utils.c

# Full paths
MAIN_SRCS		= $(addprefix $(SRC_DIR)/, $(MAIN_SRC))
PARSE_SRCS		= $(addprefix $(PARSE_DIR)/, $(PARSE_SRC))
VALIDATION_SRCS	= $(addprefix $(VALIDATION_DIR)/, $(VALIDATION_SRC))
GNL_SRCS		= $(addprefix $(GNL_DIR)/, $(GNL_SRC))

ALL_SRCS		= $(MAIN_SRCS) $(PARSE_SRCS) $(VALIDATION_SRCS) $(GNL_SRCS)
OBJS			= $(addprefix $(OBJ_DIR)/, $(ALL_SRCS:.c=.o))
DEPS			= $(OBJS:.o=.d)

# ================== RULES ==================

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -o $@ $^
	@echo "✓ $(NAME) compiled successfully"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "✓ Object files cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "✓ Everything cleaned"

re: fclean all

# ================== PHONY ==================

.PHONY: all clean fclean re