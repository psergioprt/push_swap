NAME = libft.a

CC	= cc
CFFLAGS	= -Wall -Wextra -Werror
AR	= ar
ARFLAGS	= -rcs
RM	= rm
RMFLAGS = -f
OBJDIR = obj

SRC	= $(wildcard *.c)
OBJ 	= $(patsubst :.c,$(OBJDIR)/%.o,$(notdir $(SRC)))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $(OBJ)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFFLAGS) -o$@ -c $<
clean:
	$(RM) $(RMFLAGS) $(OBJDIR)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
