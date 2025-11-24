
# ************************************** #
#                CONFIG                  #
# ************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror

# --- LIBRARIES --
LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a



# ************************************** #
#               SOURCES                  #
# ************************************** #
SRC = src/main.c \
	$(wildcard src/parsing/*.c) \
	$(wildcard src/init/*.c) \
	$(wildcard src/utils/*.c)

OBJ_DIR = ./obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


# --- Include paths
INCLUDES    = -I include -I $(LIBFT_DIR)

# ************************************** #
#                 RULES                  #
# ************************************** #
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) -o $@

# Rule to build libft if it doesn't exist
$(LIBFT_LIB): $(LIBFT_DIR)/Makefile
	$(MAKE)	-C $(LIBFT_DIR)


$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ************************************** #
#              BONUS MODE                #
# ************************************** #


# ************************************** #
#              DEBUG MODE                #
# ************************************** #

debug: CFLAGS += $(DEBUG_FLAGS)
debug: all

# ************************************** #
#              CLEAN-UP                  #
# ************************************** #

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)


fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)


re: fclean all

.PHONY: all clean fclean re
