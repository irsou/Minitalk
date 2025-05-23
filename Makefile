NAME_CLIENT = client
NAME_SERVER = server

INCLUDE_DIR = include

SRC_COMMON = \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	printf/ft_printf.c \
	printf/ft_printf_utils.c \
	printf/ft_printf_hex_utils.c
SRC_CLIENT = src/client.c ${SRC_COMMON}
SRC_SERVER = 	src/server.c ${SRC_COMMON}

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADERS = $(INCLUDE_DIR)/*.h get_next_line/get_next_line.h printf/ft_printf.h

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -I$(INCLUDE_DIR) -Iget_next_line -Iprintf -c $< -o $@

all: $(LIBFT) $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ_CLIENT) -L$(LIBFT_DIR) -lft -lm -o $@

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ_SERVER) -L$(LIBFT_DIR) -lft -lm -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	
clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
	@$(MAKE) -C $(LIBFT_DIR) clean


fclean: clean
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY:	all clean fclean re
