NAME = libftprintf.a

AR	= ar crs
CC	= cc
CFLAGS = -Wall -Wextra -Werror
RM	= rm -rf
SRCDIR	= src
OBJDIR	= obj
LIBFTDIR = Libft
LIBFT	= $(LIBFTDIR)/libft.a

SRC	= $(wildcard $(SRCDIR)/*.c)
OBJ	= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

	  ft_strlen.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_strchr.c \

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -o$@ -c $<

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(RM) $(OBJ) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all
