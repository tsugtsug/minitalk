S_NAME = server
C_NAME = client
NAME = $(S_NAME) $(C_NAME)
LIB_NAME = libft
LIB_DIR = libft
SRCS = server.c client.c
OBJS = $(SRCS:%.c=%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIB_NAME) $(S_NAME) $(C_NAME)

$(S_NAME): server.o $(LIB_NAME)
	$(CC) -o $@ $< -L$(LIB_DIR) -lft

$(C_NAME): client.o $(LIB_NAME)
	$(CC) -o $@ $< -L$(LIB_DIR) -lft

$(LIB_NAME):
	make -C $(LIB_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME) $(LIB_DIR)/$(LIB_NAME).a

re: fclean all

.PHONY: all $(NAME) $(S_NAME) $(C_NAME) $(LIB_NAME) clean fclean re