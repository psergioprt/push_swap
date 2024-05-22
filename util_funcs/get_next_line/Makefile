NAME = next_line.a
EXEC = next_line_exec
CC	= cc
CFFLAGS	= -Wall -Wextra -Werror
AR	= ar
ARFLAGS	= -rcs
RM	= rm
RMFLAGS	= -f

SRC	= get_next_line.c get_next_line_utils.c
OBJ	= $(SRC:.c=.o)

BONUS	= get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ_BONUS = $(BONUS:.c=.o)

MAIN = main.c
MAIN_OBJ = $(MAIN:.c=.o)

all: $(NAME) $(EXEC)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $(OBJ)

$(EXEC): $(MAIN_OBJ) $(NAME)
	$(CC) $(CFLAGS) -o $@ $(MAIN_OBJ) $(NAME)

bonus: $(OBJ) $(OBJ_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(OBJ_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@echo "Cleaning get_next_line objects..."
	@$(RM) $(RMFLAGS) $(OBJ) $(OBJ_BONUS) $(MAIN_OBJ)

fclean: clean
	@echo "Cleaning Libft library..."
	@$(RM) $(RMFLAGS) $(NAME) $(EXEC)

re: fclean all

.PHONY: all clean fclean re bonus
