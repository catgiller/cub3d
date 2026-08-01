NAME		= cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -Ilibft -Iget_next_line

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
GNL_DIR		= get_next_line
GNL_SRCS	= $(GNL_DIR)/get_next_line.c

SRCS		= main.c \
			  src/error.c \
			  src/parser/parser.c \
			  src/parser/read_file.c \
			  src/parser/parse_texture.c \
			  src/parser/parse_texture_utils.c \
			  $(GNL_SRCS)

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
CPPFLAGS += -I.
