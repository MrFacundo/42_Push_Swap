NAME 			= push_swap
SOURCES 		= $(shell echo srcs/*.c)
OBJECTS 		= $(SOURCES:.c=.o)
HEADER			= -Iincludes
LIBFT_DIR		= ./libft
CC 				= gcc
CFLAGS_PROD 	= -g
LFLAGS		 	= -L$(LIBFT_DIR)


# CFLAGS_PROD 	= -g -Wall -Wextra -Werror

# --- COLORS ---

NONE=\033[0m
GRAY=\033[2;37m
RED=\033[31m
GREEN=\033[32m

# --- RULES ---

all: $(NAME)

$(NAME): $(OBJECTS) libft
		@echo  "$(GRAY)----Compiling $(NAME)----$(NONE)"
		gcc -o $@ $(OBJECTS) $(LFLAGS)
		@echo "$(GREEN)$(NAME) Compiled! ᕦ(♥_♥)ᕤ$(NONE)\n"

.c.o:	%.o : %.c
		$(CC) $(CFLAGS_PROD) -c $< -o $@

libft:
		@echo  "$(GRAY)----Compiling Libft----$(NONE)"
		make -C $(LIBFT_DIR)

clean:
		@echo "$(GREEN)Deleting obs! ( ͡° ͜ʖ ͡°) $(NONE)"
		rm -f $(OBJECTS)
		make -C $(LIBFT_DIR) clean

fclean:	clean
		@echo "$(RED)Deleting everything! ( ͡° ͜ʖ ͡°) $(NONE)"
		rm -f $(NAME) $(OBJECTS) libft/libft.a


show:
		@printf "NAME	: $(NAME)\n"
		@printf "CC	: $(CC)\n"
		@printf "CFLAGS	: $(CFLAGS_PROD)\n"
		@printf "LFLAGS	: $(LFLAGS)\n"
		@printf "SOURCES	: $(SOURCES)\n"

valgrind: all
		 valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s ./so_long maps/map_4.ber


re: fclean all

.PHONY: all libft clean fclean re valgrind show