NAME_SERVER		= server

NAME_CLIENT		= client

OBJS_DIR		= obj

CLIENT			= srcs/client

SERVER			= srcs/server

SRCS_CLIENT		= $(shell find $(CLIENT) -name '*.c')

OBJS_CLIENT		= $(patsubst $(CLIENT)/%.c, $(OBJS_DIR)/%.o, $(SRCS_CLIENT))

SRCS_SERVER		= $(shell find $(SERVER) -name '*.c')

OBJS_SERVER		= $(patsubst $(SERVER)/%.c, $(OBJS_DIR)/%.o, $(SRCS_SERVER))

FLAGS			= -Wall -Wextra -Werror -fsanitize=address -g

INCS			= -I./includes -I./Libft

LIBFT			= -LLibft -lft

HEADER			= includes/minitalk.h

all:			mkdir lib $(NAME_CLIENT) $(NAME_SERVER)

obj/%.o:		srcs/*/%.c $(HEADER) Makefile
		$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(NAME_CLIENT):	$(OBJS_CLIENT)
		$(CC) $(FLAGS) $(INCS) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

$(NAME_SERVER):	$(OBJS_SERVER)
		$(CC) $(FLAGS) $(INCS) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)

mkdir:
		@mkdir -p obj

lib:
		@make -C Libft

clean:
		make clean -C Libft
		rm -rf $(OBJS_DIR)

fclean:			clean
		make fclean -C Libft
		rm -rf $(NAME_CLIENT) $(NAME_SERVER)

re:				fclean all

.PHONY:			all clean fclean re lib