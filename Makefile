NAME_CLIENT = client
NAME_SERVER = server

INCLUDE_DIR = include

SRC_CLIENT = src/client.c
SRC_SERVER = 	src/server.c \
            	get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				printf/ft_printf_utils.c \
				printf/ft_printf_hex_utils.c \
				printf/ft_printf.c \

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

CC = cc
FLAGS = -Wall -Werror -Wextra -g -fsanitize=address
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADERS = $(INCLUDE_DIR)/*.h get_next_line/get_next_line.h printf/ft_printf.h

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -I$(INCLUDE_DIR) -Iget_next_line -c $< -o $@

all: $(LIBFT) $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(FLAGS) $(OBJ_CLIENT) -L$(LIBFT_DIR) -lft -lm -o $@

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(FLAGS) $(OBJ_SERVER) -L$(LIBFT_DIR) -lft -lm -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	
clean:
	$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean


fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY:	all clean fclean re
