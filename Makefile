# Variable definition
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -I$(LIBFTDIR) -Ift_printf
TARGET = push_swap
SRCDIR = src
OBJDIR = obj
INCDIR = include
LIBFTDIR = Libft
LIBFT = $(LIBFTDIR)/libft.a
# Holds linker flags for printf(-L adds ft_printf folder, (-l specifies the library to link)
LDFLAGS = -Lft_printf -lftprintf

# Define color codes
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_RESET=\033[0m

.SILENT:


# wildcard to find all sources files
SRC = $(wildcard $(SRCDIR)/*.c)
# defines object files corresponding to each source file
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# Main target of the Makefile (push_swap), depends on Objs and Libft
# compiles the source files, links them to Libft and ft_printf Library
# and produces push_swap executable
$(TARGET): $(OBJS) $(LIBFT)
	@echo "$(COLOUR_GREEN)=>Linking objects...$(COLOUR_RESET)"
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@$(MAKE) rebuild_libft

# Generate object files from source files.
# Compiles each .c in the SRCDIR into corresponding .o file in OBJDIR
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "$(COLOUR_BLUE)=>Compiling Push_swap...$(COLOUR_RESET)"
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# To ensure Libft library is built by invoking make in LIBFDIR
$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

# Removes all object files, the push_swap executable and Libft library
# Rebuilds Libft library
clean:
	@echo "$(COLOUR_RED)=> Cleaning Push_swap library...$(COLOUR_RESET)"
	$(RM) -rf $(OBJDIR) $(TARGET)
	@echo "$(COLOUR_RED)=> Cleaning Libft library...$(COLOUR_RESET)"
	$(MAKE) -C $(LIBFTDIR) clean

rebuild_libft:
	@echo "$(COLOUR_BLUE)=>Compiling Libft Library...$(COLOUR_RESET)"
	$(MAKE) -C $(LIBFTDIR)

# Clean is a phony target, which means it doesn't output a file
# with the same name "clean".
.PHONY: clean rebuild_libft deploy
deploy:
