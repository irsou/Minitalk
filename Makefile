NAME = fdf

INCLUDE_DIR = include

SRC = get_next_line/get_next_line.c \
get_next_line/get_next_line_utils.c \
src/main.c \


OBJ = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Werror -Wextra -g -fsanitize=address
RM = rm -f
AR = ar rcs
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADERS = $(INCLUDE_DIR)/*.h

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -I$(INCLUDE_DIR) -c $< -o $@

all: $(LIBFT) $(LIBMLX) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -lm -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	
clean:
	$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean


fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY:	all clean fclean re
