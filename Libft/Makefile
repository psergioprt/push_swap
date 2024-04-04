NAME = libft.a

CC	= cc
CFFLAGS	= -Wall -Wextra -Werror
AR	= ar
ARFLAGS	= -rcs
RM	= rm
RMFLAGS = -f

SRC	= ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_memset.c ft_strlen.c ft_tolower.c ft_toupper.c \
	ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_strmapi.c ft_striteri.c ft_itoa.c ft_strtrim.c ft_split.c

OBJ	= $(SRC:.c=.o)

BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.o ft_lstlast.o ft_lstadd_back.o\
	  ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap.o

OBJ_BONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(RMFLAGS) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

bonus: $(OBJ) $(OBJ_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(OBJ_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
