CC = cc
CFLAGS = -Wall -Wextra -Werror
TARGET = push_swap
SRCDIR = src
OBJDIR = obj
INCDIR = include
LIBFTDIR = Libft
LIBFT = $(LIBFTDIR)/libft.a

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

$(TARGET): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: clean
